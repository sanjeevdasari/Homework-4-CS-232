main: *.cpp
	g++ *.cpp -o csshell

clean:
	rm -f main a.out *~ *# *.o *.out
