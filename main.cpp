#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "post.h"
#include "app.h"

using namespace std;

void menu(){
    
    cout << "--------Bienvenido a esta nueva red social :D--------" << endl;
    cout << "1. Muestra Usuarios" << endl;
    cout << "2. Muestra Amigos" << endl;
    cout << "3. Muestra Desconocidos" << endl;
    cout << "4. Ver perfil" << endl;
    cout << "5. Crear Post de Texto" << endl;
    cout << "6. Crear Post de Imagen" << endl;
    cout << "7. Agregar Amigo" << endl;
    cout << "8. Agregar Desconocido" << endl;
    cout << "9. Mostrar Post" << endl;
    cout << "10. Salir" << endl;

}

void showUsers(App& app){
    app.muestraUsuarios();
}

void showAmigos(App& app){
    app.muestraUsuarios("Amigo");
}

void showDesconocidos(App& app){
    app.muestraUsuarios("Desconocido");
}

void showProfile(App& app, int i){
    app.muestraPerfil(i);
}

void addFriend(App& app, string name, int age, string description){
    app.agregaAmigo(name, age, description);
}

void addUnknown(App& app, string name, int age){
    app.agregaUnknown(name, age);
}

void createTextPost(App& app, string title, string content, int noUser){
    app.getUser(noUser)->creaTextPost(title, content);
}

void createImagePost(App& app, string title, string content, string imageURL, int noUser){
    app.getUser(noUser)->creaImagePost(title, content, imageURL);
}

void showPosts(App& app, int i){
    app.getUser(i)->showPosts();
}

int main() {
    App app;
    string name, description, title, content, imageURL;
    int age;
    app.creaUsuarios();
    bool continua = true;
    while (continua == true){
        menu();
        int opcion;
        cout << "Ingresa una opcion valida (1-10): ";
        cin >> opcion;
        switch (opcion) {
        case 1:
            cout << "Los usuarios actuales de la app son: " << endl;
            showUsers(app);
            break;
        case 2:
            cout << "Tus amigos son: " << endl;
            showAmigos(app);
            break;
        case 3:
            cout << "Estas personas son desconocidos (ten cuidado): " << endl;
            showDesconocidos(app);
            break;
        case 4:
            int i;
            cout << "Estos son los usuarios: " << endl;
            showUsers(app);
            cout << "Elige el perfil que deseas revisar:";
            cin >> i;
            showProfile(app, i);
            break;
        case 5:
            cout << "Quien va a realizar una publicacion? ";
            showUsers(app);
            cout << "Elige a un usuario: ";
            cin >> i;
            cout << "Titulo: ";
            cin >> title;
            cout << "Contenido: ";
            cin >> content;
            createTextPost(app, title, content, i);
            break;
        case 6:
            cout << "Quien va a realizar una publicacion? ";
            showUsers(app);
            cout << "Elige a un usuario: ";
            cin >> i;
            cout << "Titulo: ";
            cin >> title;
            cout << "Contenido: ";
            cin >> content;
            cout << "URL de la imagen";
            cin >> imageURL;
            createImagePost(app, title, content, imageURL, i);
            break;
        case 7:
            cout << "Ingresa el nombre de tu amigo: ";
            cin >> name;
            cout << "Ingresa la edad de tu amigo: ";
            cin >> age;
            cout << "Describe a tu amigo en una breve oracion: " << endl;
            cin >> description;
            addFriend(app, name, age, description);
            break;
        case 8:
            cout << "Como se llama este desconocido: ";
            cin >> name;
            cout << "Que edad tiene (si no la sabes aproximala): ";
            cin >> age;
            addUnknown(app, name, age);
            break;
        case 9:
            cout << "De quien quieres ver sus publicaciones? ";
            showUsers(app);
            cout << "Elige a un usuario: ";
            cin >> i;
            showPosts(app, i);
            break;
        case 10:
            cout << "Nos vemos pronto :D" << endl;
            continua = false;
            break;
        default:
            cout << "Opcion no valida. Por favor ingresa una opcion valida" << endl;
            break;
        }
    }
    return 0;
}

