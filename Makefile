main: main.cpp
	g++ *.cpp -o main

clean:
	rm -f main a.out *~ *# *.o *.out
