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
#define TC              int t;cin >> t;FOR(tc,1,t)
#define ABS(x)          ((x)<0?-(x):(x))
#define SQ(x)           ((x)*(x))
#define SP(x)           fixed << setprecision(x)


#define Make(x,p)       (x | (1<<p))
#define DeMake(x,p)     (x & ~(1<<p))
#define Check(x,p)      (x & (1<<p))
#define popcount(x)     __builtin_popcount(x)

const int N=100005;
vector<int>V[N],DAG[N];
int id;
int vis[N];
stack<int>st;

void dfs1(int s)
{
    vis[s]=1;
    for(int i:V[s])
    {
        if(i<0 or vis[i]) continue;
        dfs1(i);
    }
    st.push(s);
}

void dfs2(int s)
{
    vis[s]=id;
    for(int i:V[s])
    {
        i=-i;
        if(i<0 or vis[i]) continue;
        dfs2(i);
    }
}

int main()
{
    int n,m;
    cin >> n >> m;
    REP(i,m)
    {
        int u,v;
        cin >> u >> v;
        V[u].pb(v);
        V[v].pb(-u);    //Reverse Graph
    }
    FOR(i,1,n) if(vis[i]==0 and V[i].size()>0) dfs1(i);
    MEM(vis,0);
    id=0;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();
        if(vis[u]) continue;
        id++;
        dfs2(u);
    }
    FOR(i,1,n)
    {
        for(int j:V[i]){
            if(j<0) continue;
            if(vis[i]!=vis[j]) DAG[vis[i]].pb(vis[j]);
        }
    }

}
