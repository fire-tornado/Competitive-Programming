//https://vjudge.net/problem/UVA-13183

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
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

const int N=1e6+5;
pii arr[N];
int flag[N];
vector<int>tree[4*N];

void build(int node,int L,int R)
{
    if(L==R){
        tree[node].pb(arr[L].ss);
        return;
    }
    int mid=(L+R)/2;
    build(node*2,L,mid);
    build(2*node+1,mid+1,R);
    merge(all(tree[2*node]),all(tree[2*node+1]),back_inserter(tree[node]));
}

int query(int node,int L,int R,int l,int r,int val)
{
    if(L==R) return tree[node][0];
    int cnt=upper_bound(all(tree[2*node]),r)-lower_bound(all(tree[2*node]),l);
    int mid=(L+R)/2;
    if(val>cnt) return query(node*2+1,mid+1,R,l,r,val-cnt);
    else return query(node*2,L,mid,l,r,val);
}

int main()
{
    int n,q;
    while(scanf("%d %d",&n,&q)!=EOF){
        FOR(i,1,4*n) tree[i].clear();

        FOR(i,1,n) scanf("%d",&arr[i].ff);
        FOR(i,1,n) arr[i].ss=i,flag[i]=arr[i].ff;
        sort(arr+1,arr+n+1);
        build(1,1,n);
        while(q--){
            int l,r,k;
            scanf("%d %d %d",&l,&r,&k);
            printf("%d\n",flag[query(1,1,n,l,r,k)]);
        }
    }
}
