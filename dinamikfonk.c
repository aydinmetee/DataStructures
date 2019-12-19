#include <stdio.h>
#include <stdlib.h>

void dinamik_matris(int *** dizi,int sat,int sut){
	int i,j;

	(*dizi)=(int **)malloc(sizeof(int *)*sat);
	for(i=0;i<sat;i++){
		(*dizi)[i]=(int *)malloc(sizeof(int)*sut);
		for(j=0;j<sut;j++){
			*(*(*dizi+i)+j)=2;
		}
	}


}

void matris_carp(int ** dizi1,int **dizi2,int *** yenidizi,int sat1,int sut1,int sat2,int sut2){
	int i,j;	
	
}

void matris_yaz(int ** dizi,int sat,int sut){
	int i,j;

	for(i=0;i<sat;i++){
		for(j=0;j<sut;j++){
			printf("%4d",dizi[i][j]); 
		}
		printf("\n");
	}
}


int main(){
	int ** matris;
	dinamik_matris(&matris,4,4);
	matris_yaz(matris,4,4);


}
