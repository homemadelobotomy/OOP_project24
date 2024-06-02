
#include "../headers/users_data.h"

UserData &UserData::getInstance()
{
    static UserData instance;
    return instance;
}
void UserData::setUsername(std::string& username){
    this->username = username;
}
void UserData::setPassword(std::string& password){
    this->password = password;
}