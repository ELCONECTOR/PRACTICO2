#include <iostream>   // Entrada/salida est�ndar
#include <limits>     // Necesario para el uso de std::numeric_limits

using namespace std;

// Declaraci�n de variables globales
int numero1, numero2;

// Declaraci�n de funciones
void mostrarMenuPrincipal();
void mostrarSubMenuOperacionesNumeros();
void realizarOperacionNumeros(int opcion);
void concatenarCadenas();
void limpiarPantalla();

int main() {
	char opcionPrincipal;
	
	do {
		// Llamar a la funci�n que muestra el men� principal
		mostrarMenuPrincipal();
		cin >> opcionPrincipal;
		
		switch (opcionPrincipal) {
		case '1':
			// Llamar a la funci�n que muestra el submen� de operaciones con n�meros
			mostrarSubMenuOperacionesNumeros();
			break;
		case '2':
			// Llamar a la funci�n que realiza la concatenaci�n de cadenas
			concatenarCadenas();
			break;
		case 's':
		case 'S':
			cout << "Saliendo del programa. Adi�s!" << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Int�ntelo de nuevo." << endl;
		}
		
		// Llamar a la funci�n para limpiar la pantalla y esperar la entrada del usuario
		limpiarPantalla();
		
	} while (opcionPrincipal != 's' && opcionPrincipal != 'S');
	
	return 0;
}

// Funci�n que muestra el men� principal
void mostrarMenuPrincipal() {
	cout << "\nMENU PRINCIPAL" << endl;
	cout << "(1) Operaciones con N�meros" << endl;
	cout << "(2) Concatenar 2 cadenas." << endl;
	cout << "(s/S) Salir" << endl;
	cout << "\nIngrese su opci�n: ";
}

// Funci�n que muestra el submen� de operaciones con n�meros
void mostrarSubMenuOperacionesNumeros() {
	char opcionSubmenu;
	
	do {
		cout << "\nSUBMENU OP NUMEROS" << endl;
		cout << "1) Suma de 2 n�meros." << endl;
		cout << "2) Divisi�n de 2 n�meros." << endl;
		cout << "(m/M) Volver al Menu principal." << endl;
		cout << "\nIngrese su opci�n: ";
		
		cin >> opcionSubmenu;
		
		switch (opcionSubmenu) {
		case '1':
		case '2':
			// Llamar a la funci�n que realiza la operaci�n seleccionada
			realizarOperacionNumeros(opcionSubmenu - '0');
			break;
		case 'm':
		case 'M':
			cout << "\nVolviendo al Menu principal." << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Int�ntelo de nuevo." << endl;
		}
		
		// Llamar a la funci�n para limpiar la pantalla y esperar la entrada del usuario
		limpiarPantalla();
		
	} while (opcionSubmenu != 'm' && opcionSubmenu != 'M');
}

// Funci�n que realiza operaciones con n�meros seg�n la opci�n seleccionada
void realizarOperacionNumeros(int opcion) {
	cout << "\nIngrese el primer n�mero: ";
	cin >> numero1;
	cout << "Ingrese el segundo n�mero: ";
	cin >> numero2;
	
	switch (opcion) {
	case 1:
		cout << "\nLa suma es: " << (numero1 + numero2) << endl;
		break;
	case 2:
		if (numero2 != 0) {
			cout << "\nLa divisi�n es: " << (static_cast<double>(numero1) / numero2) << endl;
		} else {
			cout << "No se puede dividir por cero." << endl;
		}
		break;
	default:
		cout << "Operaci�n no v�lida." << endl;
	}
}

// Funci�n que realiza la concatenaci�n de dos cadenas
void concatenarCadenas() {
	string cadena1, cadena2;
	
	cout << "\nIngrese la primera cadena: ";
	cin.ignore();  // Limpiar el buffer del teclado antes de getline
	getline(cin, cadena1);
	
	cout << "Ingrese la segunda cadena: ";
	getline(cin, cadena2);
	
	// Mostrar la concatenaci�n de las cadenas con un espacio en medio
	cout << "La concatenaci�n de las cadenas es: " << cadena1 + " " + cadena2 << endl;
}

// Funci�n que limpia la pantalla y espera la entrada del usuario
void limpiarPantalla() {
	// Limpiar la pantalla (puede no funcionar en todos los sistemas operativos)
	cout << "Presiona Enter para continuar...";
	cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); // Limpiar buffer de entrada
	cin.get();  // Esperar a que el usuario presione Enter
	system("clear || cls");
}
