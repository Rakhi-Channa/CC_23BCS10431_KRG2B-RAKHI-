#include<iostream>
using namespace std;

int main(){
    int graph[5][5] = { {0, 4, 1000, 5, 1000},
                        {1000, 0, 1, 1000, 6},
                        {2,1000 , 0, 3, 1000},
                        {1000, 1000, 1, 0, 2},
                        {1, 1000, 1000, 4, 0} 
                    };

    int V = 5;

    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(graph[i][j] > graph[i][k] + graph[k][j]){
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            if(graph[i][j] == 1e9){
                cout<<"INF"<<" ";
            }
            else{
                cout<<graph[i][j]<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}