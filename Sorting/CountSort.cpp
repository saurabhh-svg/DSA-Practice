//O(m+n)->O(n)
//for small numbers->take huge space in memory
//depends on value of maximum value in aarray

#include <iostream>
#include <algorithm>
using namespace std;

int findMax(int a[],int n){
    int max = INT_MIN;
    for (int i = 0; i < n; i++){
        if(a[i]>max)
            max = a[i];
}
return max;
}
// For Array Increasing order
void CountSort(int a[],int n){
    int max = findMax(a, n);
    int *count = new int[max + 1]; // array of max+1 size
    for (int i = 0; i < max + 1;i++) count[i] = 0; //intialise count array to 0
    for (int i = 0; i < n; i++) count[a[i]]++;
    int i = 0,j=0;
    while(i<max+1){
        if(count[i]>0){
        a[j++] = i;
         count[i]--;
        } else  i++;
    }
}
int main()
{
    int A[] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3}, n = 10;
    CountSort(A, n);
    for (int i = 0; i < 10; i++)
        cout << A[i] << " ";
    cout << endl;
}