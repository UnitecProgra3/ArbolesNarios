#include <iostream>
#include <vector>

using namespace std;

class Nodo
{
public:
    int valor;
    vector<Nodo*> hijos;
    Nodo(int valor)
    {
        this->valor=valor;
    }

    void agregarHijo(Nodo* hijo)
    {
        hijos.push_back(hijo);
    }
};

void imprimir(Nodo* raiz)
{
    if(raiz!=NULL)
    {
        cout<<raiz->valor<<endl;
        for(int i=0;i<raiz->hijos.size();i++)
        {
            imprimir(raiz->hijos[i]);
        }
    }
}

int sumar(Nodo* raiz)
{
    if(raiz!=NULL)
    {
        int suma = raiz->valor;

        for(int i=0;i<raiz->hijos.size();i++)
        {
            suma+=sumar(raiz->hijos[i]);
        }

        return suma;
    }
    return 0;
}

Nodo* buscar(Nodo* raiz, int num)
{
    if(raiz!=NULL)
    {
        if(raiz->valor == num)
        {
            return raiz;
        }

        for(int i=0;i<raiz->hijos.size();i++)
        {
            Nodo* temp = buscar(raiz->hijos[i],num);
            if(temp->valor == num)
            {
                return temp;
            }
        }

    }
    return NULL;
}

int main()
{
    Nodo* n1 = new Nodo(1);
    Nodo* n2 = new Nodo(2);
    Nodo* n3 = new Nodo(3);
    Nodo* n4 = new Nodo(4);
    Nodo* n5 = new Nodo(5);
    Nodo* n6 = new Nodo(6);
    Nodo* n7 = new Nodo(7);
    Nodo* n8 = new Nodo(8);

    n1->agregarHijo(n2);
    n1->agregarHijo(n3);
    n1->agregarHijo(n4);

    n2->agregarHijo(n5);
    n2->agregarHijo(n6);

    n4->agregarHijo(n7);

    n6->agregarHijo(n8);

    imprimir(n1);

    cout<<"Suma: "<<sumar(n1)<<endl;

    cout<<"El segundo hijo del 2: "<<buscar(n1,2)->hijos[1]->valor<<endl;

    return 0;
}
