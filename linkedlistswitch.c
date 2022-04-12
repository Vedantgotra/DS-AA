#include <stdio.h>
#include <stdlib.h>
typedef struct lklist
{
    int info;
    struct lklist *next;
} node;
void main()
{
    int data, ch,no,i=0,item,count=0,flag;
    node *head = NULL, *temp=NULL, *ptr=NULL;
    while (1)
    {
        printf("\npress 1 for insert at begning\n");
        printf("press 2 for insert at end\n");
        printf("press 3 for traverse\n");
        printf("press 4 for insert after\n");
        printf("press 5 for delete at begning\n");
        printf("press 6 for search\n");
        printf("press 10 for exit\n");
        printf("ENTER YOUR CHOICE\n");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("insert at begning\n");
            printf("enter the data to be inserted\n");
            scanf("%d", &data);

            temp = (node *)malloc(sizeof(node));
            temp->info = data;
            if (head != NULL)
            {
                temp->next = head;
                ;
            }
            else
            {
                temp->next = NULL;
            }
            head = temp;
            printf("Node Inserted\n");
            break;
        case 2:
            printf("insert at End\n");
            printf("Enter the Element to be Entered at End\n");
            scanf("%d", &data);
            temp = (node *)malloc(sizeof(node));
            temp->info = data;
            temp->next = NULL;
            if (head == NULL)
            {
                head = temp;
            }
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = temp;

            printf("node INserted");

            break;
        case 3:
            printf("traversing\n");
            temp = head;
            printf("Linked List ");
            while (temp != NULL)
            {
                printf("%d,", temp->info);
                temp = temp->next;
            }
            break;
            case 4:
            printf("Enter the NO After Which you Want to insert");
            scanf("%d",&no);
            printf("Enter the Element\n");
            scanf("%d", &data);
            ptr= (node *)malloc(sizeof(node));
             ptr->info=data;
            temp=head;
              while (i<no)
              {
                  if (temp==NULL){
                      printf("cant insert\n");
                    
                  }

                temp=temp->next; 
                i++;
              }
             
             ptr->next=temp->next;
              temp->next=ptr;
               printf("node inserted");
            break;
            case 5:
            printf("delete at begning");
            if(head==NULL){
                  printf("empty linked list");
                  break;
            }
            ptr=head;
            head=head->next;
            free(ptr);
            break;
            case 6:
            printf("Searching\n");
            printf("ENter the item you Want to Search\n");
            scanf("%d",&item);
            temp=head;
            while (temp!=NULL)
            {
                
                    
               
                if (temp->info==item)    
                {
                    
                    flag=1;
                   printf("Element foound");
                   break;
                   
                }
                 
                  if(flag==0)
               printf("Element Not Found");
                temp=temp->next;
            }
                
            
            
            break;

        case 10:
            exit(0);

        default:
            printf("Invalid Input\n");
            break;
        }
    }
}