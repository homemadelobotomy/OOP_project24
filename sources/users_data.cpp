
#include "../headers/users_data.h"


void write_users_db(std::string username, std::string password)
{ 
        std::string file_name = "../user_data/user_data_" + username + "_" + password + ".txt";
        
        std::ofstream user_out;
        user_out.open(file_name,std::ios::out);
        
        user_out.close();
    
}



char* read_users_db(std::string username, std::string password)
{
    std::string file_name = "../user_data/user_data_" + username + "_" + password + ".txt";   
    
    std::ifstream user_read_data;
    
    user_read_data.open(file_name);
    if (!user_read_data.is_open()){
        return (char*) "неверный логин или пароль";
    }
    
    char* data  = new char[128];
    user_read_data.getline(data,128);
    
    user_read_data.close();
    return data; 
}


UserWindow::UserWindow(std::string username, std::string password):
box(Gtk::Orientation::VERTICAL),
label1(read_users_db(username, password))
{
    
    set_default_size(600,600);

    box.set_halign(Gtk::Align::CENTER);
    box.set_spacing(10);
    box.set_margin(10);
    set_child(box);


    label1.set_margin_bottom(10);
    label1.set_halign(Gtk::Align::CENTER);
    box.append(label1);

}