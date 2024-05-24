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
#include <user.h>
#include <post.h>

using namespace std;

class Comment {
private:
    // Atributos
    int id;
    string content;
    string commentDate;
    User* author;
    Post* post;
public:
    // Constructores
    Comment(){}
    Comment(int id, const string& content, const string& commentDate, User* author, Post* post): id(id), content(content), commentDate(commentDate), author(author), post(post) {}

    // Metodos
    void display() const;

    // Getters
    int getId() const { return id; }
    string getContent() const { return content; }
    string getCommentDate() const { return commentDate; }
    User* getAuthor() const { return author; }
    Post* getPost() const { return post; }
};

void Comment::display() const {
    cout << author->getName() << ": " << content << endl;
}
#endif