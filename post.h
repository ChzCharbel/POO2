/*
Clase post.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase permite a los usuarios crear publicaciones dentro de la red social
*/

#ifndef POST_H_
#define POST_H_
#include <iostream>
#include <vector>
#include <string>
#include <user.h>

using namespace std;

class Post {
private:
    // Atibutos
    int id;
    string content;
    string postDate;
    User* author;
    vector<Comment*> comments;
public:
    // Constructores
    Post(){}
    Post(int id, string& content, const string& postDate, User* author): id(id), content(content), postDate(postDate), author(author) {}

    // Destructor
    virtual ~Post() = default;

    // Metodos
    void addComment(Comment* comment);
    virtual void display() const = 0;

    // Getters
    int getId() const { return id; }
    string getContent() const { return content; }
    string getPostDate() const { return postDate; }
    User* getAuthor() const { return author; }

    // Setters
    void setId(int newId) { id = newId; }
    void setContent(string newContent) { content = newContent; }
    void setPostDate(string newPostDate) { postDate = newPostDate; }
    void setAuthor(User* newAuthor) { author = newAuthor; }

};

void Post::addComment(Comment* comment) {
    comments.push_back(comment);
}

#endif