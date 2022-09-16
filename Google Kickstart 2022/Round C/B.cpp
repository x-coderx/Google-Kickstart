#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


vector<int> solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    int sum=(n*(n+1))/2;
    int z=0;
    for(int i=1;i<=sum/2;i++)
    {
        int d = __gcd(i,sum-i);
        if(x==i/d && y==(sum-i)/d)
        {
            z=i;
            break;
        }
    }
    vector<int> res;
    while(z)
    {
        if(z<=n)
        {
            res.push_back(z);
            z=0;
        }
        else
        {
            res.push_back(n);
            z-=n;
            n--;
        }
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        vector<int> res = solve();
        cout<<"Case #"<<z<<": ";
        if(res.size())
        {
            cout<<"POSSIBLE"<<endl<<res.size()<<endl;
        }
        else
            cout<<"IMPOSSIBLE";
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

