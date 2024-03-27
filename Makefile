LIBS =-lsfml-graphics -lsfml-window -lsfml-system -lsfml-network
CXX = g++

DIR_OBJ = obj/



	 

%.o:%.cpp
	
	$(CXX) -c $<  -o $(DIR_OBJ)$@ -I include
	$(CXX) -c proj/proj.cpp -o $(DIR_OBJ)proj.o
	
	
project:*.o
	$(CXX) -o project   $(DIR_OBJ)*.o $(LIBS) -L /lib
clean:
	@echo "Removing object files and executable..."
	rm project $(DIR_OBJ)*.o

