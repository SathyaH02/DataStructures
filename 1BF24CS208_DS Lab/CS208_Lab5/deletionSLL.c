# include <stdio.h>
# include <stdlib.h>

struct node{
    int data;
    struct node * next;
};

struct node * head=NULL;

void createLinkedList(int n)
{
    struct node * newNode, * temp;
    int data;
    if (n<=0)
    {
        printf("No.of nodes should be greater than 0\n");
        return;
    }
    for (int i=1;i<=n;i++)
    {
        newNode=(struct node *)malloc (sizeof (struct node));
        if (newNode==NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ",i);
        scanf("%d",&newNode->data);
        newNode->next=NULL;

        if (head==NULL)
        {
            head=newNode;
        }
        else{
            temp->next=newNode;
        }
        temp=newNode;
    }
    printf("\nCreated a linked list of size %d",n);
}

void deleteFirst()
{
    struct node *temp=head;
    if (head==NULL)
    {
        printf("List is empty");
        return;
    }
    head=head->next;
    printf("Deleted %d",temp->data);
    free(temp);
}

void deleteEnd()
{
    struct node *temp=head,*prev;
    if (head==NULL)
    {
        printf("List is empty");
        return;
    }
    if (head->next==NULL)
    {
        printf("Deleted %d",head->data);
        free(head);
        head=NULL;
        return;
    }
    while (temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    printf("Deleted %d",temp->data);
    free(temp);
    prev->next=NULL;
}

void deleteSpecific(int value)
{
    struct node *temp=head,*prev=NULL;
    if (head==NULL)
    {
        printf("List is empty");
        return;
    }
    if (head->data==value)
    {
        head=head->next;
        printf("Deleted %d",head->data);
        free(temp);
        return;
    }
    while (temp!=NULL && temp->data!=value)
    {
        prev=temp;
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("%d is not found",value) ;
        return;
    }
    prev->next=temp->next;
    printf("Deleted %d",temp->data);
    free(temp);
}

void display()
{
    if (head==NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    while (temp->next!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}

int main()
{
    int ch,n,data,pos;
    printf("Enter the operation you want to perform. 1: Create Linked list, 2: Delete the 1st node, 3: Delete the last node, 4: Delete a specific value, 5: Display the elements of the list, 0: Exit\n");
    scanf("%d",&ch);

    while (ch != 0)
    {
        switch(ch)
        {
        case 1:
            printf("Enter no.of nodes: ");
            scanf("%d",&n);
            createLinkedList(n);
            break;
        case 2:
            deleteFirst();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            printf("Enter the element to be deleted: ");
            scanf("%d",&data);
            deleteSpecific(data);
            break;
        case 5:
            printf("Elements of the Linked list: ");
            display();
            break;
        case 0:
            printf("Exiting\n");
            break;
        default:
            printf("Invalid choice.Try again\n");
        }
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
    }
    return 0;
}
