all:
	LD_LIBRARY_PATH=$$LD_LIBRARY_PATH:$$PWD
	echo $$LD_LIBRARY_PATH
	g++ -c -fPIC fluxoImpl.cpp -o fluxoImpl.o  
	g++ -c -fPIC sistemaImpl.cpp -o sistemaImpl.o  
	g++ -c -fPIC modeloImpl.cpp -o modeloImpl.o  
	gcc -shared -o libmyVensim.so modeloImpl.o sistemaImpl.o fluxoImpl.o
clean:
	rm *.o

run:
	
	
