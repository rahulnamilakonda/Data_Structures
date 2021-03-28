#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{

    int a[10],i,temp,j,min;
    printf("Enter the numbers\n");
    for(i=0;i<10;i++)
    {
        printf("Number %d: ",i+1);
        scanf("%d",&a[i]);
        system("cls");
    }
    printf("Enter Numbers are:\n");
    for(i=0;i<10;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<10;i++)
    {
        min=i;
        for(j=i+1;j<10;j++)
        {
            if(a[min]>a[j])
            min=j;
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    printf("After Sorted\n");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    getch();
}