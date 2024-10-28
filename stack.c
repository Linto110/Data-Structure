#include<stdio.h>
#define size 10
#include<stdlib.h>
int stack[size];
int sp=-1;
void main()
{
int op,data;
void push(int);
int pop();
void display();
do
{
printf("\n1.Push\n");
printf("2.Pop\n");
printf("3.Dispaly\n");
printf("4.Exit\n");
printf("Enter your choice :");
scanf("%d",&op);
switch(op)
{
case 1: printf("Enter data :");
scanf("%d",&data);
push(data);
break;
case 2: 
data=pop();
printf("popped item=%d",data);
break;
case 3:
display();
break;
case 4:
exit(0);

}
}
while(1);
}
void push(int data)
{
if(sp==size-1)
printf("Stack is full");
else
stack[++sp]=data;
}
int pop()
{
if(sp==-1)
{
printf("Stack is empty");
exit(0);
}
else 
{
return stack[sp--];
}
}
void display()
{
int tsp=sp;
printf("Stack contents \n");
while(tsp!=-1)
{
printf("%d\t",stack[tsp]);
tsp--;
}
printf("\n");
}

