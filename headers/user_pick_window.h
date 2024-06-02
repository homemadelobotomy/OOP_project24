#ifndef USER_PICK_WINDOW_H
#define USER_PICK_WINDOW_H

#include <gtkmm-4.0/gtkmm.h>
#include "users_data.h"
#include <memory>
#include "mainwindow.h"
#include "sign_up_window.h"


class MainWindow;


class MyWindow : public Gtk::Window {

    
 public:
        void show_user_window();
        MyWindow();

    private:
        Gtk::Box box;
        Gtk::Entry user_name_form;
        Gtk::Entry password_form;
        Gtk::Label user_name_label;
        Gtk::Label password_label;
        Gtk::Button login_button;
        Gtk::Button sign_up_button;
        void on_login_button_clicked();
        
        void on_sign_up_clicked();
        void on_user_window_hide();
        
        Glib::RefPtr<Gtk::AlertDialog> user_error;
        
        std::unique_ptr<MainWindow> user_window;
};


#endif