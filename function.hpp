#ifndef function_hpp
#define function_hpp
#include <iostream>

using namespace std;
//Musica
class Musica{
  private:
  public:
    string titulo;
    string artista;
    Musica();
    ~Musica();
};

//nó da lista
typedef struct node
{
  Musica faixa;
  node *next;
} node;

class lista{
  private:
  node *head, *tail;
  public:
  lista();
  ~lista();
  string nome;
  int indice=-1; //utilizado para ver qual musica a ser tocada
  void insert(string titulo, string artista);
  void remove(string pesquisa);
  void buscar(string pesquisa);
  void system_remove(string titulo, lista v);
  void toca(lista v);
  void move(string pesquisa, lista playlist1, lista playlist2);
  void exibir();
};


//funções sem classe
void playheader();
int busca_playlist(string pesquisa, int n, lista v[]);
int troca_playlist(int n, lista v[]);

#endif // function_hpp