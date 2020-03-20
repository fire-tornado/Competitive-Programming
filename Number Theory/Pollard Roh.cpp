//https://toph.co/arena?contest=criterion-2020-round-4#!/p/story-of-totient-function

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

const int N = 1000005;
LL Mul(LL a, LL b, LL m)
{
	LL ret=0, c=a;
	while(b)
	{
		if(b&1) ret=(ret+c)%m;
		b>>=1; c=(c+c)%m;
	}
	return ret;
}
LL bigmod(LL a, LL n, LL m)
{
	LL ret=1, c=a;
	while(n)
	{
		if(n&1) ret=Mul(ret, c, m);
		n>>=1; c=Mul(c, c, m);
	}
	return ret;
}
bool isPrime(long long n) {
    if (n == 2) return 1;
    if (n%2 == 0) return 0;
    long long d = n-1;
    while(d%2 == 0) d >>= 1;
    int test[] = {2,3,5,7,11,13,17,19,23};
    for(int i = 0; i < 9; i++) {
        long long x = test[i]%(n-2), temp = d;
        if (x < 2) x += 2;
        long long a = bigmod(x, d, n);
        while(temp != n-1 && a != 1 && a != n-1) {
            a = Mul(a, a, n);
            temp <<= 1;
        }
        if (a != n-1 && (temp&1) == 0) return 0;
    }
    return 1;
}

long long pollard_rho(long long n, long long c) {
    long long x = 2, y = 2, i = 1, k = 2, d;
    while(true) {
        x = (Mul(x, x, n) + c);
        if (x >= n) x -= n;
        d = __gcd(abs(x-y),n);
        if (d > 1) return d;
        if (++i == k) {
            y = x, k <<= 1;
        }
    }
    return n;
}
bool stat[N];
vector<LL>primes;

void siv()
{
    for(int i = 4;i < N;i += 2)stat[i] = 1;
    int sq = sqrt(N);
    for(int i = 3;i <= sq;i += 2){
        if(stat[i])continue;
        for(int j = i * i;j < N;j += 2 * i)stat[j] = 1;
    }
    for(int i = 2;i < N;i++)if(stat[i] == 0)primes.push_back(i);
}
void llfactorize(long long n, vector<long long> &f) {
    if (n == 1) return;
    if (n < 1e9) {
        for(int i = 0; primes[i]* primes[i] <= n; i++) {
            while(n%primes[i] == 0) {
                f.push_back(primes[i]);
                n /= primes[i];
            }
        }
        if (n != 1) f.push_back(n);
        return;
    }
    if (isPrime(n)) {
        f.push_back(n);
        return;
    }
    long long d = n;
    for(int i = 2; d == n; i++){
        d = pollard_rho(n, i);
    }
    llfactorize(d, f);
    llfactorize(n/d, f);
}
void factorize(long long n, vector<pair<long long,long long>> &ans) {
    vector<long long> v;
    llfactorize(n, v);
    if(v.size() == 0)return;
    sort(v.begin(), v.end());
    long long a = v[0], b = 1;
    for(int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1] ) b++;
        else {
            ans.push_back({a,b});
            a = v[i];
            b = 1;
        }
    }
    ans.push_back({a,b});
}

LL phi(LL n,vector<pair<long long,long long>> &ans){
    LL ph=n;
    for(auto p:ans){
        ph/=p.ff;
        ph*=(p.ff-1);
    }
    return ph;
}

int main()
{
    siv();
    int t;
    cin >> t;
    while(t--){
        vector<pair<long long,long long>>v;
        LL a;
        cin >> a;
        if(a!=1 and isPrime(a)){
            a++;
            while(!isPrime(a)) a++;
            cout << a << '\n';
            continue;
        }
        factorize(a,v);
        LL x=phi(a,v);
        LL b=a+1;
        while(true){
            vector<pair<long long,long long>>vv;
            factorize(b,vv);
            LL y=phi(b,vv);
            if(y>x){
                cout << b << '\n';
                break;
            }
            b++;
        }
    }
}
