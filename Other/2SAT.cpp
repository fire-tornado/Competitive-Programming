#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define MOD             1000000007
#define eps             1e-6
int fx[] =              {1,-1,0,0};
int fy[] =              {0,0,1,-1};

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(0);
#define fRead           freopen("in.txt","r",stdin);
#define fWrite          freopen ("out.txt","w",stdout);

#define ll              long long
#define ull             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define PI              acos(-1.0)
#define mk              make_pair
#define pii             pair<int,int>
#define pll             pair<ll,ll>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	    for(it=x.begin();it!=x.end();it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))

int n,m,id;
vector<int>G[16001],RG[16001],assignment;
stack<int>st;
int vis[16001];

inline int node(int u)
{
    if(u>0) return 2*u-1;
    return -2*u;
}

inline int compliment(int u)
{
    if(u<0) return -2*u-1;
    return 2*u;
}

void dfs1(int s)
{
    vis[s]=1;
    REP(i,G[s].size())
    {
        int u=G[s][i];
        if(!vis[u]) dfs1(u);
    }
    st.push(s);
}

void dfs2(int s)
{
    vis[s]=id;
    REP(i,RG[s].size())
    {
        int u=RG[s][i];
        if(!vis[u]) dfs2(u);
    }
}

bool solve_2SAT()
{
    MEM(vis,0);
    FOR(i,1,2*m) if(!vis[i]) dfs1(i);
    MEM(vis,0);
    id=1;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(!vis[u]) dfs2(u),id++;
    }
    assignment.clear();
    for(int i=1;i<=2*m;i+=2)
    {
        if(vis[i]==vis[i+1]) return false;
        if(vis[i]>vis[i+1]) assignment.pb(i/2+1);
    }
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        scanf("%d %d",&n,&m);
        FOR(i,1,n)
        {
            int u,v;
            scanf("%d %d",&u,&v);
            G[compliment(u)].pb(node(v));
            G[compliment(v)].pb(node(u));

            RG[node(v)].pb(compliment(u));
            RG[node(u)].pb(compliment(v));
        }
        bool f=solve_2SAT();
        if(f)
        {
            printf("Case %d: Yes\n%d",tc,assignment.size());
            REP(i,assignment.size()) printf(" %d",assignment[i]);
            printf("\n");
        }
        else
        {
            printf("Case %d: No\n",tc);
        }
        FOR(i,1,2*m) G[i].clear(),RG[i].clear();
    }
}
