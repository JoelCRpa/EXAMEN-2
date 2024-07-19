#include <iostream>
#include <vector>
#include <iomanip>
#include <conio.h>  // Para _getch()
#include <windows.h>  // Para SetConsoleCursorPosition()

using namespace std;

// Función para posicionar el cursor en la consola
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Estructura que define un candidato
struct Candidato {
    int id;
    string nombre;
    string partido;
    string plataforma;
    int votos;
};

// Función para ingresar candidatos
void ingresarCandidatos(vector<Candidato>& candidatos) {
    char continuar;
    int id = candidatos.size() + 1;
    do {
        system("cls");
        Candidato c;
        c.id = id++;
        // Pedir datos al usuario
        cout << "Ingrese el nombre del candidato: ";
        cin >> c.nombre;
        cout << "Ingrese el partido del candidato: ";
        cin >> c.partido;
        cout << "Ingrese la plataforma del candidato: ";
        cin >> c.plataforma;
        c.votos = 0; // Inicialmente, el candidato no tiene votos
        // Agregar candidato al vector de candidatos
        candidatos.push_back(c);
        // Preguntar si desea ingresar otro candidato
        cout << "Desea ingresar otro candidato? (S/N): ";
        cin >> continuar;
        
    } while (continuar == 'S' || continuar == 's');
}

// Función para registrar votos
void registrarVotos(vector<Candidato>& candidatos) {
    int idCandidato, votos;
    char continuar;
    do {
        system("cls");
        cout << "Ingrese el ID del candidato al que desea registrar votos: ";
        cin >> idCandidato;
        // Buscar el candidato por ID
        bool encontrado = false;
        for (size_t i = 0; i < candidatos.size(); ++i) {
            if (candidatos[i].id == idCandidato) {
                cout << "Ingrese la cantidad de votos: ";
                cin >> votos;
                candidatos[i].votos += votos;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            cout << "Candidato no encontrado.\n";
        }
        // Preguntar si desea registrar votos para otro candidato
        cout << "Desea registrar votos para otro candidato? (S/N): ";
        cin >> continuar;
        
    } while (continuar == 'S' || continuar == 's');
}

// Función para mostrar resultados
void verResultados(const vector<Candidato>& candidatos) {
    system("cls");
    int totalVotos = 0;
    // Calcular el total de votos
    for (size_t i = 0; i < candidatos.size(); ++i) {
        totalVotos += candidatos[i].votos;
    }
    cout << "Resultados de la Eleccion:\n";
    // Mostrar resultados por candidato
    for (size_t i = 0; i < candidatos.size(); ++i) {
        const Candidato& c = candidatos[i];
        cout << "Candidato: " << c.nombre << " (" << c.partido << ")\n";
        cout << "Plataforma: " << c.plataforma << "\n";
        cout << "Votos: " << c.votos << "\n";
        cout << "Porcentaje de votos: " << fixed << setprecision(2) 
             << (totalVotos ? (c.votos * 100.0 / totalVotos) : 0) << "%\n\n";
    }
    cout << "<Pulse tecla para volver al menu>" << endl;
    _getch(); // Esperar a que el usuario presione una tecla para continuar
}

// Función para mostrar el menú principal
void mostrarMenu() {
    system("cls"); // Limpiar la pantalla
    cout << "Menu Principal\n";
    cout << "1- Ingresar Candidatos\n";
    cout << "2- Registrar Votos\n";
    cout << "3- Ver Resultados\n";
    cout << "4- Salir\n";
    cout << "Seleccione una opcion: ";
}

int main() {
    vector<Candidato> candidatos;
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                ingresarCandidatos(candidatos);
                break;
            case 2:
                registrarVotos(candidatos);
                break;
            case 3:
                verResultados(candidatos);
                break;
            case 4:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 4);
    
    return 0;
}


