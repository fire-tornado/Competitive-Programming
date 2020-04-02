//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2031

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
#define pii             pair<int,LL>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const int N=55;
int n,m;
vector<pii>V[N];
LL dp[N][N];

double minAvgWeight(){
    double ret=1e16;
    FOR(snk,1,n){
        FOR(i,1,n) dp[0][i]=1e16;
        dp[0][snk]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                dp[i][j]=1e16;
                for(pii k:V[j]){
                    dp[i][j]=min(dp[i][j],dp[i-1][k.ff]+k.ss);
                }
            }
            ret=min(ret,dp[i][snk]/(double)i);
        }
    }
    return ret;
}

int main()
{
    Fast
    TC{
        cin >> n >> m;
        FOR(i,1,n) V[i].clear();
        double ans=1e16;
        FOR(i,1,m){
            int u,v,w;
            cin >> u >> v >> w;
            if(u==v) ans=min(ans,(double)w);
            else V[u].pb({v,w});
        }
        ans=min(minAvgWeight(),ans);
        cout << "Case #" << tc << ": ";
        if(ans>1e12) cout << "No cycle found.\n";
        else cout << fixed << setprecision(2) << ans << '\n';
     }
}
