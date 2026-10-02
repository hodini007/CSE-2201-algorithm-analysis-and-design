#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;

class graph{
    int v ;
    vector<vector<pii>> adj ;

    public:
    graph(int v){
        this->v = v ;
        adj.resize(v) ;
    }

    void addEdge(int u, int v, int weight){
        adj[u].push_back({weight,v});
        adj[v].push_back({weight,u});
    }

    void primMST(){
        priority_queue<pii,vector<pii>,greater<pii>> pq;
        int src=0 ;
        vector<int>key(v,INT_MAX);
        vector<int>parent(v,-1);
        vector<bool> inMST(v,false);

        pq.push({0,src});
        key[src]=0;

        int total =0 ;

        while(!pq.empty()){
            int u =pq.top().second ;
            int weight =pq.top().first;

            pq.pop();

            if(inMST[u])
                continue ;
            
                inMST[u]=true ;
                total+=weight ;

                for(auto& edge :adj[u]){
                    int v=edge.second ;
                    int v_weight =edge.first ;

                    if(!inMST[v] && key[v] >v_weight){
                        key[v]=v_weight ;
                        pq.push({key[v],v});
                        parent[v]=u ;
                    }

                }
        }

        cout<<"edge weight :\n ";
        for(int i =1;i<v;i++){
            if(parent[i]!=-1){
                cout<<parent[i]<<" - "<<i<<" : "<<key[i]<<"\n";
            }

        }
        cout<<"total weight : "<<total<<"\n" ;
    }
    
    


};




int main(){


    graph g(5);




    // Adding edges: addEdge(u, v, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);

    g.primMST();

    return 0;
}

   
    