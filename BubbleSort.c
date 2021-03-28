#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
    int a[10],i,temp,j;
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
        for(j=0;j<10-i;j++)
        {
            if(a[j]>a[j+1])
            {
              temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
            }
        }
    }
    printf("After Sorted\n");
    for(i=0;i<10;i++)
    printf("%d ",a[i]);
    getch();

}