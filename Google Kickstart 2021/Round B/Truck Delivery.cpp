#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

struct edge;
{
    int u, v, limit, toll;
    edge(int u, int v, int limit, int toll)
    {
        this.u = u;
        this.v = v;
        this.limit = limit;
        this.toll = toll;
    }
};

long long solve2()
{

}

void solve()
{
    int n,q;
    cin>>n>>q;
    vt<vt<edge> > edges(n+1);
    for(int i=0;i<n-1;i++)
    {
        int x,y,l,a;
        cin>>x>>y>>l>>a;
        edge temp = new edge(x,y,l,a);
        edges[x].push_back(temp);
    }
    for(int i=0;i<q;i++)
    {
        int c,w;
        cin>>c>>w;
        cout<<solve2(c,w);
    }
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

