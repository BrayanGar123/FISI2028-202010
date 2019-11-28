resultado.png : plot.py datos.dat
	python plot.py 

datos.dat : evolve.x
	./evolve.x 101 1001 > datos.dat

evolve.x : evolve.cpp
	c++ evolve.cpp -o evolve.x

clean:
	rm -f datos.dat resultado.png evolve.x