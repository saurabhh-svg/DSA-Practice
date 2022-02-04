//Modification of Insertion sort
//Time O(nlogn) or O(n^3/2) or O(n^5/2)

#include <iostream>
#include <algorithm>
using namespace std;

// For Array Increasing order
void shellSort(int a[], int n)
{
    int gap, i, j,temp;
    for (gap = n / 2; gap >= 1;gap=gap/2){
        for (i = gap; i < n;i++){
            temp = a[i];
            j= i - gap;
            while(j>=0 && a[j]>temp){
                a[j + gap] = a[j];
                j = j - gap;
            }
            a[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10;
    shellSort(A, n);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}