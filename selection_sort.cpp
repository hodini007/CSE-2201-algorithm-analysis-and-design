#include<bits/stdc++.h>
using namespace std;


void selection_sort(vector<int>&arr)
{
    int i,j,k;
    for(i=0;i<arr.size();i++)
    {
        k=i;
        for(j=i+1;j<arr.size();j++)
        {
            if(arr[j]<arr[k])
            {
                k=j;
            }
        }
        swap(arr[i],arr[k]);        
    }
}

int main()
{
    vector<int>arr={5,4,3,2,1};
    selection_sort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}