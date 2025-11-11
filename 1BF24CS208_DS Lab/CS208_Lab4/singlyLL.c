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

void insertBegin(int data)
{
    struct node * newNode;
    newNode=(struct node *)malloc (sizeof (struct node));
    newNode->data=data;
    newNode->next=head;
    head=newNode;
    printf("%d inserted at the beginning\n",data);
}

void insertEnd(int data)
{
    struct node * newNode;
    newNode=(struct node *)malloc (sizeof (struct node));
    newNode->data=data;
    newNode->next=NULL;
    if (head==NULL)
    {
        head=newNode;
    }
    else
    {
        struct node *temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;
    }
    printf("Inserted %d at the end\n",data);
}

void insertPosition(int pos, int data)
{
    if (pos<1)
    {
        printf("Position can't be less than 1\n");
        return;
    }
    if (pos==1)
    {
        insertBegin(data);
        return;
    }
    struct node * newNode;
    newNode=(struct node *)malloc (sizeof (struct node));
    newNode->data=data;
    struct node *temp=head;

    for (int i=1;i<pos-1 && temp!=NULL;i++)
    {
        temp=temp->next;
    }
    if (temp==NULL)
    {
        printf("Position out of range\n");
        free(newNode);
    }
    else
    {
        newNode->next=temp->next;
        temp->next=newNode;
        printf("Inserted %d at %d\n",data,pos);
    }

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
    printf("Enter the operation you want to perform. 1: Create Linked list, 2: Insert data in the beginning, 3: Insert data at the end, 4: Insert data at a given position, 5: Display the elements of the list\n");
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
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            insertBegin(data);
            break;
        case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d",&data);
            insertEnd(data);
            break;
        case 4:
            printf("Enter the element and the position to be inserted at: ");
            scanf("%d",&data);
            scanf("%d",&pos);
            insertPosition(pos,data);
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
