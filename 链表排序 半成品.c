
////¡¥±Ì≈≈–Ú 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node{
	char name[100];
	char num[100];
	struct p *link;
}Node,*Linklist; 
int main()
{	int k,n;
	Linklist p,list=NULL,r=NULL,i,j,index,father,indexfather,ifather;
	scanf("%d",&n);
	for(k=0;k<n;k++){
		p=(Linklist)malloc(sizeof(Node));
		scanf("%s%s",p->name,p->num);
		p->link=NULL;
		if(list==NULL)
			list=p;
		else
			r->link=p;
		r=p;			
	}
	/*for(k=0,p=list;k<n;k++){
		printf("%s\n%s\n\n",p->name,p->num);
		p=p->link;
	}*/
	for(i=list;i!=NULL;i=i->link){
		j=i->link;
		index=i;
		father=i;
		while(j!=NULL){
			if((strcmp(j->name,index->name))<=0){
                index=j;
                indexfather=father;
        	}
            father=j;
            j=j->link;
		}
		//	printf("index:%s\n%s\n\n",index->name,index->num);
		if(index!=i){
			indexfather->link=index->link;
			index->link=i;
			if(i==list)
				list=index;
			else
				ifather->link=index;
		}
		if(i==list)
			;
		else
			ifather=i;
	}
		for(k=0,p=list;k<n;k++){
			printf("%s\n%s\n\n",p->name,p->num);
			p=p->link;
	}
	/*for(i=0;i<n;i++)
        printf("%12s%12s\n",namesort[i]->name,namesort[i]->num);*/
    return 0;
}
