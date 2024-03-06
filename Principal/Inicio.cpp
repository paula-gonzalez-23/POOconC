#include <iostream>
#include <Persona>
using namespace std;


class Inicio{

    Persona usuario_1;

};

int main(){

    usuario_1.pedirDatos();
    usuario_1.mostrarPersona();
    usuario_1.calcularImc();
    usuario_1.mayorEdad();

    return 0;
}