/*
Clase comment.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase permite a los usuarios agregar comentarios a las publicaciones de otror usuarios
*/

#ifndef COMMENT_H_
#define COMMENT_H_
#include <iostream>
#include <string>
#include "user.h"
#include "post.h"

using namespace std;

class User;
class Post;

class Comment {
private:
    // Atributos
    int id;
    string content; 
    string commentDate;
    User* author;
    Post* post;

public:
    // Constructor
    Comment(int id, const string& content, User* author, Post* post): id(id), content(content), author(author), post(post) {}

    // Metodos
    void display() const{ cout << author->getName() << ": " << content << endl; }

    // Getters
    int getId() const { return id; }
    string getContent() const { return content; }
    User* getAuthor() const { return author; }
    Post* getPost() const { return post; }

    ~Comment() = default;
};

#endif