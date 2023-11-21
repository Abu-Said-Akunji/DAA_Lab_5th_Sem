#include <stdio.h>

int findRotationCount(int arr[], int size) {
   int a=0;
   int count=0;
 if(arr[a]<=arr[size-1]){
    return count;
 }
 for (int i=0;i<size;i++){
    a++;
    count++;
    if(arr[a]<arr[i]){

        return count;

    }
 } }


int main() {
    int arr[] = {15, 18, 20, 3, 6, 12};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("%d",arr[-1]);

    int rotationCount = findRotationCount(arr, size);
    printf("Number of right rotations: %d\n", rotationCount);

    return 0;
}

