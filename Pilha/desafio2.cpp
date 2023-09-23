#include <iostream>
#include <stack>

using namespace std;

int main(){

    int n;
    cin >> n;
    int numero[n];
    for (int i = 0; i < n; i++)
    {
        cin >> numero[i];
    }
    
    stack<int> pilha_impar;
    stack<int> pilha_par;

    for (int i = 0; i < n; i++) {
        if (numero[i] % 2 == 1) {
            pilha_impar.push(numero[i]);
        } else {
            pilha_par.push(numero[i]);
        }
    }

    cout << "Par" << endl;

    while (!pilha_par.empty())
    {
        cout << pilha_par.top() << " ";
        pilha_par.pop();
    }

    cout << endl << "Impar";

    while (!pilha_impar.empty())
    {
        cout << pilha_impar.top() << " ";
        pilha_impar.pop();
    }
    

    return 0;
}