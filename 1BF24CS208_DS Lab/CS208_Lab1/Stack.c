# include <stdio.h>
# define N 10
int stack[N];
int top=-1;
void push(int x)
{
    if (top==(N-1))
    printf("Stack overflow\n");
    else{
        top++;
        stack[top]=x;
    }
}

void pop()
{
    if (top==-1)
    printf("Stack is empty\n");
    else
    top--;
}

void peek()
{
    if (top==-1)
    printf("Stack is empty\n");
    else
    printf("%d\n",stack[top]);
}

int main()
{
    int c;
    printf("Enter your choice of operation 1-Push, 2-Pop, 3-Peek, 0-Exit : ");
    scanf("%d",&c);
    while (c!=0)
    {
        int x;
        switch (c)
        {
            case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d",&x);
            push(x);
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            default:
            printf("Invalid choice\n");
        }
        printf("Enter your choice: ");
        scanf("%d",&c);
        if (c==0)
            printf("Exiting");
    }
    return 0;
}
