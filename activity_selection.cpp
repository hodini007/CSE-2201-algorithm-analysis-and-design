#include<bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>> vct;
vct activitySelection(vct items) {

    vct new_pair;

    for (int i = 0; i < items.size(); i++)
    {
        new_pair.push_back({items[i].second,i});

    }
    sort(new_pair.begin(),new_pair.end());
    vct another_new ;
    for (int i = 0; i < new_pair.size(); i++)
    {
        another_new.push_back({items[new_pair[i].second].first,new_pair[i].first});
    }
    vct res;
    int lastFinish = INT_MIN;
    for (int i = 0; i < another_new.size(); i++)
    {
        int start = another_new[i].first;
        int finish = another_new[i].second;

        if (start >= lastFinish) {
            res.push_back({start, finish});
            lastFinish = finish;
        }
    }

    return res;
}

int main(){
    vct items = {{1,4}, {3,5}, {0,6}, {5,7},{3,9},{5,9},{6,10},{7,11},{8,12},{2,14},{12,16}};
    vct res = activitySelection(items);
    cout<<"The selected jobs are : ";
    for (int i = 0; i < res.size(); i++)
    {
        cout << "(" << res[i].first << ", " << res[i].second << ") ";
    }
    cout<<endl;

}