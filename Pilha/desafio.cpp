#include <iostream>
#include <stack>

using namespace std;

int main(){

    stack<string> pilha; // construtor da pilha

    int aux = 0;
    while (true)
    {
        aux++;
        if (aux > 2){
            aux--;
        }
        if(aux == 1){
            cout << "Para sair do programa digite exit\n";
        }
        cout << "Digite a sequencia: ";
        string nome;
        cin >> nome;
        pilha.push(nome); // insere no topo da pilha
        for (int i = 0; i < pilha.size(); i++)
        {
            if(pilha.top() == "("){
                pilha.pop();
            }
        }
        if(nome == "exit"){
            pilha.pop(); // remove o exit do programa
            break; // sai do loop
        }
    }
    while (!pilha.empty()) // verifica se a pilha está vazia
    {
        cout << pilha.top() << endl; // acessa o elemento do topo da pilha
        pilha.pop(); // remove o elemento do topo da pilha
    }
    return 0;
}