#include <stdio.h>
#include <stdlib.h>

struct dugum{
	int icerik;
	struct dugum * sol;
	struct dugum * sag;
};
struct ikili_arama_agaci{
	struct dugum * kok;
};

void ikili_arama_agaci_olustur(struct ikili_arama_agaci ** agac){
	(*agac)=(struct ikili_arama_agaci *)malloc(sizeof(struct ikili_arama_agaci));
	if((*agac)==NULL){
		printf("Heapde yer ayrilamadi.");
		return;
	}
	(*agac)->kok=NULL;
}
int ikili_arama_agaci_bosmu(struct ikili_arama_agaci * agac){
	if(agac->kok==NULL)return 1;
	else{return 0;}
}

struct dugum * dugum_olustur(int icerik){
	struct dugum *d;
	d=(struct dugum *)malloc(sizeof(struct dugum));
	d->icerik=icerik;
	d->sol=d->sag=NULL;
	return d;

}

void ekle(struct ikili_arama_agaci * agac,int icerik){
	struct dugum *b,*geri,*eklenen;
	eklenen=dugum_olustur(icerik);
	
	b=agac->kok;
	while(b!=NULL){
		geri=b;
		if(b->icerik > icerik)b=b->sol;
		else if(b->icerik < icerik)b=b->sag;
		else return;
	}
	if(agac->kok==NULL)agac->kok=eklenen;
	else if(icerik < geri->icerik)geri->sol=eklenen;
	else geri->sag=eklenen;

}

void inorder_yardimci(struct dugum * kok){//sol-root-sag
	if(kok==NULL)return;
	inorder_yardimci(kok->sol);
	printf("%4d", kok->icerik);
	inorder_yardimci(kok->sag);


}
void inorder(struct ikili_arama_agaci * agac){
	if(agac==NULL)return;
	inorder_yardimci(agac->kok);
	printf("\n");
}
void preorder_yardimci(struct dugum *kok){//root-sol-sag
	if(kok==NULL)return;
	printf("%4d",kok->icerik);
	preorder_yardimci(kok->sol);
	preorder_yardimci(kok->sag);
}
void preorder(struct ikili_arama_agaci * agac){
	if(agac==NULL)return;
	preorder_yardimci(agac->kok);
	printf("\n");
}

void postorder_yardimci(struct dugum * kok){//sol-sag-root
	if(kok==NULL)return;
	postorder_yardimci(kok->sol);
	postorder_yardimci(kok->sag);
	printf("%4d",kok->icerik);
}
void postorder(struct ikili_arama_agaci *agac){
	if(agac==NULL)return;
	postorder_yardimci(agac->kok);
	printf("\n");
}

int dugum_sayisi(struct dugum * kok){
	if(kok==NULL)return 0;
	return 1+dugum_sayisi(kok->sol)+dugum_sayisi(kok->sag);
}
int yaprak_sayisi(struct dugum * kok){
	if(kok==NULL)return 0;
	if(kok->sol==NULL && kok->sag==NULL)return 1;
	else return yaprak_sayisi(kok->sol)+yaprak_sayisi(kok->sag);
}

void dugum_sil(struct ikili_arama_agaci *agac,int silinen){
	struct dugum *d,*parent,*d1,*d2;
	int sol;
	parent=NULL;
	d=agac->kok;
	while(d!=NULL){
		if(silinen < d->icerik){
			parent=d;
			d=d->sol;
			sol=1;
		}
		else if(silinen > d->icerik){
			parent=d;
			d=d->sag;
			sol=0;
		}
		else break;

	}
	if(d==NULL)printf("deger agacta bulunamadi.");
	else if(d->sol==NULL){//dugumun solu bos ise.
		if(parent==NULL){
			agac->kok=d->sag;
		}
		else{
			if(sol==1)parent->sol=d->sag;
			else parent->sag=d->sag;
		}
	}
	else if(d->sag==NULL){//dugumun sagi bos ise.
		if(parent==NULL)agac->kok=d->sol;
		else{
			if(sol==1)parent->sol=d->sol;
			else parent->sag=d->sol;
		}
	}
	else{ //hem sagi hem solu dolu.
		d1=d->sag;
		d2=NULL;
		while(d1->sol!=NULL){
			d2=d1;
			d1=d1->sol;
		}
		if(d2!=NULL){
			d2->sol=d1->sag;
			d1->sag=d->sag;
		}
		d1->sol=d->sol;
		if(parent==NULL) agac->kok=d1;//agacin koku degisti.
		else{
			if(sol==1)parent->sol=d1;
			else parent->sag=d1;
		}




	}
	free(d);


}

void yoket(struct dugum ** kok){
	if((*kok)!=NULL){
		yoket(&(*kok)->sol);
		yoket(&(*kok)->sag);
		free(*kok);
		*kok=NULL;
	}
}

int foo(struct dugum *kok){//ic kok sayisi
	if(kok==NULL)return 0;
	else if(kok->sag!=NULL || kok->sol!=NULL)return 1+foo(kok->sol)+foo(kok->sag);
	else return 0;
}

void en_kucugu_sil(struct ikili_arama_agaci * x){
	struct dugum * a, *b;
	a=x->kok;
	while(a->sol!=NULL){
		b=a;
		a=a->sol;
	}
	if(a->sag!=NULL){
		b->sol=a->sag;
	}
	else b->sol=NULL;
	free(a);


}

int main(){

	struct ikili_arama_agaci *agac;
   	ikili_arama_agaci_olustur(&agac);
    
    	ekle(agac,100);
   	ekle(agac,50);
   	ekle(agac,200);
   	ekle(agac,25);
	ekle(agac,20);
   	ekle(agac,35);
   	ekle(agac,500);
   	ekle(agac,400);
   	ekle(agac,300);
   	ekle(agac,210);
   	ekle(agac,23);
	inorder(agac);
	en_kucugu_sil(agac);
	inorder(agac);
	printf("Dugum sayisi : %d \n",dugum_sayisi(agac->kok));
	printf("Yaprak sayisi : %d \n",yaprak_sayisi(agac->kok));

}
