#ifndef OPERATION_H
#define OPERATION_H


#include <gtkmm-4.0/gtkmm.h>

class MainWindow;
class Operation: public Gtk::Window{
    public:
        
        Operation(const std::string title);
         ~Operation() {}
        virtual void update_category(const double sum) = 0;
        virtual void on_confirm_button() = 0;
    protected:
        Gtk::Label LabelCat1;    
        Gtk::Label LabelCat2;    
        Gtk::Label LabelCat3; 
        Gtk::Box  box_for_oper1;       
        Gtk::Box box_for_oper2;      
        Gtk::Box box_for_oper3; 
        Gtk::Box box;
        
        std::string username_;
        std::string password_;

        Gtk::Entry EntryCat1;    // Поле ввода для категории 1
        Gtk::Entry EntryCat2;    // Поле ввода для категории 2
        Gtk::Entry EntryCat3;    // Поле ввода для категории 3

        
        void on_exit_button(){}
    private:
       

        Gtk::Label LabelTitle;   // Название операции

        Gtk::Button confirm_button;

        Gtk::Button exit_button;

        

};


class IncomeOperation:public Operation{
    public:
        std::string title = "Доходы";
        
        IncomeOperation(std::string username, std::string password): Operation(title){
            LabelCat1.set_text("Зарплата");
            LabelCat2.set_text("Переводы");
            LabelCat3.set_text("Пособия");
            username_ = username;
            password_ = password;

        }
        void update_category(const double sum) override{}
        void on_confirm_button() override;

};

class OutComeOperation:public Operation{
    public:
        OutComeOperation(std::string username, std::string password): Operation("Расходы"){
            LabelCat1.set_text("Необходимые расходы");
            LabelCat2.set_text("Развлечения ");
            LabelCat3.set_text("Сбережения");
            username_ = username;
            password_ = password;
        }
        void update_category(const double sum) override {
            
        }
        void on_confirm_button() override;

};

class DebtOperation:public Operation{
    public:
        DebtOperation(std::string username, std::string password): Operation("Долги"){
            LabelCat1.set_text("Выплаты по кредиту");
            LabelCat2.set_text("Личный займ");
            box.remove(box_for_oper3);
            username_ = username;
            password_ = password;
        }
        void update_category(const double sum) override {
            
        }
        void on_confirm_button() override;
};

#endif