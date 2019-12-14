all: sigma.png manchas.png resultado.png

sigma.png : sigma.py
	python sigma.py

manchas.png : manchas.py
	python manchas.py

resultado.png : datos.txt plot.py
	python plot.py

datos.txt : solve.x
	./solve.x > datos.txt

solve.x : solve.cpp
	c++ solve.cpp -o solve.x

clean:
	rm -f sigma.png manchas.png resultado.png datos.txt *~ solve.x