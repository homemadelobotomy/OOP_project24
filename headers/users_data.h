#ifndef USERS_DATA_H
#define USERS_DATA_H

#include <iostream>
#include <string>

class UserData{
    public:
      static UserData& getInstance();
      void setUsername(std::string& username);
      void setPassword(std::string& password);
      std::string getUsername(){return username;}
      std::string getPassword(){return password;}

    private:
      UserData(){}
      std::string username;
      std::string password;
};





#endif
