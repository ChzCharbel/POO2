/*
Clase app.h
Charbel Isaias Chavez Zavala
A01711950

La clase app, es la clase donde se guardan a los usuarios, y pueden 
crear publicaciones.
*/

#ifndef APP_H_
#define APP_H_

#include <iostream>
#include "user.h"

using namespace std;

class App
{
private:
    // Atributos
    User *users[100];
    int noUser;

public:
    // Constructor
    App() : noUser(0){};

    // Getter
    User* getUser(int i){
        return users[i];
    }

    // Metodos
    void muestraPerfil(int i);
    void creaUsuarios();
    void muestraUsuarios();
    void muestraUsuarios(string tipo);
    void agregaAmigo(string name, int age, string description);
    void agregaUnknown(string name, int age);
    void muestraPosts(int i);
};

/**
 * creaUsuarios crea ejemplos de usuarios de la red social.
 *
 * @param 
 * @return
 */
void App::creaUsuarios()
{

    users[noUser] = new Friend("Adrian", 19, "Me gusta nadar, y jugar videojuegos, estudio Ingenieria Mecanica");
    noUser++;
    users[noUser] = new Friend("Lili", 19, "Me gusta dormir y ver tiktok, estudio Tecnologias Computacionales");
    noUser++;
    users[noUser] = new Friend("Kamila", 19, "Me gusta programar y dormir, estudio ITC");
    noUser++;
    users[noUser] = new Desconocido("Juan Perez", 61);
    noUser++;
    users[noUser] = new Desconocido("Miguel Hidalgo", 34);
    noUser++;
}

/**
 * muestraPerfil muestra el perfil de un usuario.
 *
 * @param int i
 * @return
 */
void App::muestraPerfil(int i)
{
    users[i - 1]->displayProfile();
}

/**
 * muestraUsuarios muestra los usuarios de la red social.
 *
 * @param 
 * @return
 */
void App::muestraUsuarios()
{
    int num = 1;
    for (int i = 0; i < noUser; i++)
    {
        cout << num << ". " << users[i]->getName() << endl;
        num++;
    }
}

/**
 * muestraUsuarios muestra los usuarios de la red social
 * que cuentan con el mismo tipo de usuario (Amigo o Desconocido).
 * Aqui hay sobreescritura de metodos.
 * 
 * @param string tipo
 * @return
 */
void App::muestraUsuarios(string tipo)
{
    int num = 1;
    for (int i = 0; i < noUser; i++)
    {
        if (users[i]->getTipo() == tipo)
        {
            cout << num << ". " << users[i]->getName() << endl;
            num++;
        }
    }
}

/**
 * agregaAmigo agrega un amigo a la red social.
 *
 * @param string name, int age, string description
 * @return
 */
void App::agregaAmigo(string name, int age, string description)
{
    if (noUser < 100) {
        users[noUser] = new Friend(name, age, description);
        noUser++;
    } else {
        cout << "No se pueden agregar más usuarios. Límite alcanzado." << endl;
    }
}

/**
 * agregaUnknown agrega un desconocido a la red social.
 *
 * @param string name, int age
 * @return
 */
void App::agregaUnknown(string name, int age)
{
    users[noUser] = new Desconocido(name, age);
    noUser++;
}

/**
 * muestraPosts muestra los posts de un usuario.
 *
 * @param int i
 * @return
 */
void App::muestraPosts(int i){
    users[i]->showPosts();
}

#endif // APP_H_