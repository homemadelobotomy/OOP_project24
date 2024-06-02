#include "../headers/operation.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include "../headers/operation.h"


Operation::Operation(const std::string &type):type_(type),
    box(Gtk::Orientation::VERTICAL),
    box_for_oper1(Gtk::Orientation::HORIZONTAL),
    box_for_oper2(Gtk::Orientation::HORIZONTAL),
    box_for_oper3(Gtk::Orientation::HORIZONTAL),
    confirm_button("Добавить изменения"),
    reset_button("Сбросить все даныне"),
    exit_button("Выход")
    {
        
        set_default_size(800,600);

        box.set_margin (10);
        box.set_spacing(10);
        
        set_child(box);

        LabelTitle.set_margin_bottom(10);
        LabelTitle.set_halign(Gtk::Align::CENTER);
        box.append(LabelTitle);
        box.append(piechart);

        data_box.append(data_1);
        data_box.append(data_2);
        data_box.append(data_3);
        data_box.set_spacing(10);
        data_box.set_margin(10);
        
        box.append(data_box);

        piechart.set_size_request(400,400);
        box_for_oper1.set_spacing(10);
        box_for_oper1.append(LabelCat1);
        box_for_oper1.append(EntryCat1);
        box.append(box_for_oper1);
        
        
        box_for_oper2.set_spacing(10);
        box_for_oper2.append(LabelCat2);
        box_for_oper2.append(EntryCat2);
        box.append(box_for_oper2);

        box_for_oper3.set_spacing(10);
        box_for_oper3.append(LabelCat3);
        box_for_oper3.append(EntryCat3);
        box.append(box_for_oper3);

        box.append(confirm_button);

        box.append(reset_button);

        box.append(exit_button);


       
        exit_button.signal_clicked().connect(sigc::mem_fun(*this, &Operation:: on_exit_button));

    }
    void Operation::on_exit_button(){
        this->hide();
    }
    void Operation::get_data(std::string oper_name, std::map<std::string,double>& data){

        
        std::ifstream read_from_file;
        std::string filename = "../user_data/user_data_" + UserData::getInstance().getUsername() + "_" + UserData::getInstance().getPassword() + ".txt";
        std::string line;

        std::vector<std::string> lines;
        read_from_file.open(filename);
        
        
        while(std::getline(read_from_file,line)){
            lines.push_back(line);
        }

        for (size_t i = 0; i < lines.size();i++){
            if (lines[i] == oper_name){
                std::string token;
                std::istringstream iss(lines[i+1]);
                
                size_t j = 0;
                std::vector<std::pair<std::string, double>> tempData(data.begin(), data.end());
                while (std::getline(iss, token, ' ')) {
                    tempData[j].second = std::stod(token);
                    j++;
                }
                data.clear();
                for (const auto& pair: tempData){
                    data.insert(pair);
                    std::cout << pair.first << " " << pair.second << std::endl;
                }
                return ;
            
        }

    }
    }
    void Operation::on_confirm_button(const std::string operation_type, std::map<std::string,double>& data, bool reset = false)
    {
        std::ifstream read_from_file;
        std::ofstream write_in_file;
       
        std::string filename = "../user_data/user_data_" + UserData::getInstance().getUsername() + "_" + UserData::getInstance().getPassword() + ".txt";
        std::string line;

        std::vector<std::string> lines;
        read_from_file.open(filename);
        if (!read_from_file.is_open()){
            std::cout << "Невозможно открыть файл" <<std::endl;
            return;
        } 
        
        while(std::getline(read_from_file,line)){
            lines.push_back(line);
           
            
        }
        
        read_from_file.close();
        write_in_file.open(filename);
        std::map<std::string,double>::iterator iter = data.begin();
        for(int i = 0; i < 6;i++){
        std::vector<std::pair<std::string, double>> tempData(data.begin(), data.end());
        
        
            if (lines[i - 1] == operation_type){
                if (reset == false){
                    
                    lines[i] = std::to_string(std::stod(EntryCat1.get_text().empty()? "0":EntryCat1.get_text()) + data.begin()->second) + " " 
                    + std::to_string(std::stod(EntryCat2.get_text().empty() ? "0":EntryCat2.get_text()) + (++data.begin())->second) + " "
                    + std::to_string(std::stod(EntryCat3.get_text().empty() ? "0":EntryCat3.get_text()) + (--data.end())->second);
                   
                }
                else {
                    lines[i] = "0 0 0";
                }

            }
            write_in_file << lines[i] + "\n";
        }
        write_in_file.close();
    }
    
    void Operation::on_reset_button(const std::string type){

    }

    IncomeOperation::IncomeOperation(const std::string& type): Operation(type){
        LabelTitle.set_text("Доходы");
        LabelCat1.set_text("Зарплата");
        LabelCat2.set_text("Переводы");
        LabelCat3.set_text("Пособия");
        
        m_data["1.Зарплата"] = 0;
        m_data["2.Переводы"] = 0;
        m_data["3.Пособия"] = 0;
        get_data("IncomeOperation",m_data);

        std::map<std::string,double>::iterator iter = m_data.begin();
        data_1.set_text(iter->first + ": " + std::to_string(iter->second));
        iter++;
        data_2.set_text(iter->first + ": " + std::to_string(iter->second));
        iter++;
        data_3.set_text(iter->first + ": " + std::to_string(iter->second));

        piechart.set_data(m_data);
        confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &IncomeOperation::on_confirm_button_income_clicked));
        reset_button.signal_clicked().connect(sigc::mem_fun(*this,&IncomeOperation::on_reset_button_income_clicked));

    }

    void IncomeOperation::on_confirm_button_income_clicked()
    {   
        
        get_data("IncomeOperation",m_data);
        std::map<std::string,double>::iterator iter = m_data.begin();
        data_1.set_text(iter->first + ": " + std::to_string(iter->second));
        data_2.set_text((iter++)->first + ": " + std::to_string((iter++)->second));
        data_3.set_text(iter->first + ": " + std::to_string(iter->second));
        Operation::on_confirm_button("IncomeOperation",m_data);
        
    }
    void IncomeOperation::on_reset_button_income_clicked(){
        Operation::on_confirm_button("IncomeOperation",m_data,true);
    }


    OutComeOperation::OutComeOperation(const std::string& type): Operation(type) {
        LabelTitle.set_text("Расходы");
        LabelCat1.set_text("Необходимые расходы");
        LabelCat2.set_text("Развлечения ");
        LabelCat3.set_text("Сбережения");
        m_data["1.Необходимые"] = 0;
        m_data["2.Развлечения"] = 0;
        m_data["3.Сбережения"] = 0;
        get_data("OutComeOperation",m_data);

        std::map<std::string,double>::iterator iter = m_data.begin();
        data_1.set_text(iter->first + ": " + std::to_string(iter->second));
        data_2.set_text((iter++)->first + ": " + std::to_string((iter++)->second));
        data_3.set_text(iter->first + ": " + std::to_string(iter->second));

        piechart.set_data(m_data);
        confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &OutComeOperation::on_confirm_button_outcome_clicked));
        reset_button.signal_clicked().connect(sigc::mem_fun(*this,&OutComeOperation::on_reset_button_outcome_clicked));
    }

    void OutComeOperation::on_confirm_button_outcome_clicked() {

        get_data("OutComeOperation",m_data);

        std::map<std::string,double>::iterator iter = m_data.begin();
        data_1.set_text(iter->first + ": " + std::to_string(iter->second));
        data_2.set_text((iter++)->first + ": " + std::to_string((iter++)->second));
        data_3.set_text(iter->first + ": " + std::to_string(iter->second));

        Operation::on_confirm_button("OutComeOperation",m_data);
    }

    void OutComeOperation::on_reset_button_outcome_clicked(){
        Operation::on_confirm_button("OutComeOperation",m_data,true);
    }

    DebtOperation::DebtOperation(const std::string& type): Operation(type){
            LabelTitle.set_text("Задолженности");
            LabelCat1.set_text("Выплаты по кредиту");
            LabelCat2.set_text("Личный займ");
            m_data["1.Выплаты по кредиту"] = 0;
            m_data["2.Личный займ"] = 0;
            box.remove(box_for_oper3);
            get_data("DebtOperation",m_data);

            std::map<std::string,double>::iterator iter = m_data.begin();
            data_1.set_text(iter->first + ": " + std::to_string(iter->second));
            data_2.set_text((iter++)->first + ": " + std::to_string((iter++)->second));

            piechart.set_data(m_data);
            confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &DebtOperation::on_confirm_button_debt_clicked));
            reset_button.signal_clicked().connect(sigc::mem_fun(*this,&DebtOperation::on_reset_button_debt_clicked));
        }

    void DebtOperation::on_confirm_button_debt_clicked() {
        get_data("DebtOperation",m_data);

        std::map<std::string,double>::iterator iter = m_data.begin();
        data_1.set_text(iter->first + ": " + std::to_string(iter->second));
        data_2.set_text((iter++)->first + ": " + std::to_string((iter++)->second));
        Operation::on_confirm_button("DebtOperation",m_data);
    }
    void DebtOperation::on_reset_button_debt_clicked() {
        Operation::on_confirm_button("DebtOperation",m_data,true);
    }

    void showOperation(const Operation& operation){
    if (dynamic_cast<const IncomeOperation*>(&operation)){
        Operation* window = new IncomeOperation("income");
        window->show();
    }
    else if (dynamic_cast<const OutComeOperation*>(&operation)){
        Operation*  window = new OutComeOperation("outcome");
        window->show();
    }
    else if (dynamic_cast<const DebtOperation*>(&operation)){
        Operation* window = new DebtOperation ("debt");
        window->show();
    }
}



std::unique_ptr<Operation> OperationFactory::createOperation(const std::string& type){
            if (type == "income"){
                return std::make_unique<IncomeOperation>("income");
            }
            else if (type == "outcome"){
                return std::make_unique<OutComeOperation>("outcome");
            }
            else if (type == "debt"){
                return std::make_unique<DebtOperation>("debt");
            }
            else{
                return nullptr;
            }

        }