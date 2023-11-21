#include<stdio.h>
#include<stdlib.h>
int arr_length(int arr[])
{
    int i;
    int count = 0;
    for(i=0; arr[i]!='\0'; i++)
    {
        count++;
    }
    return count;
}
int mergearray(int arr1[], int arr2[],int arr3[],int arr4[], int n1, int n2,int n3,int n4,int* arr[])
{


    int n =n1 + n2+n3+n4;
    int i, j;


    for (i = 0; i < n1; i++) {
        arr[i] = arr1[i];
    }

    for (i = 0, j = n1;j < (n1+n2) && i < n2; i++, j++) {
        arr[j] = arr2[i];
    }
    for (i = 0, j = n2;j < (n2+n3) && i < n3; i++, j++) {
        arr[j] = arr3[i];
    }
    for (i = 0, j = n3;j < (n3+n4) && i < n4; i++, j++) {
        arr[j] = arr4[i];
    }


}
void main(){
    int n1,n2,n3,n4,n;

    int arr1[10]={1,5,2,7};
    int arr2[10]={4,2,7};
    int arr3[10]={9,1,5,3};
    int arr4[10]={6,2,8};
    n1 = arr_length(arr1);
    n2= arr_length(arr2);
    n3=arr_length(arr3);
    n4=arr_length(arr4);
    n=n1+n2+n3+n4;
    int arr[n];
    mergearray( arr1,  arr2, arr3, arr4,  n1,  n2, n3, n4,&arr);
     for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

}


