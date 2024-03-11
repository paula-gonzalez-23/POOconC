#include <iostream>
#include "../Salud/Persona.cpp"
using namespace std;

class Empleado : private Persona {

    //Atributos

    private:

    string cargo;
    int valorHora;
    int horasTrabajadas;
    string departamento;
    double honorarios;

    public:

    //Constructor 

    Empleado (){

    }

    //Accesores set para modificar y get para mostrar 

    void setcargo(string _cargo){

        cargo = _cargo;

    }

    string getcargo (){

        return cargo;

    }

    void setvalorHora(int _valorHora){

        valorHora = _valorHora;

    }

    int getvalorHora (){

        return valorHora;

    }

    void sethorasTrabajadas(int _horasTrabajadas){

        horasTrabajadas = _horasTrabajadas;

    }

    int gethorasTrabajadas (){

        return horasTrabajadas;

    }

    void setdepartamento(string _departamento){

        departamento = _departamento;

    }

    string getdepartamento (){

        return departamento;
    }

    //Metodos

    double calcularHonorarios(){

        double reteica = 0.00966;

        honorarios = horasTrabajadas * valorHora - (horasTrabajadas * valorHora * reteica);

        return honorarios;

    }

    void pedirDatos(){

        Persona :: pedirDatos();

        cout<<"Ingrese el cargo: "<<endl;
        cin>>cargo;

        cout<<"Ingrese el departamento: "<<endl;
        cin>>departamento;

        cout<<"Ingrese el valor por hora: "<<endl;
        cin>>valorHora;

        cout<<"Ingrese las horas trabajadas: "<<endl;
        cin>>horasTrabajadas;

    }

    void imprimirDatos(){

        cout<<"Nombre: "<<getnombre()<<endl;
        cout<<"Apellido: "<<getapellido()<<endl;
        cout<<"Cargo: "<<cargo<<endl;
        cout<<"Horas Trabajadas: "<<horasTrabajadas<<endl;
        cout<<"Valor por hora: "<<valorHora<<endl;
        cout<<"Total a pagar: "<<honorarios<<endl;

    }


};

int main (){

    Empleado usuario1;

    usuario1.pedirDatos();
    usuario1.imprimirDatos();
    usuario1.calcularHonorarios();

    return 0;
    
}