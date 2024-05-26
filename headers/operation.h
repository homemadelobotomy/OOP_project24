#ifndef OPERATION_H
#define OPERATION_H


#include <gtkmm-4.0/gtkmm.h>
#include "mainwindow.h"
#include "PieChart.h"

class MainWindow;
class MyWindow;

class Operation: public Gtk::Window{
    public:
        
        Operation(MyWindow *user_window);
        ~Operation() {}
        void get_data(std::string oper_name,std::vector<double>& data);
        void on_confirm_button(const std::string operation_type = "NULL");
    protected:
        Gtk::Label LabelCat1;    
        Gtk::Label LabelCat2;    
        Gtk::Label LabelCat3; 
        Gtk::Box  box_for_oper1;       
        Gtk::Box box_for_oper2;      
        Gtk::Box box_for_oper3; 
        Gtk::Box box;
        
        PieChart piechart;
        std::string username_;
        std::string password_;

        Gtk::Entry EntryCat1;    // Поле ввода для категории 1
        Gtk::Entry EntryCat2;    // Поле ввода для категории 2
        Gtk::Entry EntryCat3;    // Поле ввода для категории 3

        MyWindow* user_window;

        Gtk::Label LabelTitle;
        void on_exit_button();
        
        Gtk::Button confirm_button;
        
        std::vector<double> m_data;

        Gtk::Button exit_button;

        

};




class IncomeOperation:public Operation{
    public:
        IncomeOperation(MyWindow* user_window_ ): Operation(user_window_){
            LabelTitle.set_text("Доходы");
            LabelCat1.set_text("Зарплата");
            LabelCat2.set_text("Переводы");
            LabelCat3.set_text("Пособия");

            get_data("IncomeOperation",m_data);
            piechart.set_data(m_data);
            confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &IncomeOperation::on_confirm_button_income_clicked));

        }
        void on_confirm_button_income_clicked();
        

};

class OutComeOperation:public Operation{
    public:
        OutComeOperation(MyWindow* user_window_ ): Operation(user_window_) {
            LabelTitle.set_text("Доходы");
            LabelCat1.set_text("Необходимые расходы");
            LabelCat2.set_text("Развлечения ");
            LabelCat3.set_text("Сбережения");
            get_data("OutComeOperation",m_data);
            piechart.set_data(m_data);
            confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &OutComeOperation::on_confirm_button_outcome_clicked));
        }
        
        void on_confirm_button_outcome_clicked();

};

class DebtOperation:public Operation{
    public:
        DebtOperation(MyWindow* user_window_ ): Operation(user_window_){
            LabelTitle.set_text("Задолженности");
            LabelCat1.set_text("Выплаты по кредиту");
            LabelCat2.set_text("Личный займ");
            box.remove(box_for_oper3);
            get_data("DebtOperation",m_data);
            piechart.set_data(m_data);
            confirm_button.signal_clicked().connect(sigc::mem_fun(*this, &DebtOperation::on_confirm_button_debt_clicked));
        }
        
        void on_confirm_button_debt_clicked();
};

#endif