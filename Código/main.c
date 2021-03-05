#include <stdio.h>
#define TAM 5
#define BAIXO 5

void troca(int estoque[TAM], int tipoX, int tipoY, int qtde){
	estoque[tipoX] += qtde;
	estoque[tipoY] -= qtde;
}

void comprar(int estoque[TAM]){
	int i;
	for(i=0; i < TAM; i++){
		if(estoque[i] < BAIXO){
			printf("Comprar %d unidades do tipo %d\n",(BAIXO-estoque[i]),i);
		}
	}
}

int main(){
	int i, j, estoque[TAM];
	int tipoX,tipoY,qtde;
	for(i=0;i<TAM;i++){//carregar estoque de tamanho TAM
            printf("Digite o numero de unidades do tipo %d\n",i);
            scanf("%d",&estoque[i]);
	}

	for(i=0; i < TAM; i++){
            for(j=0; j<TAM; j++){
                if(estoque[i]<BAIXO){// verificar se TIPO i esta com estoque baixo
                    tipoX = i;;// se SIM: trocar por um TIPO j que estiver em alta
                    if(estoque[j]>TAM){
                        tipoY = j;
                        qtde = estoque[j] - BAIXO;
                        troca(estoque,tipoX,tipoY,qtde);
                    }
                }
            }
    	}

	comprar(estoque);

	return 0;
}
