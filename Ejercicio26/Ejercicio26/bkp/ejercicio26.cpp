//Grupo TAIS17, Samuel Rodriguez y Jorge Rueda

/*
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Restaurante {
	int InflujoIzq;
	int influjoDerecha;
	Restaurante(int i, int d) : InflujoIzq(i), influjoDerecha(d) {}
	bool operator < (const Restaurante& str) const
	{
		if (InflujoIzq == str.InflujoIzq) {
			return influjoDerecha > str.influjoDerecha;
		}else return (InflujoIzq < str.InflujoIzq);
	}
};

	void leerRestaurantes(int numE,int longitud,vector<Restaurante>& restaurantes) {
	int posicion, flujo,infI,infD;
	//vector<Restaurante> restaurantes;
	for (int j = 0; j < numE; j++) {
		cin >> posicion;
		cin >> flujo;
		infI = posicion - flujo;
		infD = posicion + flujo;
		if (infI < 0) {
			infI = 0;
		}
		if (infD > longitud) {
			infD = longitud;
		}
		restaurantes.push_back(Restaurante(infI,infD));
	}
	std::sort(restaurantes.begin(), restaurantes.end());
	//return restaurantes;

}

bool resuelveCaso() {
	int numE, longitud;
	int anterior=0;
	int infDerecho;
	int contador = 0;

	cin >> longitud;
	if (!std::cin) {
		return false;
	}
	else {
		cin >> numE;
		vector<Restaurante> restaurantes;
		leerRestaurantes(numE,longitud,restaurantes);
		if (restaurantes[0].InflujoIzq > 0) {
			cout << -1 << endl;
			return true;
		}
		else {
			infDerecho = restaurantes[0].influjoDerecha;
			for (int i = 1; i < numE; i++) {
				if (restaurantes[i].InflujoIzq > infDerecho) {
					cout << -1 << endl;
					return true;
				}
				else if (restaurantes[i].InflujoIzq <= anterior) {
					contador++;

				}
				anterior = infDerecho;
				if (anterior <= restaurantes[i].influjoDerecha) {
				infDerecho = restaurantes[i].influjoDerecha;
			}
			}
			if (infDerecho < longitud) {
				cout << -1 << endl;
				return true;
			}
		}

		cout << contador << endl;
		return true;
	}




}




int main() {

	// ajuste para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
	std::ifstream in("casos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
	while (resuelveCaso());

	// restablecimiento de cin
#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("pause");
#endif

	return 0;
}