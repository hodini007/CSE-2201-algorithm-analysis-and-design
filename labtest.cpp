#include<bits/stdc++.h>
using namespace std ;



void count_sort(vector<int> &arr){

    int m =*max_element(arr.begin(),arr.end());
    vector<int> freq(m+1,0);
    for (int i = 0; i < arr.size(); i++)
    {
        freq[arr[i]]++;
    }

    for (int i = 1; i <= m; i++)
    {
        freq[i]+=freq[i-1];
    }
    vector<int> output(arr.size()) ;

    for (int i = arr.size()-1; i >=0; i--)
    {
        output[--freq[arr[i]]]=arr[i];
    }
    
    arr=output ;




}

#include <bits/stdc++.h>
using namespace std;

void count_sort_desc(vector<int> &arr) {
    if (arr.empty()) return;

    int m = *max_element(arr.begin(), arr.end());
    vector<int> freq(m + 1, 0);

    // 1. Count frequencies
    for (int i = 0; i < arr.size(); i++) {
        freq[arr[i]]++;
    }

    // 2. Suffix sum: accumulate from m-1 down to 0
    for (int i = m - 1; i >= 0; i--) {
        freq[i] += freq[i + 1];
    }

    // 3. Build output array in reverse to maintain stability
    vector<int> output(arr.size());
    for (int i = (int)arr.size() - 1; i >= 0; i--) {
        output[--freq[arr[i]]] = arr[i];
    }

    arr = output;
}


void buck_sort(vector<float> &arr){

    int n =arr.size();
    vector<vector<float>> bucks(n) ;
    for (int i = 0; i < n; i++)
    {
        bucks[n*arr[i]].push_back(arr[i]);
    }

    for (int i = 0; i < bucks.size(); i++)
    {
        sort(bucks[i].begin(),bucks[i].end());

    }

    int index =0 ;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < bucks[i].size(); j++)
        {
            arr[index++]=bucks[i][j];
        }
        
    }
    
    
    
}

void radix_sort(vector<int> &arr){
    int m=*max_element(arr.begin(),arr.end());
    for (int exp = 1;m/exp >0 ; exp*=10)
    {
        vector<int>output(arr.size());
        vector<int> count(10,0);
        for (int i = 0; i < arr.size(); i++)
        {
            count[(arr[i]/exp)%10]++ ;
        }

        for (int  i = 1; i < 10; i++)
        {
            count[i]+=count[i-1];
        }
        for (int i = arr.size()-1; i >= 0; i--)
        {
            output[--count[(arr[i]/exp)%10]]=arr[i] ;
        }
        
        arr=output ;
        
        
        
    }
    
}



int main() {
    vector<int> arr = {23, 3, 5, 3, 2, 5, 4, 63, 5, 3, 5, 65, 6, 68, 56, 345, 4, 65, 7, 6754};
    vector<float> anda ={.34,.35,.234,.654,.56};
    //count_sort_desc(arr);
    //buck_sort(anda);
    radix_sort(arr);
    
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << "\n";

    return 0;
}
    
    


