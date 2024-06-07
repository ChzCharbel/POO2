/*
Clase user.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase sirve para crear usuarios de una red social, con un id, email y su nombre
*/

#ifndef USER_H_
#define USER_H_
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include "comment.h"
#include "post.h"

using namespace std;

class Post;
class Comment;

class User {
private:
    // Atributos
    int id;
    string name;
    string email;
    string registrationDate;
    set<User*> friends;
    vector<Post*> posts;
    vector<Comment*> comments;

public:
    // Contructores
    User(){}
    User(int id, const string& name, const string& email, const string& registrationDate): id(id), name(name), email(email), registrationDate(registrationDate) {}

    // Metodos
    void createPost(Post* post){ posts.push_back(post); }
    void addComment(Comment* comment){ comments.push_back(comment); }
    virtual void addFriend(User* user){ friends.insert(user); }
    virtual void removeFriend(User* user){ friends.erase(user); }
    virtual void displayProfile() const { 
        cout << "User: " << name << "\nEmail: " << email << "\nFecha de Registro: " << registrationDate << endl; 
        cout << "Necesitas agregar a esta persona para ver su perfil... :D";
    }

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getRegistrationDate() const { return registrationDate; }

    // Setters
    void setId(int newId) { id = newId; }
    void setName(string newName) { name = newName; }
    void setEmail(string newEmail) { email = newEmail; }
    void setRegistrationDate(string newRegistrationDate) { registrationDate = newRegistrationDate; }

};

class Friend : public User {
private:
    // Atributos
    set<User*> friends;

public:
    // Constructor  
    Friend(int id, const string& name, const string& email, const string& registrationDate): User(id, name, email, registrationDate){};

    void addFriend(User* user) override {
        cout << "Adding a close friend: " << user->getName() << endl;
        User::addFriend(user);
    }

    void removeFriend(User* user) override {
        cout << "Removing a close friend: " << user->getName() << endl;
        User::removeFriend(user);
    }

    void displayProfile() const { 
        cout << "User: " << getName() << "\nEmail: " << getEmail(); 
        cout << "Friends: ";
        for (const auto& friendUser : friends) {
            cout << friendUser->getName() << "\n";
        }
    }

};

#endif