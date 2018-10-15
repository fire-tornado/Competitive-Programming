#include<bits/stdc++.h>

using namespace std;

#define MAX             100005
#define MOD             1000003
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
#define vi              vector <int>
#define vl              vector <ll>
#define vp              vector<pii>
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
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

int id,n,q,block_size,ans;
int arr[MAX],answer[MAX],freq[MAX],cnt[2*MAX];
pii update[MAX];
pair<pii,pii>qry[MAX];

map<int,int>mp;

bool mo_cmp(pair<pii,pii>x,pair<pii,pii>y)
{
    if(x.ff.ff/block_size!=y.ff.ff/block_size)
        return x.ff.ff/block_size<y.ff.ff/block_size;
    if(x.ff.ss/block_size!=y.ff.ss/block_size)
        return x.ff.ss/block_size<y.ff.ss/block_size;
    return x.ss.ff < y.ss.ff;
}

void add(int x)
{
    freq[cnt[x]]--;
    cnt[x]++;
    freq[cnt[x]]++;
}

void Remove(int x)
{
    freq[cnt[x]]--;
    cnt[x]--;
    freq[cnt[x]]++;
}

void _update(int i,int u,int v)
{
    int idx=update[i].ff;
    int val=update[i].ss;

    if(idx>v or idx<u) swap(arr[idx],update[i].ss);
    else
    {
        Remove(arr[idx]);
        add(val);
        swap(arr[idx],update[i].ss);
    }
}

int main()
{
    FastRead
    cin >> n >> q;
    FOR(i,1,n)
    {
        cin >> arr[i];
        if(mp[arr[i]]==0)
        {
            mp[arr[i]]=++id;
            arr[i]=id;
        }
        else
            arr[i]=mp[arr[i]];
    }
    int up=0,qr=0;
    REP(i,q)
    {
        int u,v,w;
        cin >> u >> v >> w;
        if(u==1)
        {
            qry[qr]=mk(pii(v,w),pii(up,qr));
            qr++;
        }
        else
        {
            if(mp[w]==0) mp[w]=++id;
            update[++up]=pii(v,mp[w]);
        }
    }
    block_size=cbrt(n)*cbrt(n);
    sort(qry,qry+qr,mo_cmp);
    int ml=1,mr=0,mu=0;
    REP(i,qr)
    {
        int l=qry[i].ff.ff;
        int r=qry[i].ff.ss;
        int u=qry[i].ss.ff;
        while(mu<u)
        {
            mu++;
            _update(mu,ml,mr);
        }
        while(mu>u)
        {
            _update(mu,ml,mr);
            mu--;
        }
        while(mr<r)
        {
            mr++;
            add(arr[mr]);
        }
        while(mr>r)
        {
            Remove(arr[mr]);
            mr--;
        }
        while(ml<l)
        {
            Remove(arr[ml]);
            ml++;
        }
        while(ml>l)
        {
            ml--;
            add(arr[ml]);
        }
        FOR(j,1,700)
        {
            if(freq[j]==0 and answer[qry[i].ss.ss]==0)
            {
                answer[qry[i].ss.ss]=j;
                break;
            }
        }
    }
    REP(i,qr) cout << answer[i] << '\n';
    return 0;
}
