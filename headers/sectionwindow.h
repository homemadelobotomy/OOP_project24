#ifndef SECTIONWINDOW_H
#define SECTIONWINDOW_H

#include <gtkmm-4.0/gtkmm.h>
#include <vector>
#include <string>

class SectionWindow : public Gtk::Window {
public:
    SectionWindow(const std::string& title, const std::vector<std::string>& sections);
private:
    Gtk::Box vbox;
    Gtk::Label label;
    std::vector<Gtk::Button> buttons;
};

#endif 

