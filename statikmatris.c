#include <stdio.h>
#include <stdlib.h>


int main(){

	int matris[3][3];
	int i,j;

	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(i==j){
				matris[i][j]=1;
			}
			else{
				matris[i][j]=0;
			}
		}
	}


	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%4d",matris[i][j]);
		}
		printf("\n");
	}
}

void matris_yazdir(int matris[][3]){
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("%4d",matris[i][j]);
		}
		printf("\n");
	}
}
