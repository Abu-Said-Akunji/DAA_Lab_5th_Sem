#include<stdio.h>
void find_product(int arr[],int size){
    int product=1;
  int n=2*size;

for (int i = 0; i < n; i++) {

        if(n<=size){

        totalProduct *= arr[i];
    }


        int productExceptCurrent = totalProduct / arr[i];
        printf("%d ", productExceptCurrent);

}


}
int main(){
int arr[]={3,4,5,1,2};
int size=sizeof(arr)/sizeof(arr[0]);
find_product(arr,size);

}
