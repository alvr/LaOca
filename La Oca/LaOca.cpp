#include "Tablero.h"
#include <cstdlib>

using namespace std;

int main() {
	locale::global(locale("spanish"));
	int numJ;
	cout << "N�mero de jugadores: ";
	cin >> numJ;
	if(numJ > 1 && numJ < 5) {
		Tablero t(numJ);
		t.jugar();
	} else
		cout << "El n�mero de jugadores debe de ser de 2 a 4" << endl;
	system("pause");
	return 0;
}
