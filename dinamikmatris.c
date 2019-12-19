#include <stdio.h>
#include <stdlib.h>

//KÖSEGENLERİ 5 OLAN KARE MATRİS.

/*int matris_olustur(int *** matris){
	(*matris)=(int **)malloc(satir_sayisi*sizeof(int ));
	(*matris)[i]=(int*)
*/
int main(){
	
	int **matris;
	int satir_sayisi,sutun_sayisi;
	int i,j;

	printf("Satir sayisini girin : \n");
	scanf("%d",&satir_sayisi);


	printf("Sutun sayisini girin : ");
	scanf("%d",&sutun_sayisi);

	matris=(int **)malloc(satir_sayisi*sizeof(int*));
	for(i=0;i<satir_sayisi;i++){
		matris[i]=(int *)malloc(sutun_sayisi*sizeof(int));
		for(j=0;j<sutun_sayisi;j++){
			((*matris+i)+j)=rand()%1;
		}
	}

	for(i=0;i<satir_sayisi;i++){
		for(j=0;j<sutun_sayisi;j++){
			printf("%4d",matris[i][j]);
		}
		printf("\n");
	}

/*	for(i=0;i<satir_sayisi;i++){
		free(matris[i]);
	}
	free(matris);
*/

}
