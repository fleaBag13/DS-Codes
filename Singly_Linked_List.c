#include<stdio.h>
#include<stdlib.h>
struct node{
 int data;
 struct node *next;
};
int a, b;
struct node *head;
 void insert_beg(int a)
 {
 struct node *new_node = (struct node*)malloc(sizeof(struct node));
 new_node -> data = a;
 new_node -> next = head;
 head = new_node;
 }
 int search(int a, struct node *head)
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else
 {
 struct node *temp = head;
 while(temp != NULL)
 {
 if(temp->data == a)
 {
 return 0;
 }
 temp = temp->next;
 }
 printf("Element not found!\n");
 return -1;
 }
 }
 void insert_end(int a)
 {
 struct node *new_node = (struct node*)malloc(sizeof(struct node));
 struct node *temp = head;
 new_node -> data = a;
 new_node -> next = NULL;
 if(head==NULL)
 {
 head = new_node;
 }
 else
 {
 while(temp -> next != NULL)
 {
 temp = temp -> next;
 }
 temp -> next = new_node;
 }
 }
 void insert_bef(int a, int b)
 {
 struct node *new_node = (struct node*)malloc(sizeof(struct node));
 struct node *temp = head;
 struct node *prev;
 new_node -> data = a;
 if(head==NULL)
 {
 head = new_node;
 }
 else
 {
 while(temp -> data != b)
 {
 prev = temp;
 temp = temp -> next;
 }
 prev -> next = new_node;
 new_node -> next = temp;
 }
 }
 void delete_beg()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else
 {
 struct node *temp = head;
 printf("Element deleted: %d\n", temp -> data);
 head = head -> next;
 free(temp);
 }
 }
 void delete_end()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else if(head -> next == NULL)
 {
 struct node *temp = head;
 printf("Element deleted: %d\n", temp -> data);
 head = NULL;
 free(temp);
 }
 else
 {
 struct node *temp1 = head;
 struct node *temp2 = head;
 while(temp1 -> next != NULL)
 {
 temp2 = temp1;
 temp1 = temp1 -> next;
 }
 printf("Element deleted: %d\n", temp1 -> data);
 temp2 -> next = NULL;
 free(temp1);
 }
 }
 void delete_bef(int b)
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else if(head -> next == NULL)
 {
 struct node *temp = head;
 printf("Element deleted: %d\n", temp -> data);
 head = NULL;
 free(temp);
 }
 else
 {
 struct node *temp = head;
 struct node *prev;
 while(temp -> next -> data != b)
 {
 prev = temp;
 temp = temp -> next;
 }
 prev -> next = temp -> next;
 printf("Element deleted: %d\n", temp -> data);
 free(temp);
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
 while(temp != NULL)
 {
 printf("%d --> ", temp -> data);
 temp = temp -> next;
 }
 printf("\n");
 }
 }
 void backward_trav(struct node *ptr)
 {
 if(ptr == NULL)
 {
 return;
 }
 backward_trav(ptr -> next);
 printf("%d --> ", ptr -> data);
 }
 void sort()
 {
 if(head == NULL)
 {
 printf("UNDERFLOW!\n");
 }
 else {
 struct node *temp1 = head;
 struct node *temp2;
 int swap;
 while(temp1 -> next != NULL)
 {
 temp2 = temp1 -> next;
 while(temp2 != NULL)
 {
 if(temp1 -> data > temp2 -> data)
 {
 swap = temp1 -> data;
 temp1 -> data = temp2 -> data;
 temp2 -> data = swap;
 }
 temp2 = temp2 -> next;
 }
 printf(" %d -> ", temp1 -> data);
 temp1 = temp1 -> next;
 }
 printf("%d", temp1->data);
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
 int count = 0;
 while(temp != NULL)
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
 printf("\n Menu Driven LINKED LIST\n\n1.Insert at
beginning\n2.Insert at end\n3.Insert before a node\n4.Delete from
beginning\n5.Delete from end\n");
 printf("6.Delete node before specified location\n7.Forward
Traversal\n8.Backward Traversal\n9.Sort\n10.Count number of
nodes\n11.Search\n12.Exit\n");
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
 printf("Enter the value to be inserted: ");
 scanf("%d", &a);
 printf("Enter the value before which to be inserted: ");
 scanf("%d", &b);
 insert_bef(a, b);
 break;
 case 4:
 delete_beg();
 break;
 case 5:
 delete_end();
 break;
 case 6:
 printf("Enter the value before which to be deleted: ");
 scanf("%d", &b);
 delete_bef(b);
 break;
 case 7:
 forward_trav();
 break;
 case 8:
 ptr = head;
 printf("List elements in Backward Traversal: ");
 backward_trav(ptr);
 printf("\n");
 break;
 case 9:
 printf("Sorted linked list: ");
 sort(head);
 printf("\n");
 break;
 case 10:
 count(head);
 break;
 case 11:
 printf("Enter element to be searched: ");
 scanf("%d", &a);
 val = search(a, head);
 if(val==0)
 {
 printf("Element found!\n");
 }
 break;
 case 12:
 break;
 default:
 printf("Invalid input!\n");
 }
 }while(choice != 12);
}
