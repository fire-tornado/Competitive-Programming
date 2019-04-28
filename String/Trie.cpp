#include<bits/stdc++.h>
using namespace std;

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int tri[1000005][26]; //Total char in input file,Number of distinct char
bool flag[1000005]; //Indicate where string finishes
int id=1;

int main()
{
    string str;
    cin >> str;
    int r=1;
    REP(i,str.size())
    {
        int x=str[i]-'a'; // It maybe '0'/'A'/both
        if(!tri[r][x])
        {
            tri[r][x]=++id;
        }
        r=tri[r][x];
    }
    flag[r]=true;

    return 0;
}
