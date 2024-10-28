#include<stdio.h>
#include<stdlib.h>
#define size 10
int queue[size];
int front=0,rear=0;
void main()
{
void inque(int);
int deque();
int searchq(int);
int item,option;
do
{
printf("\n1.Insert\n");
printf("2.Delete\n");
printf("3.Search\n");
printf("4.Exit\n");
printf("Enter your option :");
scanf("%d",&option);
switch(option)
{
case 1:
printf("Enter data :");
scanf("%d",&item);
inque(item);
break;
case 2:
item=deque();
if(item!=-1)
printf("Deleted item is %d",item);
break;
case 3:
printf("Enter item to be searched ");
scanf("%d",&item);
if(searchq(item))
printf("Founded the searched item");
else
printf("The searched item not found ");
break;
case 4:
exit(0);
}
}
while(1);
}

//insert
void inque(int item)
{
int trear=(rear+1)%size;
if(trear==front)
{
printf("Queue is full");
}
else
{
rear=trear;
queue[rear]=item;
}
}

//delete
int deque()
{
if(front==rear)
{
printf("Queue is empty");
return -1;
}
else
front=(front+1)%size;
return queue[front];

}

//search 
int searchq(int item)
{
if(front==rear)
return 0;
int tfront=front+1;
while(tfront!=rear && queue[tfront]!=item)
tfront=(tfront+1)%size;
if(queue[tfront]==item)
return 1;
else
return 0;
}


