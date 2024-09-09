build-and-run:
	g++ -I include/ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o build/VisSort
	./build/VisSort

build:
	g++ -I include/ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o build/VisSort

build_linux_bin:

	g++ -I include/ src/*.cpp -lsfml-graphics -lsfml-window -lsfml-system -o /usr/bin/vis-sort