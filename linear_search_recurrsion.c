#include<stdio.h>
#include<conio.h>
int linearfun(int [],int,int,int);
int main()
{
    int a[]={8,6,5,3,2,1,0,4,10,60};
    int i,re,key;
    printf("Enter the element to be searched\n");
    scanf("%d",&key);
    re=linearfun(a,key,10,0);
    if(re!=0)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
}
int linearfun(int a[],int key,int n,int index)
{
    int pos=0;
    if(index>10)
    {
        return pos;
    }
    else
    {
     if(a[index]==key)
     {
         pos=pos+index;
         return pos;
     }
     else
      return(linearfun(a,key,10,index+1));
    }
}
