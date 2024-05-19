 #include <iostream>

#include <gtkmm-4.0/gtkmm.h>

class MyWindow : public Gtk::Window {
public:
    MyWindow();

private:
    Gtk::Box m_VBox;          // Вертикальный контейнер для всех виджетов
    Gtk::Label m_Label;       // Надпись
    Gtk::Button m_Button1;    // Первая кнопка
    Gtk::Button m_Button2;    // Вторая кнопка
    Gtk::Button m_Button3;    // Третья кнопка

    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
};

MyWindow::MyWindow()
    : m_VBox(Gtk::Orientation::VERTICAL),
      m_Label("Выберите пользователя"),
      m_Button1("Пользователь 1"),
      m_Button2("Пользователь 2"),
      m_Button3("User 4") {
    set_title("GTKmm Example");
    set_default_size(400, 200);

    // Настройка вертикального контейнера
    m_VBox.set_spacing(10);
    m_VBox.set_margin(10);
    set_child(m_VBox);

    // Настройка надписи
    m_Label.set_margin_bottom(10);
    m_Label.set_halign(Gtk::Align::CENTER);
    m_VBox.append(m_Label);

    // Настройка кнопок
    m_Button1.set_halign(Gtk::Align::CENTER);
    m_Button2.set_halign(Gtk::Align::CENTER);
    m_Button3.set_halign(Gtk::Align::CENTER);

    // Добавление кнопок в контейнер
    m_VBox.append(m_Button1);
    m_VBox.append(m_Button2);
    m_VBox.append(m_Button3);

    // Присоединение сигналов
    m_Button1.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button1_clicked));
    m_Button2.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button2_clicked));
    m_Button3.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button3_clicked));
}

void MyWindow::on_button1_clicked() {
    std::cout << "Пользователь 1 выбран" << std::endl;
}

void MyWindow::on_button2_clicked() {
    std::cout << "Пользователь 2 выбран" << std::endl;
}

void MyWindow::on_button3_clicked() {
    std::cout << "Пользователь 3 выбран" << std::endl;
}

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");

    MyWindow window;

    return app->make_window_and_run<MyWindow>(argc, argv);
}
