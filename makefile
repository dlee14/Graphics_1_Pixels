all: pixels.c
	gcc pixels.c
clean:
	rm *.o
run: all
	./a.out
	convert pic.ppm pic.png
