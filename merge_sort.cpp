#include<bits/stdc++.h>
using namespace std;


void merge(vector<int>&arr,int l,int m,int h)
{
    int i,j,k;
    i=l,j=m+1,k=l;
    int aux[100];
    while(i<=m && j<=h)
    {
        if(arr[i]<arr[j])
        {
            aux[k++]=arr[i++];
        }
        else
        {
            aux[k++]=arr[j++];
        }
    }
    for(;i<=m;i++)
    {
        aux[k++]=arr[i];
    }
    for(;j<=h;j++)
    {
        aux[k++]=arr[j];    
    }

    for(i=l;i<=h;i++)
    {
        arr[i]=aux[i];
    } 

}


void merge_sort(vector<int>&arr,int l,int h)
{
    if(l<h)
    {
        int m=(l+h)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,h);
        merge(arr,l,m,h);
    }
}