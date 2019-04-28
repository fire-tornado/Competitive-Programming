// Complexity O(V*E)
// For V=1000,around 20 iteration works fine.

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

struct edge
{
    int u,v,w;
};
vector<edge>V;
int dis[105];
int n,m;

bool bellmanford(int s)
{
    FOR(i,1,n) dis[i]=INT_MAX;
    dis[s]=0;
    FOR(i,1,n-1)
    {
        REP(j,V.size())
        {
            edge e=V[j];
            if(dis[e.v]>dis[e.u]+e.w)
            {
                dis[e.v]=dis[e.u]+e.w;
            }
        }
    }

    REP(j,V.size())
    {
        edge e=V[j];
        if(dis[e.v]>dis[e.u]+e.w)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    cin >> n >> m;
    FOR(i,1,m)
    {
        int u,v,w;
        cin >> u >> v >> w;
        V.pb({u,v,w});
    }
    if(bellmanford(1)) cout << "No Negative Cycle\n";
    else cout << "Negative Cycle\n";
}
