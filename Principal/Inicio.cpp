#include <iostream>
#include "../Salud/Persona.cpp"
using namespace std;


class Inicio{

    Persona usuario;

};

int main(){

    Persona usuario;

    usuario.pedirDatos();
    usuario.mostrarPersona();
    usuario.calcularImc();
    usuario.mayorEdad();

    return 0;
}