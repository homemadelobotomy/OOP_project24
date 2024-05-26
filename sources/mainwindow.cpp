#include "../headers/mainwindow.h"

MainWindow::MainWindow(MyWindow* user_window_)
    : button_income("Доходы"), button_expense("Расходы"), button_debt("Долги"),
    user_window(user_window_), exit_button("Выйти")
    {

    set_title("Финансовый Контроль");
    set_default_size(300, 200);

    vbox.set_orientation(Gtk::Orientation::VERTICAL);
    vbox.set_spacing(10);
    vbox.set_margin(10);

    button_income.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_income_clicked));
    button_expense.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_expense_clicked));
    button_debt.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_debt_clicked));

    exit_button.signal_clicked().connect(sigc::mem_fun(*this,&MainWindow::on_exit_button_clicked));

    vbox.append(button_income);
    vbox.append(button_expense);
    vbox.append(button_debt);
    vbox.append(exit_button);

    set_child(vbox);
}

void MainWindow::on_button_income_clicked() {
    Operation *window = new IncomeOperation(user_window);
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}

void MainWindow::on_button_expense_clicked() {
    Operation *window = new OutComeOperation(user_window);
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}

void MainWindow::on_button_debt_clicked() {
    Operation *window = new DebtOperation(user_window)  ;
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}
void MainWindow::on_exit_button_clicked(){
    this->hide();
}
