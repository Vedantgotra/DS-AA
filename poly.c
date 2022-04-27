#include <stdio.h>
#include <stdlib.h>
typedef struct lklist
{
    int coeff;
    int power;
    struct lklist *next;

} node;
void main()
{
    void insertatbeg(node **, int, int);
    void traverse(node *);
    node *head = NULL, *head1 = NULL, *head2 = NULL, *temp, *temp1;
    int i, t, c, p, c1;
    printf("Enter the No of Terms for first polynomial\n");
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        printf("Enter the value for term %d of coeffecient and powerln", i + 1);
        scanf("%d %d", &c, &p);
        insertatbeg(&head, c, p);
    }
    traverse(head);

    printf("\nEnter the No of Terms for 2nd polynomial\n");
    scanf("%d", &t);
    for (i = 0; i < t; i++)
    {
        printf("Enter the value for term %d of coeffecient and power \n", i + 1);
        scanf("%d %d", &c, &p);
        insertatbeg(&head1, c, p);
    }
    traverse(head1);

    printf("the Addition of Two Polyomial");
    for (temp = head; temp != NULL; temp = temp->next)
    {
        for (temp1 = head1; temp1 != NULL; temp1 = temp1->next)
        {
            if (temp->power == temp1->power)
            {
                c1 = temp->coeff + temp1->coeff;
                insertatbeg(&head2, c1,temp->power);
            }
            else if(temp1->next==NULL){
                   insertatbeg(&head2,temp->coeff,temp->power);
            }
        }
    }
    for (temp1 = head1; temp1 != NULL; temp1 = temp1->next)
    {
        for (temp = head; temp != NULL; temp = temp->next)
        {
              if(temp->next==NULL){
                  insertatbeg(&head2,temp1->coeff,temp->power);
              }

        }
    }
    traverse(head2);
}

void insertatbeg(node **head, int c, int p)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->coeff = c;
    temp->power = p;
    temp->next = *head;
    *head = temp;
}
void traverse(node *head)
{
    node *temp;
    temp = head;
    while (temp != NULL)
    {
        if (temp->coeff < 0)
        {
            printf("%dx^%d", temp->coeff, temp->power);
        }

        else if (temp == head)
        {
            printf("%dx^%d", temp->coeff, temp->power);
        }
        else if (temp->coeff > 0)
        {
            printf("+%dx^%d", temp->coeff, temp->power);
        }
        else if (temp->next == NULL)
        {
            printf("+%dx^%d", temp->coeff, temp->power);
        }
        temp = temp->next;
    }
}
