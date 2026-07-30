#include<bits/stdc++.h>
using namespace std;

void count_sort(int arr[],int n){

    int m=max(arr[0],arr[1]);
    int cnt[m];
    for(int i =0;i<n;i++){
        cnt[arr[i]]++;
    }

    int cum[m];
    for (int i = 0; i < m; i++)
    {
        cum[i] = cnt[i];
    }
    
    for (int i = 1; i <= m; i++)
    {
        cum[i] += cum[i-1];
    }

    int output[n];
    for (int i = n-1; i >= 0; i--)
    {
        output[cum[arr[i]]-1] = arr[i];
        cum[arr[i]]--;

    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

}


vector<int> count_sort_another(vector<int>& arr, int n)
{
    int mx=*max_element(arr.begin(),arr.end());
    vector<int>cnt(mx+1,0);
    for(int i=0;i<n;i++)
    {
        cnt[arr[i]]++;
    }
    for(int i=1;i<=mx  ;i++)
    {
        cnt[i]+=cnt[i-1];
    }
    vector<int>output(n);
    for(int i=n-1;i>=0;i--)
    {
        output[cnt[arr[i]]-1]=arr[i];
        cnt[arr[i]]--;
    }
    return output;
}



int main()
{
    vector<int>arr={5,4,3,2,1,2443,545,6243,32,545,436,21};
    vector<int>sorted_arr=count_sort_another(arr, arr.size());
    for(int i=0;i<sorted_arr.size();i++)
    {
        cout<<sorted_arr[i]<<" ";
    }



    
}
