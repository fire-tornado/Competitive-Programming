//Problem : http://lightoj.com/volume_showproblem.php?problem=1367

/*
Algorithm (Only works for DAG)

i.      Take a dummySource DS, and dummySink DD
ii.     For each edge u->v with lower bound L, capacity C
            a. addEdge(DS,v,L)
            b. addEdge(u,DD,L)
            c. addEdge(u,v,C-L)
iii.    addEdge(actualSink,actualSource,inf)
iv.     Run MaxFlow
v.      If summation of lower bound == maxFlow then possible
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

const int N=405;
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

        REP(i,n+5) g[i].clear();

        dummySrc = 0;
        dummySink = n+3;

        vector<pair<int,pii> >Ed; //For printing

        int sum = 0;
        REP(i,m)
        {
            int u,v,Lo,Cap;
            scanf("%d %d %d %d",&u,&v,&Lo,&Cap);

            addEdge(dummySrc,v,Lo);
            addEdge(u,dummySink,Lo);
            Ed.pb({u,{g[u].size(),Lo}});
            addEdge(u,v,Cap-Lo);
            sum += Lo;
        }
        addEdge(n,1,1e8);

        int flow = maxFlow();
        if(sum==flow) {
            printf("Case %d: yes\n",tc);
            for(auto p:Ed){
                int f = g[p.ff][p.ss.ff].f+p.ss.ss;
                printf("%d\n",f);
            }
        }
        else printf("Case %d: no\n",tc);
    }
    return 0;
}
