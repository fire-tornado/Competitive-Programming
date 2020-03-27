/*
https://atcoder.jp/contests/dp/tasks/dp_e

Knapsack: Weight range is high, Value range is low
*/

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

LL dp[101][100005];

int main()
{
    int n,w;
    cin >> n >> w; //1 <= w <= 1e9
    pii arr[n+1];
    FOR(i,1,n) cin >> arr[i].ff >> arr[i].ss; // Weight Value
    int sum=0;
    FOR(i,1,n) sum+=arr[i].ss;
    MEM(dp,0x3f3f3f3f3f3f);
    dp[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(j-arr[i].ss>=0) dp[i][j]=min(dp[i][j],dp[i-1][j-arr[i].ss]+arr[i].ff);
            dp[i][j]=min(dp[i-1][j],dp[i][j]);
        }
    }
    int ans=0;
    for(int i=0;i<=sum;i++) if(dp[n][i]<=w) ans=i;
    cout << ans;
}

