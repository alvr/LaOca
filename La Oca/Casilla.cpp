#include "Casilla.h"

Casilla::Casilla(int n, int s, int t) {
	numero = n;
	siguiente = s;
	turnos = t;
}

void Casilla::setNumero(int n) {
	numero = n;
}

void Casilla::setSiguiente(int s) {
	siguiente = s;
}

void Casilla::setTurnos(int t) {
	turnos = t;
}

int Casilla::getNumero() {
	return numero;
}

int Casilla::getSiguiente() {
	return siguiente;
}

int Casilla::getTurnos() {
	return turnos;
}
