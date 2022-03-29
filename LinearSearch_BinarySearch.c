#include <stdio.h>

void linSearch(int val, int array[], int n)
{
       int j;
       for (j = 0; j < n; j++)
      {
       if (array[j] == val)
       {
           printf("%d is present at location %d.\n", val, j+1);
           break;
       }
      }
       if (j == n)
      {
       printf("%d is not present in array.\n", val);
      }
}

int binSearch(int val, int array[], int n)
{
    int start = 0;
    int end = n-1;
    int mid;
    while(start<=end)
    {
        mid = (start + end)/2;
        if(array[mid]==val)
        {
            printf("%d is present at location %d.\n", val, (mid+1));
            break;
        }
        else if(val < array[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
}

void main()
{
   int array[50], val, i, n, ch;

   printf("\n\tLINEAR AND BINARY SEARCH\n\nEnter the number of elements in array: ");
   scanf("%d",&n);

   printf("\n");
   for (i = 0; i < n; i++)
   {
       printf("Enter array element %d: ", (i+1));
       scanf("%d", &array[i]);
   }
   printf("\nEnter the number to be searched: ");
   scanf("%d", &val);

   do{
       printf("\n1.Linear Search Algorithm\n2.Binary Search Algorithm\n3.Exit\n\nEnter choice: ");
       scanf("%d", &ch);

       switch(ch)
       {
           case 1:
           linSearch(val, array, n);
           break;

           case 2:
           binSearch(val, array, n);
           break;

           case 3:
           break;

           default:
           printf("Invalid input!");
       }
   }
   while(ch!=3);


}

