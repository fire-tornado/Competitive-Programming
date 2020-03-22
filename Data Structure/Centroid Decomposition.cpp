//Number of nodes are d distance away from a node u

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
int n,q;
set<int>G[N];
int sub[N],par[N];
void dfs(int node,int pr)
{
    sub[node]=1;
    for(int u:G[node]){
        if(u==pr) continue;
        dfs(u,node);
        sub[node]+=sub[u];
    }
}

int centroid(int node,int pr,int sz)
{
    for(int u:G[node]){
        if(u==pr) continue;
        if(sub[u]>sz) return centroid(u,node,sz);
    }
    return node;
}

vector<pii>Dis[N];
map<pii,int>mp;
void CalDist(int c,int node,int pr,int d){
    Dis[c].push_back({node,d});
    mp[{c,node}]=d;
    for(int u:G[node]){
        if(u==pr) continue;
        CalDist(c,u,node,d+1);
    }
}

int root;
vector<int>V[N];
int start[N],finish[N],id;
void EularTour(int node){
    start[node]=++id;
    for(int u:V[node]) EularTour(u);
    finish[node]=++id;
}

void decompose(int node,int pr)
{
    dfs(node,-1);
    int c=centroid(node,-1,sub[node]/2);
    CalDist(c,c,-1,0);

    if(pr==-1) root=c;
    else V[pr].pb(c);
    par[c]=pr;

    for(int u:G[c]){
        G[u].erase(c);
        decompose(u,c);
    }
}

bool cmp(pii a,pii b){
    if(a.ss==b.ss) {
        return start[a.ff]<start[b.ff];
    }
    return a.ss<b.ss;
}

void build(){
    decompose(1,-1);
    EularTour(root);

    FOR(i,1,n) sort(all(Dis[i]),cmp);
}

int cntbisearch(int u,int d,int st,int en){
    int lo=0,hi=Dis[u].size()-1,mid,lidx=-1,ridx=-1;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(Dis[u][mid].ss==d){
            lidx=mid;
            hi=mid-1;
        }
        else if(Dis[u][mid].ss>d) hi=mid-1;
        else lo=mid+1;
    }
    if(lidx==-1) return 0;

    lo=0,hi=Dis[u].size()-1;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(Dis[u][mid].ss==d){
            ridx=mid;
            lo=mid+1;
        }
        else if(Dis[u][mid].ss>d) hi=mid-1;
        else lo=mid+1;
    }

    int left=-1,right=-1;
    lo=lidx,hi=ridx;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(start[Dis[u][mid].ff]>=st){
            left=mid;
            hi=mid-1;
        }
        else lo=mid+1;
    }

    lo=lidx,hi=ridx;
    while(lo<=hi){
        mid=(lo+hi)/2;
        if(start[Dis[u][mid].ff]<=en){
            right=mid;
            lo=mid+1;
        }
        else hi=mid-1;
    }

    if(left==-1 or right==-1) return ridx-lidx+1;
    return ridx-lidx-right+left;
}

int query(int node,int d){
    int ans=cntbisearch(node,d,1e8,-1),u=node;
    while(u!=root){
        ans+=cntbisearch(par[u],d-mp[{par[u],node}],start[u],finish[u]);
        u=par[u];
    }
    return ans;
}

int main()
{
    cin >> n >> q;
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin >> u >> v;
        G[u].insert(v);
        G[v].insert(u);
    }
    build();
    while(q--){
        int u,d;
        cin >> u >> d;
        cout << query(u,d) << '\n';
    }
    return 0;
}
/*
10 1
9 8
8 1
1 2
2 3
3 4
4 5
2 6
6 10
10 7
9 1
*/
