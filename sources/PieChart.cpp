#include "../headers/PieChart.h"
#include <cmath>
#include<iostream>

PieChart::PieChart(){

    colors.push_back(Gdk::RGBA("green"));
    colors.push_back(Gdk::RGBA("blue"));
    colors.push_back(Gdk::RGBA("purple"));
    set_draw_func(sigc::mem_fun(*this, &PieChart::on_draw));

}

void PieChart::set_data(std::map< std::string, double >& data){
    this_data = data;
    queue_draw();
    
}

void  PieChart::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){
    const int radius = std::min(height, width)/2;

    const double center_x = width / 2;
    const double center_y = height / 2;
    
    double sum = 0;
    std::map<std::string,double>::iterator iter;
    for (const auto& [_, value] : this_data) {
            sum += value;
            std::cout << value <<  " " << _<< std::endl;
        }
    
    if (sum  == 0){return;}

    double start = 0;
    size_t i = 0;
   for (const auto& [label, value] : this_data){
        double angle = (value / sum) * 2 * M_PI;
        
        cr->set_source_rgba(colors[i % colors.size()].get_red(),
                            colors[i % colors.size()].get_green(),
                            colors[i % colors.size()].get_blue(),
                            colors[i % colors.size()].get_alpha());
        cr->move_to(center_x,center_y);
        cr->arc(center_x,center_y,radius, start, start + angle);
        
        cr->close_path();
        cr->fill();
        cr->move_to(center_x + radius, center_y);

        
        double labelAngle = start + angle / 2;
        double labelX = center_x + (radius / 2) * cos(labelAngle);
        double labelY = center_y + (radius / 2) * sin(labelAngle);

        cr->save(); 
        cr->translate(labelX, labelY);
        cr->rotate(labelAngle);       
     
        if (labelAngle > M_PI_2 && labelAngle < 3*M_PI_2) { 
            cr->rotate(M_PI);
        }

        // Устанавливаем черный цвет текста
        cr->set_source_rgb(0.0, 0.0, 0.0);

        // Рисуем подпись
        
        auto layout = create_pango_layout(label);
        int textWidth, textHeight;
        layout->get_pixel_size(textWidth, textHeight);
        cr->move_to(-textWidth / 2, -textHeight / 2); // Рисуем текст от нового начала координат
        layout->show_in_cairo_context(cr);

    cr->restore(); // Восстанавливаем состояние контекста


        start += angle;
        i++;
    }

    return;
}