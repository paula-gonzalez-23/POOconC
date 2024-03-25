#include <iostream>
#include <list>
using namespace std;

//Lista Enlazada 

struct Node {

    string data;
    Node* next;

    Node(string val): data(val), next(nullptr){}

};

//Crear la funcion que me permite insertar

void insertarInicio (Node* &head, string val){

    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
};

//funcion que muestre la lista

void imprimirLista (Node* head){
    while (head != nullptr){
        cout<<head->data<<" ";
        head = head->next;
    }

    cout<<endl;
};

int main (){

    Node* head = nullptr;

    insertarInicio(head,"Bubalu");

    cout<<"Lista Paula"<<endl;
    imprimirLista(head);

    return 0;
}

