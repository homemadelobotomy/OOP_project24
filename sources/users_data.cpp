
#include "../headers/users_data.h"


void write_users_db(unsigned number_of_users)
{ 
    
    for(size_t i = 0; i < number_of_users; i++)
    {
        std::string file_name = "../user_data/user_data_" + std::to_string(i+1) + ".txt";
        
        std::ofstream user_out;
        user_out.open(file_name,std::ios::out);
        
        user_out.close();
    }
}



char* read_users_db(int user_id)
{
    std::string file_name = "../user_data/user_data_" + std::to_string(user_id) + ".txt";   
    
    std::ifstream user_read_data;
    
    user_read_data.open(file_name);
    
    char* data  = new char[128];
    user_read_data.getline(data,128);
    
    user_read_data.close();
    return data; 
}


UserWindow::UserWindow(const int user_id):
box(Gtk::Orientation::VERTICAL),
label1(read_users_db(user_id))
{
    
    set_title(std::to_string(user_id));
    set_default_size(600,600);


    box.set_spacing(10);
    box.set_margin(10);
    set_child(box);


    label1.set_margin_bottom(10);
    label1.set_halign(Gtk::Align::CENTER);
    box.append(label1);

}