
////�������ķǵݹ��ջ������� 
#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	struct tree *lchild;
	char item;
	struct tree *rchild;
	int flag;//��¼�Ƿ���ʹ������ʹ�����1 �ں�����������õ� 
	int permit;//��¼��ǰ����Ƿ���Է��ʣ�Ϊ1���Է��� �ں�������ĵڶ����㷨���õ� 
}node,*leaf; 
void visit(leaf p){
	printf("%c ",p->item);
	return;
}


int main()
{	
	leaf head,p,stack[100],pre;
	int top,i;
	
	
//build:
	leaf p1,p2,p3,p4,p5,p6,p7,p8,p9,p10;
	p1=(leaf)malloc(sizeof(node));// 									A
	p2=(leaf)malloc(sizeof(node));// 							B              C
	p3=(leaf)malloc(sizeof(node));// 						D     E        F      G
	p4=(leaf)malloc(sizeof(node));// 						 H   J        I     
	p5=(leaf)malloc(sizeof(node));// 
	p6=(leaf)malloc(sizeof(node));
	p7=(leaf)malloc(sizeof(node));
	p8=(leaf)malloc(sizeof(node));
	p9=(leaf)malloc(sizeof(node));
	p10=(leaf)malloc(sizeof(node));
	p1->lchild=p2;p1->rchild=p3;p1->item='A';p1->flag=0;p1->permit=0;
	p2->lchild=p4;p2->rchild=p5;p2->item='B';p2->flag=0;p2->permit=0;
	p3->lchild=p6;p3->rchild=p7;p3->item='C';p3->flag=0;p3->permit=0;
	p4->lchild=NULL;p4->rchild=p10;p4->item='D';p4->flag=0;p4->permit=0;
	p5->lchild=p8;p5->rchild=NULL;p5->item='E';p5->flag=0;p5->permit=0;
	p6->lchild=NULL;p6->rchild=p9;p6->item='F';p6->flag=0;p6->permit=0;
	p7->lchild=NULL;p7->rchild=NULL;p7->item='G';p7->flag=0;p7->permit=0;
	p8->lchild=NULL;p8->rchild=NULL;p8->item='J';p8->flag=0;p8->permit=0;
	p9->lchild=NULL;p9->rchild=NULL;p9->item='I';p9->flag=0;p9->permit=0;
	p10->lchild=NULL;p10->rchild=NULL;p10->item='H';p10->flag=0;p10->permit=0;
	head=p1;
	
	
	//ǰ�������
	p=head;
	top=-1;
	printf("ǰ��������У�");
	if(head!=NULL){
	
	do{
		while(p!=NULL){
			stack[++top]=p;	 
			visit(p);	//ÿ����һ���ڵ㣬���ȷ�������ڵ� 
			p=p->lchild;
		}
		p=stack[top--];
		p=p->rchild;
	}while(!(p==NULL&&top==-1));
	}
	putchar('\n');
	
	
	
	//���������
	p=head;
	top=-1;
	printf("����������У�");
	if(head!=NULL){
	
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}//һֱѰ������ֱ���Ҳ���Ϊֹ 
		p=stack[top--];//�˳�NULL�ĸ��ڵ���Ϊ��ǰҪ���ʵ�Ԫ�� 
		visit(p);	 
		p=p->rchild;	//�ٴӸ��ڵ���Ҷ��ӿ�ʼ 
	}while(!(p==NULL&&top==-1));
	}
	putchar('\n');
	
	
	


	//������������������Ҫ�ж����������Ƿ񶼷��ʹ��� 
	p=head;
	top=-1;
	printf("����������У�");
	if(head!=NULL){
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}
		p=stack[top];
		while(top!=-1&&(p->rchild==NULL||p->rchild->flag==1)){	//�Һ���Ϊ�ջ����Һ����Ѿ����ʹ����ͷ��ʸýڵ� 
													//������while������if����Ϊifֻ����һ�Σ����ܻ����ĳԪ�ض��ν�ջ����� 
			visit(p);
			p->flag=1;
			top--;
			if(top!=-1) 
				p=stack[top];	//���ʹ��󣬰�pָ��ջ��Ԫ�أ�Ȼ������жϣ��������ڸôη��ʵ���ջ�����Һ��ӵ���ջ��Ԫ�ؿ��Է��ʣ� 
		}
		p=p->rchild;	//�����Һ���׼����ջ 
	}while(!(top==-1));	//����û����p==NULLԭ��head�ǵ�һ����ջ��Ԫ�أ�Ҳ�������ʵ�Ԫ�أ����ջ���ˣ���һ���Ƿ��ʽ�����
						//						 ����������ʱ��pʵ���ϵ���head->rchild��Ҳ����						 
	}
	putchar('\n');
	
	
	//���������
	p=head;
	top=-1;
	printf("����������У�");
	if(head!=NULL){
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}
		p=stack[top--];	//ֱ����ջ�����p�����ʴ����ٽ�ջ
		if(p->permit==0){
			stack[++top]=p;
			p->permit=1;
			p=p->rchild;
		} 
		else{
			visit(p); 
		    p=NULL;	//��visit p֮�󣬾Ͳ�������p=p->rchild�ˣ����������ظ����ʵ���� 
		}

		
	}while(!(top==-1));	//����û����p==NULLԭ��head�ǵ�һ����ջ��Ԫ�أ�Ҳ�������ʵ�Ԫ�أ����ջ���ˣ���һ���Ƿ��ʽ�����
						//��ʵ�������㷨�£�p==NULL����Ҳ����						 
	}
	putchar('\n');
	
	

return 0; 
} 























