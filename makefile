.SUFFIXES: .o

vpath %.h include
vpath %.c src
vpath %.so lib
vpath %.a lib

%.o: %.c
	gcc -c $<

code2: code2.c volume.o area.a
	gcc -o code2 $^ -I./include
	export LD_LIBRARY_PATH=$(LD_LIBRARY_PATH):./

area.o: area.c
area.a: area.o cubeArea.o
	ar -rs $@ $^
cubeArea.o: cubeArea.c
volume.o: volume.c
	gcc -fPIC -c $<
volume.so: volume.o
	gcc -shared -o $@ $^
clean:
	rm -f code2 *.o *.a *.so
