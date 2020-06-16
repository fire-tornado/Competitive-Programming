//https://codeforces.com/contest/429/problem/D
//Author : Anachor

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
#define SQR(a)          ((a)*(a))

LL ClosestPair(vector<pii> pts) {
    int n = pts.size();
    sort(all(pts));
    set<pii> s;

    LL best_dist = 1e18;
    int j = 0;
    for (int i = 0; i < n; ++i) {
        int d = ceil(sqrt(best_dist));
        while (pts[i].ff - pts[j].ff >= best_dist) {
            s.erase({pts[j].ss, pts[j].ff});
            j += 1;
        }

        auto it1 = s.lower_bound({pts[i].ss - d, pts[i].ff});
        auto it2 = s.upper_bound({pts[i].ss + d, pts[i].ff});

        for (auto it = it1; it != it2; ++it) {
            int dx = pts[i].ff - it->ss;
            int dy = pts[i].ss - it->ff;
            best_dist = min(best_dist, 1LL * dx * dx + 1LL * dy * dy);
        }
        s.insert({pts[i].ss, pts[i].ff});
    }
    return best_dist;
}

int main(){
    Fast
    int n, sum = 0;
    cin >> n;
    vector<pii> pts;
    FOR(i,1,n){
        int tmp;
        cin >> tmp;
        sum += tmp;
        pts.emplace_back(i,sum);
    }
    cout << ClosestPair(pts);
}
