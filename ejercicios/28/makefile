solve.png : solve.dat plot.py
	python plot.py

solve.dat : solve.x
	./solve.x

solve.x: solve.cpp
	g++ solve.cpp -o solve.x