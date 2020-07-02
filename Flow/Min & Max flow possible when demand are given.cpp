//https://algo.codemarshal.org/contests/bup-iupc-19/problems/G


/*
Key Idea: Binary search on edge (sink -> source)
Min Flow: keep demand = 0, binary search on capacity
Max Flow: keep capacity = inf, binary search on demand
*/

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

struct edge
{
    int to,rev,f,cap;
};

const int N=205;
int dummySrc,dummySink,lev[N],q[N],work[N];
vector<edge>g[N];

inline void addEdge(int u,int v,int w)
{
    edge a= {v,g[v].size(),0,w};
    edge b= {u,g[u].size(),0,0};
    g[u].pb(a);
    g[v].pb(b);
}

bool dinic_bfs()
{
    MEM(lev,-1);
    lev[dummySrc]=0;
    int idx=0;
    q[idx++]=dummySrc;
    REP(i,idx)
    {
        int u=q[i];
        REP(j,g[u].size())
        {
            edge &e=g[u][j];
            if(lev[e.to]<0 and e.f<e.cap)
            {
                lev[e.to]=lev[u]+1;
                q[idx++]=e.to;
            }
        }
    }
    return lev[dummySink]>=0;
}

int dinic_dfs(int u,int f)
{
    if(u==dummySink) return f;
    for(int &i=work[u];i<g[u].size();i++)
    {
        edge &e=g[u][i];
        if(e.cap<=e.f) continue;
        if(lev[e.to]==lev[u]+1)
        {
            int flow=dinic_dfs(e.to,min(f,e.cap-e.f));
            if(flow>0)
            {
                e.f+=flow;
                g[e.to][e.rev].f-=flow;
                return flow;
            }
        }
    }
    return 0;
}

int maxFlow()
{
    int ret=0;
    while(dinic_bfs())
    {
        MEM(work,0);
        while(int flow=dinic_dfs(dummySrc,INT_MAX))
            ret+=flow;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t){
        int n,m;
        scanf("%d %d",&n,&m);

        FOR(i,0,2*n+1) g[i].clear();

        dummySrc = 0;
        dummySink = 2*n+1;

        vector<pair<pii,pii>>edgeInfo(m+5);
        vector<pii>nodeInfo(n+5);
        FOR(i,1,m) edgeInfo[i].ss.ff = 0,edgeInfo[i].ss.ss = 1e9;
        FOR(i,1,n) nodeInfo[i].ff = 0,nodeInfo[i].ss = 1e9;

        FOR(i,1,m) scanf("%d %d",&edgeInfo[i].ff.ff,&edgeInfo[i].ff.ss);

        int a,b;
        scanf("%d",&a);
        FOR(i,1,a){
            int type,u,x;
            scanf("%d %d %d",&type,&u,&x);
            if(type==0) edgeInfo[u].ss.ff = x;
            else nodeInfo[u].ff = x;
        }

        scanf("%d",&b);
        FOR(i,1,b){
            int type,u,x;
            scanf("%d %d %d",&type,&u,&x);
            if(type==0) edgeInfo[u].ss.ss = x;
            else nodeInfo[u].ss = x;
        }

        int sum = 0;
        FOR(i,1,n){
            sum += nodeInfo[i].ff;
            addEdge(dummySrc,i+n,nodeInfo[i].ff);
            addEdge(i,dummySink,nodeInfo[i].ff);
            addEdge(i,i+n,nodeInfo[i].ss-nodeInfo[i].ff);
        }

        FOR(i,1,m){
            sum += edgeInfo[i].ss.ff;
            addEdge(dummySrc,edgeInfo[i].ff.ss,edgeInfo[i].ss.ff);
            addEdge(edgeInfo[i].ff.ff+n,dummySink,edgeInfo[i].ss.ff);
            addEdge(edgeInfo[i].ff.ff+n,edgeInfo[i].ff.ss,edgeInfo[i].ss.ss-edgeInfo[i].ss.ff);
        }

        int idx = g[n+n].size();
        addEdge(n+n,1,1e9);
        int flow = maxFlow();

        if(flow!=sum) printf("Case %d: -1\n",tc);
        else{
            int minflow = 1e9,maxflow = 0;
            int lo = 0,hi = 1e9;
            while(lo<=hi){
                int mid = (lo+hi)/2;
                g[n+n][idx].cap = mid;

                FOR(i,0,2*n+1) for(edge &e:g[i]) e.f = 0;
                flow = maxFlow();
                if(sum==flow) {
                    minflow = mid;
                    hi = mid-1;
                }
                else lo = mid+1;
            }

            g[n+n].pop_back();
            g[1].pop_back();
//          Comment part use the idea of super source
//          int superSource = n+n+2;
//          addEdge(n+n,superSource,1e9);

            lo = 0, hi = 1e9;
            while(lo<=hi){
                int mid = (lo+hi)/2;

                FOR(i,0,2*n+1) for(edge &e:g[i]) e.f = 0;

//                addEdge(dummySrc,1,mid);
//                addEdge(superSource,dummySink,mid);
//                addEdge(superSource,1,1e9);

                addEdge(dummySrc,1,mid);
                addEdge(n+n,dummySink,mid);
                addEdge(n+n,1,1e9-mid);

                flow = maxFlow();

                g[dummySrc].pop_back();
                g[1].pop_back();
                g[n+n].pop_back();
                g[dummySink].pop_back();
                g[n+n].pop_back();
                g[1].pop_back();

//                g[dummySrc].pop_back();
//                g[1].pop_back();
//                g[superSource].pop_back();
//                g[dummySink].pop_back();
//                g[superSource].pop_back();
//                g[1].pop_back();

                if(flow==sum+mid){
                    maxflow = mid;
                    lo = mid+1;
                }
                else hi = mid - 1;
            }

            printf("Case %d: %d %d\n",tc,minflow,maxflow);
        }
    }
    return 0;
}
