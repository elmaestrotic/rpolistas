#include <iostream>
using namespace std;

class Nodo {
private:
    int data;
    Nodo *link;

public:
    Nodo(int data);
    Nodo(int data, Nodo *link);
    int getData() const;
    void setData(int data);
    Nodo *getLink() const;
    void setLink(Nodo *link);
};

//Definición de métodos de la clase Nodo
Nodo::Nodo(int data) {
    this->data = data;
    this->link = NULL;
}

Nodo::Nodo(int data, Nodo *link) {
    this->data = data;
    this->link = link;
}

int Nodo::getData() const {
    return data;
}

void Nodo::setData(int data) {
    Nodo::data = data;
}

Nodo *Nodo::getLink() const {
    return link;
}

void Nodo::setLink(Nodo *link) {
    Nodo::link = link;
}

class Lista {
private:
    Nodo *head;

public:
    void crearLista();
    void insertarALaCabeza(int dato);
    void visualizarLista();
};
//definición de los métodos de la clase Lista

void Lista::crearLista() {
    head = nullptr;
    int datoentrada;
    cout << "Ingrese un entero o -1 para terminar: " << endl;
    do {
        cin >> datoentrada;
        if (datoentrada != -1) {
            head = new Nodo(datoentrada, head);
        }
    } while (datoentrada != -1);
}

void Lista::insertarALaCabeza(int dato) {
    Nodo *nuevo;
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
    } else {

        nuevo->setData(dato);
        nuevo->setLink(head);
    }
    head = nuevo;
}

void Lista::visualizarLista() {
    int n = 0;//contador de nodos
    Nodo *temp;
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
    } else {
        temp=head;
        while (temp != NULL) {
            char c;
            c++;
            c = (c % 10 != 0 ? ' ' : '\n');
            cout << temp->getData() << "|" <<c;
            temp->getLink();

        }

    }

}

int main() {
    Lista lista;
    lista.crearLista();
    lista.insertarALaCabeza(10);
    lista.visualizarLista();
    return 0;
}
