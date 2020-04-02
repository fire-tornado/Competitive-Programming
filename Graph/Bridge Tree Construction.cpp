//http://lightoj.com/volume_showproblem.php?problem=1291

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const int N=100005;

set<int>V[N+5];
int vis[N+5];
int discover[N+5];
int low[N+5];
int pr[N+5];
vector<pii>br,edge;

void dfs(int u)
{
    static int time = 0;
    vis[u] = 1;
    discover[u] = low[u] = ++time;

    for(int v : V[u]){
        if(!vis[v]){
            pr[v] = u;
            dfs(v);
            low[u] = min(low[u],low[v]);
            if(low[v]>discover[u]){
                br.push_back({u,v});
            }
        }
        else if(pr[u]!=v){
            low[u] = min(low[u],discover[v]);
        }
    }
}

void DFS(int s,int id){
    vis[s]=id;
    for(int u:V[s]){
        if(vis[u]) continue;
        DFS(u,id);
    }
}

vector<int>graph[N];

int main()
{
    Fast
    MEM(pr,-1);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin >> u >> v;
        V[u].insert(v);
        V[v].insert(u);
        edge.pb({u,v});
    }
    for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);

    MEM(vis,0);
    int id=0;
    for(pii p:br){
        V[p.ff].erase(p.ss);
        V[p.ss].erase(p.ff);
    }
    for(int i=1;i<=n;i++) if(!vis[i]) DFS(i,++id);

    for(pii p:edge) {
        if(vis[p.ff]!=vis[p.ss]){
            graph[vis[p.ff]].pb(vis[p.ss]);
            graph[vis[p.ss]].pb(vis[p.ff]);
        }
    }
}
