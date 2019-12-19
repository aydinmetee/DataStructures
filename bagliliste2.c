#include <stdio.h>
#include <stdlib.h>

struct hucre{
	int icerik;
	struct hucre * sonraki;
};

struct hucre * hucre_olustur(int icerik){
	struct hucre * a;
	a=(struct hucre *)malloc(sizeof(struct hucre));
	if(a==NULL){
		printf("Heapte yer ayrilamadi.");
		return NULL;
	}
	a->icerik=icerik;
	a->sonraki=NULL;
	return a;
}

void liste_basina_ekle(int icerik,struct hucre ** liste_basi){
	struct hucre *a;
	a=hucre_olustur(icerik);
	a->sonraki=(*liste_basi)
	
}


int main(){

}
