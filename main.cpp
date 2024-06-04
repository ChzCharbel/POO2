#include <iostream>
#include <set>
#include <user.h>
#include <post.h>
#include <comment.h>

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

void newProfile(){
    set<User*> perfiles;
    User* newprofile = new User;
    
}


int main(){

    int opcion;
    menu();
    
    cout << "Ingresa una opcion (1-8): " << endl;
    cin >> opcion;
    switch (opcion){
    case 1:
        newProfile();
        break;
    
    default:
        break;
    }

    return 0;
}