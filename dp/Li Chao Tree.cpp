/*
https://atcoder.jp/contests/dp/tasks/dp_z
https://www.youtube.com/watch?v=DknbfinVLLk&t
*/

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

const int N = 1e6+1;
const LL INF = 1e17;

vector<vector<LL> >tree(4*N,{0,INF});

LL f(vector<LL>line,int x){
    return line[0]*x + line[1];
}

void add(vector<LL>line,int lo = 1,int hi = N,int pos = 1){
    int m = (lo+hi)/2;
    bool left = f(line,lo) < f(tree[pos],lo);
    bool mid  = f(line,m)  < f(tree[pos],m);
    if(mid) swap(tree[pos],line);
    if(hi-lo==1) return;
    else if(left!=mid) add(line,lo,m,2*pos);
    else add(line,m,hi,2*pos+1);
}

LL query(int x,int lo = 1,int hi = N,int pos = 1){
    int m = (lo+hi)/2;
    LL curr = f(tree[pos],x);
    if(hi-lo==1) return curr;
    if(x<m) return min(curr,query(x,lo,m,2*pos));
    else return min(curr,query(x,m,hi,2*pos+1));
}

int main()
{
    int n;
    LL c;
    cin >> n >> c;
    vector<LL>dp(n,0),h(n);
    for(int i=0;i<n;i++) {
        cin >> h[i];
        if(i!=0) dp[i] = c + h[i]*h[i] + query(h[i]);
        add({-2*h[i],dp[i]+h[i]*h[i]});
    }
    cout << dp[n-1];
}
