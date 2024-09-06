build-and-run:
	g++ -I include/ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o build/VisSort
	./build/VisSort