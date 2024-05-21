#include "../headers/user_pick_window.h"


MyWindow::MyWindow()
    : m_VBox(Gtk::Orientation::VERTICAL),
      m_Label("Выберите пользователя"),
      m_Button1("Пользователь 1"),
      m_Button2("Пользователь 2"),
      m_Button3("Пользователь 3") {
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
    // m_Button1.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    // m_Button2.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
    // m_Button3.signal_clicked().connect(sigc::mem_fun(*this, &MyWindow::on_button_clicked));
}


// void MyWindow::on_button_clicked(){
//     show_user_window();
// }
void MyWindow::on_button1_clicked() {
   
   
    show_user_window(1);
}

void MyWindow::on_button2_clicked() {
       
    show_user_window(2);
}

void MyWindow::on_button3_clicked() {
    
    show_user_window(3);
}
void MyWindow::on_user_window_hide(){
    user_window.reset();
}

void MyWindow::show_user_window(const int user_id ){

    if (user_window  && user_window->is_visible()){
        user_window->close();
        
    }
    
    user_window = std::make_unique<UserWindow>(user_id);
    user_window->signal_hide().connect(sigc::mem_fun(*this, &MyWindow::on_user_window_hide));
    user_window->show();
}