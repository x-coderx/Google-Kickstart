#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

bool pal(string x)
{
    for(int i=0;i<5;i++)
        if(s[i]!=s[4-i] || (s[i]=='?'))
            return false;
    return true;
}
long long solve()
{
    ll n;
    cin>>n;
    string s;
    cin>>s;
    string p = s.substr(0,6);

}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        long long res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}

