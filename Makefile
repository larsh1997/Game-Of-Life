SFML_PATH = C:\Users\Lars\Documents\libraries\SFML-3.0.0
SOURCES = main.cpp grid.cpp logic.cpp

all: 
	g++ $(SOURCES) -o main -I$(SFML_PATH)\include -L$(SFML_PATH)\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -DSFML_STATIC 

clean:
	rm -f main *.o