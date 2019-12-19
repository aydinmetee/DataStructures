#include <stdio.h>
#include <stdlib.h>

struct yigin{
	int * dizi;
	int ust;
	int kapasite;
};

struct yigin * yiginOlustur(int kapasite){
	if(kapasite<=0)printf("kapasite pozitif tam sayi olmali.");
	else{
	
		struct yigin *ptr;
		ptr=(struct yigin *)malloc(sizeof(struct yigin));
		ptr->dizi=(int *)malloc(kapasite*sizeof(int));
		ptr->ust=-1;
		ptr->kapasite=kapasite;
		return ptr;
	}
}
void yiginOlustur_parametre(int kapasite,struct yigin **y){
	if(kapasite<=0)printf("kapasite pozitif tam sayi olmali. ");
	else{
		(*y)=(struct yigin *)malloc(sizeof(struct yigin));
		(*y)->dizi=(int *)malloc(kapasite*sizeof(int));
		(*y)->ust=-1;
		(*y)->kapasite=kapasite;
	}
}
int yigin_bos_mu(struct yigin *y){
	if(y->ust==-1)return 1;
	else{return 0;}

}
int yigin_dolu_mu(struct yigin *y){
	if(y->ust==y->kapasite - 1)return 1;
	else{return 0;}
}

void yigina_ekle(int icerik,struct yigin *y){
	if(yigin_dolu_mu(y))printf("Yigin dolu, eklenemiyor.");
	else{
		y->ust++;
		y->dizi[y->ust]=icerik;
	}
}

void yigin_yaz(struct yigin *y){
	int i;
	printf("Yigin kapasitesi : %d \n",y->kapasite);
	printf("Yigindaki eleman sayisi : %d \n",y->ust+1);

	for(i=y->ust;i>=0;i--){
		printf("%4d",y->dizi[i]);
	}

}



int main(){
	struct yigin * yeni;
	yeni=yiginOlustur(10);

	yigina_ekle(7,yeni);
	yigina_ekle(15,yeni);
	yigina_ekle(20,yeni);
	yigina_ekle(5,yeni);
	yigina_ekle(50,yeni);
	yigina_ekle(9,yeni);
	yigin_yaz(yeni);

}
