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
    this->data = data;
}

Nodo *Nodo::getLink() const {
    return link;
}

void Nodo::setLink(Nodo *link) {
    this->link = link;
}

class Lista {
private:
    Nodo *head;

public:
    Lista();

    void crearLista();

    void insertarALaCabeza(int dato);

    void visualizarLista();
};

//definición de los métodos de la clase Lista
Lista::Lista() { head = NULL; }

void Lista::crearLista() {
    head = NULL;
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
    nuevo->setData(dato);
    if (head == nullptr) {
        nuevo=NULL;
    } else {
        nuevo->setLink(head);
    }
    head = nuevo;
}

void Lista::visualizarLista() {
    Nodo *temp;
    if (head == nullptr) {
        cout << "Lista vacía" << endl;
    } else {
        temp=head;
        int n = 0;//contador de nodos
        while (temp != NULL) {
            char c;
            n++;//contamos los nodos
            c = (n % 10 != 0 ? ' ' : '\n');
            cout << temp->getData() << "|" << c;
           temp= temp->getLink();
        }
    }
}


    int main() {
        Lista lista;
        lista.crearLista();
        // lista.insertarALaCabeza(10);
        lista.visualizarLista();
        return 0;
    }
