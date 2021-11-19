CC=g++
exe=ejemplo_prueba
lib=sim_futbol
libpy=_$(lib).so
wrapper=$(lib)_wrap
flags=-Werror -Wall -Wundef -std=c++11

$(libpy): simulacion.o partido.o equipo.o $(wrapper).o
	$(CC) $(flags) -shared simulacion.o partido.o equipo.o $(lib)_wrap.o -o $(libpy)

$(exe):	main.o simulacion.o partido.o equipo.o
	$(CC) $(flags) -o $@ $^

$(wrapper).o: $(wrapper).cxx
	$(CC) $(flags) -fPIC -c $< -I/usr/include/python3.8/

$(wrapper).cxx: $(lib).i
	swig -python -c++ $<

main.o: main.cpp simulacion.h partido.h equipo.h
	$(CC) $(flags) -o $@ $< -c

simulacion.o: simulacion.cpp simulacion.h partido.h equipo.h
	$(CC) $(flags) -o $@ $< -c -fPIC

partido.o: partido.cpp partido.h
	$(CC) $(flags) -o $@ $< -c -fPIC

equipo.o: equipo.cpp equipo.h
	$(CC) $(flags) -o $@ $< -c -fPIC
clean:
	rm -f *.o $(exe) *.so *.cxx $(lib).py
	rm -f -r __pycache__/
