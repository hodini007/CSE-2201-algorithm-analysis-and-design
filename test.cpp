#include<bits/stdc++.h>
using namespace std ;
typedef vector<pair<int,int>> vct ;
double knapsack(vct item,int capacity){
    vector<pair<double,int>> ratio ;
    int n = item.size();
    for (int i = 0; i < n; i++)
    {
        double cratio=static_cast<double>(item[i].first/item[i].second);
        ratio.push_back(make_pair(cratio,i));
    }

    sort(ratio.rbegin(),ratio.rend());
    
    double remaining = capacity ;
    double ans =0 ;
    for (int i = 0; i < n; i++)
    {
        if(item[ratio[i].second].second <= remaining){
            remaining-= item[ratio[i].second].second ;
            ans+=item[ratio[i].second].first ;
        }
        else{
            ans+= ((remaining/item[ratio[i].second].second)*item[ratio[i].second].first);
            break ;
        }
    }
    return ans ;
    
    
}






int main(){
    vct items = {{54, 9}, {48, 6}, {70, 14}, {35, 5}, {77, 11}, {44, 8}};
    int capacity = 27;
    vector<double> fractions;

    double totalValue = knapsack(items, capacity);

    cout << fixed << setprecision(2);
    cout << "Total value: " << totalValue << '\n';
   
    

}