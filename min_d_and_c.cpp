#include<bits/stdc++.h>
using namespace std;

int arr[12]={234,43,523,4,23,324,3332,4,234,3,4,24};


pair<int,int> min_and_max(int l,int r){

    if (l==r) return {arr[l],arr[l]};
    int mid = (l+r)/2;
    pair<int,int> left = min_and_max(l,mid);
    pair<int,int> right = min_and_max(mid+1,r);
    return {min(left.first,right.first),max(left.second,right.second)};
}

int max(int l,int r){

    if (l==r) return arr[l];
    int mid = (l+r)/2;
    return max(max(l,mid),max(mid+1,r));
}

int min(int l,int r){

    if (l==r) return arr[l];
    int mid = (l+r)/2;
    return min(min(l,mid),min(mid+1,r));
}

int main(){


int n= sizeof(arr)/sizeof(arr[0]);
pair<int,int> ans = min_and_max(0,n-1);
cout<<"Minimum element is: "<<ans.first<<endl;
cout<<"maximum element is: "<<ans.second<<endl;


}