#include <iostream>
#include <string>
#include <random>
#include "post.h"
#include "comment.h"
#include "user.h" 



using namespace std;

void menu(){
        cout << "------Bienvenido a esta nueva Red Social------" << endl;
        cout << "¿Que deseas hacer?" << endl;
        cout << "1. Crear Perfil Nuevo" << endl;
        cout << "2. Realizar una publicacion" << endl;
        cout << "3. Comentar una publicacion" << endl;
        cout << "4. Agregar Amigo" << endl;
        cout << "5. Eliminar Amigo" << endl;
        cout << "6. Revisar publicaciones" << endl;
        cout << "7. Revisar perfil" << endl; 
        cout << "8. Salir";
    }

void newProfile(int& contador_perfiles){
    User perfiles[100];
    if (contador_perfiles < 100){
        string name;
        string email;
        string currentDate;
        cout << "Ingresa tu nombre: " << endl;
        cin >> name;
        cout << "Ingresa tu correo electronico: " << endl;
        cin >> email;
        cout << "Ingresa la fecha de hoy (dd/mm/yyyy): " << endl;
        cin >> currentDate;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(10001, 99999);
        int newId = dis(gen);
        perfiles[contador_perfiles] = User(newId, name, email, currentDate);
        contador_perfiles++;
    }
}


int main(){
    int contador_perfiles = 0;
    int opcion;
    bool continua = true;
    while (continua == true){
        menu();
        
        cout << "Ingresa una opcion (1-8): " << endl;
        cin >> opcion;
        switch (opcion){
        case 1:
            newProfile(contador_perfiles);
            break;
        /*case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break; */
        case 8:
            cout << "Nos vemos pronto :D" << endl;  
            continua = false;
            break;    
        default:
            break;
        }
    }
    return 0;
}