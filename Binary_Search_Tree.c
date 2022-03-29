#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *left;
    int data;
    struct node *right;
};

int a, b;
struct node *root;


    struct node *smallest(struct node *temp)
    {
        if((temp == NULL) || (temp -> left == NULL))
        {
            return temp;
        }
        else
        {
            return smallest(temp -> left);
        }
    };

    struct node *largest(struct node *temp)
    {
        if((temp == NULL) || (temp -> right == NULL))
        {
            return temp;
        }
        else
        {
            return largest(temp -> right);
        }
    };

    struct node *insert(struct node *root, int a)
    {
        struct node *new_node = (struct node*)malloc(sizeof(struct node));
        struct node *temp1, *temp2;
        new_node -> data = a;
        new_node -> left = NULL;
        new_node -> right = NULL;

        if(root == NULL)
        {
            root = new_node;
        }
        else
        {
            temp2 = NULL;
            temp1 = root;
            while(temp1 != NULL)
            {
                temp2 = temp1;
                if(a <= temp1->data)
                {
                    temp1 = temp1 -> left;
                }
                else
                {
                    temp1 = temp1 -> right;
                }
            }
            if(a < temp2 -> data)
            {
                temp2->left = new_node;
            }
            else
            {
                temp2->right = new_node;
            }
        }
        return root;
    }


    struct node *deleteNode(struct node *root, int a)
    {
        if(root == NULL)
        {
            root = root;
        }
        else if(a > root->data)
        {
            root -> right = deleteNode(root->right, a);
        }
        else if(a < root->data)
        {
            root -> left = deleteNode(root->left, a);
        }
        else
        {
            if(root -> left == NULL)
            {
                struct node *temp = root -> right;
                free(root);
                return temp;
            }
            else if(root -> right == NULL)
            {
                struct node *temp = root -> left;
                free(root);
                return temp;
            }
            else
            {
                struct node *temp = smallest(root -> right);
                root -> data = temp -> data;
                root -> right = deleteNode(root -> right, temp -> data);
            }
        }
        return root;
    }

    void preorder_trav(struct node *temp)
    {
        if(temp == NULL)
        {
            return;
        }
        else if(temp != NULL)
        {
            printf("%d, ", temp -> data);
            preorder_trav(temp -> left);
            preorder_trav(temp -> right);
        }

    }

    void inorder_trav(struct node *temp)
    {
        if(temp == NULL)
        {
            return;
        }

        inorder_trav(temp->left);

        printf("%d, ", temp->data);

        inorder_trav(temp->right);

    }

    void postorder_trav(struct node *temp)
    {
        if(temp == NULL)
        {
            return;
        }
        else if(temp != NULL)
        {
            postorder_trav(temp -> left);

            postorder_trav(temp -> right);

            printf("%d, ", temp -> data);
        }

    }

    int countTotal(struct node *temp)
    {
        if(temp != NULL)
        {
            return(countTotal(temp -> left) + countTotal(temp -> right) + 1);
        }
        else {
            return 0;
        }
    }

    int countInternal(struct node *temp)
    {
        if(temp==NULL || ((temp->left == NULL) && (temp->right == NULL)))
        {
            return 0;
        }
        else
        {
            return(countInternal(temp -> left) + countInternal(temp -> right) + 1);
        }
    }

    int countExternal(struct node *temp)
    {
        if(temp==NULL)
        {
            return 0;
        }
        else if((temp->left == NULL) && (temp->right == NULL))
        {
            return 1;
        }
        else
        {
            return(countExternal(temp -> left) + countExternal(temp -> right));
        }
    }

    int bstHeight(struct node *temp)
    {
        if(temp == NULL)
        {
            return -1;
        }
        else
        {
            int lh = bstHeight(temp -> left);
            int rh = bstHeight(temp -> right);
            int maxx = ((lh > rh) ? lh : rh);
            return (maxx+1);
        }
    }

    void deleteTree(struct node *temp)
    {
    if (temp == NULL)
    {
        return;
    }

    deleteTree(temp->left);
    deleteTree(temp->right);

    printf("%d, ", temp->data);
    free(temp);
   }

   void mirrorTree(struct node *temp)
   {
       if(temp == NULL)
       {
           return;
       }
       else
       {
           mirrorTree(temp->left);

           mirrorTree(temp->right);

           struct node *temp2 = root->left;
           temp -> left = temp -> right;
           temp -> right = temp2;
       }
   }

int main()
{
    int choice, val;
    struct node *temp;
    struct node *ptr;
    do
    {
        printf("\n  Menu Driven BINARY SEARCH TREE\n\n1.Insert a node\n2.Delete a node\n3.Preorder Traversal\n4.Postorder Traversal\n5.Inorder Traversal\n");
        printf("6.Count total number of nodes\n7.Count total number of internal nodes\n8.Count total number of external nodes\n9.Height of the tree\n");
        printf("10.Largest element in the tree\n11.Smallest element in the tree\n12.Deleting entire tree\n13.Mirror Of BST\n14.Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
            printf("Enter the value to be inserted: ");
            scanf("%d", &a);
            root = insert(root, a);
            printf("Node inserted!\n");
            break;

        case 2:
            printf("Enter the value to be deleted: ");
            scanf("%d", &a);
            root = deleteNode(root, a);
            printf("Node deleted!\n");
            break;

        case 3:
            temp = root;
            printf("Preorder Traversal: ");
            preorder_trav(temp);
            printf("\n");
            break;

        case 4:
            temp = root;
            printf("Postorder Traversal: ");
            postorder_trav(temp);
            printf("\n");
            break;

        case 5:
            temp = root;
            printf("Inorder Traversal: ");
            inorder_trav(temp);
            printf("\n");
            break;

        case 6:
            temp = root;
            val = countTotal(temp);
            printf("The total number of nodes in the binary search tree = %d\n", val);
            break;

        case 7:
            temp = root;
            val = countInternal(temp);
            printf("The total number of internal nodes in the binary search tree = %d\n", val);
            break;

        case 8:
            temp = root;
            val = countExternal(temp);
            printf("The total number of external nodes in the binary search tree = %d\n", val);
            break;

        case 9:
            temp = root;
            val = bstHeight(temp);
            printf("The height of the binary search tree = %d\n", val);
            break;

        case 10:
            temp = root;
            ptr = largest(temp);
            printf("The element with the largest value in the tree is %d\n", ptr->data);
            break;

        case 11:
            temp = root;
            ptr = smallest(temp);
            printf("The element with the smallest value in the tree is %d\n", ptr->data);
            break;

        case 12:
            printf("Are you sure you want to delete the tree?(Y or N): ");
            char con;
            scanf(" %c", &con);
            temp = root;
            if(con == 'Y' || con == 'y')
            {
                printf("\nDeleting nodes: ");
                deleteTree(temp);
                printf("\nTree deleted.\n");
            }
            else
            {
                printf("Please choose another option!");
            }
            break;

        case 13:
            temp = root;
            mirrorTree(temp);
            printf("Mirror of BST updated!\n");
            break;

        case 14:
            break;

        default:
            printf("Invalid input!\n");
        }

    }while(choice != 14);

}
