#include<stdio.h>
#include<conio.h>
void binarysearch(int a[],int key,int low,int high);
int main()
{
    int a[]={1,2,3,4,5};
    int key,i;
    printf("Enter the key\n");
    scanf("%d",&key);
    binarysearch(a,key,0,4);
}
void binarysearch(int a[],int key,int low,int high)
{   
    int mid;
    if(low>=high)
    {   
    printf("Not found\n");
    return;
    }
    else
    {
        mid=(low+high)/2;
        if(key>a[mid])
        binarysearch(a,key,low=mid+1,high);
        else if(key<a[mid])
        binarysearch(a,key,low,high=mid-1);
        if(a[mid]==key)
       { printf("Key found\n");
        return ;
       }
    }
}