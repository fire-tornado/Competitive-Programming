#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

struct edge{
    int v, rev;
    int cap, cost, flow;
    edge(){}
    edge(int v, int rev, int cap, int cost) : v(v), rev(rev), cap(cap), cost(cost), flow(0){}
};

struct mcmf{
    int src, sink, nodes;
    const int inf = 1e9;
    vector<int> par, idx;
    vector<bool> inq;
    vector<int> dis;
    vector<vector<edge>> g;

    mcmf(){}
    mcmf(int src, int sink, int nodes) : src(src), sink(sink), nodes(nodes),
                                         par(nodes), idx(nodes), inq(nodes),
                                         dis(nodes), g(nodes){}

    void addEdge(int u, int v, int cap, int cost, bool directed = true){
        edge _u = edge(v, g[v].size(), cap, cost);
        edge _v = edge(u, g[u].size(), 0, -cost);
        g[u].pb(_u);
        g[v].pb(_v);
        if(!directed) addEdge(v, u, cap, cost, true);
    }

    bool spfa(){
        for(int i = 0; i < nodes; i++){
            dis[i] = inf, inq[i] = false;
        }

        queue<int>q;
        q.push(src);
        dis[src] = 0, par[src] = -1, inq[src] = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            inq[u] = false;
            for(int i = 0; i < g[u].size(); i++){
                edge &e = g[u][i];
                if(e.cap <= e.flow) continue;
                if(dis[e.v] > dis[u] + e.cost){
                    dis[e.v] = dis[u] + e.cost;
                    par[e.v] = u, idx[e.v] = i;
                    if(!inq[e.v]) inq[e.v] = true, q.push(e.v);
                }
            }
        }

        return (dis[sink] != inf);
    }

    pair<int,int> solve(){
        int mincost = 0, maxflow = 0;
        while(spfa()){
            int bottleneck = inf;
            for(int u = par[sink], v = idx[sink]; u != -1; v = idx[u], u = par[u]){
                edge &e = g[u][v];
                bottleneck = min(bottleneck, e.cap - e.flow);
            }

            for(int u = par[sink], v = idx[sink]; u != -1; v = idx[u], u = par[u]){
                edge &e = g[u][v];
                e.flow += bottleneck;
                g[e.v][e.rev].flow -= bottleneck;
            }

            mincost += bottleneck * dis[sink], maxflow += bottleneck;
        }

        return make_pair(mincost, maxflow);
    }
};

int main(){
    int t;
    scanf("%d",&t);
    FOR(tc,1,t){
        int n;
        scanf("%d",&n);
        int arr[n+1][n+1];
        FOR(i,1,n) FOR(j,1,n) scanf("%d",&arr[i][j]);

        mcmf Flow(0,n+n+1,n+n+2);
        FOR(i,1,n) Flow.addEdge(0,i,1,0),Flow.addEdge(i+n,n+n+1,1,0);
        FOR(i,1,n){
            FOR(j,1,n){
                Flow.addEdge(i,j+n,1,-arr[i][j]);
            }
        }
        printf("Case %d: %d\n",tc,-Flow.solve().ff);
    }
}
