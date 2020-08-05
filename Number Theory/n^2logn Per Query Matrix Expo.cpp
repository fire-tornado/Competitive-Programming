/*
Problem     : https://codeforces.com/gym/102644/problem/I
Blog        : https://shefin-cse16.github.io/post/matrix-exponentiation-optimization/
Solution by : Anachor
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

const int MOD = 1e9+7;
typedef vector<int> row;
typedef vector<row> matrix;

matrix operator*(const matrix&a, const matrix &b) {
    int n = a.size();
    int p = b.size();
    int m = b[0].size();

    matrix ans(n, row(m));
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            for (int k=0; k<p; k++)
                ans[i][j] = (ans[i][j] + 1LL*a[i][k]*b[k][j])%MOD;
    return ans;
}

matrix unit(int n) {
    matrix ans(n, row(n));
    for (int i=0; i<n; i++)
        ans[i][i] = 1;
    return ans;
}

matrix power(const matrix &a, long long p) {
    if (p == 0)     return unit(a.size());
    matrix ans = power(a, p/2);
    ans = ans * ans;
    if (p%2)        ans = ans*a;
    return ans;
}

const int K = 31;
matrix pwr[K];

int main() {
    Fast

    int n, m, q;
    cin>>n>>m>>q;

    matrix base(n, row(n));
    for (int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        u--; v--;
        base[u][v]++;
    }

    pwr[0] = base;
    ///Precalculating all the 2th power of base matrix
    for (int i=1; i<K; i++) pwr[i] = pwr[i-1]*pwr[i-1];

    while (q--) {
        int s, t, k;
        cin>>s>>t>>k;
        s--;
        t--;
        matrix col(n, row(1));
        col[t][0] = 1;

        for(int i=0; i<31; i++)
            if (k&(1<<i))
                col = pwr[i] * col;

        cout<<col[s][0]<<'\n';
    }
}
