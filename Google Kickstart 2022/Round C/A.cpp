#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


string solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int a=0, b=0, c=0, d=0, e=0;
    for(char x : s)
    {
        if(x>='A' && x<='Z')
        {
            b=1;
            continue;
        }
        if(x>='a' && x<='z')
        {
            c=1;
            continue;
        }
        if(x>='0' && x<='9')
        {
            d=1;
            continue;
        }
        if(x=='#' || x=='@' || x=='*' || x=='&')
        {
            e=1;
            continue;
        }
    }
    if(b==0)
    {
        s+='A';
        n++;
    }
    if(c==0)
    {
        s+='a';
        n++;
    }
    if(d==0)
    {
        s+='0';
        n++;
    }
    if(e==0)
    {
        s+='#';
        n++;
    }
    while(n<7)
    {
        s+='a';
        n++;
    }
    return s;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        string res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}

