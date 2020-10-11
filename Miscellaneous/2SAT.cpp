//https://www.codechef.com/problems/VRTXCOVR

/*

* Example xor:
    |a|b|
    ------
    |0|0| x or(a,b)
    |0|1|
    |1|0|
    |1|1| x or(-a,-b)
* Do OR of negation of values of variables for each undesired situation to make it impossible.


* Edge (u->v) means that u implies v. If u is true, v must be true
* (V1 or V2) into implication operations:
    i)  If V1 = False, V2 must be true ---->   !V1 -> V2
    ii) If V2 = False, V1 must be true ---->   !V2 -> V1
* If b is reachable from a and a is assigned a true value, then b must also be true.

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

const int N = 2e5+5;

struct twoSat{
    int n;
    vector<int> Graph[2*N], Rev[2*N], V, sortedNodes;
    bool state[2*N], vis[2*N];
    int sccID[2*N];

    void init(int _n)
    {
        n = _n;
        for(int i = 0; i<=2*n; i++) Graph[i].clear(), Rev[i].clear(), state[i] = false;
        sortedNodes.clear();
    }

    inline int actual(int a)
    {
        return (a<0) ? n-a : a;
    }

    inline int neg(int a)
    {
        return (a>n) ? a-n : n+a;
    }

    void dfs(int node)
    {
        vis[node] = true;
        for(int v: Graph[node]) if(!vis[v]) dfs(v);
        V.pb(node);
    }

    void dfsRev(int node, int id)
    {
        sortedNodes.pb(node);
        vis[node] = true;
        sccID[node] = id;
        for(int v: Rev[node]) if(!vis[v]) dfsRev(v, id);
    }

    void buildSCC()
    {
        V.clear();
        for(int i = 0; i<=2*n; i++) vis[i] = 0;
        for(int i = 1; i<=2*n; i++) if(!vis[i]) dfs(i);
        for(int i = 0; i<=2*n; i++) vis[i] = 0;
        reverse(all(V));

        int id = 0;
        for(int u: V) if(!vis[u]) dfsRev(u, ++id);
    }

    bool topologicalOrder(int a, int b)
    {
        return sccID[a] < sccID[b];
    }

    bool satisfy()
    {
        buildSCC();
        for(int i = 1; i<=n; i++) if(sccID[i] == sccID[i+n]) return false;

        for(int i = (int)sortedNodes.size()-1; i>=0; i--)
        {
            int u = sortedNodes[i];
            if(state[neg(u)] == false) state[u] = true;
        }
        return true;
    }

    void addEdge(int u, int v)
    {
        u = actual(u);
        v = actual(v);
        Graph[u].pb(v);
        Rev[v].pb(u);
    }

    void addOr(int u, int v)
    {
        addEdge(-u, v);
        addEdge(-v, u);
    }

    void addXor(int u, int v)
    {
        addOr(u, v);
        addOr(-u, -v);
    }

}sat;

int main()
{
    TC{
        int n,m;
        cin >> n >> m;
        sat.init(n);

        FOR(i,1,m){
            int u,v;
            cin >> u >> v;
            sat.addOr(u,v);
        }

        FOR(i,1,n/2) sat.addXor(2*i,2*i-1);

        if(!sat.satisfy()) cout << "impossible\n";
        else{
            cout << "possible\n";
            FOR(i,1,n) cout << sat.state[i];
            cout << '\n';
        }
    }
}
