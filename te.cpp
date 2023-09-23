#include <iostream>
#include <fstream>

using namespace std;

struct No {
  double coeficiente;
  No* proximo;
};

class ListaEncadeada {
public:
  ListaEncadeada() : primeiro(nullptr) {}

  void adicionar(double coeficiente) {
    No* novo = new No();
    novo->coeficiente = coeficiente;
    novo->proximo = primeiro;
    primeiro = novo;
  }

  int grau() const {
    if (primeiro == nullptr) {
      return -1;
    }

    int grau = 0;
    No* atual = primeiro;
    while (atual != nullptr) {
      grau++;
      atual = atual->proximo;
    }
    return grau;
  }

  double operator()(double x) const {
    double p = 0;
    No* atual = primeiro;
    while (atual != nullptr) {
      p += atual->coeficiente * pow(x, atual->coeficiente);
      atual = atual->proximo;
    }
    return p;
  }

private:
  No* primeiro;
};

int main() {
  ifstream arquivo("entrada.txt");
  if (!arquivo.is_open()) {
    cerr << "Erro ao abrir o arquivo" << endl;
    return 1;
  }

  ListaEncadeada polinomio;
  string linha;
  while (getline(arquivo, linha)) {
    linha = linha.strip();

    if (linha.startswith("+")) {
      // Adicionar dois polinômios
      ListaEncadeada p1, p2;
      p1 = ler_polinomio(arquivo);
      p2 = ler_polinomio(arquivo);
      polinomio = p1 + p2;
    } else if (linha.startswith("grau")) {
      // Obter o grau de um polinômio
      polinomio = ler_polinomio(arquivo);
      cout << polinomio.grau() << endl;
    } else if (linha.startswith("exibe")) {
      // Exibir a representação textual de um polinômio
      polinomio = ler_polinomio(arquivo);
      cout << polinomio << endl;
    } else {
      // Avaliar um polinômio em um ponto
      polinomio = ler_polinomio(arquivo);
      double x = stod(linha);
      cout << polinomio(x) << endl;
    }
  }

  arquivo.close();
  return 0;
}

ListaEncadeada ler_polinomio(ifstream& arquivo) {
  string linha;
  getline(arquivo, linha);

  // Ignorar comentários
  while (linha.startswith("//")) {
    getline(arquivo, linha);
  }

  // Ignorar linhas em branco
  if (linha.empty()) {
    return ListaEncadeada();
  }

  // Separar os coeficientes do polinômio
  ListaEncadeada polinomio;
  for (char c : linha) {
    if (c == 'x') {
      continue;
    }

    // Ignorar espaços
    while (c == ' ') {
      c = arquivo.get();
    }

    // Adicionar o coeficiente ao polinômio
    polinomio.adicionar(stod(string(1, c)));
  }

  return polinomio;
}