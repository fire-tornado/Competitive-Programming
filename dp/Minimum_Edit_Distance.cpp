//https://www.spoj.com/problems/EDIST/

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

const int N=2005;
int dp[N][N];

int main()
{
    Fast
    TC{
        string A,B;
        cin >> A >> B;
        int n=A.size();
        int m=B.size();

        //Weight for deletion, insertion, substitution.
        int del=1,ins=1,sub=1; //Sub can be 2

        FOR(i,0,n){
            FOR(j,0,m){
                if(j==0) dp[i][0]=i*del;
                else if(i==0) dp[0][j]=j*ins;
                else{
                    dp[i][j]=min(dp[i-1][j]+del,dp[i][j-1]+ins);
                    if(A[i-1]==B[j-1]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
                    else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+sub);
                }
            }
        }
        cout << dp[n][m] << '\n';
    }
}
