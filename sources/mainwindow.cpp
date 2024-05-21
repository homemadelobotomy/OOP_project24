#include "../headers/mainwindow.h"

MainWindow::MainWindow(std::string user_name, std::string password)
    : button_income("Доходы"), button_expense("Расходы"), button_debt("Долги") {

    set_title("Финансовый Контроль");
    set_default_size(300, 200);

    vbox.set_orientation(Gtk::Orientation::VERTICAL);
    vbox.set_spacing(10);
    vbox.set_margin(10);

    button_income.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_income_clicked));
    button_expense.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_expense_clicked));
    button_debt.signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_button_debt_clicked));

    vbox.append(button_income);
    vbox.append(button_expense);
    vbox.append(button_debt);

    set_child(vbox);
}

void MainWindow::on_button_income_clicked() {
    SectionWindow *window = new SectionWindow("Доходы", {"Зарплата", "Инвестиции", "Дополнительный доход"});
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}

void MainWindow::on_button_expense_clicked() {
    SectionWindow *window = new SectionWindow("Расходы", {"Жилье", "Транспорт", "Продукты"});
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}

void MainWindow::on_button_debt_clicked() {
    SectionWindow *window = new SectionWindow("Долги", {"Кредиты", "Ипотека", "Личные займы"});
    window->set_transient_for(*this);
    window->set_modal(true);
    window->present();
}
