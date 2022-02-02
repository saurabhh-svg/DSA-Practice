//We select a position and we find out an element for that position
//use a pointer to find minimum element
//Select an element and compare it with entire array to find minimum
//comparisons -> n(n-1)/2 ->O(n^2)
//Swaps -> O(n) [Minimum Swap Algo]
//If i perform K Passes i get K smaller elements from start

//NOT Stable XX
//NOT Adaptive

#include <iostream>
#include <algorithm>
using namespace std;

// For Array Increasing order
void selectionSort(int a[], int n)
{
    int k = 0;
    for (int i = 0; i < n - 1; i++){ // for passes
        k = i;
        for (int j =i; j < n; j++) { // for comparison
        if(a[j]<a[k])
            k = j; //k is storing index of minimum element
        }
        swap(a[i], a[k]);
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10;
    selectionSort(A, n);
    for (int i = 0; i < 10; i++)
        cout<< A[i]<<" ";
    cout << endl;
}