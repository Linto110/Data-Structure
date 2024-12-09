struct node{
int data;
struct node* next;
};
#include<stdio.h>
#include<stdlib.h>
void main(){
struct node *start=(struct node*)0;
struct node *insert(struct node*,int);
struct node *delete(struct node*);
void display(struct node*);
int opt,data;
do{
printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
printf("Enter your choice :");
scanf("%d",&opt);
switch(opt)
{
case 1:
printf("Enter your data :");
scanf("%d",&data);
start=insert(start,data);
break;
case 2:
start=delete(start);
break;
case 3:
display(start);
break;
case 4:
exit(0);
}
}while(1);
}

//To insert a node
struct node* insert(struct node* s,int item)
{
struct node* t;
t=(struct node*)malloc(sizeof(struct node*));
t->data=item;
t->next=s;
return t;
}

//To delete a nod
struct node* delete(struct node* s)
{
struct node* t;
t=s;
if(s!=(struct node*)0)
{
printf("%d is deleted",t->data);
s=s->next;
free(t);
}
else{
printf("List is empty");
}

return s;
}
//To display the list
void display(struct node* s)
{
if(s==0)
{
printf("Empty list");
return;
}
while(s!=(struct node*)0)
{
printf("%d\t",s->data);
s=s->next;
}
}
