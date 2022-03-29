#include<stdio.h>
int stack[10], top, val, a, i, max, choice;
int push(int a)
{
 if(top < max-1)
 {
 top = top + 1;
 stack[top] = a;
 }
 else
 {
 printf("Stack OVERFLOW\n");
 }
}
void pop()
{
 if(top > -1)
 {
 val = stack[top];
 printf("The value popped is %d\n", val);
 top = top-1;
 }
 else
 {
 printf("Stack UNDERFLOW\n");
 }
}
void peek()
{
 if(top > -1)
 {
 printf("Topmost stack element: %d\n", stack[top]);
 }
 else
 {
 printf("Stack is empty.\n");
 }
}
void display()
{
 if(top > -1)
 {
 printf("Stack elements are: ");
 for(i=top; i>-1; i--)
 {
 printf("/n%d ", stack[i]);
 }
 printf("/n");
 }
 else
 {
 printf("Stack is empty.\n");
 }
}
void size()
{
 if(top < 0)
 {
 printf("Stack is empty.\n");
 }
 else
 {
 printf("\nSize: %d", top+1);
 }
}
int main()
{
 top = -1;
 printf("\n Enter the max size of STACK : ");
 scanf("%d",&max);
 do
 {
 printf("\nImplementation of Stack ADT:");

printf("\n1.PUSH\n2.POP\n3.PEEK\n4.SIZE\n5.DISPLAY\n6.EXIT");
 printf("\nEnter the choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1:
 {
 printf("Enter the input to be pushed: ");
 scanf("%d",&a);
 push(a);
 break;
 }
 case 2:
 {
 pop();
 break;
 }
 case 3:
 {
 peek();
 break;
 }
 case 4:
 {
 size();
 break;
 }
 case 5:
 {
 display();
 break;
 }
 case 6:
 {
 break;
 }
 default:
 {
 printf("Invalid input!");
 }
 }
 }
 while(choice != 6);
return 0;
}
