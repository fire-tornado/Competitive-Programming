//http://codeforces.com/contest/932/problem/F

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

const LL is_query = -(1LL<<62);
struct Line {
    LL m, b;
    mutable function<const Line*()> succ;
    bool operator<(const Line& rhs) const {
        if (rhs.b != is_query) return m < rhs.m;
        const Line* s = succ();
        if (!s) return 0;
        LL x = rhs.m;
        return b - s->b < (s->m - m) * x;
    }
};
struct HullDynamic : public multiset<Line> { // will maintain upper hull for maximum
    bool bad(iterator y) {
        auto z = next(y);
        if (y == begin()) {
            if (z == end()) return 0;
            return y->m == z->m && y->b <= z->b;
        }
        auto x = prev(y);
        if (z == end()) return y->m == x->m && y->b <= x->b;

        return (__int128) (x->b - y->b) * (z->m - y->m) >= (__int128)(y->b - z->b) * (y->m - x->m);
        //return (x->b - y->b) * (z->m - y->m) >= (y->b - z->b) * (y->m - x->m);
    }
    void insert_line(LL m, LL b) {
        auto y = insert({ m, b });
        y->succ = [=] { return next(y) == end() ? 0 : &*next(y); };
        if (bad(y)) { erase(y); return; }
        while (next(y) != end() && bad(next(y))) erase(next(y));
        while (y != begin() && bad(prev(y))) erase(prev(y));
    }
    LL eval(LL x) {
        auto l = *lower_bound((Line) { x, is_query });
        return l.m * x + l.b;
    }
};

const int N = 1e5 + 5;
LL a[N],b[N],subtree[N],ans[N];
vector<int>V[N];

void dfs(int s,int pr){
    subtree[s] = 1;
    for(int u:V[s]){
        if(u==pr) continue;
        subtree[s] += subtree[u];
    }
}

void smallToLarge(int s,int pr,HullDynamic &cur){
    int mx = -1, bigchild = -1;
    for(int u:V[s]){
        if(u==pr) continue;
        if(subtree[u]>mx){
            mx = subtree[u];
            bigchild = u;
        }
    }

    if(bigchild!=-1) smallToLarge(bigchild,s,cur);

    for(int u:V[s]){
        if(u!=pr and u!=bigchild){
            HullDynamic tmp;
            smallToLarge(u,s,tmp);
            for(auto it:tmp){
                cur.insert_line(it.m,it.b);
            }
        }
    }

    if(bigchild==-1) ans[s] = 0;
    else ans[s] = -cur.eval(a[s]);
    cur.insert_line(-b[s],-ans[s]);
}

int main()
{
    Fast
    int n;
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];

    FOR(i,1,n-1){
        int u,v;
        cin >> u >> v;
        V[u].pb(v);
        V[v].pb(u);
    }

    dfs(1,0);
    HullDynamic cur;
    smallToLarge(1,0,cur);
    FOR(i,1,n) cout << ans[i] << ' ';
}
