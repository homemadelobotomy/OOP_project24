#include "../headers/operation.h"
#include <string>


Operation::Operation(const std::string title):
    box(Gtk::Orientation::VERTICAL),
    LabelTitle(title),
    box_for_oper1(Gtk::Orientation::HORIZONTAL),
    box_for_oper2(Gtk::Orientation::HORIZONTAL),
    box_for_oper3(Gtk::Orientation::HORIZONTAL),
    confirm_button("Добавить изменения")
    {
        set_title(title);
        set_default_size(500,500);

        box.set_margin (10);
        box.set_spacing(10);
        set_child(box);

        LabelTitle.set_margin_bottom(10);
        LabelTitle.set_halign(Gtk::Align::CENTER);
        box.append(LabelTitle);


        box_for_oper1.set_spacing(10);
        box_for_oper1.append(LabelCat1);
        box_for_oper1.append(EntryCat1);
        box.append(box_for_oper1);
        
        
        box_for_oper2.set_spacing(10);
        box_for_oper2.append(LabelCat2);
        box_for_oper2.append(EntryCat2);
        box.append(box_for_oper2);

        box_for_oper3.set_spacing(10);
        box_for_oper3.append(LabelCat3);
        box_for_oper3.append(EntryCat3);
        box.append(box_for_oper3);

        box.append(confirm_button);
        

    }