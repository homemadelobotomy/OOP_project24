#ifndef PIECHART_H
#define PIECHART_H

#include <gtkmm-4.0/gtkmm.h>
#include <vector>
#include <map>

class PieChart : public Gtk::DrawingArea {
    public:
        PieChart();
        virtual ~PieChart(){}

        void set_data(std::map<std::string, double>& data);
        void re_draw(){queue_draw();}

        protected:
            void  on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) ;
        
        private:
            std::map< std::string, double> this_data;
            std::vector<Gdk::RGBA> colors;
};

#endif