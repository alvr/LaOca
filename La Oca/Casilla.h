#include <iostream>

using namespace std;

class Casilla {
	
	private:
		int numero;
		int siguiente;
		int turnos;
		
	public:
		Casilla(int, int, int);
		
		void setNumero(int);
		void setSiguiente(int);
		void setTurnos(int);
		
		int getNumero();
		int getSiguiente();
		int getTurnos();
	
};
