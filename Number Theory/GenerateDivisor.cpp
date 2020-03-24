#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

const int NUM=5000005;
bool flag[NUM];
vector <LL> prime;
void sieve(){
    flag[1]=true;
    for(int i=4; i<NUM; i+=2) flag[i]=true;
    for(int i=3; i*i<=NUM; i+=2){
        if(!flag[i]){
            for(int j=i*i; j<NUM; j+=(i<<1))
                flag[j]=true;
        }
    }
    prime.pb(2);
    for(int i=3; i<NUM; i+=2) if(!flag[i]) prime.pb(i);
    return;
}

vector<pii>fact;
void NOD(LL n){
    fact.clear();
    for(int i=0; prime[i]*prime[i]<=n; i++){
        if(n%prime[i]==0){
            int cnt=0;
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            fact.pb({prime[i],cnt});
        }
    }
    if(n>1) fact.pb({n,1});
    return;
}

vector<LL>divs;
void divisor(){
    divs.clear();
    divs.pb(1);
    for(pii p:fact){
        int sz=divs.size();
        LL x=1;
        for(int j=0;j<p.ss;j++){
            x*=p.ff;
            for(int k=0;k<sz;k++){
                divs.pb(divs[k]*x);
            }
        }
    }
    sort(all(divs));
}

int main()
{
    sieve();
    LL n;
    while(cin >> n){
        if(n==0) break;
        NOD(n);
        divisor();
        for(LL x:divs) cout << x << ' ';
        cout << '\n';
    }
}
