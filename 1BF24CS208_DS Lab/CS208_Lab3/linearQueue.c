# include <stdio.h>
# define N 10
int queue[N];
int front=-1,rear=-1;

void enqueue()
{
    int x;
    printf("Enter the element to be inserted: ");
    scanf("%d",&x);
    if (front==-1 && rear==-1)
    {
        front=rear=0;
        queue[rear]=x;
    }
    else if (rear==N-1)
        printf("Queue overflow");
    else
    {
        rear++;
        queue[rear]=x;
    }
}

void dequeue()
{
    if (front==-1 && rear==-1)
    {
        printf("Queue underflow");
    }
    else if (front==rear)
    {
        printf("Deleted %d",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Deleted %d",queue[front]);
        front++;
    }
}

void display()
{
    if (front==-1 && rear==-1)
        printf("Queue is empty");
    else
    {
        for (int i=front;i<=rear;i++)
        printf("%d ",queue[i]);
    }
}

int main()
{
    int ch;
    printf("Enter your choice (1: Enqueue, 2: Dequeue, 3: Display, 0: Exit): ");
    scanf("%d",&ch);
    while (ch!=0)
    {
        switch (ch)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 0:
            printf("Exiting");
            break;
        default:
            printf("Invalid choice");
        }
        printf("\nEnter your choice: ");
        scanf("%d",&ch);
    }
}
