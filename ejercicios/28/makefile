friccion.png : sin_friccion.dat con_friccion.dat plot.py
	python plot.py

sin_friccion.dat : solve.x
	./solve.x

con_friccion.dat : solve.x
	./solve.x

solve.x: solve.cpp
	c++ solve.cpp -o solve.x

clean:
	rm -f *~ solve.x sin_friccion.dat con_friccion.dat friccion.png