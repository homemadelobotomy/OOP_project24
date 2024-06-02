#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <gtkmm-4.0/gtkmm.h>
#include "user_pick_window.h"
#include "sectionwindow.h"
#include "operation.h"

class Operation;

class MainWindow : public Gtk::Window {
public:
    MainWindow(MyWindow* user_window);

protected:
    void on_button_income_clicked();
    void on_button_expense_clicked();
    void on_button_debt_clicked();
    void on_exit_button_clicked();

private:
    MyWindow* user_window;
    Gtk::Box vbox;
    Gtk::Button button_income;
    Gtk::Button button_expense;
    Gtk::Button button_debt;
    Gtk::Button exit_button;
};
void showOperation(const Operation& operation);


#endif 
