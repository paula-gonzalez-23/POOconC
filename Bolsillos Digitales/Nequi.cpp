#include <iostream>
#include <list>
using namespace std;

class Nequi {

    //Atributos

    private:

    list<pair<string, int>>Usuarios;
    list<pair<string, int>>Movimientos;
    double saldo = 0;

    public:

    Nequi(){

    }

    //Metodos set para modificar y get para mostrar

    void agregarUsuario (const pair<string, int>& usuario){
        Usuarios.push_back(usuario);
    }

    const list<pair<string, int>>& getUsuarios() const{
        return Usuarios;
    }

    void agregarMovimiento (const pair<string, int>& movimiento){
        Movimientos.push_back(movimiento);
    }

    const list<pair<string, int>>& getMovimientos() const{
        return Movimientos;
    }

    void setsaldo(double _saldo){

        saldo = _saldo;
    }

    double getsaldo(){

        return saldo;
    }

    //Funciones

    void menu(){

        cout << "Bienvenido a Nequi" << endl;
        cout << "Menu" << endl;
        cout << "1. Recargar Nequi" << endl;
        cout << "2. Colchon" << endl;
        cout << "3. Meta" << endl;
        cout << "4. Bolsillos" << endl;
        cout << "5. Ver movimientos" << endl;
        cout << "6. Salir" << endl;

    }

    void llenarUsuarios(){
        string usuario;
        int clave;
        cout << "Ingrese el usuario y clave (ejemplo: usuario - clave), escriba 0 para salir" << endl;
        while (true){
            getline (cin, usuario);
            if (usuario == "0"){
                break;
            }
            size_t pos = usuario.find("-");
            if (pos != string::npos){
                string nombreUsuario = usuario.substr(0, pos);
                clave = stoi(usuario.substr(pos +1));
                agregarUsuario(make_pair(nombreUsuario, clave));
            }else {
                cout << "Formato de entrada incorrecto. Recuerda que dede ir (usuario - clave)" << endl;
            }
        }
    }

    void recargaNequi (){
        
        int opcion;

        cout << "Seleccione una opcion para recargar saldo en nequi" <<endl;
        cout << "1. Recargar con efectivo" << endl;
        cout << "2. Recargar desde otros bancos" << endl;
        cout << "3. Recargar con codigo" << endl;
        cout << "4. Recargar desde la app" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                recargarEfectivo();
                break;
            case 2: 
                recargarOtrosBancos();
                break;
            case 3:
                recargarCodigo();
                break;
            case 4:
                recargarPlataAlToque();
                break;
            default:
                cout << "Opcion no valida" << endl;
        }
    }

    void recargarEfectivo (){

        double monto;
        int numerocel;

        cout << "Ingrese el numero de celular al que quiere recargar" << endl;\
        cin >> numerocel;
        cout << "Ingrese el monto que desea recargar con efectivo" << endl;
        cin >> monto;
        cout << "Recarga con efectivo exitosa. Saldo actual" << endl;
    }

    void recargarOtrosBancos(){

        int opcion, opcion1;
        int numerocel, renumerocel;
        double monto;

        cout << "Si deseas recargar tu nequi desde pse, seleccione una opcion" << endl;
        cout << "1. Siguiente" << endl;
        cout << "2. Volver al menu" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ingrese el numero de celular" << endl;
                cin >> numerocel;
                cout << "Confirma el numero de ceular" << endl;
                cin >> renumerocel;
                cout << "Ingresa la cantidad que deseas recargar" << endl;
                cin >> monto;
                cout << "Elige el tipo de persona" << endl;
                cout << "1. Natual" << endl;
                cout << "2. Juridica" << endl;
                cin >> opcion1;
                cout << "Elige el banco desde donde deseas hacer la recarga" << endl;
                cout << "1. Banco AV Villas" << endl;
                cout << "2. Banco BBVA Colombia SA" << endl;
                cout << "3. Bancolombia" << endl;
                cout << "4. Daviplata" << endl;
                cout << "5. Rappipay" << endl;

                if (numerocel == renumerocel){
                    cout << "La recarga se ha realizado con exito. Saldo actual: " << endl;
                }else {
                    cout << "El numero de confirmacion no coincide con el ingresado" << endl;
                    cout << "Por su seguridad vuelva a ingresar todos los datos" << endl;
                }

            case 2:
                menu();

            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    }

    void recargarCodigo(){

        char codigo;
        double monto;

        cout << "Ingrese el codigo de regalo que obtuviste" << endl;
        cin >> codigo;
        cout << "Ingrese el valor" << endl;
        cin >> monto;

        cout << "El codigo ha sido verificado en la base de datos de Nequi" << endl;
        cout << "La recarga se ha realizad con exito. Saldo actual: " << endl;
    }

    void recargarPlataAlToque(){

        int numerocel, opcion;
        double monto;

        cout << "Esta seguro que tiene una cuenta en Bancolombia" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Ingrese una opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ingrese su numero de celular que tiene nequi" << endl;
                cin >> numerocel;
                cout << "Ingrese el valor que desea recargar" << endl;
                cin >> monto;

                cout << "La recarga se ha realizado con exito. Saldo actual: " << endl;

            case 2:
                cout << "Si no tienes una cuenta en Bancolombia no puedes utilizar esta opcion para recargar, utiliza otra" << endl;

            default:
                cout << "Ingrese una opcion valida" << endl;
        }
    }
};

int main (){

    Nequi user;

    user.llenarUsuarios();
    user.menu();
    user.recargaNequi();

    return 0;
}