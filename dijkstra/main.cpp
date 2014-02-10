//-*-coding:utf-8-*-
//----------------------------------------------------------
// module: main
//----------------------------------------------------------
#include <algorithm>
#include <vector>
#include <queue>

#include <cstdio>

using namespace std;

struct edge {int to, cost;};
typedef pair<int, int> P; // cost, vector

const int MAX_V = 100;
const int INF = 2^20;

int V;
vector<edge> G[MAX_V];
int d[MAX_V];


void dijkstra(int s){
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    int cost = 0;

    while(!que.empty()){
        P v = que.top();
        que.pop();
        printf("vector: %d, cost: %d\n", v.second, v.first);

        for (int i = 0; i < G[v.second].size(); ++i)
            {
                edge e = G[v.second][i];
                if (d[e.to] > v.first + e.cost) {
                    d[e.to] = v.first + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
    }
}

int main(int argc, char *argv[])
{
    V = 4;
    vector<edge> v0;
    vector<edge> v1;
    vector<edge> v2;
    vector<edge> v3;

    v0.push_back({1, 4});
    v0.push_back({2, 2});

    v1.push_back({3, 1});
    v2.push_back({1, 1});

    G[0] = v0;
    G[1] = v1;
    G[2] = v2;
    G[3] = v3;

    dijkstra(0);

    for (int i = 0; i < V; ++i)
        {
            printf("vector %d distance: %d\n", i, d[i]);
        }

    return 0;
}



