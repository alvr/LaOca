#include <iostream>
#include "Jugador.h"
#include "Casilla.h"

using namespace std;

class Tablero {
	
	private:
		Jugador *j[4];
		Casilla *c[63];
		int numJugadores;
		int turnoJugador;
		void inicializarCasillas();
		int siguienteJugador();
		
	public:
		Tablero(int n);
		void jugar();	
	
};
