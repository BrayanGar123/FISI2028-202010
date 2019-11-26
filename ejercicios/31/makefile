resultado.png : plot.py datos.dat
	python plot.py 

datos.dat : evolve.x
	./evolve.x 10 > datos.dat
	./evolve.x 20 >> datos.dat
	./evolve.x 30 >> datos.dat
	./evolve.x 40 >> datos.dat
	./evolve.x 50 >> datos.dat
	./evolve.x 60 >> datos.dat
	./evolve.x 70 >> datos.dat
	./evolve.x 80 >> datos.dat
	./evolve.x 90 >> datos.dat
	./evolve.x 100 >> datos.dat

evolve.x : evolve.cpp
	c++ evolve.cpp -o evolve.x

clean:
	rm -f datos.dat resultado.png evolve.x