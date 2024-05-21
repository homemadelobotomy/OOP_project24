#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm-4.0/gtkmm.h>
#include "sectionwindow.h"

class MainWindow : public Gtk::Window {
public:
    MainWindow(std::string user_name, std::string password);

protected:
    void on_button_income_clicked();
    void on_button_expense_clicked();
    void on_button_debt_clicked();

private:
    Gtk::Box vbox;
    Gtk::Button button_income;
    Gtk::Button button_expense;
    Gtk::Button button_debt;
};

#endif 
