//Divide and Conquer
//fastest -> O(nlogn)

#include <iostream>
#include <algorithm>
using namespace std;
// Iterative
void merge(int a[],int l,int h,int mid){
    int i=l, j=mid+1, k=l; //Merging two sections of same array
    int B[100]; //temp array to store sorted merged
    while(i<=mid && j<=h){
        if(a[i]<a[j]) B[k++] = a[i++];
            else
                B[k++] = a[j++];
    }
    for (; i <= mid;i++)
        B[k++] = a[i];
    for (; j <= h; j++)
        B[k++] = a[j];

    for (int i = l; i <= h;i++)
        a[i] = B[i]; //copying back to array a
}
void IterativeMergeSort(int a[], int n){
    int p, i,l, h, mid;
    for (p = 2; p <= n;p=p*2){
        for (i = 0; i + p - 1 < n;i=i+p){
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merge(a, l, h, mid);
             
        }
    }
    if((p/2)<n)
        merge(a, 0, n-1,(p/2)-1 );
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10;
    IterativeMergeSort(A, n);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}