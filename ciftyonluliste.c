#include <stdio.h>
#include <stdlib.h>

struct ciftyonluEleman{
	int icerik;
	struct ciftyonluEleman *ileri;
	struct ciftyonluEleman *geri;
};
typedef struct ciftyonluEleman Eleman;

struct ciftyonluListe{
	struct ciftyonluEleman *bas;
	struct ciftyonluEleman *son;
};
typedef struct ciftyonluListe Liste;

Eleman * elemanOlustur(int icerik){
	Eleman *yeni;
	yeni=(Eleman *)malloc(sizeof(Eleman));
	yeni->icerik=icerik;
	yeni->ileri=yeni->geri=NULL;
	return yeni;
}

void ciftyonluListeBaslat(Liste ** list1){
	(*list1)=(Liste *)malloc(sizeof(Liste));
	(*list1)->bas=(*list1)->son=NULL;
}

void liste_basina_ekle(int icerik,Liste * list1){
	Eleman *yeni;
	yeni=elemanOlustur(icerik);
	if(list1->son==NULL)list1->son=yeni;
	else{
		list1->bas->geri=yeni;
		yeni->ileri=list1->bas;
	}
	list1->bas=yeni;
}

void liste_sonuna_ekle(int icerik,Liste * list1){
	Eleman *yeni;
	yeni=elemanOlustur(icerik);
	if(list1->bas==NULL)list1->bas=yeni;
	else{
		list1->son->ileri=yeni;
		yeni->geri=list1->son;
	}
	list1->son=yeni;
	
}

void liste_yaz(Liste * list1){
	Eleman* bas;
	bas=list1->bas;

	while(bas!=NULL){
		printf("%d ",bas->icerik);
		bas=bas->ileri;

	}
	printf("\n");
}

int main(){
	Liste * list1;
	ciftyonluListeBaslat(&list1);

	liste_basina_ekle(40,list1);
	liste_sonuna_ekle(60,list1);

	liste_basina_ekle(10,list1);
	liste_sonuna_ekle(20,list1);

	liste_yaz(list1);
}
