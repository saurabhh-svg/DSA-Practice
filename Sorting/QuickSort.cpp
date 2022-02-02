//Selecting an element and finding its position
//All elements before pivot is smaller and after pivot must be larger than pivot
// Mark end of list with INFINTY

// If we Take first element of list as pivot, then
// Worst Case -> Already Sorted (Either Ascending Or Descending)-> O(n^2)
// Best Case -> Paritioning in Middle -> O(nlogn)

//If we take mid element of list as pivot,
//Worst Case -> Partition in end 
//Best Case -> sorted list

// PARTITIONING PROCEDURE + RECURSIVE
//SELECTION EXCHANGE SORT 

#include <iostream>
#include <algorithm>
using namespace std;

// For Array Increasing order
int partion(int a[],int l,int h){
    int pivot = a[l];
    int i = l, j = h;
   do{
    do{i++; } while (a[i] <= pivot);
    do { j--; } while (a[j] > pivot);
    if(i<j) swap(a[i], a[j]);
   } while (i < j); // while loop breaks when i>j
   swap(a[l], a[j]);
   return j; // partioning position
}

void quickSort(int a[], int start,int end){
        if (start < end){
         int j = partion(a, start, end);
            quickSort(a, start, j );
            quickSort(a, j + 1, end);
        }
}

int main(){
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3,INT_MAX}, n = 11;
    quickSort(A, 0,n-1);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}