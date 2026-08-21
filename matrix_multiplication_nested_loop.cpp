#include<bits/stdc++.h>
using namespace std;





int main(){
int mat1[3][3]={{2,34,2},
                {23,4,3},
            {13,2,11}};
int mat2[3][4]{
    {12,32,1,2},
    {23,34,1,3},
    {2,41,5,4}
};

int ans[3][4] ;
int sum=0;



for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 4; j++)
    {
        for (int k = 0; k <3 ; k++)
        {
            sum+= mat1[i][k]*mat2[k][j];
        }
        ans[i][j]=sum;
        sum=0;
        
    }
    
}

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 4; j++)
    {
        cout<<ans[i][j]<<" " ;

    }
    cout<<endl;
}





}