#include<stdio.h>
void Prefixsum(int arr[],int n){
    int prefix_sum[n];

for(int i=0;i<n;i++){
          int sum=0;
        for(int j=0;j<=i;j++){
            sum+=arr[j];
       }
        prefix_sum[i]=sum;

}
for(int i=0;i<n;i++){
     printf("%d\t",prefix_sum[i]);
}

}


int main(){
    int n;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements of the array:");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++){
        printf("%d\t",arr[i]);
    }
    printf("\n");
   Prefixsum(arr,n);
  return 0;
}
