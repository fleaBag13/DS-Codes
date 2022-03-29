#include<stdio.h>

int queue[10], max, front, rear, i, j, a, choice, qmax, pos;

int enqueue(int a)
{
    if(rear == max-1)
    {
        printf("Queue OVERFLOW\n");
        return -1;
    }
    else if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=a;
    }
    else
    {
        rear = rear + 1;
        queue[rear]=a;
    }
}

int dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW\n");
    }
    else
    {
        if(front==rear)
        {
            a=queue[front];
            front=-1;
            rear=-1;
        }
        else
        {
            pos = 0;
            qmax = queue[0];
            for(i=1; i<=rear; i++)
            {
                if(queue[i] > qmax)
                {
                    pos = i;
                    qmax = queue[i];
                }
            }

            for(j=pos; j<=rear-1; j++)
            {
                queue[j] = queue[j+1];
            }
            rear = rear - 1;
            a = qmax;
        }
        printf("Value deleted: %d\n", a);
    }
}

int getFront()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW\n");
    }
    if(front!=-1 && rear!=-1)
    {
        return queue[front];
    }
}

int getRear()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW\n");
    }
    if(front!=-1 && rear!=-1)
    {
        return queue[rear];
    }
}

void size()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue UNDERFLOW\n");
    }
    else
    {
        int i, count=0;
        for(i=front; i<=rear; i++)
        {
            count = count + 1;
        }
        printf("Queue size: %d\n", count);
    }

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
        for(i=front; i<=rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main()
{
    front=-1;
    rear=-1;

    printf("\n Enter the max size of QUEUE : ");
    scanf("%d",&max);

 do
 {
     printf("\nImplementation of PRIORITY QUEUE:");
     printf("\n1.ENQUEUE\n2.DEQUEUE(as per priority)\n3.GET FRONT\n4.GET REAR\n5.SIZE\n6.DISPLAY\n7.EXIT");
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
           dequeue();
           break;
        }
        case 3:
        {
           printf("The front element of the queue: %d\n", getFront());
           break;
        }
        case 4:
        {
           printf("The rear element of the queue: %d\n", getRear());
           break;
        }
        case 5:
       {
         size();
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
         printf("Invalid input!\n");
       }

    }
 }
 while(choice != 7);


    return 0;
}
