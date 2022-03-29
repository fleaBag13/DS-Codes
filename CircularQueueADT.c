#include<stdio.h>
int queue[10], max, front, rear, i, a, choice, count=0;
int enqueue(int a)
{
 if(front==0 && rear==max-1)
 {
 printf("Queue OVERFLOW\n");
 return;
 }
 else if(front==-1 && rear==-1)
 {
 front=0;
 rear=0;
 }
 else if(front != 0 && rear == max-1)
 {
 rear=0;
 }
 else
 {
 rear = rear + 1;
 }
 queue[rear]=a;
}
int dequeue()
{
 if(front==-1 && rear==-1)
 {
 printf("Queue UNDERFLOW\n");
 return -1;
 }
 else
 {
 a=queue[front];
 if(front==rear)
 {
 front=-1;
 rear=-1;
 }
 else
 {
 if(front==max-1)
 {
 front=0;
 }
 else
 {
 front++;
 }
 }
 }
 return a;
}
int getFront()
{
 if(front==-1 && rear==-1)
 {
 printf("Queue UNDERFLOW\n");
 return -1;
 }
 if(front!=-1)
 {
 return queue[front];
 }
}
int getRear()
{
 if(front==-1 && rear==-1)
 {
 printf("Queue UNDERFLOW\n");
 return -1;
 }
 if(front!=-1)
 {
 return queue[rear];
 }
}
int size()
{
 if(front==-1 && rear==-1)
 {
 printf("Queue UNDERFLOW\n");
 return -1;
 }
 else
 {
 int i;
 if(front<=rear)
 {
 for(i=front; i<=rear; i++)
 {
 count = count + 1;
 }
 }
 else
 {
 for(i=front; i<=max-1; i++)
 {
 count = count + 1;
 }
 for(i=0; i<=rear; i++)
 {
 count = count + 1;
 }
 }
 }
 return count;
}
void display()
{
 int i;
 if(front==-1 && rear==-1)
 {
 printf("Queue UNDERFLOW\n");
 }
 else
 {
 printf("Queue elements are: ");
 if(front<=rear)
 {
 for(i=front; i<=rear; i++)
 {
 printf("%d ", queue[i]);
 }
 printf("\n");
 }
 else
 {
 for(i=front; i<=max-1; i++)
 {
 printf("%d ", queue[i]);
 }
 for(i=0; i<=rear; i++)
 {
 printf("%d ", queue[i]);
 }
 printf("\n");
 }
 }
}
int main()
{
 front=-1;
 rear=-1;
 printf("\n Enter the max size of CIRCULAR QUEUE : ");
 scanf("%d",&max);
 do
 {
 printf("\nImplementation of Circular Queue ADT:");
 printf("\n1.ENQUEUE\n2.DEQUEUE\n3.GET FRONT\n4.GET
REAR\n5.SIZE\n6.DISPLAY\n7.EXIT");
 printf("\nEnter the choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 printf("Enter the element to be inserted: ");
 scanf("%d",&a);
 enqueue(a);
 break;
 }
 case 2:
 {
 a = dequeue();
 if(a != -1)
 {
 printf("Value deleted: %d\n", a);
 }
 break;
 }
 case 3:
 {
 a = getFront();
 if(a != -1)
 {
 printf("The front element of the queue: %d\n", a);
 }
 break;
 }
 case 4:
 {
 a = getRear();
 if(a != -1)
 {
 printf("The rear element of the queue: %d\n", a);
 }
 break;
 }
 case 5:
 {
 a = size();
 if(a != -1)
 {
 printf("The size of the queue: %d\n", a);
 }
 break;
 }
 case 6:
 {
 display();
 break;
 }
 case 7:
 {
 break;
 }
 default:
 {
 printf("Invalid input!");
 }
 }
 }
 while(choice != 7);
 return 0;
}
