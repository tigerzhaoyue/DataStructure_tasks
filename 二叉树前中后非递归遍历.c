
////二叉树的非递归堆栈中序遍历 
#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
	struct tree *lchild;
	char item;
	struct tree *rchild;
	int flag;//记录是否访问过，访问过就置1 在后序遍历中有用到 
	int permit;//记录当前结点是否可以访问，为1可以访问 在后序遍历的第二种算法有用到 
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
	
	
	//前序遍历：
	p=head;
	top=-1;
	printf("前序遍历序列：");
	if(head!=NULL){
	
	do{
		while(p!=NULL){
			stack[++top]=p;	 
			visit(p);	//每到达一个节点，就先访问这个节点 
			p=p->lchild;
		}
		p=stack[top--];
		p=p->rchild;
	}while(!(p==NULL&&top==-1));
	}
	putchar('\n');
	
	
	
	//中序遍历：
	p=head;
	top=-1;
	printf("中序遍历序列：");
	if(head!=NULL){
	
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}//一直寻找左孩子直到找不到为止 
		p=stack[top--];//退出NULL的父节点作为当前要访问的元素 
		visit(p);	 
		p=p->rchild;	//再从父节点的右儿子开始 
	}while(!(p==NULL&&top==-1));
	}
	putchar('\n');
	
	
	


	//后序遍历：后序遍历需要判断左右子树是否都访问过。 
	p=head;
	top=-1;
	printf("后序遍历序列：");
	if(head!=NULL){
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}
		p=stack[top];
		while(top!=-1&&(p->rchild==NULL||p->rchild->flag==1)){	//右孩子为空或者右孩子已经访问过，就访问该节点 
													//这里用while而不是if是因为if只能有一次，可能会出现某元素二次进栈的情况 
			visit(p);
			p->flag=1;
			top--;
			if(top!=-1) 
				p=stack[top];	//访问过后，把p指向栈顶元素，然后继续判断（可能由于该次访问的是栈顶的右孩子导致栈顶元素可以访问） 
		}
		p=p->rchild;	//否则右孩子准备入栈 
	}while(!(top==-1));	//这里没有用p==NULL原因：head是第一个进栈的元素，也是最后访问的元素，如果栈空了，那一定是访问结束了
						//						 而且最后结束时，p实际上等于head->rchild，也就是						 
	}
	putchar('\n');
	
	
	//后序遍历：
	p=head;
	top=-1;
	printf("后序遍历序列：");
	if(head!=NULL){
	do{
		while(p!=NULL){
			stack[++top]=p;
			p=p->lchild;
		}
		p=stack[top--];	//直接退栈，如果p不访问待会再进栈
		if(p->permit==0){
			stack[++top]=p;
			p->permit=1;
			p=p->rchild;
		} 
		else{
			visit(p); 
		    p=NULL;	//当visit p之后，就不能再让p=p->rchild了，否则会出现重复访问的情况 
		}

		
	}while(!(top==-1));	//这里没有用p==NULL原因：head是第一个进栈的元素，也是最后访问的元素，如果栈空了，那一定是访问结束了
						//事实上这种算法下，p==NULL加上也可以						 
	}
	putchar('\n');
	
	

return 0; 
} 























