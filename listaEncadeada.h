#include <iostream>

using namespace std;

template <typename TIPO>
struct Telemento
{
    TIPO dado;
    Telemento<TIPO> *proximo;
};

template <typename TIPO>
struct ListaEncadeada
{
    Telemento<TIPO> *inicio;
};

template <typename TIPO>
void inicializaLista(ListaEncadeada<TIPO> &lista)
{
    lista.inicio = NULL;
}

template <typename TIPO>
bool inserirElementoInicio(ListaEncadeada<TIPO> &lista, TIPO dadoInsere)
{
    Telemento<TIPO> *novo = new Telemento<TIPO>;
    novo->dado = dadoInsere;
    novo->proximo = lista.inicio;
    lista.inicio = novo;
    return true;
}

template <typename TIPO>
bool insereFinal(ListaEncadeada<TIPO> &lista, TIPO dadoInsere)
{
    Telemento<TIPO> *novo = new Telemento<TIPO>;
    novo->dado = dadoInsere;
    novo->proximo = NULL;

    if (lista.inicio == NULL)
    {
        lista.inicio = novo;
        return true;
    }
    else
    {
        Telemento<TIPO> *intermediario = lista.inicio;
        while (intermediario->proximo != NULL)
        {
            intermediario = intermediario->proximo;
        }
        intermediario->proximo = novo;
        return true;
    }
}

template <typename TIPO>
bool inserePosicao(ListaEncadeada<TIPO> &lista, TIPO dado, int posicao)
{
    if (posicao < 0)
    {
        cout << "Posição inválida!" << endl;
        return false;
    }

    Telemento<TIPO> *novo = new Telemento<TIPO>;
    novo->dado = dado;
    novo->proximo = NULL;

    if (posicao == 0)
    {
        inserirElementoInicio(lista, dado);
        return true;
    }

    Telemento<TIPO> *aux = lista.inicio;
    for (int i = 0; i < posicao - 1; i++)
    {
        if (aux == NULL || aux->proximo == NULL)
        {
            cout << "Posição inválida!" << endl;
            delete novo;
            return false;
        }
        aux = aux->proximo;
    }

    novo->proximo = aux->proximo;
    aux->proximo = novo;
    return true;
}

template <typename TIPO>
void exibeLista(const ListaEncadeada<TIPO> &lista)
{
    Telemento<TIPO> *atual = lista.inicio;
    while (atual != NULL)
    {
        cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    cout << "NULL" << endl;
}
template <typename TIPO>
void removeInicio(ListaEncadeada<TIPO> &lista)
{
    if (lista.inicio == NULL)
    {
        cout << "Lista vaiza";
    }
    else
    {
        lista.inicio = lista.inicio->proximo;
    }
}
template <typename TIPO>
void removeFinal(ListaEncadeada<TIPO> &lista)
{
    if (lista.inicio == NULL)
    {
        cout << "Lista vaiza";
    }
    else
    {
        Telemento<TIPO> *aux = lista.inicio;
        Telemento<TIPO> *aux2 = new Telemento<TIPO>;
        while (aux->proximo != NULL)
        {
            aux2 = aux;
            aux = aux->proximo;
        }
        aux2->proximo = NULL;
    }
}
template <typename TIPO>
void removePosicao(ListaEncadeada<TIPO> &lista, int posicao)
{
    if (lista.inicio == NULL)
    {
        cout << "Lista vazia" << endl;
        return;
    }

    Telemento<TIPO> *aux = lista.inicio;
    Telemento<TIPO> *anterior = nullptr;

    // Se a posição for 0, remover o primeiro elemento
    if (posicao == 0)
    {
        lista.inicio = aux->proximo; // Atualiza o início da lista
        delete aux;                  // Libera a memória do nó removido
        return;
    }

    // Percorre a lista até a posição desejada
    for (int i = 0; aux != NULL && i < posicao; i++)
    {
        anterior = aux;
        aux = aux->proximo;
    }

    // Se aux for NULL, significa que a posição era inválida
    if (aux == NULL)
    {
        cout << "Posição inválida" << endl;
        return;
    }

    // Remove o elemento e ajusta os ponteiros
    anterior->proximo = aux->proximo;
    delete aux; // Libera a memória do nó removido
};
