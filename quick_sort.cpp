#include<bits/stdc++.h>
using namespace std ;

void swap(int arr[],int i,int j){
    int temp =arr[j];
    arr[j]=arr[i];
    arr[i]=temp;
}
int partition(int arr[],int l,int r){

    int pivot=arr[r];
    int i=l-1;
    for (int j = l; j < r; j++)
    {
        if (arr[j]<pivot)
        {
            i++ ;
            swap(arr,i,j);

        }
        
        
        
    }
    swap(arr,i+1,r);
    return i+1 ;
}


void quicksort(int arr[],int l,int r){
    if(l<r){
        int pi =partition(arr,l,r);

        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,r);
        
    }

}



int main(){

        int arr[]={42,23,56,6,4323,5,45,3,53,5,35,235,235};
        quicksort(arr,0,12);
        for (int i = 0; i <13 ; i++)
        {
            cout<<arr[i]<<" ";
        }
        



}