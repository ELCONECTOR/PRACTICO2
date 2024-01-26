#include <iostream>   // Entrada/salida estándar
#include <cstdlib>    // Funciones generales de C, incluida rand()
#include <ctime>      // Para utilizar la función time() y obtener la semilla para rand()
#include <cmath>      // Funciones matemáticas estándar sqrt() en este caso
using namespace std;
// Declaración de funciones
void generarNumeroEntre0y500(int &numeroAleatorio);
void generarNumeroReal(double &numeroRealAleatorio);
bool esPrimo(int numero);
void generarNumerosPrimosAleatorios(int N);

int main() {
	// Inicializar la semilla para los números aleatorios
	srand(static_cast<unsigned int>(time(0)));
	
	char opcion;
	
	do {
		// Menú principal
		cout << "\nBienvenido al programa" <<endl;
		cout << "(1) Genere al azar número entre 0-500" <<endl;
		cout << "(2) Genere un número aleatorio real" <<endl;
		cout << "(3) Genere N números primos aleatorios" <<endl;
		cout << "(s/S) Salir" <<endl;
		cout << "\nSeleccione una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1':
		{
			// Generar y mostrar número aleatorio entre 0 y 500
			int numeroAleatorio;
			generarNumeroEntre0y500(numeroAleatorio);
			cout << "\nNúmero aleatorio entre 0 y 500: " << numeroAleatorio <<endl;
		}
		break;
		case '2':
		{
			// Generar y mostrar número aleatorio real
			double numeroRealAleatorio;
			generarNumeroReal(numeroRealAleatorio);
			cout << "\nNúmero real aleatorio: " << numeroRealAleatorio <<endl;
		}
		break;
		case '3':
		{
			// Generar y mostrar N números primos aleatorios
			int N;
			cout << "\nIngrese la cantidad de números primos aleatorios a generar: ";
			cin >> N;
			generarNumerosPrimosAleatorios(N);
		}
		break;
		case 's':
		case 'S':
			cout << "Saliendo del programa. ¡Hasta luego!" <<endl;
			break;
		default:
			cout << "Opción no válida. Inténtelo de nuevo." <<endl;
		}
		
	} while (opcion != 's' && opcion != 'S');
	
	return 0;
}

// Función para generar un número aleatorio entre 0 y 500
void generarNumeroEntre0y500(int &numeroAleatorio) {
	numeroAleatorio = rand() % 501;
}

// Función para generar un número aleatorio real
void generarNumeroReal(double &numeroRealAleatorio) {
	numeroRealAleatorio = static_cast<double>(rand()) / RAND_MAX;
}

// Función para verificar si un número es primo
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

// Función para generar N números primos aleatorios
void generarNumerosPrimosAleatorios(int N) {
	int contador = 0;
	
	while (contador < N) {
		// Generar un número aleatorio entre 0 y 999
		int numeroAleatorio = rand() % 1000;
		
		// Verificar si es primo y mostrarlo
		if (esPrimo(numeroAleatorio)) {
			cout << numeroAleatorio << " ";
			++contador;
		}
	}
	
	cout <<endl;
}
