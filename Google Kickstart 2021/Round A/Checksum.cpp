#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&p, int x)
{
    return x^p[x]?find(p,p[x]):x;
}

int join(vector<int> &p, int x, int y)
{
    if((x=find(p,x))==(y=find(p,y)))
        return 0;
    p[x]=y;
    return 1;
}

long long solve()
{
    int n;
    cin>>n;
    long long ans = 0ll;
    vector<vector<int> >v(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>v[i][j];
    vector<vector<int> >b(n,vector<int>(n));
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>b[i][j];
    vector<int> r(n),c(n);
    for(int i=0;i<n;i++)
        cin>>r[i];
    for(int i=0;i<n;i++)
        cin>>c[i];
    vector<array<int,3> > check;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(v[i][j]<0)
            {
                ans+=b[i][j];
                check.push_back({b[i][j],i,n+j});
            }
        }
    }
    vector<int> p(2*n);
    for(int i=0;i<2*n;i++)
        p[i]=i;

    sort(check.begin(),check.end());
    reverse(check.begin(),check.end());

    for(auto x : check)
    {
        if(join(p,x[1],x[2]))
            ans-=x[0];
    }
    return ans;
}
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long long res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}
