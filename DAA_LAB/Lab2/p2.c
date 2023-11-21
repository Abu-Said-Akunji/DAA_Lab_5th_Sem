#include<stdio.h>
int find_dominant(int arr[],int n){
    int sum=0;
  for(int j=1;j<n;j++){
        sum+=arr[j-1];
    if(arr[j]>sum){
        printf("\n%d",arr[j]);
    }

  }

}

int main(){
int arr[]={10,-5,6,9,-2,17};
int n=sizeof(arr)/sizeof(arr[0]);
for (int i=0;i<n;i++){
    printf("%d\t",arr[i]);
}
find_dominant(arr,n);



}
