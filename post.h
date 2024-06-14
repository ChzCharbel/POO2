/*
Clase post.h
Charbel Isaias Chavez Zavala
A01711950

Esta clase permite a los usuarios crear publicaciones dentro de la red social.
Existen dos tipos de publicaiones, publicaciones de texto y publicaciones con imagen,
para esto, existe una clase padre llamada Post y dos clases derivadas llamadas TextPost
e ImagePost
*/

#ifndef POST_H_
#define POST_H_
#include <iostream>
#include <string>

using namespace std;

class Post
{
private:
    // Atibutos
    string title;
    string content;

public:
    // Constructor
    Post(string &title, string &content) : title(title), content(content) {}

    // Metodos
    virtual string display() const = 0;

    // Getters
    string getTitle() const { return title; }
    string getContent() const {return content; }

    // Setters
    void setTitle(string newTitle) { title = newTitle; }
    void setContent(string newContent) { content = newContent; }

    // Destructor
    virtual ~Post() = default;
};

class TextPost : public Post
{
public:
    TextPost(string &title, string &content) : Post(title, content) {}

    string display() const override;
};

string TextPost::display() const {
    return getTitle() + ": " + getContent() + "\n";
}

class ImagePost : public Post
{
private:
    string imageURL;

public:
    ImagePost(string &title, string &content, const string &imageURL) : Post(title, content), imageURL(imageURL) {}

    string display() const override;
};

string ImagePost::display() const
{
    return getTitle() + ": " + getContent() + "[URL: " + imageURL + "]" + "\n";
}

#endif