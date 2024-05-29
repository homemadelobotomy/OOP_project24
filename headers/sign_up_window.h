#ifndef SIGNUP_WINDOW_H
#define SIGNUP_WINDOW_H
#include <gtkmm-4.0/gtkmm.h>
#include "user_pick_window.h"
#include <string>
#include <fstream>
#include <iostream>
class MyWindow;

class SignUpWindow : public Gtk::Window {
    public:
        SignUpWindow(MyWindow *user_window);
        ~SignUpWindow(){}
        
    protected:
    
        MyWindow* user_window;
        Gtk::Label label;
        Gtk::Label login_label;
        Gtk::Entry login;
        Gtk::Label password_label;
        Gtk::Entry password;
        Gtk::Label confirm_label;
        Gtk::Entry confirm_password;
        Gtk::Button register_button;
        Gtk::Button exit_button;
        Gtk::Box box;
        Glib::RefPtr<Gtk::AlertDialog> username_error;
        void on_register_clicked();
        void on_exit_clicked();
        
};

int check_username(std::string username);
#endif