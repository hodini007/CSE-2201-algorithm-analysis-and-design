#include<bits/stdc++.h>
using namespace std;

void bubble(vector<int>&arr)
{
    for(int i=0;i<arr.size();i++)
    {   
        int flag=0;
        for(int j=0;j<arr.size()-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                flag=1;
            }

        }
        if(flag==0)
        {
            break;
        }
    }
}

int main()
{
    vector<int>arr={5,4,3,2,1};
    bubble(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
}