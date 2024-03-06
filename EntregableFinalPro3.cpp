#include <iostream>
#include <string>
#include <cstdlib> // Para usar rand y srand
#include <ctime>   // Para usar time

using namespace std;

const int MAX_ENTIDADES = 5;

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
    
    Usuario obtenerUsuario(int indice) {
        return usuarios[indice];
    }

    int obtenerNumeroUsuarios() const {
        return numUsuarios;
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

    Bibliotecario obtenerBibliotecario(int indice) {
        return bibliotecarios[indice];
    }

    int obtenerNumeroBibliotecarios() const {
        return numBibliotecarios;
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

    Libro obtenerLibro(int indice) {
        return libros[indice];
    }

    int obtenerNumeroLibros() const {
        return numLibros;
    }
};

char toLowerCase(char c) {
    return tolower(static_cast<unsigned char>(c)); 
}

string generarEmail(string nombre, string apellido) {
    return nombre + "." + apellido + "@correo.com";
}

void menuListados(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros, bool datosLlenados);
void imprimirListadoTabla(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros);
void imprimirListadoBloque(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros);

void menuPrincipal(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros) {
    char opcion;
    
    bool datosLlenados = false;
    
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
            datosLlenados = true;
            break;
        case '2':
            if (datosLlenados)
                menuListados(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros, datosLlenados);
            else
                cout << "Por favor, primero llene los datos (opción 1).\n";
            break;
        case '3':
            // Lógica para el menú de búsquedas
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

void menuListados(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros, bool datosLlenados) {
    char opcion;
    
    do {
        cout << "\n--- SUBMENÚ LISTADOS ---\n";
        cout << "A) Listado de Libros.\n";
        cout << "B) Listado Usuarios.\n";
        cout << "C) Listado Bibliotecarios.\n";
        cout << "D) Imprimir en tabla o bloque.\n";
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
        case 'd':
            if (datosLlenados) {
                char imprimirOpcion;
                cout << "¿Cómo desea imprimir los listados? (T para tabla, B para bloque): ";
                cin >> imprimirOpcion;
                if (toLowerCase(imprimirOpcion) == 't')
                    imprimirListadoTabla(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);
                else if (toLowerCase(imprimirOpcion) == 'b')
                    imprimirListadoBloque(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);
                else
                    cout << "Opción no válida.\n";
            } else {
                cout << "Por favor, primero llene los datos (opción 1).\n";
            }
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

void imprimirListadoTabla(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros) {
    cout << "--- Listado en Tabla ---\n";
    cout << "Usuarios:\n";
    cout << "ID\tNombre\tApellido\tEmail\tFecha de Registro\n";
    for (int i = 0; i < gestoraUsuarios.obtenerNumeroUsuarios(); ++i) {
        Usuario usuario = gestoraUsuarios.obtenerUsuario(i);
        cout << usuario.obtenerID() << "\t" << usuario.obtenerNombre() << "\t" << usuario.obtenerApellido() << "\t" << usuario.obtenerEmail() << "\t" << usuario.obtenerFechaRegistro() << endl;
    }
    cout << "\nBibliotecarios:\n";
    cout << "ID\tNombre\tApellido\tEmail\tCargo\n";
    for (int i = 0; i < gestoraBibliotecarios.obtenerNumeroBibliotecarios(); ++i) {
        Bibliotecario bibliotecario = gestoraBibliotecarios.obtenerBibliotecario(i);
        cout << bibliotecario.obtenerID() << "\t" << bibliotecario.obtenerNombre() << "\t" << bibliotecario.obtenerApellido() << "\t" << bibliotecario.obtenerEmail() << "\t" << bibliotecario.obtenerCargo() << endl;
    }
    cout << "\nLibros:\n";
    cout << "Título\tAutor\tISBN\tAño\n";
    for (int i = 0; i < gestoraLibros.obtenerNumeroLibros(); ++i) {
        Libro libro = gestoraLibros.obtenerLibro(i);
        cout << libro.obtenerTitulo() << "\t" << libro.obtenerAutor() << "\t" << libro.obtenerISBN() << "\t" << libro.obtenerAnio() << endl;
    }
}

void imprimirListadoBloque(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros) {
    cout << "--- Listado en Bloque ---\n";
    cout << "Usuarios:\n";
    for (int i = 0; i < gestoraUsuarios.obtenerNumeroUsuarios(); ++i) {
        Usuario usuario = gestoraUsuarios.obtenerUsuario(i);
        cout << "ID: " << usuario.obtenerID() << endl;
        cout << "Nombre: " << usuario.obtenerNombre() << " " << usuario.obtenerApellido() << endl;
        cout << "Email: " << usuario.obtenerEmail() << endl;
        cout << "Fecha de Registro: " << usuario.obtenerFechaRegistro() << endl << endl;
    }
    cout << "Bibliotecarios:\n";
    for (int i = 0; i < gestoraBibliotecarios.obtenerNumeroBibliotecarios(); ++i) {
        Bibliotecario bibliotecario = gestoraBibliotecarios.obtenerBibliotecario(i);
        cout << "ID: " << bibliotecario.obtenerID() << endl;
        cout << "Nombre: " << bibliotecario.obtenerNombre() << " " << bibliotecario.obtenerApellido() << endl;
        cout << "Email: " << bibliotecario.obtenerEmail() << endl;
        cout << "Cargo: " << bibliotecario.obtenerCargo() << endl << endl;
    }
    cout << "Libros:\n";
    for (int i = 0; i < gestoraLibros.obtenerNumeroLibros(); ++i) {
        Libro libro = gestoraLibros.obtenerLibro(i);
        cout << "Título: " << libro.obtenerTitulo() << endl;
        cout << "Autor: " << libro.obtenerAutor() << endl;
        cout << "ISBN: " << libro.obtenerISBN() << endl;
        cout << "Año: " << libro.obtenerAnio() << endl << endl;
    }
}

int main() {
    GestoraUsuarios gestoraUsuarios;
    GestoraBibliotecarios gestoraBibliotecarios;
    GestoraLibros gestoraLibros;
    
    menuPrincipal(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);
    
    return 0;
}
