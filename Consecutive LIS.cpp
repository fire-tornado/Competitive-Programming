#include<bits/stdc++.h>
using namespace std;

//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

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


const int N=200005;
int n;
int arr[N];
int dp[N];
int from[N];
map<int,int>occur;
vector<int>v;

int main()
{
    //FastRead
    cin >> n;
    FOR(i,1,n) cin >> arr[i];

    // Calculating LIS - Complexity O(n log n)
    ROF(i,n,1)
    {
        dp[i]=1;
        from[i]=n+1;

        if(occur[arr[i]+1]) // This is Consecutive Subsequence
        {
            int id=occur[arr[i]+1];
            dp[i]=dp[id]+1;
            from[i]=id;
        }
        occur[arr[i]]=i;
    }

    int cnt=0,maxid=0;
    FOR(i,1,n)
    {
        if(dp[i]>cnt)
        {
            cnt=dp[i];
            maxid=i;
        }
    }

    //Here is printing part
    while(maxid<=n)
    {
        v.pb(arr[maxid]);
        maxid=from[maxid];
    }

    cout << v.size() << '\n';
    for(int i:v) cout << i << ' ';
}
