#include "../headers/sign_up_window.h"

SignUpWindow::SignUpWindow(MyWindow* user_window_) : user_window(user_window_),
    label("Регистрация"),register_button("Зарегестрироваться"),
    exit_button("Выйти"),box(Gtk::Orientation::VERTICAL),login_label("Введите имя пользователя"),
    password_label("Введите пароль"), confirm_label("Подтвердите пароль")
{
    box.set_margin(5);
    box.set_spacing(10);

    set_child(box);
    set_default_size(600,400);

    box.set_halign(Gtk::Align::CENTER);
    


    box.append(label);
    box.append(login_label);
    box.append(login);
    box.append(password_label);
    box.append(password);
    box.append(confirm_label);
    box.append(confirm_password);
    box.append(register_button);
    box.append(exit_button);

    register_button.signal_clicked().connect(sigc::mem_fun(*this,&SignUpWindow::on_register_clicked));
    exit_button.signal_clicked().connect(sigc::mem_fun(*this,&SignUpWindow::on_exit_clicked));
}

void SignUpWindow::on_register_clicked(){
    
    std::string username = (login.get_text().empty() ? "0":login.get_text());
    std::string mpassword = (password.get_text().empty() ? "0":password.get_text());
    std::string mconfirm_password = (confirm_password.get_text().empty() ? "0":confirm_password.get_text());
    bool mistakes = false;
    if(int res = check_username(username)){
        if (!username_error){
            username_error = Gtk::AlertDialog::create();
        }
        else{
            username_error->set_buttons({});
            username_error->set_default_button(-1);
            username_error->set_cancel_button(-1);  
        }
        if (res == 1){
            username_error->set_message("Пожалуйста введите имя пользователя");    
            mistakes = true;
        }
        if (res == 2){
            username_error->set_message("Извините произошла непредвиденная ошибка, попробуйте еще раз");
            mistakes = true;
        }
        if(res == 3){
            username_error->set_message("Пользователь с таким именем уже существует");
            mistakes = true;
        }
        if(mpassword.size() < 5 || mpassword == "0"){
            username_error->set_message("Длина пароля должна быть болше 5 символов");
            mistakes = true;
        }
        if (mpassword != mconfirm_password){
            username_error->set_message("Пароли должны совпадать");
            mistakes = true;
        }
        username_error->set_cancel_button(1);
        username_error->show(*this);
 
    }
    if (mistakes == false){
        std::ofstream createfile;
        std::string filename = "../user_data/user_data_" + username + "_" + mpassword + ".txt";
        createfile.open(filename);
        createfile << "IncomeOperation\n" << "0 0 0\n" << "OutComeOperation\n" << "0 0 0\n" << "DebtOperation\n" << "0 0 0\n";
        createfile.close(); 
    }
    
}

void SignUpWindow::on_exit_clicked(){
    this->hide();
    delete this;
}

int check_username(std::string username){
    std::ifstream read_file;
    std::string line;
    std::ofstream write;
    if (username == "0"){
        return 1;
    }
    read_file.open("../user_data/usernames.txt");
    if (!read_file.is_open()){
        std::cout << "Cannot read file" << std::endl;
        return 2;
    }


    while(std::getline(read_file,line)){
       if (line == username ){
        return 3;
       }
        
    }
    read_file.close();
    write.open("../user_data/usernames.txt", std::ios::app);
    
    write << username << std::endl;
    write.close();
   
    return 0;

}