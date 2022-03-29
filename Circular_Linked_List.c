#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
int a;
struct node *head;
 int insert_beg(int a)
 {
 struct node *new_node = (struct node*)malloc(sizeof(struct node));
 new_node -> data = a;
 if(head==NULL)
 {
 head = new_node;
 new_node -> next = head;
 }
 struct node *temp = head;
 while(temp->next != head)
 {
 temp = temp -> next;
 }
 new_node -> next = head;
 temp -> next = new_node;
 head = new_node;
 }
 void insert_end(int a)
 {
 struct node *new_node = (struct node*)malloc(sizeof(struct node));
 new_node -> data = a;
 if(head==NULL)
 {
 head = new_node;
 new_node -> next = head;
 }
 else
 {
 struct node *temp = head;
 while(temp -> next != head)
 {
 temp = temp -> next;
 }
 new_node -> next = head;
 temp -> next = new_node;
 }
 }
 void delete_beg()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else if(head -> next == head)
 {
 struct node *temp = head;
 printf("Element deleted: %d\n", temp->data);
 head = NULL;
 free(temp);
 }
 else
 {
 struct node *temp = head;
 while(temp -> next != head)
 {
 temp = temp -> next;
 }
 temp -> next = head -> next;
 printf("Element deleted: %d\n", head->data);
 free(head);
 head = temp -> next;
 }
 }
 void delete_end()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else if(head -> next == head)
 {
 struct node *temp = head;
 printf("Element deleted: %d\n", temp->data);
 head = NULL;
 free(temp);
 }
 else
 {
 struct node *temp1 = head;
 struct node *temp2 = head;
 while(temp1 -> next != head)
 {
 temp2 = temp1;
 temp1 = temp1 -> next;
 }
 temp2 -> next = temp1 -> next;
 printf("Element deleted: %d\n", temp1 -> data);
 free(temp1);
 }
 }
 void forward_trav()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else
 {
 struct node *temp = head;
 printf("List elements in Forward Traversal: ");
 while(temp -> next != head)
 {
 printf("%d --> ", temp -> data);
 temp = temp -> next;
 }
 printf("%d\n", temp->data);
 }
 }
 void backward_trav(struct node *ptr)
 {
 if(ptr == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else
 {
 if(ptr -> next != head)
 {
 backward_trav(ptr -> next);
 printf("%d --> ", ptr -> next -> data);
 }
 }
 }
 void count()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else {
 struct node *temp = head;
 int count = 1;
 while(temp -> next != head)
 {
 count++;
 temp = temp -> next;
 }
 printf("The number of nodes in the linked list are %d\n", count);
 }
 }
int main()
{
 struct node *ptr;
 int choice, val;
 do
 {
 printf("\n Menu Driven CIRCULAR LINKED LIST\n\n1.Insert at
beginning\n2.Insert at end\n3.Delete from beginning\n4.Delete from
end\n");
 printf("5.Forward Traversal\n6.Backward Traversal\n7.Count
number of nodes\n8.Exit\n");
 printf("Enter choice: ");
 scanf("%d", &choice);
 switch(choice)
 {
 case 1:
 printf("Enter the value to be inserted: ");
 scanf("%d", &a);
 insert_beg(a);
 break;
 case 2:
 printf("Enter the value to be inserted: ");
 scanf("%d", &a);
 insert_end(a);
 break;
 case 3:
 delete_beg();
 break;
 case 4:
 delete_end();
 break;
 case 5:
 forward_trav();
 break;
 case 6:
 ptr = head;
 printf("List elements in Backward Traversal: ");
 backward_trav(ptr);
 printf("%d\n", head->data);
 printf("\n");
 break;
 case 7:
 count(head);
 break;
 case 8:
 break;
 default:
 printf("Invalid input!\n");
 }
 }while(choice != 8);
}
