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
    // Constructor
    Post(int id, string& content, const string& postDate, User* author): id(id), content(content), postDate(postDate), author(author) {}

    // Destructor
    virtual ~Post() = default;

    // Metodos
    void addComment(Comment* comment){
        comments.push_back(comment);
    };
    virtual string display() const = 0;

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

class TextPost : public Post {
public:
    TextPost(int id, string& content, const string& postDate, User* author):Post(id, content, postDate, author){}

    string display() const override {
        return "Text Post: " + getContent() + " by " + getAuthor()->getName();
    }
};

class ImagePost : public Post {
private:
    string imageURL;

public:
    ImagePost(int id, string& content, const string& postDate, User* author, const string& imageURL):Post(id, content, postDate, author), imageURL(imageURL) {}

    string display() const override {
        return "Image Post: " + getContent() + " [Image URL: " + imageURL + "]";
    }

};

#endif