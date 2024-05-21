#include "../headers/sectionwindow.h"

SectionWindow::SectionWindow(const std::string& title, const std::vector<std::string>& sections) {
    set_title(title);
    set_default_size(300, 200);

    vbox.set_orientation(Gtk::Orientation::VERTICAL);
    vbox.set_spacing(10);
    vbox.set_margin(10);

    label.set_text("Разделы:");
    label.set_halign(Gtk::Align::CENTER);

    vbox.append(label);

    for (const auto& section : sections) {
        buttons.emplace_back(section);
        vbox.append(buttons.back());
    }

    set_child(vbox);
}
