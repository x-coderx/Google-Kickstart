#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


long long solve2(vector<int> &s, pair<int,int> z, int pre, int n, int x, vector<vector<pair<int,int> > > &v)
{
    if(x==n)
        return 0;
    if(s[x]==pre)
        return solve2(s,z,pre,n,x+1,v);
    int key = s[x];
    long long res = INT_MAX;
    for(int i=0;i<v[key].size();i++)
    {
        pair<int,int> t = v[key][i];
        int add = min(abs(z.first-t.first),abs(z.first-t.second));
        add = min(add,abs(z.second-t.first));
        add = min(add,abs(z.second-t.second));
        if(z.first==-1)
            add=0;
        res = min(res,add+solve2(s,t,key,n,x+1,v));
    }
    return res;
}

long long solve()
{
    int n,m;
    cin>>n;
    vector<int> s(n);
    for(int i=0;i<n;i++)
        cin>>s[i];
    cin>>m;
    vector<int> k(m);
    for(int i=0;i<m;i++)
        cin>>k[i];

    if(n==1)
        return 0;

    vector<vector<pair<int,int> > > v(2501);
    v[k[0]].pb({0,0});
    for(int i=1;i<m;i++)
    {
        if(k[i]==k[i-1])
        {
            v[k[i]][v[k[i]].size()-1].second++;
        }
        else
            v[k[i]].pb({i,i});
    }
    return solve2(s,{-1,-1},-1,n,0,v);
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

