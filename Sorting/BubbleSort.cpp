#include<iostream>
using namespace std;

void swap(int *a,int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void Bubble(int a[],int size){
    int i, j,flag=0;
    for ( i = 0; i < size - 1;i++){ //last element is already sorted
        flag = 0;
        for (j = 0; j < size - 1 - i; j++)
        { // after every pass of i last i elements will be sorted
            if (a[j] > a[j + 1])
            {
                swap(&a[j], &a[j + 1]);
                flag = 1;
            }
        }
        if(flag==0)
            break;
    }
    } 


    int main(){
        int arr[] = {3, 2, 5, 1, 7, 6, 9, 8,10,0};
        Bubble(arr, 10);
        for (int i = 0; i < 10; i++)
            cout << arr[i] << " ";
        cout << endl;
    }