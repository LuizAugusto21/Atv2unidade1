#include "function.hpp"
#include<iostream>
#include <cstring>

using namespace std;
//construtor musica
Musica::Musica(){
  this->artista = "DEFAULT";
  this->titulo = "DEFAULT";

}
//destrutor musica
Musica::~Musica(){
}
//construtor lista
lista::lista(){
    this->head = NULL;
    this->tail = NULL;  
};
//destrutor lista
lista::~lista(){};


void playheader(){
  cout<<'\n';
  cout<<"*-----Escolha uma das opções abaixo-----*"<<"\n\n\n";

  cout<<"1 - Adicionar uma música"<<endl;
  cout<<"2 - Remover uma música de uma playlist"<<endl;
  cout<<"3 - Procurar uma música/artista em uma playlist"<<endl;
  cout<<"4 - Listar playlist"<<endl;
  cout<<"5 - Listar todas as musicas do sistema"<<endl;
  cout<<"6 - Remover musicas do sistema"<<endl;
  cout<<"7 - exibir proxima musica a tocar em uma playlist"<<endl;
  cout<<"8 - Mover musica entre playlists"<<endl;
  cout<<"0 - Sair"<<"\n\n";

}
//cria um novo nó(representando a música) em uma playlist
void lista::insert(std::string titulo, std::string artista){
  node *temp=new node;

  temp->faixa.titulo=titulo;
  temp->faixa.artista=artista;
  temp->next=NULL;
  if(head==NULL)
  {
    head=temp;
    tail=temp;
    temp=NULL;
  }
  else
  {	
    tail->next=temp;
    tail=temp;
  } 

}

//remove músicas de uma playlist, seja ela no inicio meio e fim
void lista::remove(std::string pesquisa){

  node *atual=new node;
  node *anterior=new node;
  atual = head;


  if(atual->faixa.titulo==pesquisa)
  {
    atual=head;
    head=head->next;
    delete atual;
    
  }
  else{
    while(atual!=NULL){

      if(atual->faixa.titulo==pesquisa){

        anterior->next=atual->next;
        break;
      }
      anterior=atual;
      atual=atual->next;
    }
    if(atual==NULL && atual->faixa.titulo==pesquisa){

      tail=anterior;
      anterior->next=NULL;
      delete atual;
    }
  }
}


//exibe todas as músicas em uma playlist
void lista::exibir(){
    
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      
      cout<<temp->faixa.titulo<<" ---- ";
      cout<<temp->faixa.artista<<endl;
      temp=temp->next;
    }
  }
/*busca uma música ou todas as músicas de um artista em uma playlist, se 
houver a música ou o artista desejado ele imprime, se houver várias músicas
do mesmo artista, imprime todas*/
void lista::buscar(std::string pesquisa){

    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
      if(pesquisa==temp->faixa.titulo){

      cout<<temp->faixa.titulo<<" ---- ";
      cout<<temp->faixa.artista<<endl;
      }
      else if (pesquisa==temp->faixa.artista){
      
      cout<<temp->faixa.titulo<<" ---- ";
      cout<<temp->faixa.artista<<endl;

      }
      temp=temp->next;
    }
}
//Procura se a lista(playlist) tem o objeto requerido, se tiver, ele remove com a função lista::remove()
void lista::system_remove(string pesquisa, lista v){
  node *temp=new node;
  int i=0;
  temp=head;
  while(temp!=NULL){
    if(pesquisa==temp->faixa.titulo)
    {
      v.remove(pesquisa);
      
    }
    temp=temp->next;
    i++;
  }

}
//printa a próxima musica a ser tocada
void lista::toca(lista v){

  node *temp=new node;
  temp = head;

  if(v.indice==0){
    cout<<temp->faixa.titulo<<endl;
  }
  else{
    for(int i=0; i<(v.indice-1); i++){
      temp=temp->next;
    }
    cout<<temp->faixa.titulo<<endl;
  }
}
/*procura o objeto desejado na primeira playlist e copia na segunda e depois exclui na primeira*/
void lista::move(std::string pesquisa, lista playlist1, lista playlist2){
    node *temp=new node;

    temp=playlist1.head;

    while(temp!=NULL){
      if(temp->faixa.titulo==pesquisa){
        playlist2.insert(temp->faixa.titulo, temp->faixa.artista);
        playlist1.remove(pesquisa);
        break;
      }
      temp=temp->next;
    }
}

//procura playlists no sistema e retorna sua posição
int busca_playlist(string pesquisa, int n, lista v[]){
  int i;
  for(i=0; i<n; i++){

    if(v[i].nome==pesquisa){
      //cout<<i<<endl;
      return i;
    }
  }
  if(i==n-1){
    cout<<"não existe playlist com esse nome"<<endl;
  }
    
  
  return 0;
}
//pega informações do usuário para implementar a função de busca
int troca_playlist(int n, lista v[]){

  string pesquisa;
  cout<<"Nome da playlist:"<<endl;
  getline(cin, pesquisa);
  cout<<"\n"<<endl;
  n = busca_playlist(pesquisa, n, v);

  return n;

}
