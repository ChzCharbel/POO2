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
#include <comment.h>
#include <post.h>

using namespace std;

class User {
private:
    // Atributos
    int id;
    string name;
    string email;
    string registrationDate;
    vector<Post*> posts;
    vector<Comment*> comments;

public:
    // Contructores
    User(){}
    User(int id, const string& name, const string& email, const string& registrationDate): id(id), name(name), email(email), registrationDate(registrationDate) {}

    // Metodos
    void createPost(Post* post);
    void addComment(Comment* comment);

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
void User::createPost(Post* post){
    posts.push_back(post);
}

void User::addComment(Comment* comment){
    comments.push_back(comment);
}

#endif