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
#define pll             pair<LL,LL>
#define vi              vector <int>
#define vl              vector <LL>
#define vp              vector<pii>
#define all(a)          a.begin(),a.end()

#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define IT(it,x)	for(it=x.begin();it!=x.end;it++)

#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())

int main()
{
    //fWrite
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        ll n;
        scanf("%lld",&n);
        ll arr[n+1];
        REP(i,n) scanf("%lld",&arr[i]);
        stack<ll>st;
        st.push(0);
        ll ans=-1;
        FOR(i,1,n)
        {
            if(i==n)
            {
                while(!st.empty())
                {
                    ll j=st.top();
                    st.pop();
                    if(!st.empty())
                    {
                        ans=max(ans,arr[j]*(i-st.top()-1));
                    }
                    else
                    {
                        ans=max(ans,arr[j]*i);
                        break;
                    }
                }
            }
            else
            {
                if(arr[i]>=arr[st.top()])
                {
                    st.push(i);
                }
                else
                {
                    while(arr[st.top()]>arr[i])
                    {
                        ll j=st.top();
                        st.pop();
                        if(!st.empty())
                        {
                            ans=max(ans,arr[j]*(i-st.top()-1));
                        }
                        else
                        {
                            ans=max(ans,arr[j]*i);
                            break;
                        }
                    }
                    st.push(i);
                }
            }
        }
        printf("Case %d: %lld\n",tc,ans);
    }
    return 0;
}
