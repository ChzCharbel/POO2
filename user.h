/*
Clase user.h
Charbel Isaias Chavez Zavala
A01711950

La clase user es una clase abstracta, que hereda para Friend y Desconocido, 
permite crear usuarios de una red social.
*/

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include "post.h"

using namespace std;

class User {
protected:
    // Atributos
    string name;
    int age;
    string tipo;
    Post* posts[100];
    int noPost;

public:
    // Contructores
    User(){}
    User(const string& name, int age, string tipo) : name(name), age(age), tipo(tipo), noPost(0) {}

    // Getters
    string getName() const { return name; }
    int getAge() const { return age; }
    string getTipo() const { return tipo; }

    // Metodos
    void showPosts();
    void creaTextPost(string& title, string& content);
    void creaImagePost(string& title, string& content, const string& imageURL);
    virtual void displayProfile() const = 0;
    virtual ~User() = default;
};

void User::showPosts(){
    for (auto post : posts){
        post->display();
    }
}

void User::creaTextPost(string& content, string& date){
    posts[noPost] = new TextPost(content, date);
    noPost++;
}

void User::creaImagePost(string& content, string& date, const string& imageURL){
    posts[noPost] = new ImagePost(content, date, imageURL);
    noPost++;
}

class Friend : public User{
private:
    string description;
public:
    // Constructor  
    Friend(const string& name, int age, string description): User(name, age, "Amigo"), description(description){};

    // Getters
    string getDescription() { return description; }

    // Setters
    void setDescription(string newDescription) { description = newDescription; }

    // Metodos
    void displayProfile() const;

};

void Friend::displayProfile() const {
    cout << "User: " << name << "\nAge: " << age << endl;
    cout << "Description: " << description << endl;
}

class Desconocido : public User {
public:
    // Constructor  
    Desconocido(const string& name, int age): User(name, age, "Desconocido"){};

    //Metodo
    void displayProfile() const;
};

void Desconocido::displayProfile() const {
    cout << "User: " << name << "\nAge: " << age << endl;
    cout << "Necesitas agregar a esta persona para ver su perfil... :D" << endl;
}

#endif