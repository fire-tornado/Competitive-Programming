//http://lightoj.com/volume_showproblem.php?problem=1359

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,LL>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define Unique(a)       a.erase(unique(a.begin(),a.end()),a.end())
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int n,m;
const int N=100005;

//Dijkstra to get DAG
struct point
{
    int name;
    LL val;
    bool operator <(const point &p) const
    {
        return p.val < val;
    }
};
vector<pii>V[N];
LL dis[N];
bool vis[N];
void Dijkstra(int s)
{
    MEM(dis,0x3f3f3f3f3f3f);
    MEM(vis,0);
    dis[s]=0;
    priority_queue<point>Q;
    point get;
    get.name=s;
    get.val=0;
    Q.push(get);
    while(!Q.empty())
    {
        point tmp=Q.top();
        Q.pop();
        int now=tmp.name;
        if(vis[now]) continue;
        vis[now]=1;
        REP(i,V[now].size())
        {
            int x=V[now][i].ff;
            int y=V[now][i].ss;
            if(dis[now]+y<dis[x])
            {
                dis[x]=dis[now]+y;
                get.name=x;
                get.val=dis[x];
                Q.push(get);
            }
        }
    }
    return;
}

//Building DAG from Dijkstra
vector<int>DAG[N];
void getDirection(int s){
    vis[s]=true;
    for(pii u:V[s]){
        if(dis[u.ff]==dis[s]+u.ss) DAG[s].pb(u.ff);
        else if(dis[s]==dis[u.ff]+u.ss) DAG[u.ff].pb(s);
        if(!vis[u.ff]) getDirection(u.ff);
    }
}

//TopSort of all the nodes
stack<int>topsort;
void TopSort(int s){
    vis[s]=true;
    for(int u:DAG[s]) if(!vis[u]) TopSort(u);
    topsort.push(s);
}

vector<int>parent[N];
int L[N],P[N][22];

//LCA Query
int query(int p,int q)
{
    if(L[p]<L[q]) swap(p,q);
    ROF(i,21,0) if(L[P[p][i]]>=L[q]) p=P[p][i];
    if(p==q) return p;
    ROF(i,21,0)
    {
        if(P[p][i]!=P[q][i])
        {
            p=P[p][i];
            q=P[q][i];
        }
    }
    return P[p][0];
}

//Finding the subtree size of Dominator Graph
vector<int>graph[N];
int subtree[N];
void dfs(int s){
    vis[s]=true;
    subtree[s]=1;
    for(int u:graph[s]){
        dfs(u);
        subtree[s]+=subtree[u];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t){
        scanf("%d %d",&n,&m);

        REP(i,n) V[i].clear();
        FOR(i,1,m){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            V[u].pb({v,w});
            V[v].pb({u,w});
        }
        Dijkstra(0);

        REP(i,n) DAG[i].clear();
        MEM(vis,0);
        getDirection(0);
        REP(i,n) Unique(DAG[i]);

        MEM(vis,0);
        TopSort(0);

        MEM(P,0);
        MEM(L,0);
        REP(i,n){
            graph[i].clear();
            parent[i].clear();
        }
        REP(i,n){
            for(int u:DAG[i]){
                parent[u].pb(i);
            }
        }

        //Building the dominator tree
        while(!topsort.empty()){
            int u=topsort.top();
            topsort.pop();
            int p=0;
            REP(i,parent[u].size()){
                if(i==0) p=parent[u][i];
                else p=query(p,parent[u][i]);
            }
            P[u][0]=p;
            L[u]=L[p]+1;
            if(u!=0) graph[p].pb(u);
            for(int j=1;(1<<j)<N;j++)
            {
                P[u][j]=P[P[u][j-1]][j-1];
            }
        }

        MEM(vis,0);
        dfs(0);

        printf("Case %d:\n",tc);
        int q;
        scanf("%d",&q);
        while(q--){
            int k;
            scanf("%d",&k);
            int u,ans=-1;
            REP(i,k){
                scanf("%d",&u);
                if(!vis[u]) continue;
                if(ans==-1) ans=u;
                else ans=query(ans,u);
            }
            if(ans==-1) printf("0\n");
            else printf("%d %d\n",L[ans],subtree[ans]);
        }
    }
}

