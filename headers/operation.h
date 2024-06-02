#ifndef OPERATION_H
#define OPERATION_H


#include <gtkmm-4.0/gtkmm.h>
#include "mainwindow.h"
#include "PieChart.h"
#include <map>

class MainWindow;
class MyWindow;

class Operation: public Gtk::Window{
    std::string type_;
    public:
        explicit Operation(const std::string& type);
        virtual ~Operation() = default;
        void get_data(std::string oper_name,std::map<std::string,double>& data);

        void on_confirm_button(const std::string operation_type, std::map<std::string, double >& data,bool reset);

        void on_reset_button(const std::string operation_type);
    protected:
        Gtk::Label LabelCat1;    
        Gtk::Label LabelCat2;    
        Gtk::Label LabelCat3; 
        Gtk::Box  box_for_oper1;       
        Gtk::Box box_for_oper2;      
        Gtk::Box box_for_oper3; 
        Gtk::Box box;

        Gtk::Box data_box;
        Gtk::Label data_1;
        Gtk::Label data_2;
        Gtk::Label data_3;
        
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
        
        std::map<std::string,double> m_data;

        Gtk::Button reset_button;

        Gtk::Button exit_button;
};


class IncomeOperation: public Operation{
    public:
        IncomeOperation(const std::string& type);
        void on_confirm_button_income_clicked();
        void on_reset_button_income_clicked();
        

};

class OutComeOperation:public Operation{
    public:
        OutComeOperation(const std::string& type);
        
        void on_confirm_button_outcome_clicked();
        void on_reset_button_outcome_clicked();

};

class DebtOperation:public Operation{
    public:
        DebtOperation(const std::string& type);
        
        void on_confirm_button_debt_clicked();
        void on_reset_button_debt_clicked();
};


class OperationFactory{
    public:
        static std::unique_ptr<Operation> createOperation(const std::string& type);
};
#endif