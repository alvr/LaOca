#include "Tablero.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

Tablero::Tablero(int n) {	
	string nombre;
	turnoJugador = -1;
	numJugadores = n;
	for (int i = 0; i < n; i++) {
		cout << "Introduce el nombre del jugador " << i + 1 << ": ";
		cin >> nombre;
		j[i] = new Jugador(nombre);
	}	
	inicializarCasillas();
}

void Tablero::inicializarCasillas() {
	ifstream archivo("casillas.txt");
	int n, s, t, i = 0;
	if (!archivo) {
		cout << "Error al abrir el fichero \"casillas.txt\"." << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}
	else {
		while (!archivo.eof()) {
			archivo >> n >> s >> t;
			c[i] = new Casilla(n, s, t);
			i++;
		}
		archivo.close();
	}
}

void Tablero::jugar() {
	int turno = 0, dados, casilla, cTurnos, jTurnos;
	bool fin = false;
	string nom;
	do {		

		jTurnos = j[turno]->getTurnos();
			
		if(jTurnos == 0) {
			nom = j[turno]->getNombre();
			dados = j[turno]->tirarDados();
			casilla = j[turno]->mover(dados);				
	
			cout << "Turno de " << nom << ": Tirada: " << dados << "; Casilla: " << casilla << "." << endl;
			if (c[casilla - 1]->getSiguiente() != casilla + 1)
				j[turno]->setCasilla(c[casilla - 1]->getSiguiente());
				
			casilla = j[turno]->getCasilla();
			cTurnos = c[casilla - 1]->getTurnos();
			j[turno]->setTurnos(cTurnos);
			if(cTurnos == 1) {
				jTurnos = j[turno]->getTurnos();
				j[turno]->setTurnos(jTurnos);
				turno = siguienteJugador();
			}
				
		} else {
			jTurnos = j[turno]->getTurnos();
			if(jTurnos > 1)
				cout << "Turno de " << nom << ": Debes esperar " << jTurnos << " turnos para tirar." << endl;
			j[turno]->setTurnos(jTurnos - 1);
			turno = siguienteJugador();
		}

		if(casilla == 63)
			fin = true;

		cin.sync();
		cin.ignore();
	} while (!fin);
	cout << "ENHORABUENA " << nom << ", HAS GANADO." << endl;
}

int Tablero::siguienteJugador() {
	turnoJugador++;
	return turnoJugador % numJugadores;
}
