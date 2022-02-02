//insert the element at sorted position 
//O(1)-O(n^2) -> no. of passes = (n-1) mo.of comparisons=n*(n-1)/2 
//Best method is to use with LinkedList because we dont have to shift elements in it just insert

#include<iostream>
using namespace std;

//For Array Increasing order
void Isertionsort(int a[],int n){
    for (int i = 1; i < n;i++){  //Loop for passes (start from 1,leave 0th element, cuz it  is fixed )
        int j = i - 1; //for shifting
        int x = a[i]; //element to be compared and inserted
        while(a[j]>x && j>-1){
            a[j + 1] = a[j]; //shifting 
            j--;
        }
        a[j + 1] = x;
    }
}

int main() {
int A[]={11,13,7,12,16,9,24,5,10,3},n=10;
Isertionsort(A,n);
for(int i=0;i<10;i++)
printf("%d ",A[i]);
printf("\n");
  }