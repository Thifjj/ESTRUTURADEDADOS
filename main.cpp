#include <iostream>
#include "listaEncadeada.h"
using namespace std;

int main()
{
    ListaEncadeada<int> lista;
    inicializaLista(lista);
    inicializaLista(lista);
    
    inserirElementoInicio(lista, 10);
    inserirElementoInicio(lista, 5);
    inserirElementoInicio(lista, 5);
    inserirElementoInicio(lista, 5);
    insereFinal(lista, 20);
    insereFinal(lista, 30);
    inserePosicao(lista, 15, 2);
    removePosicao(lista,0);
    cout << "Lista encadeada: ";
    exibeLista(lista);
    
    return 0;
}