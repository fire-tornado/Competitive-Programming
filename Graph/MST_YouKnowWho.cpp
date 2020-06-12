//https://toph.co/p/poltu-and-minimum-spanning-tree
//Author: YouKnowWho

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

struct dsu {
	vector<int> par, rnk, Size; int c;
	dsu(int n) : par(n+1), rnk(n+1,0), Size(n+1,1), c(n) {
		for (int i = 1; i <= n; ++i) par[i] = i;
	}
	int Find(int i) { return (par[i] == i ? i : (par[i] = Find(par[i]))); }
	bool Same(int i, int j) { return Find(i) == Find(j); }
	int Get_Size(int i) { return Size[Find(i)]; }
	int Count() { return c; } //connected components
	int Merge(int i, int j) {
		if ((i = Find(i)) == (j = Find(j))) return -1; else --c;
		if (rnk[i] > rnk[j]) swap(i, j);
		par[i] = j; Size[j] += Size[i];
		if (rnk[i] == rnk[j]) rnk[j]++;
		return j;
	}
};

const int N = 5e5+5;
int n,m,k;
int u[N], v[N], w[N], c[N];
pair<long long, int> MST() {
	vector< array<int, 4> > ed;
    for(int i = 1; i <= m; i++){
        ed.push_back({w[i], u[i] , v[i], c[i]});
    }
    sort(ed.begin(), ed.end());
    long long ans = 0; int white = 0;
    dsu d(n);
    for(auto e: ed){
        int u = e[1], v = e[2], w = e[0], c = e[3];
        if(d.Same(u, v)) continue;
        ans += w; white += c;
        d.Merge(u, v);
    }
    return {ans, white};
}

int main()
{
    Fast
    cin >> n >> m >> k;
    FOR(i,1,m) cin >> u[i] >> v[i] >> w[i] >> c[i];
    dsu d(n);
    FOR(i,1,m) if(c[i]) d.Merge(u[i],v[i]);
    if(d.Count()>n-k) return cout << -1,0;
    int lo = -1e9, hi= 1e9, mid;
    LL ans = -1;
    while(lo<=hi){
        mid = (lo+hi)/2;
        FOR(i,1,m) if(c[i]) w[i]+=mid;
        auto p = MST();
        if(p.ss <=k ) ans = p.ff - 1LL * k * mid,hi = mid -1;
        else lo = mid+1;
        FOR(i,1,m) if(c[i]) w[i]-=mid;
    }
    cout << ans;
}
