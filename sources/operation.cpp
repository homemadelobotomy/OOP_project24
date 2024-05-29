#include "../headers/operation.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>



Operation::Operation(MyWindow* user_window_):
    box(Gtk::Orientation::VERTICAL),
    user_window(user_window_),
    box_for_oper1(Gtk::Orientation::HORIZONTAL),
    box_for_oper2(Gtk::Orientation::HORIZONTAL),
    box_for_oper3(Gtk::Orientation::HORIZONTAL),
    confirm_button("Добавить изменения"),
    exit_button("Выход")
    {
        
        set_default_size(500,500);

        box.set_margin (10);
        box.set_spacing(10);
        
        set_child(box);

        LabelTitle.set_margin_bottom(10);
        LabelTitle.set_halign(Gtk::Align::CENTER);
        box.append(LabelTitle);
        box.append(piechart);

        piechart.set_size_request(100,100);
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

        box.append(exit_button);


       
        exit_button.signal_clicked().connect(sigc::mem_fun(*this, &Operation:: on_exit_button));

        

    }
    void Operation::on_exit_button(){
        this->hide();
    }
    void Operation::get_data(std::string oper_name, std::vector<double>& data){
        
        std::ifstream read_from_file;
        std::string filename = "../user_data/user_data_" + user_window->GetUsername() + "_" + user_window->GetPassword() + ".txt";
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
                while (std::getline(iss, token, ' ')) {
                data.push_back(std::stod(token));
                }
                return ;
            
        }

    }
    }
    void Operation::on_confirm_button(const std::string operation_type)
    {
        std::ifstream read_from_file;
        std::ofstream write_in_file;
        std::string filename = "../user_data/user_data_" + user_window->GetUsername() + "_" + user_window->GetPassword() + ".txt";
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
        for(int i = 0; i < 6;i++){
        std::cout << lines[i] << std::endl;
            if (lines[i - 1] == operation_type){
                lines[i] = (EntryCat1.get_text().empty()? "0":EntryCat1.get_text()) + " " 
                + (EntryCat2.get_text().empty() ? "0":EntryCat2.get_text()) + " "
                + (EntryCat3.get_text().empty() ? "0":EntryCat3.get_text());
            }
            write_in_file << lines[i] + "\n";
        }
        write_in_file.close();
    }
    
    void IncomeOperation::on_confirm_button_income_clicked()
    {
        Operation::on_confirm_button("IncomeOperation");
        
    }

    void OutComeOperation::on_confirm_button_outcome_clicked() {
        Operation::on_confirm_button("OutComeOperation");
    }
    void DebtOperation::on_confirm_button_debt_clicked() {
        Operation::on_confirm_button("DebtOperation");
    }