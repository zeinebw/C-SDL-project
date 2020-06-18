


all : prog clean
prog : main.o ajoutconditions.o
	@echo "building..."
	gcc main.c  ajoutconditions.c   -o prog  -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
clean:
	@echo "cleaning up..."
	rm *.o
