#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<int> pilha; // construtor da pilha
    stack<int> pilha2(pilha); // construtor de cópia
    stack<int> pilha3; // construtor da pilha

    for (int i = 0; i < 10; i++)
    {
        pilha.push(i); // insere no topo da pilha
    }

    cout << pilha.size(); // retorna o tamanho da pilha
    pilha.swap(pilha3); // troca o conteúdo de duas pilhas

    while (!pilha.empty()) // verifica se a pilha está vazia
    {
        cout << pilha.top() << endl; // acessa o elemento do topo da pilha
        pilha.pop(); // remove o elemento do topo da pilha
    }
    
    return 0;
}