#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
void displayList();
//void deleteFromBeginning();
//void deleteFromEnd();
void deleteFromN(int position);


int main()
{
    int n, data, choice=1;

    head = NULL;
    last = NULL;
    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);
    createList(n);
    //deleteFromBeginning();
    //deleteFromEnd();
    printf("Enter the node position which you want to delete: ");
    scanf("%d", &n);
    deleteFromN(n);
    displayList();
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
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last node
        }
}

void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move the current pointer to next node */
            temp = temp->next;
        }
    }
}

void deleteFromN(int position)
{
    struct node *current;
    int i;
    current = head;

    for(i=1; i<position && current!=NULL; i++)
    {
        current = current->next;
    }

    if(position == 1)
    {
        //delete From Beginning
        struct node * toDelete;
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
    }
    else if(current == last)
    {
        //elete From End
        struct node * toDelete;
        toDelete = last;

        last = last->prev; // Move last pointer to 2nd last node
        last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
    }
    else if(current != NULL)
    {
        current->prev->next = current->next;
        current->next->prev = current->prev;

        free(current); // Delete the n node

        printf("SUCCESSFULLY DELETED NODE FROM %d POSITION.\n", position);
    }
}
    /*else
    {
        printf("Invalid position!\n");
    }*/

/*void deleteFromBeginning()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
        printf("SUCCESSFULLY DELETED NODE FROM BEGINNING OF THE LIST.\n");
    }
}

void deleteFromEnd()
{
    struct node * toDelete;

    if(last == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = last;

        last = last->prev; // Move last pointer to 2nd last node
        last->next = NULL; // Remove link to of 2nd last node with last node

        free(toDelete);       // Delete the last node
        printf("SUCCESSFULLY DELETED NODE FROM END OF THE LIST.\n");
    }
}*/
