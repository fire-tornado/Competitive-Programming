//https://acm.timus.ru/problem.aspx?space=1&num=1658

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

//N is max sum from 100 digits. M is max sum of square of digits.
const int N=900,M=8100;
bool vis[N+5][M+5];
pii from[N+5][M+5];
char str[N+5][M+5];

void bfs(){
    queue<pii>Q;
    Q.push({0,0});
    vis[0][0]=true;

    FOR(digit,1,100){
        queue<pii>tmp;
        while(!Q.empty()){
            pii p=Q.front();
            Q.pop();
            FOR(d,1,9){
                pii r(p.ff+d,p.ss+d*d);
                if(vis[r.ff][r.ss]) continue;
                vis[r.ff][r.ss]=true;
                from[r.ff][r.ss]=p;
                str[r.ff][r.ss]=(d+'0');
                tmp.push(r);
            }
        }
        swap(tmp,Q);
    }
}

int main()
{
    Fast
    bfs();

    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a>N or b>M or !vis[a][b]) cout << "No solution\n";
        else{
            string ans;
            while(a and b){
                ans+=str[a][b];
                pii p=from[a][b];
                a=p.ff;
                b=p.ss;
            }
            reverse(all(ans));
            cout << ans << '\n';
        }
    }
}
