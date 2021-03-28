#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct queue
{
    int info;
    struct queue *next;
};
struct queue *front,*rear,*curr,*dis;
void enqueue()
{
    printf("Enter the Element to be Added\n");
    curr=(struct queue*)malloc(sizeof(struct queue));
    scanf("%d",&curr->info);
    curr->next=NULL;
    if(front==NULL)
    {
        front=rear=curr;
    }
    else
    {
        rear->next=curr;
        rear=curr;
    }
    printf("Inserted Successfully\n");
}
int dequeue()
{
    int val;
    if(front==NULL)
    {
        return -1;
    }
    else
    {
        val=front->info;
        
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
        return val;
    }
}
void display()
{
    dis=front;
    while(1)
    {
        printf("%d->",dis->info);
        if(dis->next==NULL)
        break;
        dis=dis->next;
    }
}
int main()
{
    int ch,val;
    front=rear=NULL;
    do
    {
        system("cls");
        printf("Enter your Choice\n");
        printf("1.Enqeueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {
            enqueue();
        }
        else if(ch==2)
        {
            
            val=dequeue();
            if(val!=-1)
            {
                printf("The removed value is %d",val);
            }
            else
            {
                printf("Queue is Empty\n");
            }
        }
        else if(ch==3)
        {
            display();
        }
        getch();
    } while (ch!=4);
    
}