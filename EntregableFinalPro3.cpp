#include <iostream>
#include <string>
#include <cstdlib> // Para usar rand y srand
#include <ctime>   // Para usar time

using namespace std;

const int MAX_ENTIDADES = 3;

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

class Usuario : public Persona {
private:
    string sFechaRegistro;

public:
    Usuario(int id, string nombre, string apellido, string email, string fechaRegistro)
        : Persona(id, nombre, apellido, email), sFechaRegistro(fechaRegistro) {}

    Usuario() : Persona(0, "", "", ""), sFechaRegistro("") {}

    string obtenerFechaRegistro() const { return sFechaRegistro; }
};

class GestoraUsuarios {
private:
    Usuario usuarios[MAX_ENTIDADES];
    int numUsuarios;

public:
    GestoraUsuarios() : numUsuarios(0) {}

    void llenado() {
        if (numUsuarios >= MAX_ENTIDADES) {
            cout << "No se puede agregar más usuarios. La capacidad máxima ha sido alcanzada." << endl;
            return;
        }
        
        string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Pedro"};
        string listaApellidos[] = {"Perez", "Gomez", "Rodriguez", "Diaz", "Sanchez"};
        string listaEmails[] = {"juan@example.com", "maria@example.com", "luis@example.com", "ana@example.com", "pedro@example.com"};
        
        srand(time(nullptr)); // Inicializar la semilla de generación de números aleatorios
        
        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            int indice = rand() % 5; // Obtener un índice aleatorio entre 0 y 4
            Usuario usuario(numUsuarios + 1, listaNombres[indice], listaApellidos[indice], listaEmails[indice], "2024-03-05"); // Se utiliza una fecha de registro fija
            usuarios[numUsuarios++] = usuario;
        }
        
        cout << "Usuarios agregados.\n";
    }

    void listado() {
        cout << "--- Listado de Usuarios ---\n";
        for (int i = 0; i < numUsuarios; ++i) {
            cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
        }
        cout << endl;
    }

    void buscar(string nombre) {
        bool encontrado = false;
        for (int i = 0; i < numUsuarios; ++i) {
            if (usuarios[i].obtenerNombre() == nombre) {
                cout << "Usuario encontrado:\n";
                cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "El usuario no se encuentra en la lista.\n";
        }
    }
};

class Bibliotecario : public Persona {
private:
    string sCargo;

public:
    Bibliotecario(int id, string nombre, string apellido, string email, string cargo)
        : Persona(id, nombre, apellido, email), sCargo(cargo) {}

    Bibliotecario() : Persona(0, "", "", ""), sCargo("") {}

    string obtenerCargo() const { return sCargo; }
};

class GestoraBibliotecarios {
private:
    Bibliotecario bibliotecarios[MAX_ENTIDADES];
    int numBibliotecarios;

public:
    GestoraBibliotecarios() : numBibliotecarios(0) {}

    void llenado() {
        if (numBibliotecarios >= MAX_ENTIDADES) {
            cout << "No se puede agregar más bibliotecarios. La capacidad máxima ha sido alcanzada." << endl;
            return;
        }

        string listaNombres[] = {"Carlos", "Luisa", "Pedro", "Ana", "Juan"};
        string listaApellidos[] = {"Gonzalez", "Lopez", "Martinez", "Gomez", "Perez"};
        string listaEmails[] = {"carlos@example.com", "luisa@example.com", "pedro@example.com", "ana@example.com", "juan@example.com"};
        string listaCargos[] = {"Bibliotecario A", "Bibliotecario B", "Bibliotecario C", "Bibliotecario D", "Bibliotecario E"};

        srand(time(nullptr)); // Inicializar la semilla de generación de números aleatorios
        
        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            int indice = rand() % 5; // Obtener un índice aleatorio entre 0 y 4
            Bibliotecario bibliotecario(numBibliotecarios + 1, listaNombres[indice], listaApellidos[indice], listaEmails[indice], listaCargos[indice]);
            bibliotecarios[numBibliotecarios++] = bibliotecario;
        }
        
        cout << "Bibliotecarios agregados.\n";
    }

    void listado() {
        cout << "--- Listado de Bibliotecarios ---\n";
        for (int i = 0; i < numBibliotecarios; ++i) {
            cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
        }
        cout << endl;
    }

    void buscarPorCargo(string cargo) {
        bool encontrado = false;
        for (int i = 0; i < numBibliotecarios; ++i) {
            if (bibliotecarios[i].obtenerCargo() == cargo) {
                cout << "Bibliotecario encontrado:\n";
                cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
                encontrado = true;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron bibliotecarios con ese cargo.\n";
        }
    }
};

class Libro {
private:
    string Titulo;
    string Autor;
    string ISBN;
    int Anio;

public:
    Libro() : Titulo(""), Autor(""), ISBN(""), Anio(0) {}
    Libro(string titulo, string autor, string isbn, int anio)
        : Titulo(titulo), Autor(autor), ISBN(isbn), Anio(anio) {}

    string obtenerTitulo() const { return Titulo; }
    string obtenerAutor() const { return Autor; }
    string obtenerISBN() const { return ISBN; }
    int obtenerAnio() const { return Anio; }
};

class GestoraLibros {
private:
    Libro libros[MAX_ENTIDADES];
    int numLibros;

public:
    GestoraLibros() : numLibros(0) {}

    void llenado() {
        if (numLibros >= MAX_ENTIDADES) {
            cout << "No se puede agregar más libros. La capacidad máxima ha sido alcanzada." << endl;
            return;
        }

        string listaLibros[] = {"Aprende C", "Effective C++", "Programación en C++", "Curso de programación", "Modern C++", "Clean Code", "The Art of Computer Programming", "Programming Pearls", "Introduction to Algorithms"};
        string listaAutores[] = {"Autor1", "Autor2", "Autor3", "Autor4", "Autor5", "Autor6", "Autor7", "Autor8", "Autor9"};
        string listaISBNs[] = {"1234567890", "0987654321", "1357924680", "2468013579", "9876543210", "0123456789", "5432167890", "6789012345", "3210987654"};
        int listaAnios[] = {2000, 2005, 2010, 2015, 2020, 2021, 2019, 2018, 2017};

        srand(time(nullptr)); // Inicializar la semilla de generación de números aleatorios

        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            int indice = rand() % 9; // Obtener un índice aleatorio entre 0 y 8
            Libro libro(listaLibros[indice], listaAutores[indice], listaISBNs[indice], listaAnios[indice]);
            libros[numLibros++] = libro;
        }

        cout << "Libros agregados.\n";
    }

    void listado() {
        cout << "--- Listado de Libros ---\n";
        for (int i = 0; i < numLibros; ++i) {
            cout << "Título: " << libros[i].obtenerTitulo() << ", Autor: " << libros[i].obtenerAutor() << ", ISBN: " << libros[i].obtenerISBN() << ", Año: " << libros[i].obtenerAnio() << endl;
        }
        cout << endl;
    }

    void buscar(string titulo) {
        bool encontrado = false;
        for (int i = 0; i < numLibros; ++i) {
            if (libros[i].obtenerTitulo() == titulo) {
                cout << "Libro encontrado:\n";
                cout << "Título: " << libros[i].obtenerTitulo() << ", Autor: " << libros[i].obtenerAutor() << ", ISBN: " << libros[i].obtenerISBN() << ", Año: " << libros[i].obtenerAnio() << endl;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "El libro no se encuentra en la lista.\n";
        }
    }
};

char toLowerCase(char c) {
    return tolower(static_cast<unsigned char>(c)); 
}

string generarEmail(string nombre, string apellido) {
    return nombre + "." + apellido + "@correo.com";
}

void menuListados(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros);
void menuBusquedas();

void menuPrincipal(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros) {
    char opcion;

    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1) Llenado de datos.\n";
        cout << "2) Listados.\n";
        cout << "3) Búsquedas.\n";
        cout << "0) Salir.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (toLowerCase(opcion)) {
        case '1':
            gestoraLibros.llenado();
            gestoraUsuarios.llenado();
            gestoraBibliotecarios.llenado();
            break;
        case '2':
            menuListados(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);
            break;
        case '3':
            menuBusquedas();
            break;
        case '0':
            cout << "Saliendo...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
            break;
        }
    } while (opcion != '0');
}

void menuListados(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros) {
    char opcion;

    do {
        cout << "\n--- SUBMENÚ LISTADOS ---\n";
        cout << "A) Listado de Libros.\n";
        cout << "B) Listado Usuarios.\n";
        cout << "C) Listado Bibliotecarios.\n";
        cout << "0) Volver al menú principal.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (toLowerCase(opcion)) {
        case 'a':
            gestoraLibros.listado();
            break;
        case 'b':
            gestoraUsuarios.listado();
            break;
        case 'c':
            gestoraBibliotecarios.listado();
            break;
        case '0':
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
            break;
        }
    } while (opcion != '0');
}

void menuBusquedas() {
    char opcion;

    do {
        cout << "\n--- SUBMENÚ BÚSQUEDAS ---\n";
        cout << "1) Buscar Libro.\n";
        cout << "2) Buscar Usuario.\n";
        cout << "3) Buscar Bibliotecario.\n";
        cout << "0) Volver al menú principal.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (toLowerCase(opcion)) {
        case '1': {
            string titulo;
            cout << "Ingrese el título del libro a buscar: ";
            cin.ignore();
            getline(cin, titulo);
            GestoraLibros gestoraLibros;
            gestoraLibros.buscar(titulo);
            break;
        }
        case '2': {
            string nombre;
            cout << "Ingrese el nombre del usuario a buscar: ";
            cin.ignore();
            getline(cin, nombre);
            GestoraUsuarios gestoraUsuarios;
            gestoraUsuarios.buscar(nombre);
            break;
        }
        case '3': {
            string cargo;
            cout << "Ingrese el cargo del bibliotecario a buscar: ";
            cin.ignore();
            getline(cin, cargo);
            GestoraBibliotecarios gestoraBibliotecarios;
            gestoraBibliotecarios.buscarPorCargo(cargo);
            break;
        }
        case '0':
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
            break;
        }
    } while (opcion != '0');
}

int main() {
    GestoraUsuarios gestoraUsuarios;
    GestoraBibliotecarios gestoraBibliotecarios;
    GestoraLibros gestoraLibros;

    menuPrincipal(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);

    return 0;
}
