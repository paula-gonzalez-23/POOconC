#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

struct Usuario {
    string numcel;
    int clave;
};

class Nequi {

    private:

    vector<Usuario> usuarios;

    bool usuarioExiste(const string& numcel, int clave) const{
        for (const Usuario& usuario : usuarios){
            if (usuario.numcel == numcel && usuario.clave == clave){
                return true;
            }
        }
        return false;
    }

    list<pair<string, double>>Movimientos;
    vector<pair<string, vector<double>>>Bolsillos;
    double saldo = 0;

    public:

    Nequi(){

    }

    void agregarMovimiento (const string& movimiento, double monto){
        Movimientos.push_back(make_pair(movimiento, monto));
    }

    void setsaldo(double _saldo){

        saldo = _saldo;
    }

    double getsaldo(){

        return saldo;
    }

    void menu(){

        cout << "Menu" << endl;
        cout << "1. Recargar Nequi" << endl;
        cout << "2. Colchon" << endl;
        cout << "3. Meta" << endl;
        cout << "4. Bolsillos" << endl;
        cout << "5. Sacar Plata" << endl;
        cout << "6. Ver movimientos" << endl;
        cout << "7. Salir" << endl;
        cout << "Saldo disponible: " << saldo << endl;

    }

    bool llenarUsuarios(){

        usuarios.push_back({"3128991399", 1234});

        string entrada, numcel;
        int clave;

        cout << "Ingrese el numero de celular y clave (ejemplo numero de celular-clave), escriba fin para salir" << endl;
        while (true){
            getline(cin,entrada);

            if (entrada == "fin"){
                break;
            }

            size_t pos = entrada.find('-');
            if (pos == string::npos){
                cout << "Formato de entrada incorrecto. Debe ser 'numero de celular-clave'. Intente de nuevo" << endl;
                continue;
            }

            numcel = entrada.substr(0,pos);
            clave = stoi(entrada.substr(pos + 1));

            if (numcel.length() != 10){
                cout << "El numero de celular debe tener 10 digitos. Intente de nuevo" << endl;
                continue;
            }

            if (entrada.substr(pos + 1).length() != 4){
                cout << "La clave debe tener 4 digitos. Intente de nuevo" << endl;
                continue;
            }

            if (usuarioExiste(numcel,clave)){
                cout << "Acceso otorgado" << endl;
                return true;
            } else {
                cout << "El usuario no existe" << endl;
            }
        }
        return false;
    }

    void recargarNequi (){
        
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
                break;
        }
    }

    void recargarEfectivo (){

        double monto;
        string numerocel;

        cout << "Ingrese el numero de celular al que quiere recargar" << endl;
        cin >> numerocel;
        cout << "Ingrese el monto que desea recargar con efectivo" << endl;
        cin >> monto;
        saldo += monto;
        cout << "Recarga con efectivo exitosa. Saldo actual: " << saldo << endl;

        agregarMovimiento("Recarga con efectivo", monto);
    }

    void recargarOtrosBancos(){

        int opcion, opcion1, banco;
        string numerocel, renumerocel;
        double monto;

        cout << "Si deseas recargar tu nequi desde pse, seleccione una opcion" << endl;
        cout << "1. Siguiente" << endl;
        cout << "2. Salir" << endl;
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
                saldo += monto;
                cout << "Elige el tipo de persona" << endl;
                cout << "1. Natual" << endl;
                cout << "2. Juridica" << endl;
                cout << "Ingresa tu opcion" << endl;
                cin >> opcion1;
                cout << "Elige el banco desde donde deseas hacer la recarga" << endl;
                cout << "1. Banco AV Villas" << endl;
                cout << "2. Banco BBVA Colombia SA" << endl;
                cout << "3. Bancolombia" << endl;
                cout << "4. Daviplata" << endl;
                cout << "5. Rappipay" << endl;
                cout << "Ingresa tu opcion" << endl;
                cin >> banco;

                if (numerocel == renumerocel){
                    cout << "La recarga se ha realizado con exito. Saldo actual: " << saldo << endl;
                    agregarMovimiento("Recarga desde otos bancos", monto);
                }else {
                    cout << "El numero de confirmacion no coincide con el ingresado" << endl;
                    cout << "Por su seguridad vuelva a ingresar todos los datos" << endl;
                }
                break;

            case 2:
                cout << "A la proxima dale una oportunidad a Nequi" << endl; 
                break;

            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    }

    void recargarCodigo(){

        string codigo;
        double monto;

        cout << "Ingrese el codigo de regalo que obtuviste (ejemplo 'J5G67U')" << endl;
        cin >> codigo;
        cout << "Ingrese el valor" << endl;
        cin >> monto;
        saldo += monto;

        cout << "El codigo ha sido verificado en la base de datos de Nequi" << endl;
        cout << "La recarga se ha realizad con exito. Saldo actual: " << saldo << endl;
        agregarMovimiento("Recarga con codigo de reaglo", monto);
    }

    void recargarPlataAlToque(){

        string numerocel;
        int opcion;
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
                saldo += monto;

                cout << "La recarga se ha realizado con exito. Saldo actual: " << saldo << endl;
                agregarMovimiento("Recarga con plata al toque", monto);
                break;

            case 2:
                cout << "Si no tienes una cuenta en Bancolombia no puedes utilizar esta opcion para recargar, utiliza otra" << endl;
                break;

            default:
                cout << "Ingrese una opcion valida" << endl;
                break;
        }
    }

    void colchon(){

        int opcion;
        double valor; 
        double limiteColchon = 0.0;

        cout << "Bienvenido al colchon, desea activarlo?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ahora debes establecer un limite maximo de dinero que vas a reservar aqui" << endl;
                do {
                    cout << "Ingrese el valor(debe ser mayor a cero): " << endl;
                    cin >> valor;
                } while (valor <= 0);

                limiteColchon = valor;
                cout << "El colchon ha sido activado con exito. El limite maximo es: " << limiteColchon << endl;
                break;

            case 2: 
                cout << "Colchon no activado. Gracias por usar Nequi" << endl;
                break;

            default:
                cout << "Opcion no valida. Colchon no activado" << endl;
                break;
        }
    }

    void meta(){

        double valor, monto;
        string fecha;
        int opcion;

        cout << "Bienvenido a tu meta" << endl;
        cout << "Ingrese el valor de la meta" << endl;
        cin >> valor;
        cout << "Ingrese la fecha maxima que tiene para cumplir su meta" << endl;
        cin >> fecha;

        cout << "Desea empezar a abonar a su meta?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                cout << "Ingrese el monto que desea abonar" << endl;
                cin >> monto;

                cout << "Se ha abonado " << monto << "a su meta" << endl;
                agregarMovimiento("Se recargo su meta", monto);
                break;
            
            case 2:
                cout << "No se han realizado abonos a su meta" << endl;
                break;
            
            default:
                cout << "Opcion no valida." << endl;
                break;
        }
    }

    void bolsillos(){

       string nombreBolsillo;
       double valor;

       cout << "Bienvenido a tus bolsillos" << endl;
       cout << "Ingrese el nombre del bolsillo" << endl;
       cin >> nombreBolsillo;

       cout << "Ingrese el valor que desea guardar" << endl;
       cin >> valor;

       if (valor > saldo){
        cout << "Fondos insufientes" << endl;
       } else {
        saldo -= valor;
        Bolsillos.push_back({nombreBolsillo,{valor}});
        cout << "Ahora tu bolsillo " << nombreBolsillo << " guarda el valor de " << valor << endl;
        agregarMovimiento("Se guardo plata en el bolsillo", valor);
       }
        
    }

    void sacarPlata(){

        int opcion, random;
        double monto;
        srand(time(NULL));

        cout << "Ingresa la opcion que deseas realizar" << endl;
        cout << "1. Retirar desde un cajero Bancolombia" << endl;
        cout << "2. Retirar desde un punto fisico" << endl;
        cout << "Ingrese su opcion" << endl;
        cin >> opcion;

        switch (opcion){
            case 1:
                random = 100000+rand()%(999999+1-100000);

                cout << "El codigo para retirar es: " << random << endl;
                cout << "Ingrese el monto a retirar" << endl;
                cin >> monto;
                if (monto > saldo){
                    cout << "Fondos insuficientes" << endl;
                }else {
                    saldo -= monto;
                    cout << "Retiro exitoso. Saldo actual: " << saldo << endl;
                    agregarMovimiento("Se retiro por cajero", monto);
                }
                break;
            
            case 2: 
                random = 100000+rand()%(999999+1-100000);

                cout << "El codigo para retirar es: " << random << endl;
                cout << "Ingrese el monto a retirar" << endl;
                cin >> monto;
                if (monto > saldo){
                    cout << "Fondos insuficientes" << endl;
                }else {
                    saldo -= monto;
                    cout << "Retiro exitoso. Saldo actual: " << saldo << endl;
                    agregarMovimiento("Se retiro por punto fisico", monto);
                }
                break;
            
            default:
                cout << "Opcion no valida" << endl;
                break;
        }
    }

    void verMovimientos() const {
        cout << "Movimientos:" << endl;
        for (const auto& movimiento : Movimientos){
            cout << movimiento.first << ": $" << movimiento.second << endl;
        }
    }

};