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
    
    Usuario* obtenerUsuarios() {
        return usuarios;
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
    
    Bibliotecario* obtenerBibliotecarios() {
        return bibliotecarios;
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
    
    Libro* obtenerLibros() {
        return libros;
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

void imprimirListadoTabla(GestoraUsuarios* gestoraUsuarios, GestoraBibliotecarios* gestoraBibliotecarios, GestoraLibros* gestoraLibros) {
    cout << "--- Listado en Tabla ---\n";
    cout << "Usuarios:\n";
    cout << "ID\tNombre\tApellido\tEmail\tFecha de Registro\n";
    Usuario* usuarios = gestoraUsuarios->obtenerUsuarios();
    for (int i = 0; i < gestoraUsuarios->obtenerNumeroUsuarios(); ++i) {
        cout << usuarios[i].obtenerID() << "\t" << usuarios[i].obtenerNombre() << "\t" << usuarios[i].obtenerApellido() << "\t" << usuarios[i].obtenerEmail() << "\t" << usuarios[i].obtenerFechaRegistro() << endl;
    }
    cout << "\nBibliotecarios:\n";
    cout << "ID\tNombre\tApellido\tEmail\tCargo\n";
    Bibliotecario* bibliotecarios = gestoraBibliotecarios->obtenerBibliotecarios();
    for (int i = 0; i < gestoraBibliotecarios->obtenerNumeroBibliotecarios(); ++i) {
        cout << bibliotecarios[i].obtenerID() << "\t" << bibliotecarios[i].obtenerNombre() << "\t" << bibliotecarios[i].obtenerApellido() << "\t" << bibliotecarios[i].obtenerEmail() << "\t" << bibliotecarios[i].obtenerCargo() << endl;
    }
    cout << "\nLibros:\n";
    cout << "Título\tAutor\tISBN\tAño\n";
    Libro* libros = gestoraLibros->obtenerLibros();
    for (int i = 0; i < gestoraLibros->obtenerNumeroLibros(); ++i) {
        cout << libros[i].obtenerTitulo() << "\t" << libros[i].obtenerAutor() << "\t" << libros[i].obtenerISBN() << "\t" << libros[i].obtenerAnio() << endl;
    }
}

void imprimirListadoBloque(GestoraUsuarios* gestoraUsuarios, GestoraBibliotecarios* gestoraBibliotecarios, GestoraLibros* gestoraLibros) {
    cout << "--- Listado en Bloque ---\n";
    cout << "Usuarios:\n";
    Usuario* usuarios = gestoraUsuarios->obtenerUsuarios();
    for (int i = 0; i < gestoraUsuarios->obtenerNumeroUsuarios(); ++i) {
        cout << "ID: " << usuarios[i].obtenerID() << endl;
        cout << "Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << endl;
        cout << "Email: " << usuarios[i].obtenerEmail() << endl;
        cout << "Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl << endl;
    }
    cout << "Bibliotecarios:\n";
    Bibliotecario* bibliotecarios = gestoraBibliotecarios->obtenerBibliotecarios();
    for (int i = 0; i < gestoraBibliotecarios->obtenerNumeroBibliotecarios(); ++i) {
        cout << "ID: " << bibliotecarios[i].obtenerID() << endl;
        cout << "Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << endl;
        cout << "Email: " << bibliotecarios[i].obtenerEmail() << endl;
        cout << "Cargo: " << bibliotecarios[i].obtenerCargo() << endl << endl;
    }
    cout << "Libros:\n";
    Libro* libros = gestoraLibros->obtenerLibros();
    for (int i = 0; i < gestoraLibros->obtenerNumeroLibros(); ++i) {
        cout << "Título: " << libros[i].obtenerTitulo() << endl;
        cout << "Autor: " << libros[i].obtenerAutor() << endl;
        cout << "ISBN: " << libros[i].obtenerISBN() << endl;
        cout << "Año: " << libros[i].obtenerAnio() << endl << endl;
    }
}

void buscarUsuariosPorNombre(GestoraUsuarios& gestoraUsuarios) {
    string nombreBusqueda;
    cout << "Ingrese el nombre del usuario a buscar: ";
    cin >> nombreBusqueda;
    
    cout << "--- Resultados de la búsqueda por nombre ---\n";
    Usuario* usuarios = gestoraUsuarios.obtenerUsuarios();
    bool encontrado = false;
    for (int i = 0; i < gestoraUsuarios.obtenerNumeroUsuarios(); ++i) {
        if (usuarios[i].obtenerNombre() == nombreBusqueda) {
            cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontraron usuarios con ese nombre.\n";
}

void buscarBibliotecariosPorCargo(GestoraBibliotecarios& gestoraBibliotecarios) {
    string cargoBusqueda;
    cout << "Ingrese el cargo del bibliotecario a buscar: ";
    cin >> cargoBusqueda;
    
    cout << "--- Resultados de la búsqueda por cargo ---\n";
    Bibliotecario* bibliotecarios = gestoraBibliotecarios.obtenerBibliotecarios();
    bool encontrado = false;
    for (int i = 0; i < gestoraBibliotecarios.obtenerNumeroBibliotecarios(); ++i) {
        if (bibliotecarios[i].obtenerCargo() == cargoBusqueda) {
            cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
            encontrado = true;
        }
    }
    if (!encontrado)
        cout << "No se encontraron bibliotecarios con ese cargo.\n";
}

void menuListados(GestoraUsuarios& gestoraUsuarios, GestoraBibliotecarios& gestoraBibliotecarios, GestoraLibros& gestoraLibros, bool datosLlenados);
void imprimirListadoTabla(GestoraUsuarios* gestoraUsuarios, GestoraBibliotecarios* gestoraBibliotecarios, GestoraLibros* gestoraLibros);
void imprimirListadoBloque(GestoraUsuarios* gestoraUsuarios, GestoraBibliotecarios* gestoraBibliotecarios, GestoraLibros* gestoraLibros);

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
            char tipoBusqueda;
            cout << "\n--- MENÚ BÚSQUEDAS ---\n";
            cout << "A) Buscar usuarios por nombre.\n";
            cout << "B) Buscar bibliotecarios por cargo.\n";
            cout << "0) Volver al menú principal.\n";
            cout << "Seleccione una opción: ";
            cin >> tipoBusqueda;
            switch (toLowerCase(tipoBusqueda)) {
                case 'a':
                    buscarUsuariosPorNombre(gestoraUsuarios);
                    break;
                case 'b':
                    buscarBibliotecariosPorCargo(gestoraBibliotecarios);
                    break;
                case '0':
                    cout << "Volviendo al menú principal...\n";
                    break;
                default:
                    cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
                    break;
            }
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
    if (!datosLlenados) {
        cout << "Por favor, primero llene los datos (opción 1 en el menú principal).\n";
        return;
    }
    
    char tipoListado;
    cout << "\n--- MENÚ LISTADOS ---\n";
    cout << "1) Listado en tabla.\n";
    cout << "2) Listado en bloque.\n";
    cout << "0) Volver al menú principal.\n";
    cout << "Seleccione una opción: ";
    cin >> tipoListado;
    
    switch (toLowerCase(tipoListado)) {
        case '1':
            imprimirListadoTabla(&gestoraUsuarios, &gestoraBibliotecarios, &gestoraLibros);
            break;
        case '2':
            imprimirListadoBloque(&gestoraUsuarios, &gestoraBibliotecarios, &gestoraLibros);
            break;
        case '0':
            cout << "Volviendo al menú principal...\n";
            break;
        default:
            cout << "Opción no válida. Por favor, seleccione una opción válida.\n";
            break;
    }
}

int main() {
    GestoraUsuarios gestoraUsuarios;
    GestoraBibliotecarios gestoraBibliotecarios;
    GestoraLibros gestoraLibros;
    
    menuPrincipal(gestoraUsuarios, gestoraBibliotecarios, gestoraLibros);
    
    return 0;
}
