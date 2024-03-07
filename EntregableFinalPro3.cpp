#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

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
        
        srand(time(nullptr));
        
        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            int indice = rand() % 5;
            Usuario usuario(numUsuarios + 1, listaNombres[indice], listaApellidos[indice], listaEmails[indice], "2024-03-05");
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

    // Método para buscar usuarios por nombre (considerando primeras y últimas letras)
    void buscarPorNombre(const string& nombre) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por nombre: " << nombre << " ---\n";
        for (int i = 0; i < numUsuarios; ++i) {
            string nombreUsuario = usuarios[i].obtenerNombre();
            string apellidoUsuario = usuarios[i].obtenerApellido();
            transform(nombreUsuario.begin(), nombreUsuario.end(), nombreUsuario.begin(), ::tolower);
            transform(apellidoUsuario.begin(), apellidoUsuario.end(), apellidoUsuario.begin(), ::tolower);
            if (nombreUsuario.find(nombre) == 0 || apellidoUsuario.find(nombre) == 0 || nombreUsuario.rfind(nombre) == nombreUsuario.length() - nombre.length() || apellidoUsuario.rfind(nombre) == apellidoUsuario.length() - nombre.length()) {
                encontrado = true;
                cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron usuarios con ese nombre.\n";
        }
        cout << endl;
    }

    // Método para buscar usuarios por apellido (considerando primeras y últimas letras)
    void buscarPorApellido(const string& apellido) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por apellido: " << apellido << " ---\n";
        for (int i = 0; i < numUsuarios; ++i) {
            string nombreUsuario = usuarios[i].obtenerNombre();
            string apellidoUsuario = usuarios[i].obtenerApellido();
            transform(nombreUsuario.begin(), nombreUsuario.end(), nombreUsuario.begin(), ::tolower);
            transform(apellidoUsuario.begin(), apellidoUsuario.end(), apellidoUsuario.begin(), ::tolower);
            if (nombreUsuario.find(apellido) == 0 || apellidoUsuario.find(apellido) == 0 || nombreUsuario.rfind(apellido) == nombreUsuario.length() - apellido.length() || apellidoUsuario.rfind(apellido) == apellidoUsuario.length() - apellido.length()) {
                encontrado = true;
                cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron usuarios con ese apellido.\n";
        }
        cout << endl;
    }

    // Método para buscar usuarios por ID
    void buscarPorID(int id) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por ID: " << id << " ---\n";
        for (int i = 0; i < numUsuarios; ++i) {
            if (usuarios[i].obtenerID() == id) {
                encontrado = true;
                cout << "ID: " << usuarios[i].obtenerID() << ", Nombre: " << usuarios[i].obtenerNombre() << " " << usuarios[i].obtenerApellido() << ", Email: " << usuarios[i].obtenerEmail() << ", Fecha de Registro: " << usuarios[i].obtenerFechaRegistro() << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "No se encontró ningún usuario con ese ID.\n";
        }
        cout << endl;
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
        
        srand(time(nullptr));
        
        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            int indice = rand() % 5;
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

    // Método para buscar bibliotecarios por nombre (considerando primeras y últimas letras)
    void buscarPorNombre(const string& nombre) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por nombre: " << nombre << " ---\n";
        for (int i = 0; i < numBibliotecarios; ++i) {
            string nombreBibliotecario = bibliotecarios[i].obtenerNombre();
            string apellidoBibliotecario = bibliotecarios[i].obtenerApellido();
            transform(nombreBibliotecario.begin(), nombreBibliotecario.end(), nombreBibliotecario.begin(), ::tolower);
            transform(apellidoBibliotecario.begin(), apellidoBibliotecario.end(), apellidoBibliotecario.begin(), ::tolower);
            if (nombreBibliotecario.find(nombre) == 0 || apellidoBibliotecario.find(nombre) == 0 || nombreBibliotecario.rfind(nombre) == nombreBibliotecario.length() - nombre.length() || apellidoBibliotecario.rfind(nombre) == apellidoBibliotecario.length() - nombre.length()) {
                encontrado = true;
                cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron bibliotecarios con ese nombre.\n";
        }
        cout << endl;
    }

    // Método para buscar bibliotecarios por apellido (considerando primeras y últimas letras)
    void buscarPorApellido(const string& apellido) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por apellido: " << apellido << " ---\n";
        for (int i = 0; i < numBibliotecarios; ++i) {
            string nombreBibliotecario = bibliotecarios[i].obtenerNombre();
            string apellidoBibliotecario = bibliotecarios[i].obtenerApellido();
            transform(nombreBibliotecario.begin(), nombreBibliotecario.end(), nombreBibliotecario.begin(), ::tolower);
            transform(apellidoBibliotecario.begin(), apellidoBibliotecario.end(), apellidoBibliotecario.begin(), ::tolower);
            if (nombreBibliotecario.find(apellido) == 0 || apellidoBibliotecario.find(apellido) == 0 || nombreBibliotecario.rfind(apellido) == nombreBibliotecario.length() - apellido.length() || apellidoBibliotecario.rfind(apellido) == apellidoBibliotecario.length() - apellido.length()) {
                encontrado = true;
                cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron bibliotecarios con ese apellido.\n";
        }
        cout << endl;
    }

    // Método para buscar bibliotecarios por cargo (considerando primeras y últimas letras)
    void buscarPorCargo(const string& cargo) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por cargo: " << cargo << " ---\n";
        for (int i = 0; i < numBibliotecarios; ++i) {
            string nombreBibliotecario = bibliotecarios[i].obtenerNombre();
            string apellidoBibliotecario = bibliotecarios[i].obtenerApellido();
            transform(nombreBibliotecario.begin(), nombreBibliotecario.end(), nombreBibliotecario.begin(), ::tolower);
            transform(apellidoBibliotecario.begin(), apellidoBibliotecario.end(), apellidoBibliotecario.begin(), ::tolower);
            string cargoBibliotecario = bibliotecarios[i].obtenerCargo();
            transform(cargoBibliotecario.begin(), cargoBibliotecario.end(), cargoBibliotecario.begin(), ::tolower);
            if (cargoBibliotecario.find(cargo) != string::npos) {
                encontrado = true;
                cout << "ID: " << bibliotecarios[i].obtenerID() << ", Nombre: " << bibliotecarios[i].obtenerNombre() << " " << bibliotecarios[i].obtenerApellido() << ", Email: " << bibliotecarios[i].obtenerEmail() << ", Cargo: " << bibliotecarios[i].obtenerCargo() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron bibliotecarios con ese cargo.\n";
        }
        cout << endl;
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
        
        string listaTitulos[] = {"El señor de los anillos", "Cien años de soledad", "Don Quijote de la Mancha", "Harry Potter y la piedra filosofal", "1984"};
        string listaAutores[] = {"J.R.R. Tolkien", "Gabriel García Márquez", "Miguel de Cervantes", "J.K. Rowling", "George Orwell"};
        string listaISBNs[] = {"9788445000655", "9788439708131", "9788423345296", "9788478884453", "9788408182815"};
        int listaAnios[] = {1954, 1967, 1605, 1997, 1949};
        
        srand(time(nullptr));
        
        for (int i = 0; i < MAX_ENTIDADES; ++i) {
            Libro libro(listaTitulos[i], listaAutores[i], listaISBNs[i], listaAnios[i]);
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

    // Método para buscar libros por título (considerando primeras y últimas letras)
    void buscarPorTitulo(const string& titulo) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por título: " << titulo << " ---\n";
        for (int i = 0; i < numLibros; ++i) {
            string tituloLibro = libros[i].obtenerTitulo();
            transform(tituloLibro.begin(), tituloLibro.end(), tituloLibro.begin(), ::tolower);
            if (tituloLibro.find(titulo) == 0 || tituloLibro.rfind(titulo) == tituloLibro.length() - titulo.length()) {
                encontrado = true;
                cout << "Título: " << libros[i].obtenerTitulo() << ", Autor: " << libros[i].obtenerAutor() << ", ISBN: " << libros[i].obtenerISBN() << ", Año: " << libros[i].obtenerAnio() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron libros con ese título.\n";
        }
        cout << endl;
    }

    // Método para buscar libros por año de publicación
    void buscarPorAnio(int anio) {
        bool encontrado = false;
        cout << "--- Resultados de la búsqueda por año: " << anio << " ---\n";
        for (int i = 0; i < numLibros; ++i) {
            if (libros[i].obtenerAnio() == anio) {
                encontrado = true;
                cout << "Título: " << libros[i].obtenerTitulo() << ", Autor: " << libros[i].obtenerAutor() << ", ISBN: " << libros[i].obtenerISBN() << ", Año: " << libros[i].obtenerAnio() << endl;
            }
        }
        if (!encontrado) {
            cout << "No se encontraron libros publicados en ese año.\n";
        }
        cout << endl;
    }

    // Método para buscar libros por número de páginas
    // En este ejemplo, asumimos que hay un atributo "numPaginas" en la clase Libro
    // Se debe agregar ese atributo y modificar el método de búsqueda según sea necesario
    // void buscarPorNumeroPaginas(int numPaginas) {
    //     // Lógica para buscar libros por número de páginas
    // }
};

void submenuBusquedaUsuario(GestoraUsuarios& gestoraUsuarios) {
    int opcion;
    string nombre;
    string apellido;
    int id;
    cout << "\n--- MENÚ DE BÚSQUEDA DE USUARIO ---\n";
    cout << "1) Buscar por nombre.\n";
    cout << "2) Buscar por apellido.\n";
    cout << "3) Buscar por ID.\n";
    cout << "0) Volver.\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "Ingrese el nombre a buscar: ";
            cin >> nombre;
            gestoraUsuarios.buscarPorNombre(nombre);
            break;
        case 2:
            cout << "Ingrese el apellido a buscar: ";
            cin >> apellido;
            gestoraUsuarios.buscarPorApellido(apellido);
            break;
        case 3:
            cout << "Ingrese el ID a buscar: ";
            cin >> id;
            gestoraUsuarios.buscarPorID(id);
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
    }
}

void submenuBusquedaBibliotecario(GestoraBibliotecarios& gestoraBibliotecarios) {
    int opcion;
    string nombre;
    string apellido;
    string cargo;
    cout << "\n--- MENÚ DE BÚSQUEDA DE BIBLIOTECARIO ---\n";
    cout << "1) Buscar por nombre.\n";
    cout << "2) Buscar por apellido.\n";
    cout << "3) Buscar por cargo.\n";
    cout << "0) Volver.\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "Ingrese el nombre a buscar: ";
            cin >> nombre;
            gestoraBibliotecarios.buscarPorNombre(nombre);
            break;
        case 2:
            cout << "Ingrese el apellido a buscar: ";
            cin >> apellido;
            gestoraBibliotecarios.buscarPorApellido(apellido);
            break;
        case 3:
            cout << "Ingrese el cargo a buscar: ";
            cin >> cargo;
            gestoraBibliotecarios.buscarPorCargo(cargo);
            break;
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
    }
}

void submenuBusquedaLibro(GestoraLibros& gestoraLibros) {
    int opcion;
    string titulo;
    int anio;
    cout << "\n--- MENÚ DE BÚSQUEDA DE LIBRO ---\n";
    cout << "1) Buscar por título.\n";
    cout << "2) Buscar por año.\n";
    // Agregar más opciones según sea necesario (por ejemplo, buscar por número de páginas)
    cout << "0) Volver.\n";
    cout << "Seleccione una opción: ";
    cin >> opcion;
    switch (opcion) {
        case 1:
            cout << "Ingrese el título a buscar: ";
            cin >> titulo;
            gestoraLibros.buscarPorTitulo(titulo);
            break;
        case 2:
            cout << "Ingrese el año a buscar: ";
            cin >> anio;
            gestoraLibros.buscarPorAnio(anio);
            break;
        // Agregar más casos según sea necesario
        case 0:
            break;
        default:
            cout << "Opción inválida.\n";
    }
}

int main() {
    int opcion;
    GestoraUsuarios gestoraUsuarios;
    GestoraBibliotecarios gestoraBibliotecarios;
    GestoraLibros gestoraLibros;
    
    do {
        cout << "\n--- MENÚ PRINCIPAL ---\n";
        cout << "1) Llenado de datos.\n";
        cout << "2) Listados.\n";
        cout << "3) Búsquedas.\n";
        cout << "0) Salir.\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                gestoraUsuarios.llenado();
                gestoraBibliotecarios.llenado();
                gestoraLibros.llenado();
                break;
            case 2:
                gestoraUsuarios.listado();
                gestoraBibliotecarios.listado();
                gestoraLibros.listado();
                break;
            case 3:
                int opcionBusqueda;
                cout << "\n--- MENÚ DE BÚSQUEDA ---\n";
                cout << "1) Buscar Usuario.\n";
                cout << "2) Buscar Bibliotecario.\n";
                cout << "3) Buscar Libro.\n";
                cout << "4) Volver.\n";
                cout << "Seleccione una opción: ";
                cin >> opcionBusqueda;
                switch (opcionBusqueda) {
                    case 1:
                        submenuBusquedaUsuario(gestoraUsuarios);
                        break;
                    case 2:
                        submenuBusquedaBibliotecario(gestoraBibliotecarios);
                        break;
                    case 3:
                        submenuBusquedaLibro(gestoraLibros);
                        break;
                    case 4:
                        break;
                    default:
                        cout << "Opción inválida.\n";
                }
                break;
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 0);
    
    return 0;
}
