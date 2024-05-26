#include "../headers/PieChart.h"
#include <cmath>

PieChart::PieChart(){

    colors.push_back(Gdk::RGBA("green"));
    colors.push_back(Gdk::RGBA("blue"));
    colors.push_back(Gdk::RGBA("purple"));
    set_draw_func(sigc::mem_fun(*this, &PieChart::on_draw));

}

void PieChart::set_data(std::vector<double>& data){
    this_data = data;
    queue_draw();
}

void  PieChart::on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height){
    const int radius = std::min(height, width)/2;

    const double center_x = width / 2;
    const double center_y = height / 2;
    
    double sum = 0;
    for(double value : this->this_data){
        sum += value;
    }

    if (sum  == 0){return;}

    double start = 0;

    for (size_t i = 0; i < this_data.size(); i++){
        double angle = (this_data[i] / sum) * 2 * M_PI;

        cr->set_source_rgba(colors[i % colors.size()].get_red(),
                            colors[i % colors.size()].get_green(),
                            colors[i % colors.size()].get_blue(),
                            colors[i % colors.size()].get_alpha());
        cr->move_to(center_x,center_y);
        cr->arc(center_x,center_y,radius, start, start + angle);
        
        cr->close_path();
        cr->fill();
        cr->move_to(center_x + radius, center_y);


        start += angle;
    }

    return;
}