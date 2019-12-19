#include <stdio.h>
#include <stdlib.h>


struct hucre{
	int icerik;
	struct hucre * sonraki;
};

struct hucre * hucre_olustur(int icerik){
	struct hucre * a;
	a=(struct hucre *)malloc(sizeof(struct hucre));
	a->icerik=icerik;
	a->sonraki=NULL;
	return a;
}

void liste_basina_ekle(int icerik,struct hucre ** liste_basi){
	struct hucre *a;
	a=hucre_olustur(icerik);

	if((*liste_basi)==NULL){
		(*liste_basi)=a;
	}

	else{
		a->sonraki=(*liste_basi);
		(*liste_basi)=a;
	}
}
void liste_sonuna_ekle(int icerik,struct hucre ** liste_basi){
	struct hucre *a,*b;
	a=hucre_olustur(icerik);
	if((*liste_basi)==NULL){
		(*liste_basi)=a;
	}
	else{
		b=(*liste_basi);
		while(b->sonraki!=NULL){
			b=b->sonraki;
		}
		b->sonraki=a;
	}
}

void liste_yaz(struct hucre * liste_basi){
	while(liste_basi!=NULL){
		printf("%d ",liste_basi->icerik);
		liste_basi=liste_basi->sonraki;
	}
	printf("\n");
}

void liste_yaz_recursive(struct hucre * liste_basi){
	if(liste_basi!=NULL){
		printf("%d ",liste_basi->icerik);
		liste_yaz_recursive(liste_basi->sonraki);
	}
}

void liste_yok_et(struct hucre ** liste_basi){
	struct hucre *a;
	while((*liste_basi)!=NULL){
		a=(*liste_basi);
		(*liste_basi)=(*liste_basi)->sonraki;
		free(a);
	}
	printf("liste silindi. \n");

}

void liste_sirali_ekle(int icerik,struct hucre ** liste_basi){
	struct hucre *eklenen,*a,*b;
	eklenen=hucre_olustur(icerik);
	if((*liste_basi)==NULL)(*liste_basi)=eklenen;

	else{
		b=(*liste_basi);
		while(b!=NULL && b->icerik < eklenen->icerik ){
			a=b;
			b=b->sonraki;
		}
		if(b==(*liste_basi)){
				eklenen->sonraki=(*liste_basi);
				(*liste_basi)=eklenen;
		}
		else{
			a->sonraki=eklenen;
			eklenen->sonraki=b;

		}
	}
}

void liste_eleman_sil(int silinen,struct hucre ** liste_basi){
	struct hucre *a,*b;
	b=(*liste_basi);
	while(b!=NULL && b->icerik!=silinen){
		a=b;
		b=b->sonraki;
	}
	if(b==NULL){
		printf("Eleman listede bulunmuyor. \n");
	}
	else if(b==(*liste_basi)){
		(*liste_basi)=(*liste_basi)->sonraki;
		free(b);
	}
	else{
		a->sonraki=b->sonraki;
		free(b);
	}

}




	
int main(){
	struct hucre * liste1;
	liste1=NULL;
	liste_basina_ekle(15,&liste1);
	liste_basina_ekle(35,&liste1);
	liste_basina_ekle(25,&liste1);
	liste_sonuna_ekle(45,&liste1);
	liste_yaz(liste1);
	liste_yok_et(&liste1);
	liste_sirali_ekle(20,&liste1);
	liste_sirali_ekle(50,&liste1);
	liste_eleman_sil(50,&liste1);
	liste_sirali_ekle(40,&liste1);
	liste_sirali_ekle(10,&liste1);
	liste_yaz(liste1);
}


