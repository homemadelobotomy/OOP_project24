#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <time.h>
#include "proj/proj.h"


int main(){
    srand(static_cast<unsigned int> (time(0)));
    proj proj;
    
    while(proj.running()){
        proj.update();
        
        proj.render();
    }
    return 0;
}