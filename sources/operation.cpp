#include "../headers/operation.h"
#include <string>
#include <fstream>
#include <vector>
#include <iostream>


Operation::Operation(const std::string title):
    box(Gtk::Orientation::VERTICAL),
    LabelTitle(title),
    box_for_oper1(Gtk::Orientation::HORIZONTAL),
    box_for_oper2(Gtk::Orientation::HORIZONTAL),
    box_for_oper3(Gtk::Orientation::HORIZONTAL),
    confirm_button("Добавить изменения"),
    exit_button("Выход")
    {
        set_title(title);
        set_default_size(500,500);

        box.set_margin (10);
        box.set_spacing(10);
        set_child(box);

        LabelTitle.set_margin_bottom(10);
        LabelTitle.set_halign(Gtk::Align::CENTER);
        box.append(LabelTitle);


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


        confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &Operation::on_confirm_button));
        exit_button.signal_clicked().connect(sigc::mem_fun(*this, &Operation:: on_exit_button));

        

    }

    void IncomeOperation::on_confirm_button() {
        std::ifstream read_from_file;
        std::ofstream write_in_file;
        std::string filename = "../user_data/user_data_" + username_ + "_" + password_ + ".txt";
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
            if (lines[i - 1] == "IncomeOperation"){
                lines[i] = (EntryCat1.get_text().empty()? "0":EntryCat1.get_text()) + " " 
                + (EntryCat2.get_text().empty()? "0":EntryCat2.get_text());
            }
            write_in_file << lines[i] + "\n";
        }

        write_in_file.close();
    }
    void DebtOperation::on_confirm_button() {
        std::ifstream read_from_file;
        std::ofstream write_in_file;
        std::string filename = "../user_data/user_data_" + username_ + "_" + password_ + ".txt";
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
            if (lines[i - 1] == "DebtOperation"){
                lines[i] = (EntryCat1.get_text().empty()? "0":EntryCat1.get_text()) + " " 
                + (EntryCat2.get_text().empty()? "0":EntryCat2.get_text()) + " " 
                + (EntryCat3.get_text().empty()? "0":EntryCat3.get_text()); 
            }
            write_in_file << lines[i] + "\n";
        }

        write_in_file.close();
    }
    void OutComeOperation::on_confirm_button() {
        std::ifstream read_from_file;
        std::ofstream write_in_file;
        std::string filename = "../user_data/user_data_" + username_ + "_" + password_ + ".txt";
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
            if (lines[i - 1] == "OutComeOperation"){
                lines[i] = (EntryCat1.get_text().empty()? "0":EntryCat1.get_text()) + " " 
                + (EntryCat2.get_text().empty()? "0":EntryCat2.get_text()) + " " 
                + (EntryCat3.get_text().empty()? "0":EntryCat3.get_text()); 
            }
            write_in_file << lines[i] + "\n";
        }

        write_in_file.close();
    }