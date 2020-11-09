#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head,*last;

void createList(int n);
void displayListFromFirst();
//void displayListFromEnd();
void insertAtBeginning(int data);
void insertAtN(int data, int position);


int main()
{
    int n, data;

    head = NULL;
    last = NULL;

    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);
    createList(n);
    displayListFromFirst();
    //displayListFromEnd();

    printf("Enter node position: ");
    scanf("%d", &n);
    printf("Enter data you want to insert at %d position: ", n);
    scanf("%d", &data);
    insertAtN(data, n);
    displayListFromFirst();
    //displayListFromEnd();

    return 0;
}
void createList(int n)
{
    int i, data;
    struct node *newNode;
            head = (struct node *)malloc(sizeof(struct node));
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            last = head;
            for(i=2; i<=n; i++)
            {
                newNode = (struct node *)malloc(sizeof(struct node));
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = last;
                    newNode->next = NULL;

                    last->next = newNode;
                    last = newNode;
            }
        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }

void displayListFromFirst()
{
    struct node * temp;
        temp = head;
        printf("\n\nDATA IN THE LIST From First:\n");

        while(temp != NULL)
        {
            printf("DATA = %d\n", temp->data);
            temp = temp->next;
        }
    }
/*void insertAtBeginning(int data){
    struct node * newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        printf("NODE INSERTED SUCCESSFULLY AT THE BEGINNING OF THE LIST\n");
}*/

/*void insertAtEnd(int data)
{
    struct node * newNode;
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;
}*/
void insertAtN(int data, int position)
{
    int i;
    struct node * newNode, *temp;
        temp = head;
        i=1;

        while(i<position-1 && temp!=NULL)
        {
            temp = temp->next;
            i++;
        }

        /*if(position == 1)
        {
        /*fr inserting first positn
        struct node * newNode;
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = head;
        newNode->prev = NULL;
        head->prev = newNode;
        head = newNode;
        }
        else if(temp == last)
        {
            /*fr inserting last positn
             struct node * newNode;
        newNode = (struct node *)malloc(sizeof(struct node));

        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = last;

        last->next = newNode;
        last = newNode;
        }
        else if(temp!=NULL)
        {*/
            newNode = (struct node *)malloc(sizeof(struct node));

            newNode->data = data;
            newNode->next = temp->next;
            newNode->prev = temp;
            //if(temp->next != NULL)
            //{
                temp->next->prev = newNode;
            //}
            temp->next = newNode;
        //}
    }



/*void displayListFromEnd()
{
    struct node * temp;
        temp = last;
        printf("\n\nDATA IN THE LIST From End:\n");

        while(temp != NULL)
        {
            printf("DATA = %d\n", temp->data);
            temp = temp->prev;
        }
    }*/


