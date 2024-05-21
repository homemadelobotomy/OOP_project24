#ifndef USERS_DATA_H
#define USERS_DATA_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <gtkmm-4.0/gtkmm.h>


void write_users_db(unsigned number_of_users);

char* read_users_db(int user_id);

class UserWindow: public Gtk::Window{
  public:
    UserWindow(std::string username, std::string password);
  private:
    Gtk::Label label1;
    Gtk::Box box;
};

  





#endif
