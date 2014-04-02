#include <iostream>
#include <string>

using namespace std;

class Jugador {
	
	private:
		string nombre;
		int casilla;
		int turnos;		
		
	public:
		Jugador(string);

		int tirarDados();

		void setCasilla(int);
		void setTurnos(int);
		
		string getNombre();
		int getCasilla();
		int getTurnos();
	
		int mover(int);
	
};
