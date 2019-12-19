#include <stdio.h>
#include <stdlib.h>

//Dinamik matrisin ters köşegenleri 3 olsun.

int main(){

	int ** matris;
	int sat,sut;
	int i,j;
	sat=3;
	sut=3;

	matris=(int **)malloc(sat*sizeof(int* ));
	for(i=0;i<sat;i++){
		matris[i]=(int *)malloc(sut*sizeof(int));
		for(j=0;j<sut;j++){
		/*	if(i+j==2){ 
				matris[i][j]=3;
			}
			else{ 
				matris[i][j]=1;
			}*/
			((*matris+i)+j)=2;
		}
	}

	for(i=0;i<sat;i++){
		for(j=0;j<sut;i++){
			printf("%4d",matris[i][j]);
		}
		printf("\n");
	}



}
