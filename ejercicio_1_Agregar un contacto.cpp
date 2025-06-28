#include <iostream>
using namespace std;

struct contactoEmail {
    string nombreCompleto;
    char sexo;
    int edad;
    string telefono;
    string email;
    string nacionalidad;
};

const int MAX = 100;
contactoEmail contactos[MAX];
int totalContactos = 0;

void agregarContacto() {
    if (totalContactos >= MAX) {
        cout << "Lista de contactos llena\n";
        return;
    }

    contactoEmail nuevo;

    cin.ignore();

    cout << "\n---AGREGAR CONTACTO---\n";
    cout << "Nombre completo: ";
    getline(cin, nuevo.nombreCompleto);
    cout << "Sexo(M/F): ";
    cin >> nuevo.sexo;
    cout << "Edad: ";
    cin >> nuevo.edad;
    cout << "Telefono: ";
    cin >> nuevo.telefono;
    cout << "Email: ";
    cin >> nuevo.email;
    cin.ignore();
    cout << "Nacionalidad: ";
    getline(cin, nuevo.nacionalidad);

    contactos[totalContactos] = nuevo;
    totalContactos++;

    cout << "Contacto agregado correctamente\n";
}
void eliminarContacto() {
    if (totalContactos == 0) {
        cout << "No hay contactos registrados\n";
        return;
    }

    string emailEliminar;
    cout << "\n---ELIMINAR CONTACTO---\n";
    cout << "Ingrese email: ";
    cin >> emailEliminar;

    bool encontrado = false;

    for (int i = 0; i < totalContactos; i++) {
        if (contactos[i].email == emailEliminar) {
            for (int j = i; j < totalContactos - 1; j++) {
                contactos[j] = contactos[j + 1];
            }
            totalContactos--;
            encontrado = true;
            cout << "Contacto eliminado\n";
            break;
        }
    }

    if (!encontrado) {
        cout << "Contacto no econtrado\n";
    }
}

void mostrarContactos() {
    if (totalContactos == 0) {
        cout << "No hay contactos registrados\n";
        return;
    }

    cout << "\n---LISTADOCONTACTOS---\n";

    for (int i = 0; i < totalContactos; i++) {
        cout << "------------------------\n";
        cout << "Nombre: " << contactos[i].nombreCompleto << endl;
        cout << "Sexo: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Telefono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
    }
}
void mostrarMenu() {
    cout << "\n=====MENU=====\n";
    cout << "1.Agregar contacto\n";
    cout << "2.Eliminar contacto\n";
    cout << "3.Mostrar contactos\n";
    cout << "4.Salir\n";
    cout << "Opcion: ";
}
int main() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarContacto();
                break;
            case 2:
                eliminarContacto();
                break;
            case 3:
                mostrarContactos();
                break;
            case 4:
                cout << "Saliendo del programa\n";
                break;
            default:
                cout << "Opcion no valida\n";
        }

    } while (opcion != 4);

    return 0;
}
