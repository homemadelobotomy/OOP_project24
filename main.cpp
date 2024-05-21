 #include <iostream>
#include <string>
#include "headers/user_pick_window.h"
#include <gtkmm-4.0/gtkmm.h>

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create("org.gtkmm.example");

    MyWindow window;

    return app->make_window_and_run<MyWindow>(argc, argv);
}
