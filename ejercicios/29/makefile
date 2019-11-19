all: evolve_A.png evolve_B.png evolve_C.png

evolve_A.png: evolve_30_450.dat evolve_31_450.dat evolve_29_450.dat evolve_30_440.dat plot.py
	python plot.py

evolve_B.png: evolve_30_450.dat evolve_31_450.dat evolve_29_450.dat evolve_30_440.dat plot.py
	python plot.py

evolve_C.png: evolve_30_450.dat evolve_31_450.dat evolve_29_450.dat evolve_30_440.dat plot.py
	python plot.py

evolve_30_450.dat : evolve.x
	./evolve.x 30 450 > evolve_30_450.dat

evolve_31_450.dat : evolve.x
	./evolve.x 31 450 > evolve_31_450.dat

evolve_29_450.dat : evolve.x
	./evolve.x 29 450 > evolve_29_450.dat

evolve_30_440.dat : evolve.x
	./evolve.x 30 440 > evolve_30_440.dat

evolve.x : evolve.cpp
	c++ evolve.cpp -o evolve.x

clean:
	rm evolve.x *.dat