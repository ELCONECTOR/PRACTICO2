#include <iostream>   // Entrada/salida estándar
#include <limits>     // Necesario para el uso de std::numeric_limits

using namespace std;

// Declaración de variables globales
int numero1, numero2;

// Declaración de funciones
void mostrarMenuPrincipal();
void mostrarSubMenuOperacionesNumeros();
void realizarOperacionNumeros(int opcion);
void concatenarCadenas();
void limpiarPantalla();

int main() {
	char opcionPrincipal;
	
	do {
		// Llamar a la función que muestra el menú principal
		mostrarMenuPrincipal();
		cin >> opcionPrincipal;
		
		switch (opcionPrincipal) {
		case '1':
			// Llamar a la función que muestra el submenú de operaciones con números
			mostrarSubMenuOperacionesNumeros();
			break;
		case '2':
			// Llamar a la función que realiza la concatenación de cadenas
			concatenarCadenas();
			break;
		case 's':
		case 'S':
			cout << "Saliendo del programa. Adiós!" << endl;
			break;
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
		
		// Llamar a la función para limpiar la pantalla y esperar la entrada del usuario
		limpiarPantalla();
		
	} while (opcionPrincipal != 's' && opcionPrincipal != 'S');
	
	return 0;
}

// Función que muestra el menú principal
void mostrarMenuPrincipal() {
	cout << "\nMENU PRINCIPAL" << endl;
	cout << "(1) Operaciones con Números" << endl;
	cout << "(2) Concatenar 2 cadenas." << endl;
	cout << "(s/S) Salir" << endl;
	cout << "\nIngrese su opción: ";
}

// Función que muestra el submenú de operaciones con números
void mostrarSubMenuOperacionesNumeros() {
	char opcionSubmenu;
	
	do {
		cout << "\nSUBMENU OP NUMEROS" << endl;
		cout << "1) Suma de 2 números." << endl;
		cout << "2) División de 2 números." << endl;
		cout << "(m/M) Volver al Menu principal." << endl;
		cout << "\nIngrese su opción: ";
		
		cin >> opcionSubmenu;
		
		switch (opcionSubmenu) {
		case '1':
		case '2':
			// Llamar a la función que realiza la operación seleccionada
			realizarOperacionNumeros(opcionSubmenu - '0');
			break;
		case 'm':
		case 'M':
			cout << "\nVolviendo al Menu principal." << endl;
			break;
		default:
			cout << "Opción no válida. Inténtelo de nuevo." << endl;
		}
		
		// Llamar a la función para limpiar la pantalla y esperar la entrada del usuario
		limpiarPantalla();
		
	} while (opcionSubmenu != 'm' && opcionSubmenu != 'M');
}

// Función que realiza operaciones con números según la opción seleccionada
void realizarOperacionNumeros(int opcion) {
	cout << "\nIngrese el primer número: ";
	cin >> numero1;
	cout << "Ingrese el segundo número: ";
	cin >> numero2;
	
	switch (opcion) {
	case 1:
		cout << "\nLa suma es: " << (numero1 + numero2) << endl;
		break;
	case 2:
		if (numero2 != 0) {
			cout << "\nLa división es: " << (static_cast<double>(numero1) / numero2) << endl;
		} else {
			cout << "No se puede dividir por cero." << endl;
		}
		break;
	default:
		cout << "Operación no válida." << endl;
	}
}

// Función que realiza la concatenación de dos cadenas
void concatenarCadenas() {
	string cadena1, cadena2;
	
	cout << "\nIngrese la primera cadena: ";
	cin.ignore();  // Limpiar el buffer del teclado antes de getline
	getline(cin, cadena1);
	
	cout << "Ingrese la segunda cadena: ";
	getline(cin, cadena2);
	
	// Mostrar la concatenación de las cadenas con un espacio en medio
	cout << "La concatenación de las cadenas es: " << cadena1 + " " + cadena2 << endl;
}

// Función que limpia la pantalla y espera la entrada del usuario
void limpiarPantalla() {
	// Limpiar la pantalla (puede no funcionar en todos los sistemas operativos)
	cout << "Presiona Enter para continuar...";
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada
	cin.get();  // Esperar a que el usuario presione Enter
	system("clear || cls");
}
