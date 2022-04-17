#include <stdio.h>
#include <stdlib.h>
typedef struct lklist
{
    int info;
    struct lklist *next;
} node;

void main()
{
    int ch, item, data;
    node *head, *loc;
    void insertshuru(node **, int);
    void insertant(node **, int);
    void insertbaadme(node *, int, int);
    void chalo(node *);
    node *search(node *, int);
    void deleteshuru(node **);
    void deleteant(node **);
    void deletebaadme(node *, int);
    void deletepuri(node **);
    void createlist(node **);
    createlist(&head);
    while (1)
    {
        printf("\npress 1 for insert at begning\n");
        printf("press 2 for insert at end\n");
        printf("press 3 insert after element \n");
        printf("press 4 for delete at begning\n");
        printf("press 5 delete at end\n");
        printf("press 6 delete specific element\n");
        printf("press 7 delete complete all \n");
        printf("press 8 for search\n");
        printf("press 9 for traversing\n");
        printf("press 10 for exit\n");
        printf("Enter Your Choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("enter the element you want to insert\n");
            scanf("%d", &data);
            insertshuru(&head, data);
            break;
        case 2:
            printf("enter the element you want to insert\n");
            scanf("%d", &data);
            insertant(&head, data);
            break;
        case 3:
            printf("enter the element after you want to inserted\n");
            scanf("%d", &item);
            printf("enter the element which is to be inserted\n");
            scanf("%d", &data);
            insertbaadme(head, item, data);
            break;
        case 4:
            if (head == NULL)
            {
                printf("linked is empty\n");
            }
            else
            {
                deleteshuru(&head);
            }
            break;
        case 5:
            if (head == NULL)
            {
                printf("linked is empty\n");
            }
            else
            {
                deleteant(&head);
            }
            break;
        case 6:
            printf("enter the element you want to delete\n");
            scanf("%d", &item);
            deletebaadme(head, item);
            break;
        case 7:
            deletepuri(&head);
            break;
        case 8:
            printf("enter the element you want to search\n");
            scanf("%d", &item);
            loc = search(head, item);
            if (loc != NULL)
            {
                printf("element found\n");
            }
            else
            {
                printf("element not found\n");
            }
            break;
        case 9:
            chalo(head);
            break;
        case 10:
            exit(1);
        default:
            printf("wrong choice\n");
            break;
        }
    }
}
void createlist(node **head)
{
    *head = NULL;
}
void insertshuru(node **head, int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->info = data;
    if (*head != NULL)
    {
        temp->next = *head;
    }
    else
        temp->next = NULL;
    *head = temp;
    printf("node inserted\n");
}
void insertant(node **head, int data)
{
    node *temp, *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    ptr->next = NULL;
    temp = *head;
    if (*head == NULL)
    {
        *head = ptr;
    }
    else
    {
        while (temp->next != NULL)
        {

            temp = temp->next;
        }

        temp->next = ptr;
    }
    printf("node inserted\n");
}

void insertbaadme(node *head, int item, int data)
{
    node *temp, *ptr;
    temp=head;
    ptr = (node *)malloc(sizeof(node));
    ptr->info = data;
    if (head == NULL)
    {
        printf("cant insertn\n");
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->info ==item)
            {
                ptr->next = temp->next;
                temp->next = ptr;
                printf("node inserted\n");
                break;
            }
            temp = temp->next;
        }
    }
    if (temp == NULL)
    {
        printf("element not found\n");
    }
}
void chalo(node *head)
{
    node *temp;
    if (head == NULL)
    {
        printf("linked list empty\n");
    }
    else
    {
        temp = head;
        printf("linked list ");
        while (temp != NULL)
        {

            printf("%d,", temp->info);
            temp = temp->next;
        }
    }
}
node *search(node *head, int item)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->info == item)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}
void deleteshuru(node **head)
{
    if (*head == NULL)
    {
        printf("linked is empty\n");
    }
    else
    {
        node *temp;
        temp=*head;
        *head = temp->next;
        free(temp);
        printf("element deleted\n");
    }
}
void deleteant(node **head)
{

    node *temp, *ptr;
    temp = *head;
    if (*head == NULL)
    {
        printf("linkednlist is empty\n");
    }
    else if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next != NULL)
        {
            ptr = temp;
            temp = temp->next;
        }
        ptr->next = NULL;
        free(temp);
        printf("element deleted\n");
    }
}
void deletebaadme(node *head, int item)
{
    node *temp, *ptr;
    temp=head;
    if (head == NULL)
    {
        printf("cant insert");
    }
    else
    {
        while (temp!= NULL)
        {
            ptr = head;
            if (temp->info == item)
            {

                ptr->next = temp->next;
                free(temp);
                printf("Element Deleted");
                break;
            }
            ptr = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            printf("element not Found\n");
        }
    }
}
void deletepuri(node**head){
    node*temp,*ptr;
    temp=*head;
    *head=NULL;
    if (*head==NULL){
        printf("Empty Linked LIst");
    }
    else{
    while (temp->next!=NULL)
    {
           ptr=temp;
           temp=temp->next; 
           free(ptr); 
    }
    printf("deleted");
}
}
