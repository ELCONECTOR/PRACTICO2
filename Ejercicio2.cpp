#include <iostream>   // Entrada/salida est�ndar
#include <cstdlib>    // Funciones generales de C, incluida rand()
#include <ctime>      // Para utilizar la funci�n time() y obtener la semilla para rand()
#include <cmath>      // Funciones matem�ticas est�ndar sqrt() en este caso
using namespace std;
// Declaraci�n de funciones
void generarNumeroEntre0y500(int &numeroAleatorio);
void generarNumeroReal(double &numeroRealAleatorio);
bool esPrimo(int numero);
void generarNumerosPrimosAleatorios(int N);

int main() {
	// Inicializar la semilla para los n�meros aleatorios
	srand(static_cast<unsigned int>(time(0)));
	
	char opcion;
	
	do {
		// Men� principal
		cout << "\nBienvenido al programa" <<endl;
		cout << "(1) Genere al azar n�mero entre 0-500" <<endl;
		cout << "(2) Genere un n�mero aleatorio real" <<endl;
		cout << "(3) Genere N n�meros primos aleatorios" <<endl;
		cout << "(s/S) Salir" <<endl;
		cout << "\nSeleccione una opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
		{
			// Generar y mostrar n�mero aleatorio entre 0 y 500
			int numeroAleatorio;
			generarNumeroEntre0y500(numeroAleatorio);
			cout << "\nN�mero aleatorio entre 0 y 500: " << numeroAleatorio <<endl;
		}
		break;
		case '2':
		{
			// Generar y mostrar n�mero aleatorio real
			double numeroRealAleatorio;
			generarNumeroReal(numeroRealAleatorio);
			cout << "\nN�mero real aleatorio: " << numeroRealAleatorio <<endl;
		}
		break;
		case '3':
		{
			// Generar y mostrar N n�meros primos aleatorios
			int N;
			cout << "\nIngrese la cantidad de n�meros primos aleatorios a generar: ";
			cin >> N;
			generarNumerosPrimosAleatorios(N);
		}
		break;
		case 's':
		case 'S':
			cout << "Saliendo del programa. �Hasta luego!" <<endl;
			break;
		default:
			cout << "Opci�n no v�lida. Int�ntelo de nuevo." <<endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

// Funci�n para generar un n�mero aleatorio entre 0 y 500
void generarNumeroEntre0y500(int &numeroAleatorio) {
	numeroAleatorio = rand() % 501;
}

// Funci�n para generar un n�mero aleatorio real
void generarNumeroReal(double &numeroRealAleatorio) {
	numeroRealAleatorio = static_cast<double>(rand()) / RAND_MAX;
}

// Funci�n para verificar si un n�mero es primo
bool esPrimo(int numero) {
	if (numero < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(numero); ++i) {
		if (numero % i == 0) {
			return false;
		}
	}
	return true;
}

// Funci�n para generar N n�meros primos aleatorios
void generarNumerosPrimosAleatorios(int N) {
	int contador = 0;
	
	while (contador < N) {
		// Generar un n�mero aleatorio entre 0 y 999
		int numeroAleatorio = rand() % 1000;
		
		// Verificar si es primo y mostrarlo
		if (esPrimo(numeroAleatorio)) {
			cout << numeroAleatorio << " ";
			++contador;
		}
	}
	
	cout <<endl;
}
