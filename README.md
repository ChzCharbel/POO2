# TC1030 Proyecto Charbel Chavez A01711950
Este proyecto fue realizado como parte de la materia TC1030. Programacion Orientada a Objetos
Es una simulacion de una red social, donde los usuarios pueden crear publicaciones, de igual forma, se pueden crear nuevos usuarios, asi como agregar amigos o usuarios normales (desconocidos).

## Funcionalidad
El programa permite crear usuarios nuevos, atribuyendoles la caracteristica de ser amigos o desconocidos, donde de esto dependera el tipo de perfil que se muestre cuando se acceda a ellos, de igual forma, todos los usuarios, pueden crear publicaciones que incluyan solo texto o que incluyan imagenes, en este caso, la imagen se representa con una url.
Primeramente, se imprime un menu con todas las funciones de la aplicacion, y permite al usuario elegir lo que el desea hacer.
El programa termina cuando el usuario elige la opcion salir, o cuando durante una funcion, ingresa un parametro equivocado, por ejemplo, un caracter cuando se solicita un entero.
Para poder ejecutar la opcion 9, es necesario que el usuario elegido haya creado algun post antes.

## Consideraciones
El programa solo corre en la consola y esta hecho con c++ standard por lo que corre en todos los sistemas operativos

compilar con:
    "g++ post.h user.h app.h main.cpp"
    
 correr en linux:
      "/a.out"
      
 correr en windows:
      "a.exe"
