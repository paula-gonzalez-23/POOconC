#include <iostream>
#include "Persona.cpp"
using namespace std;

class Empleado : public Persona {

    //Atributos

    private:

    string cargo;
    int valorHora;
    int horasTrabajadas;
    string departamento;
    double honorarios;
    int fecha_nacimiento;
    int fecha_actual;

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

    void setfecha_nacimiento(int _fecha_nacimiento){

        fecha_nacimiento = _fecha_nacimiento;

    }

    int getfecha_nacimiento (){

        return fecha_nacimiento;
    }

    void setfecha_actual(int _fecha_actual){

        fecha_actual = _fecha_actual;

    }

    int getfecha_actual (){

        return fecha_actual;
    }


    //Metodos

    void calcularHonorarios(){

        honorarios = (valorHora * horasTrabajadas)-((valorHora* horasTrabajadas)*0.966/100);

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

        cout<<"Ingrese el anio actual: "<<endl;
        cin>>fecha_actual;

        cout<<"Ingrese su anio de nacimiento: "<<endl;
        cin>>fecha_nacimiento;

    }

    void mostrarPersona(){

        Persona :: mostrarPersona();

        cout<<"Su cargo es: "<<cargo<<endl;
        cout<<"Su departamento es: "<<departamento<<endl;
        cout<<"Sus horas trabajadas son: "<<horasTrabajadas<<endl;
        cout<<"El valor de la hora es: "<<valorHora<<endl;
        cout<<"El total a pagar es: "<<honorarios<<endl;

    }

    int mayorEdad(int fecha_nacimiento, int fecha_actual){

        int edad = fecha_actual - fecha_nacimiento;

        if (edad>=18){
            cout<<"Es mayor de edad"<<endl;
        }else if (edad<18){
            cout<<"Es menor de edad"<<endl;
        }
        
        return edad;
    }

};
