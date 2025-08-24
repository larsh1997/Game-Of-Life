all: compile link

compile: 
	g++ -c main.cpp -IC:\Users\Lars\Documents\libraries\SFML-3.0.0\include -DSFML_STATIC

link:
	g++ main.o -o main -LC:\Users\Lars\Documents\libraries\SFML-3.0.0\lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lfreetype -lwinmm -lgdi32 -mwindows 

clean:
	rm -f main *.o