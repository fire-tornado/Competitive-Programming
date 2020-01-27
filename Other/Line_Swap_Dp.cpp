//https://dmoj.ca/problem/ioi00p1
//https://www.commonlounge.com/discussion/6701338ab1e24ffd89e470ffe848af3f

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int dp[3][5005];

int main()
{
    Fast
    int n;
    string str;
    cin >> n >> str;
    // handling the empty / single characters strings case
    for(int i=0;i<n;i++) dp[0][i]=dp[1][i]=0;

    // iterating through lengths
    for(int len=2;len<=n;len++){

        // initiating the table we are going to fill
        for(int l=0;l<n;l++) dp[2][l]=0x3f3f3f3f;

        // filling table
        for(int l=0;l+len-1<n;l++){
            if(str[l]==str[l+len-1]) dp[2][l]=dp[0][l+1];
            else dp[2][l]=min(dp[1][l+1],dp[1][l])+1;
        }

        // dropping the pre-previous table and shifting our tables
        swap(dp[0],dp[1]);
        swap(dp[1],dp[2]);
    }
    cout << dp[1][0];
}

