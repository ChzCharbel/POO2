#include <iostream>
#include <vector>
#include <string>
#include "user.h"
#include "post.h"
#include "comment.h"

using namespace std;

int main() {
    vector<User*> users;

    // Crear usuarios
    User* friendUser = new Friend(1, "Emiliano", 19);
    User* unknownUser = new Desconocido(2, "Kamila", 19);

    users.push_back(friendUser);
    users.push_back(unknownUser);

    // Crear un post de texto
    string postContent = "Hola a todos :D";
    Post* post1 = new TextPost(1, postContent, friendUser);
    friendUser->createPost(post1);

    // Crear un comentario
    string commentContent = "Holaaaa 8)";
    Comment* comment1 = new Comment(1, commentContent, unknownUser, post1);
    post1->addComment(comment1);
    unknownUser->addComment(comment1);

    // Mostrar perfiles
    cout << "Perfiles de usuarios:" << endl;
    for (const auto& user : users) {
        user->displayProfile();
        cout << endl;
    }

    // Mostrar posts
    cout << "\nMostrando posts:" << endl;
    cout << post1->display() << endl;

    // Mostrar comentarios del post
    cout << "\nMostrando comentarios del post:" << endl;
    comment1->display();

    // Limpiar memoria
    for (User* user : users) {
        delete user;
    }

    return 0;
}

