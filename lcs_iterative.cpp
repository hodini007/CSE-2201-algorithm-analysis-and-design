#include<bits/stdc++.h>
using namespace std ;


string x ="abc";
string y ="acd";
int m=x.size();
int n=y.size();
int mem[100][100];

int lcs(int i, int j){
    if(i==m || j==n) return 0;
    if (mem[i][j]!=-1) return mem[i][j];
    if(x[i]==y[j]){
        return mem[i][j]=1+lcs(i+1,j+1);
    }
    else{
        return mem[i][j]=max(lcs(i+1,j),lcs(i,j+1));
    }
    return mem[i][j];

}

int main(){


    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            mem[i][j]=-1;
        }
    }

    int ans = lcs(0, 0);
    cout<<ans<<endl;
}