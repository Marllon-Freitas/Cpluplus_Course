/*
Escreva um programa que mantenha registro de doações feitas a uma instituição
de caridade. Ele deve perguntar ao usuário o número de contribuintes e então
solicitar o nome e valor doado por cada pessoa. Estas informações devem ser
armazenadas em um vetor dinâmico de registros. Após ler todos os valores, o
programa deve mostrar o nome e quantia doada por todos os contribuintes que
doaram R$10000 ou mais. Esta lista deve ser intitulada de “Grandes Patronos”. Em
seguida o programa deve listar os doadores remanescentes intitulando-os apenas
de “Patronos”.

Digite o número de contribuintes: 4
#1
Nome : José Silva
Valor: 22000
#2
Nome : Carlos Bezerra
Valor: 200
#3
Nome : Antônio Souza
Valor: 10000
#4
Nome : Pedro Neto
Valor: 3000
Grandes Patronos
José Silva 22000
Antônio Souza 10000
Patronos
Carlos Bezerra 200
Pedro Neto 3000

Se não existir doadores em uma das categorias, o programa deve exibir a palavra
“nenhum”. Não é preciso fazer a ordenação das doações, basta exibi-las em duas
categorias.
*/

#include <iostream>
using namespace std;

struct contribuinte
{
  char nome[30];
  int valorDoado;
};

int main()
{
  int tamanhoVetor = 0;
  bool temGrandePatronos = false, temPatronos = false;
  cout << "Digite o número de contribuintes: ";
  cin >> tamanhoVetor;
  contribuinte *doadores = new contribuinte[tamanhoVetor];

  for (int i = 0; i < tamanhoVetor; i++)
  {
    cout << "#" << i + 1 << endl;
    cout << "Nome : ";
    cin.ignore();
    cin.getline(doadores[i].nome, 30);
    cout << "Valor : ";
    cin >> doadores[i].valorDoado;
  }

  cout << "Grandes Patronos" << endl;
  for (int i = 0; i < tamanhoVetor; i++)
  {
    if (doadores[i].valorDoado >= 10000)
    {
      temGrandePatronos = true;
      cout << doadores[i].nome << " " << doadores[i].valorDoado << endl;
    }
  }

  if (!temGrandePatronos)
  {
    cout << "nenhum" << endl;
  }

  cout << "Patronos" << endl;
  for (int i = 0; i < tamanhoVetor; i++)
  {
    if (doadores[i].valorDoado < 10000)
    {
      temPatronos = true;
      cout << doadores[i].nome << " " << doadores[i].valorDoado << endl;
    }
  }

  if (!temPatronos)
  {
    cout << "nenhum" << endl;
  }

  delete[] doadores;
  return 0;
}