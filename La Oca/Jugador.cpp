#include "Jugador.h"
#include <conio.h>
#include <time.h>
#include <cstdlib>

Jugador::Jugador(string n) {
	nombre = n;
	casilla = 0;
	turnos = 0;
}

void Jugador::setCasilla(int c) {
	casilla = c;
}

void Jugador::setTurnos(int t) {
	turnos = t;
}

string Jugador::getNombre() {
	return nombre;
}

int Jugador::getCasilla() {
	return casilla;
}

int Jugador::getTurnos() {
	return turnos;
}

int Jugador::tirarDados() {
	srand(time(NULL));
	return 1 + rand() % 6;
}

int Jugador::mover(int tirada) {
	if(casilla + tirada > 63) 
        casilla = 63 - (tirada - (63 - casilla)); 
    else
        casilla += tirada;
	return casilla;
}
