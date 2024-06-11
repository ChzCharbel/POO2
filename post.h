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
#include "user.h"
#include "comment.h"

using namespace std;

class User;
class Comment;

class Post {
private:
    // Atibutos
    int id;
    string content;
    User* author;
    vector<Comment*> comments;

public:
    // Constructor
    Post(int id, string& content, User* author): id(id), content(content), author(author) {}

    // Metodos
    void addComment(Comment* comment){ comments.push_back(comment); }
    virtual string display() const = 0;

    // Getters
    int getId() const { return id; }
    string getContent() const { return content; }
    User* getAuthor() const { return author; }

    // Setters
    void setContent(string newContent) { content = newContent; }

    // Destructor
    virtual ~Post() {
        for (Comment* comment : comments) {
            delete comment;
        }
    }

};

class TextPost : public Post {
public:
    TextPost(int id, string& content, User* author):Post(id, content, author){}

    string display() const override {
        return "Publicacion: " + getContent() + " por " + getAuthor()->getName();
    }
};

class ImagePost : public Post {
private:
    string imageURL;

public:
    ImagePost(int id, string& content, User* author, const string& imageURL):Post(id, content, author), imageURL(imageURL) {}

    string display() const override {
        return "Publicacion (imagen): " + getContent() + " [URL: " + imageURL + "]" + " por " + getAuthor()->getName();
    }

};

#endif