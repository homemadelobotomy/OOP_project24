#ifndef OPERATION_H
#define OPERATION_H

#include <gtkmm-4.0/gtkmm.h>

class Operation: public Gtk::Window{
    public:
        Operation(const std::string title);
        virtual ~Operation() {};
        virtual void update_category(const double sum) = 0;
    protected:
        Gtk::Label LabelCat1;    
        Gtk::Label LabelCat2;    
        Gtk::Label LabelCat3; 

        Gtk::Box  box_for_oper1;       
        Gtk::Box box_for_oper2;      
        Gtk::Box box_for_oper3; 
        Gtk::Box box;
    private:
       

        Gtk::Label LabelTitle;   // Название операции
            
        Gtk::Entry EntryCat1;    // Поле ввода для категории 1
        Gtk::Entry EntryCat2;    // Поле ввода для категории 2
        Gtk::Entry EntryCat3;    // Поле ввода для категории 3

        Gtk::Button confirm_button;

        void on_confirm_button();

};


class IncomeOperation:public Operation{
    public:
        IncomeOperation(): Operation("Доходы"){
            LabelCat1.set_text("Зарплата");
            LabelCat2.set_text("Подарки");
            LabelCat3.set_text("Пособия");
        }
        void update_category(const double sum) override {
            
        }

};

class OutComeOperation:public Operation{
    public:
        OutComeOperation(): Operation("Расходы"){
            LabelCat1.set_text("Необходимые расходы");
            LabelCat2.set_text("Развлечения ");
            LabelCat3.set_text("Сбережения");
        }
        void update_category(const double sum) override {
            
        }

};

class DebtOperation:public Operation{
    public:
        DebtOperation(): Operation("Долги"){
            LabelCat1.set_text("Выплаты по кредиту");
            LabelCat2.set_text("Личный займ");
            box.remove(box_for_oper3);
        }
        void update_category(const double sum) override {
            
        }

};

#endif