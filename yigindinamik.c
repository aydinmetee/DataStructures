#include <stdio.h>
#include <stdlib.h>

#define SENTINEL -1

struct dugum{
	int icerik;
	struct dugum * link;
};

struct dugum * dugumOlustur(int icerik){
	struct dugum *a;
	a=(struct dugum *)malloc(sizeof(struct dugum));
	a->icerik=icerik;
	a->link=NULL;
	return a;
}



void ekle(int icerik,struct dugum **dugum_gostergesi){
	struct dugum *a;
	a=dugumOlustur(icerik);
	if((*dugum_gostergesi)==NULL)(*dugum_gostergesi)=a;
	else{
		a->link=(*dugum_gostergesi);
		(*dugum_gostergesi)=a;
	}

}

void yazdir(struct dugum * yigin_gostergesi){
	while(yigin_gostergesi!=NULL){
		printf("%4d" , yigin_gostergesi->icerik);
		yigin_gostergesi=yigin_gostergesi->link;
	}	
	printf("\n");
}

int cikar(struct dugum ** yigin_gostergesi){
	int a;
	struct dugum *b;
	b=(*yigin_gostergesi);
	(*yigin_gostergesi)=(*yigin_gostergesi)->link;
	a=b->icerik;
	free(b);
	return a;

}

int yigin_bos_mu(struct dugum * yigin_gostergesi){
	if(yigin_gostergesi==NULL)return 1;
	else{
		return 0;
	}
}



int main(){
	int a;
	struct dugum * yigin_gostergesi=NULL;

	ekle(50,&yigin_gostergesi);
	ekle(20,&yigin_gostergesi);
	ekle(70,&yigin_gostergesi);
	ekle(100,&yigin_gostergesi);
	yazdir(yigin_gostergesi);

	a=cikar(&yigin_gostergesi);
	if(a!=SENTINEL)printf("%4d\n",a);
	yazdir(yigin_gostergesi);

}
