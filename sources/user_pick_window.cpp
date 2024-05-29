#include "../headers/user_pick_window.h"


MyWindow::MyWindow():
    box(Gtk::Orientation::VERTICAL),
    login_button("Войти"),
    password_label("Пароль"),
    user_name_label("Логин"),
    sign_up_button("Создать аккауунт")
    {
        set_default_size(400,300);
        

         box.set_spacing(10);
        box.set_margin(10);
        set_child(box);

        //user_name_form.set_halign(Gtk::Align::CENTER);
        box.set_halign(Gtk::Align::CENTER);
        box.append(user_name_label);
        box.append(user_name_form);
        box.append(password_label);
        box.append(password_form);
        box.append(login_button);

        box.append(sign_up_button);

        login_button.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::on_login_button_clicked));
        password_form.set_visibility(false);
        sign_up_button.signal_clicked().connect(sigc::mem_fun(*this,&MyWindow::on_sign_up_clicked));
    }

void MyWindow::on_sign_up_clicked(){
    SignUpWindow* sign_up_window = new SignUpWindow(this);
    sign_up_window->show(); 
}

void MyWindow::on_login_button_clicked(){
    username = user_name_form.get_text();
    password = password_form.get_text();
    show_user_window();
}
void MyWindow::on_user_window_hide(){
    user_window.reset();
}

void MyWindow::show_user_window(){

    if (user_window  && user_window->is_visible()){
        user_window->close();
        
    }
    
    user_window = std::make_unique<MainWindow>(this);
    user_window->signal_hide().connect(sigc::mem_fun(*this, &MyWindow::on_user_window_hide));
    user_window->show();
}