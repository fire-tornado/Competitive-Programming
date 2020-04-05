/*
https://www.codechef.com/problems/GRAPHCNT/
https://tanujkhattar.wordpress.com/2016/01/11/dominator-tree-of-a-directed-graph/
*/
#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

const int N = 1e5+5;
vector<int>graph[N],dtree[N],rGraph[N],bucket[N];
int sdom[N],par[N],dom[N],dsu[N],label[N];
int arr[N],rev[N],Time;
LL ans;

int Find(int u,int x=0)
{
	if(u==dsu[u]) return x?-1:u;
	int v = Find(dsu[u],x+1);
	if(v<0) return u;
	if(sdom[label[dsu[u]]] < sdom[label[u]]) label[u] = label[dsu[u]];
	dsu[u] = v;
	return x?v:label[u];
}

void Union(int u,int v)
{
	dsu[v]=u;
}

void dfs0(int s)
{
	Time++;arr[s]=Time;rev[Time]=s;
	label[Time]=Time;sdom[Time]=Time;dsu[Time]=Time;
	for(int u:graph[s]){
		if(!arr[u]) dfs0(u),par[arr[u]]=arr[s];
		rGraph[arr[u]].pb(arr[s]);
	}
}

void build(int source)
{
    dfs0(source);
	int n=Time;
	for(int i=n;i>=1;i--)
	{
		for(int u:rGraph[i]) sdom[i] = min(sdom[i],sdom[Find(u)]);
		if(i>1) bucket[sdom[i]].pb(i);
		for(int u:bucket[i]){
			int v = Find(u);
			if(sdom[v]==sdom[u]) dom[u]=sdom[u];
			else dom[u] = v;
		}
		if(i>1) Union(par[i],i);
	}

	for(int i=2;i<=n;i++)
	{
		if(dom[i]!=sdom[i]) dom[i]=dom[dom[i]];
		dtree[rev[i]].pb(rev[dom[i]]);
		dtree[rev[dom[i]]].pb(rev[i]);
	}
}

int dfs(int s,int p)
{
	int ret=1;
	for(int u:dtree[s])
	{
		if(u==p)continue;
		int x = dfs(u,s);
		if(s==1) ans -= (x*1ll*(x-1ll))/2ll;
		ret+=x;
	}
	return ret;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		graph[u].pb(v);
	}

	build(1);

	ans = (Time*1ll*(Time-1ll))/2ll;
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
