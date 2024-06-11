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
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include "comment.h"
#include "post.h"

using namespace std;

class Comment;
class Post;

class User {
private:
    // Atributos
    int id;
    string name;
    int age;
    vector<Post*> posts;
    vector<Comment*> comments;
    set<User*> friends;

public:
    // Contructores
    User(){}
    User(int id, const string& name, int age) : id(id), name(name), age(age) {}

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }

    // Metodos
    void createPost(Post* post){ posts.push_back(post); }
    
    void deletePost(Post* post){ 
        auto it = find(posts.begin(), posts.end(), post);
        if (it != posts.end()) {
                delete *it;
                posts.erase(it);
        }
    }

    void addComment(Comment* comment){ comments.push_back(comment); }
    virtual void displayProfile() const = 0;
    virtual void addFriend(User* user) { friends.insert(user); }
    virtual void removeFriend(User* user) { friends.erase(user); }

    ~User() { 
        for (Post* post : posts) {
            delete post;
        } for (Comment* comment : comments) {
            delete comment;
        }
    }
};

class Friend : public User {
private:
    // Atributos
    set<User*> friends;

public:
    // Constructor  
    Friend(int id, const string& name, int age): User(id, name, age){};

    // Funciones propias de la clase
    void addFriend(User* user) {
        cout << "Agregaste a: " << user->getName() << endl;
        friends.insert(user);
    }

    void removeFriend(User* user) {
        cout << "Eliminaste a: " << user->getName() << endl;
        friends.erase(user);
    }

    void displayProfile() const override {
        cout << "User: " << getName() << "\nAge: " << getAge() << endl;
        cout << "Friends: ";
        for (const auto& friendUser : friends) {
            cout << friendUser->getName() << " ";
        }
        cout << endl;
    }

};

class Desconocido : public User {
public:
    // Constructor  
    Desconocido(int id, const string& name, int age): User(id, name, age){};

    void displayProfile() const override {
        cout << "User: " << getName() << "\nAge: " << getAge() << endl;
        cout << "Necesitas agregar a esta persona para ver su perfil... :D" << endl;
    }
};

#endif