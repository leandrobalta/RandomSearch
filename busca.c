#include <stdio.h>
#include <stdlib.h>

int qntd;
int qntd_buscas;

void EnfiaNoMeio(int indice_atual, int* vetor, int valor, int tamanho)
{ 
  for (int i = ; i >= indice_atual; i--)
  {
    vetor[i+1] = vetor[i]; 
  }
  
  vetor[indice_atual] = valor;
} 

void organiza(int* V, int valor, int i, int f, int tamanho)
{
  if(tamanho == 0){
    V[0] = valor;
    return;
  }

  int mediana = (i + f) / 2;

  if(valor < V[mediana] && mediana - 1 == 0){
    V[mediana-1] = valor;
    return;
  }

  if(valor > V[mediana] && mediana + 1 = qntd - 1){
    V[mediana + 1] = valor;
    return;
  }
  
  if(valor > V[mediana] && valor < V[mediana])
  {
    EnfiaNoMeio(mediana, V, valor, );
    return;
  }

  if(valor > V[mediana])
  {
    organiza(V, valor, V[mediana + 1], f);
  }
  else
  {
    organiza(V, valor, i, V[mediana - 1]);
  }


}
//devolve a posicao do vetor V em que o 
//valor_buscado estah, devolve -1 se naum encontrar
int busca_valor(int * V, int n, int valor_buscado){
  for(int i = 0; i < n; i++){
    if(V[i] == valor_buscado){
      //encontrei o valor posso terminar;
      return i;
    }
  }
  //naum achei
  return -1;
}

int main(int argc, char * argv[]){
  int n;
  int quantidade_buscas;
  
  scanf("%d %d", &n, &quantidade_buscas);
  
  //definindo uma semente para a geracao de numero aleatorio
  srand(n);
  
  int * V = (int *) malloc(n*sizeof(int));
  
  for(int i = 0; i < n; i++){
     V[i] = rand() % (2*n);
     organiza(V, V[i], 0, i, i);
  }
  
  
  int hit = 0;
  int miss = 0;
  
  for(int b = 0; b < quantidade_buscas; b++){
    int valor_buscado = rand() % (2*n);
    int res = busca_valor(V, n, valor_buscado);
    if(res != -1) {
      hit++;
    }else{
      miss++;
    }
  }
  printf("Acertos: %d Erros: %d\n", hit, miss);

  return 0;
}
