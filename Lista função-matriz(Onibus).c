#include<stdio.h>
#include <stdlib.h>

//Código construido usando alocação dinâmica e ponteiros para que os lugares comprados ou vazios pudessem ser gravados;
//Ultilizo também Matriz e função ao mesmo tempo;

int escolherLugar(), MapaDeAssentos(int (*aCorredor)[], int (*aJanela)[]);
int Janela(int (*aJanela)[]), Corredor(int (*aCorredor)[]);
int aCorredor[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int aJanela[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int main(){
    int resp1;


    printf("\n\tBEM VINDO AO ARTUR PASSAGENS\n\t\tVOCE DESEJA\n");
    printf("\n\t[1] COMPRAR PASSAGEM");
    printf("\n\t[2] VER MAPA DE ASSENTOS");
    printf("\n\t[3] SAIR\n\t");

    scanf("%d", &resp1);

    switch(resp1){

        case (1):
            system("cls");
            escolherLugar();
        break;

        case(2):
            system("cls");
            MapaDeAssentos(&aCorredor, &aJanela);
        break;

        case(3):
            exit(0);

    }

    return 0;
}

int escolherLugar(){
    int JanelaOuCorredor;

        printf("\n\tVCE DESEJA\n\t[1] - JANELA\n\t[2] - CORREDOR\n\t[3] - VOLTAR\n\t");
        scanf("%d", &JanelaOuCorredor);

        if(JanelaOuCorredor == 1){
            system("cls");
            Janela(&aJanela);
        }
        if(JanelaOuCorredor == 2){
            system("cls");
            Corredor(&aCorredor);
        }
        if(JanelaOuCorredor == 3){
            system("cls");
            main();
        }
}

int MapaDeAssentos(int (*aCorredor)[], int (*aJanela)[]){
	int i;
	int resp2;

    printf("\n\t _______________________________\n");	//imprime o mapa das poltronas ocupadas
	printf("\n\t|   Corredor\t||   janela\t|\n");
	for(i = 0; i<24; i++){
		if((*aCorredor)[i] == 0){
			printf("\t|%d - Livre\t|", i+1);
		}else{
			printf("\t|%d - Ocupada\t|", i+1);
		}
		if((*aJanela)[i] == 0){
			printf("|%d - Livre\t|\n", i+1);
		}else{
			printf("|%d - Ocupada\t|\n", i+1);
		}
	}
    printf("\t -------------------------------");

    printf("\n\n\tVOLTAR AO MENU [1-SIM/2-NAO]");
    scanf("%d", &resp2);

    if(resp2 == 1){
        system("cls");
        main();
    }else{
        return 0;
    }
}


int Corredor(int (*aCorredor)[]){
    int poltrona;
    int i, lotado=0;
    int resp3;

    for(i = 0; i<24; i++){
		if((*aCorredor)[i] == 1 ){ //Checagem de todas as cadeiras do corredor;
            printf("\n\tTODAS AS POLTRONAS DO CORREDOR OCUPADAS!");
			lotado++;
		}
		else{
			break;
		}
	}
	if(lotado<24){

        printf("\n\t   QUAL POLTRONA VOCE DESEJA?\n\tPOLTRONAS DE 1 A 24\n\t");
        scanf("%d", &poltrona);

        if((*aCorredor)[poltrona-1] == 0){//poltrona vazia;
            (*aCorredor)[poltrona-1] = 1;
            printf("\nVENDA REALIZADA COM SUCESSO POLTRONA: %d (CORREDOR)\n", poltrona);

        }else{//poltrona ocupada;
            printf("\nVENDA NAO REALIZADA POLTRONA %d ESTA OCUPADA\n", poltrona);
            }

        printf("\n\n\tVOLTAR AO MENU [1-SIM/2-NAO]");
        scanf("%d", &resp3);

        if(resp3 == 1){
            system("cls");
            main();
        }else{
            return 0;
        }
	}
}


int Janela(int (*aJanela)[]){
    int poltrona;
    int i, lotado =0;
    int resp3;

    for(i = 0; i<24; i++){
		if((*aJanela)[i] == 1){ //Checagem de todas as cadeiras Janela;
            printf("\n\TODAS AS POLPTRONAS DA JANELAS OCUPADAS!");
			lotado++;
		}
		else{
			break;
		}
	}
	if(lotado < 24){

        printf("\n\t   QUAL POLTRONA VOCE DESEJA?\n\tPOLTRONAS DE 1 A 24\n\t");
        scanf("%d", &poltrona);

            if((*aJanela)[poltrona-1] == 0){ //poltrona vazia;
                (*aJanela)[poltrona-1] = 1;
                printf("\nVENDA REALIZADA COM SUCESSO POLTRONA: %d (JANELA)\n", poltrona);

            }else{//poltrona ocupada;
                printf("\nVENDA NAO REALIZADA POLTRONA %d ESTA OCUPADA\n", poltrona);
            }
        printf("\n\n\tVOLTAR AO MENU [1-SIM/2-NAO]");
        scanf("%d", &resp3);

        if(resp3 == 1){
            system("cls");
            main();
        }else{
            return 0;
        }

    }
}
