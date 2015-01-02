#include<bits/stdc++.h>
using namespace std;
#define V 9
int minDistance(int dist[],int sptSet[]){
    for(int k=0;k<V;k++){cout<<sptSet[k]<<" "<<dist[k]<<endl;}
    int min = INT_MAX,min_index;
    for(int v=0;v<V;v++){
       // cout<<sptSet[v]<<"  "<<dist[v]<<endl;
        if(sptSet[v]==0 && dist[v]<min){
            min = dist[v],min_index = v;
        }
        return min_index;
    }
}
int printSol(int dist[],int n){
    for(int i=0;i<V;i++){
        cout<<dist[i]<<endl;
    }
}
void dijkstra(int graph[V][V],int src){
    int dist[V];
    int sptSet[V];
    for(int i=0;i<V;i++){
        dist[i]=INT_MAX;sptSet[i]=0;

    }
    dist[src]=0;
    for(int cnt=0;cnt<V-1;cnt++){
        int u = minDistance(dist,sptSet);
        cout<<"u: "<<u<<endl;
        sptSet[u]=1;

        for(int v=0;v<V;v++){
            cout<<" sptSet: "<<sptSet[v]<<" dist: "<<dist[u]<<" graph: "<<graph[u][v]<<"dist[v]"<<dist[v]<<endl;
            if(sptSet[v]==0 && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){cout<<"if...."<<endl;
                dist[v] = dist[u]+graph[u][v];

            }

        }



    }

    printSol(dist,V);



}
int main(){
      int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 0, 10, 0, 2, 0, 0},
                      {0, 0, 0, 14, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };

    dijkstra(graph, 0);

    return 0;


}
