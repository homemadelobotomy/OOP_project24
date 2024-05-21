#include <gtkmm-4.0/gtkmm.h>
#include "users_data.h"
#include <memory>
#include "mainwindow.h"

class MyWindow : public Gtk::Window {

    
 public:
        void show_user_window();
        std::string GetUsername(){return username;}
        std::string GetPassword(){return password;}
        
        MyWindow();

    private:
        Gtk::Box box;
        Gtk::Entry user_name_form;
        Gtk::Entry password_form;
        Gtk::Label user_name_label;
        Gtk::Label password_label;
        Gtk::Button login_button;
        std::string username;
        std::string password;
        void on_login_button_clicked();

        void on_user_window_hide();
        
        std::unique_ptr<MainWindow> user_window;
};


