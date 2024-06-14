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

    // Metodo virtual puro
    virtual void display() const = 0;

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
    // constructor
    TextPost(string &title, string &content) : Post(title, content) {}

    // metodo display con sobrecarga
    void display() const override;
};

/**
 * display muestra el contenido y atributos de una publicacion que contiene solamente texto.
 *
 * devuelve un string con los valores y texto concatenado.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
void TextPost::display() const {
    cout << getTitle() << ": " << getContent() << "\n";
}

class ImagePost : public Post
{
private:
    // atributo
    string imageURL;

public:
    // constructor
    ImagePost(string &title, string &content, const string &imageURL) : Post(title, content), imageURL(imageURL) {}

    // metodo display con sobrecarga
    void display() const override;
};

/**
 * display muestra el contenido y atributos de una publicacion que contiene una imagen.
 *
 * devuelve un string con los valores y texto concatenado.
 *
 * @param
 * @return string con los valores y texto concatenado.
 */
void ImagePost::display() const
{
    cout << getTitle() << ": " << getContent() << ". [URL: " << imageURL << "]" << "\n";
}

#endif