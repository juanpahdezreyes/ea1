#include <iostream>
#include <vector>
#include <string>

using namespace std;

// aqui defino la clase alumno
class Alumno {
public:
    string nombre;
    string apellido;
    int edad;

    Alumno(string nombre, string apellido, int edad) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->edad = edad;
    }

    string nombreCompleto() const { // marcar la función como const por que el nombre no va a cambiar, siempre va a ser constante
        return nombre + " " + apellido;
    }
};

// diseño de menu
void mostrarMenu() {
    cout << "==============================" << endl;
    cout << "    REGISTRO DE ALUMNOS 5C     " << endl;
    cout << "==============================" << endl;
    cout << "1. Agregar nuevo alumno" << endl;
    cout << "2. Editar alumno existente" << endl;
    cout << "3. Eliminar alumno" << endl;
    cout << "4. Listar alumnos registrados" << endl;
    cout << "0. Salir" << endl;
    cout << "==============================" << endl;
    cout << "Elige una opción: ";
}

// funcion para agregar un nuevo alumno
void agregarAlumno(vector<Alumno>& alumnos) {
    string nombre, apellido;
    int edad;

    cout << "Ingrese el nombre del alumno: ";
    cin >> nombre;
    cout << "Ingrese el apellido del alumno: ";
    cin >> apellido;
    cout << "Ingrese la edad del alumno: ";
    cin >> edad;

    alumnos.push_back(Alumno(nombre, apellido, edad));
    cout << "Alumno agregado exitosamente!" << endl;
}

// funcion para editar un alumno que ya existe
void editarAlumno(vector<Alumno>& alumnos) {
    int index;
    if (alumnos.empty()) {
        cout << "No hay alumnos registrados para editar." << endl;
        return;
    }

    cout << "Ingrese el número del alumno a editar (1 a " << alumnos.size() << "): ";
    cin >> index;

    if (index < 1 || index > alumnos.size()) {
        cout << "Índice no válido." << endl;
        return;
    }

    string nuevoNombre, nuevoApellido;
    int nuevaEdad;

    cout << "Ingrese el nuevo nombre: ";
    cin >> nuevoNombre;
    cout << "Ingrese el nuevo apellido: ";
    cin >> nuevoApellido;
    cout << "Ingrese la nueva edad: ";
    cin >> nuevaEdad;

    alumnos[index - 1].nombre = nuevoNombre;
    alumnos[index - 1].apellido = nuevoApellido;
    alumnos[index - 1].edad = nuevaEdad;

    cout << "Alumno actualizado exitosamente!" << endl;
}

// funcion para elimnar un alumno ya existente
void eliminarAlumno(vector<Alumno>& alumnos) {
    int index;
    if (alumnos.empty()) {
        cout << "No hay alumnos registrados para eliminar." << endl;
        return;
    }

    cout << "Ingrese el número del alumno a eliminar (1 a " << alumnos.size() << "): ";
    cin >> index;

    if (index < 1 || index > alumnos.size()) {
        cout << "Índice no válido." << endl;
        return;
    }

    alumnos.erase(alumnos.begin() + (index - 1));
    cout << "Alumno eliminado exitosamente!" << endl;
}

// funcion para enlistar los alumnos ya guardados
void listarAlumnos(const vector<Alumno>& alumnos) {
    if (alumnos.empty()) {
        cout << "No hay alumnos registrados." << endl;
    } else {
        cout << "Lista de alumnos registrados:" << endl;
        for (int i = 0; i < alumnos.size(); i++) {
            cout << i + 1 << ". " << alumnos[i].nombreCompleto() << ", Edad: " << alumnos[i].edad << endl;
        }
    }
}

int main() {
    vector<Alumno> alumnos;
    int opcion;
    string entrada;

    do {
        mostrarMenu();
        cin >> entrada;
        if(entrada.size()!=1)opcion=5;
        else
        {
            if(entrada=="0")opcion=0;
            else if(entrada=="1")opcion=1;
            else if(entrada=="2")opcion=2;
            else if(entrada=="3")opcion=3;
            else if(entrada=="4")opcion=4;
            else opcion=5;
        }
        switch (opcion) {
        case 1:
            agregarAlumno(alumnos);
            break;
        case 2:
            editarAlumno(alumnos);
            break;
        case 3:
            eliminarAlumno(alumnos);
            break;
        case 4:
            listarAlumnos(alumnos);
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opción no válida. Intente de nuevo." << endl;
        }

        cout << endl;

    } while (opcion != 0);

    return 0;
}
