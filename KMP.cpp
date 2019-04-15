#include <bits/stdc++.h>
using namespace std;

int lps[2000006];
string txt,pat;

void failure_table()
{
    int i=1,j=0,len=pat.size();
    lps[0]=0;
    while(i<len)
    {
        if(pat[i]==pat[j]){
            j++;
            lps[i]=j;
            i++;
        }
        else{
            if(j!=0) j=lps[j-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return;
}

int KMP()
{
    int m=pat.size();
    int n=txt.size();
    failure_table();
    int i=0,j=0;
    while(i<n)
    {
        if(pat[j]==txt[i]){
            i++;
            j++;
        }
        if(j==m) return i-j;
        else if(i<n and pat[j]!=txt[i]){
            if(j!=0) j=lps[j-1];
            else i++;
        }
    }
    return -1;
}

int main()
{
    cin >> txt >> pat;
    cout << KMP();
    return 0;
}
