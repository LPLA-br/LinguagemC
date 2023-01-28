#"make" no dirétorio que contém makefile
all: func.o #main.c depende func.o para compilar.
	gcc main.c -o main func.o

func.o: func.h
	gcc -c func.c -o func.o

clean:
	rm *.o main
#"make clean"
