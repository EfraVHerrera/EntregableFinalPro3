#include <iostream>
#include <string>
#include <cctype> // Para usar la función tolower

using namespace std;

class Persona {
protected:
	int nID;
	string sNombre;
	string sApellido;
	string sEmail;
	
public:
	Persona(int id, string nombre, string apellido, string email)
		: nID(id), sNombre(nombre), sApellido(apellido), sEmail(email) {}
	
	int obtenerID() const { return nID; }
	string obtenerNombre() const { return sNombre; }
	string obtenerApellido() const { return sApellido; }
	string obtenerEmail() const { return sEmail; }
};

// Clase Usuario hereda de Persona
class Usuario : public Persona {
private:
	string sFechaRegistro;
	
public:
	Usuario(int id, string nombre, string apellido, string email, string fechaRegistro)
		: Persona(id, nombre, apellido, email), sFechaRegistro(fechaRegistro) {}
	
	string obtenerFechaRegistro() const { return sFechaRegistro; }
};

// Clase Bibliotecario hereda de Persona
class Bibliotecario : public Persona {
private:
	string sCargo;
	
public:
	Bibliotecario(int id, string nombre, string apellido, string email, string cargo)
		: Persona(id, nombre, apellido, email), sCargo(cargo) {}
	
	string obtenerCargo() const { return sCargo; }
};

// Función para convertir la entrada del usuario a minúsculas
char toLowerCase(char c) {
	return tolower(static_cast<unsigned char>(c)); // Conversión segura a minúsculas
}

// Gestora de Usuarios
class GestoraUsuarios {
private:
	static const int MAX_USUARIOS = 10;
	Usuario usuarios[MAX_USUARIOS];
	int numUsuarios;
	
public:
	GestoraUsuarios() : numUsuarios(0) {}
	
	void agregarUsuario(const Usuario& usuario) {
		if (numUsuarios < MAX_USUARIOS) {
			usuarios[numUsuarios++] = usuario;
		} else {
			cout << "No se puede agregar más usuarios. La capacidad máxima ha sido alcanzada." << endl;
		}
	}
	
	void mostrarUsuarios() {
		cout << "--- Listado de Usuarios ---\n";
		for (int i = 0; i < numUsuarios; ++i) {
			cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
		}
		cout << endl;
	}
};

// Gestora de Bibliotecarios
class GestoraBibliotecarios {
private:
	static const int MAX_BIBLIOTECARIOS = 10;
	Bibliotecario bibliotecarios[MAX_BIBLIOTECARIOS];
	int numBibliotecarios;
	
public:
	GestoraBibliotecarios() : numBibliotecarios(0) {}
	
	void agregarBibliotecario(const Bibliotecario& bibliotecario) {
		if (numBibliotecarios < MAX_BIBLIOTECARIOS) {
			bibliotecarios[numBibliotecarios++] = bibliotecario;
		} else {
			cout << "No se puede agregar más bibliotecarios. La capacidad máxima ha sido alcanzada." << endl;
		}
	}
	
	void mostrarBibliotecarios() {
		cout << "--- Listado de Bibliotecarios ---\n";
		for (int i = 0; i < numBibliotecarios; ++i) {
			cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
		}
		cout << endl;
	}
};

// Función para el menú principal
void menuPrincipal(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios) {
	char opcion;
	do {
		cout << "\n--- Menú Principal ---\n";
		cout << "1) Agregar Usuario\n";
		cout << "2) Agregar Bibliotecario\n";
		cout << "3) Mostrar Usuarios\n";
		cout << "4) Mostrar Bibliotecarios\n";
		cout << "0) Salir\n";
		cout << "Seleccione una opción: ";
		cin >> opcion;
		
		// Convertimos la opción ingresada a minúsculas
		opcion = toLowerCase(opcion);
		
		switch (opcion) {
		case '1':
			// Agregar Usuario
			int id;
			string nombre, apellido, email, fechaRegistro;
			cout << "Ingrese el ID del usuario: ";
			cin >> id;
			cout << "Ingrese el nombre del usuario: ";
			cin >> nombre;
			cout << "Ingrese el apellido del usuario: ";
			cin >> apellido;
			cout << "Ingrese el email del usuario: ";
			cin >> email;
			cout << "Ingrese la fecha de registro del usuario: ";
			cin >> fechaRegistro;
			gestoraUsuarios.agregarUsuario(Usuario(id, nombre, apellido, email, fechaRegistro));
			break;
		case '2':
			// Agregar Bibliotecario
			int idB;
			string nombreB, apellidoB, emailB, cargo;
			cout << "Ingrese el ID del bibliotecario: ";
			cin >> idB;
			cout << "Ingrese el nombre del bibliotecario: ";
			cin >> nombreB;
			cout << "Ingrese el apellido del bibliotecario: ";
			cin >> apellidoB;
			cout << "Ingrese el email del bibliotecario: ";
			cin >> emailB;
			cout << "Ingrese el cargo del bibliotecario: ";
			cin >> cargo;
			gestoraBibliotecarios.agregarBibliotecario(Bibliotecario(idB, nombreB, apellidoB, emailB, cargo));
			break;
		case '3':
			// Mostrar Usuarios
			gestoraUsuarios.mostrarUsuarios();
			break;
		case '4':
			// Mostrar Bibliotecarios
			gestoraBibliotecarios.mostrarBibliotecarios();
			break;
		case '0':
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
		}
	} while (opcion != '0');
}

int main() {
	GestoraUsuarios gestoraUsuarios;
	GestoraBibliotecarios gestoraBibliotecarios;
	
	// Se inicia el menú principal
	menuPrincipal(gestoraUsuarios, gestoraBibliotecarios);
	
	return 0;
}
