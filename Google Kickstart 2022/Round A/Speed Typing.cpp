#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


long long solve()
{
    ll count=0ll;
    string s,p;
    cin>>s>>p;
    int i=0,j=0;
    while(i<s.size() && j<p.size())
    {
        if(s[i]==p[j])
        {
            i++,j++;
        }
        else
        {
            j++;
            count++;
        }
    }
    if(i!=s.size())
        return -1;
    return count+(p.size()-j);
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        long long res = solve();
        if(res<0)
            cout<<"Case #"<<z<<": IMPOSSIBLE"<<endl;
        else
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}

