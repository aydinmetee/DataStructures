#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL{
	char *anahtar;
	struct CELL *next;
};

int lookup(char *anahtar,struct CELL *l){
	if(l==NULL)return 0;
	else if(!strcmp(anahtar,l->anahtar))return 1;
	else return lookup(anahtar,l->next);
}

int insert(char *anahtar,struct CELL **l){
	if(*l==NULL){
		*l=(struct CELL*)malloc(sizeof(struct CELL));
		(*l)->anahtar=(char*)malloc((strlen(anahtar)+1)*sizeof(char));
		strcpy((*l)->anahtar,anahtar);
		(*l)->next=NULL;
		return 1;
	}
	else if(strcmp(anahtar,(*l)->anahtar))return insert(anahtar,&((*l)->next));
	else return 0;
}


struct table_node{
	int counter;
	struct CELL *header;
};


struct hash_tablosu{
	struct table_node *tablo_basi;
	int tablo_uzunlugu;
	int multiplier;
};

unsigned hash(char *anahtar,int multiplier, int table_size){
        int i=0;
        unsigned int value=0;
        while(anahtar[i]){
                value=(anahtar[i]+multiplier*value)%table_size;
                i++
        }
        return value;
}


int main(){


}
