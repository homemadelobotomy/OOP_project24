#include <gtkmm-4.0/gtkmm.h>
#include "users_data.h"
#include <memory>


class MyWindow : public Gtk::Window {
public:
    MyWindow();
    void show_user_window(const int user_id);
private:
    Gtk::Box m_VBox;          // Вертикальный контейнер для всех виджетов
    Gtk::Label m_Label;       // Надпись
    Gtk::Button m_Button1;    // Первая кнопка
    Gtk::Button m_Button2;    // Вторая кнопка
    Gtk::Button m_Button3;    // Третья кнопка

    void on_button1_clicked();
    void on_button2_clicked();
    void on_button3_clicked();
    void on_user_window_hide();

    void on_button_clicked();

    std::unique_ptr<UserWindow> user_window;
};


