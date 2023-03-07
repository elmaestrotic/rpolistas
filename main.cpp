#include <iostream>
using namespace std;

class Nodo {
private:
int data;
Nodo *link;
public:
Nodo(int data);
Nodo(int data, Nodo*link);
int getData() const;
Nodo* getLink() const;

void setData(int dato);
void setLink(Nodo* link);
};//fin de la class Nodo
//Defininimos los métodos de la clase Nodo
Nodo::Nodo(int data) {
    this->data=data;
    this->link= 0;
}
Nodo::Nodo(int data, Nodo* link) {
    this->data=data;
    this->link= link;
}

int Nodo::getData() const {
    return this->data;
}

Nodo* Nodo::getLink() const {
    return this->link;
}

void Nodo::setData(int dato) {
    data=dato;
}


void Nodo::setLink(Nodo *link) {
    this->link=link;
}

class Lista{
private:
    Nodo* head;

public:
    Lista();
    void crearLista();
    void visualizarLista();
    void insertarAlaCabeza(int dato);
};
//Definimos métodos de la clase Lista
Lista::Lista() {head= NULL;}

void Lista::crearLista() {
    int dato;
   cout << "Ingrese enteros o -1 para terminar"<<endl;
    do{
       cin>> dato;
       if (dato != -1){
           this->head=new Nodo(dato,head);
       }
    }while(dato !=-1);
}
void Lista::visualizarLista() {
    int n;//contador de nodos
    Nodo *temp;
    if (head == nullptr) {
        cout << "La lista está vacía " << endl;
    } else {
        temp = head;
        while (temp != NULL) {
            char c;
            c = (n % 10 != 0 ? ' ' : '\n');
            n++;
            cout << temp->getData() << "|" << c;
            temp = temp->getLink();
        }
    }
}
  void Lista::insertarAlaCabeza(int dato){
    Nodo *nuevo ;
    nuevo = new Nodo(dato);
    nuevo->setLink(head); // enlaza nuevo nodo al frente de la lista
   head= nuevo; // mueve primero y apunta al nuevo nodo
}


int main() {
    Lista lista;
    lista.crearLista();
    lista.insertarAlaCabeza(8);
    lista.visualizarLista();
    return 0;
}
