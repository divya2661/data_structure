#include<bits/stdc++.h>
using namespace std;
class graph{
    int V;
    list<int> *adj;

public:
    graph(int V){
        adj  = new list<int>[V];
    }
    void makeEdge(int v,int w){
        adj[v].push_back(w);
    }
    void BFS(int s){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i]=false;
        }
        list<int>queue;
        visited[s] = true;
        queue.push_back(s);
        list<int>::iterator i;
        while(!queue.empty()){
            s = queue.front();
            cout<<s<<" ";
            queue.pop_front();
            for(i=adj[s].begin();i!=adj[s].end();i++){
                if(!visited[*i]){
                    visited[*i]=true;
                    queue.push_back(*i);
                }
            }
        }
    }
    void DFSRecur(int v, bool visited[]){
        visited[v]=true;
        cout<<v<<" ";
        list<int>::iterator i;
        for(i=adj[v].begin();i!=adj[v].end();i++){
            if(!visited[*i]){
                DFSRecur(*i,visited);

            }
        }
    }
    void DFS(int v){
        bool *visited = new bool[V];
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        DFSRecur(v,visited);
    }
};

int main(){
     graph g(4);
    g.makeEdge(0, 1);
    g.makeEdge(0,2);
    g.makeEdge(1,2);
    g.makeEdge(2,0);
    g.makeEdge(2,3);
    g.makeEdge(3,3);
    cout << "Breadth First Traversal: "<<endl;
    g.BFS(2);
    cout<<endl;
    cout << "Depth First Traversal: "<<endl;
    g.DFS(2);
    return 0;


}
