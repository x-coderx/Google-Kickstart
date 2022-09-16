#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


long long solve2(int ai,int aj, int bi, int bj, int x, int k, vector<ll> &a, vector<ll> &b)
{
    if(x==k)
        return 0ll;
    if(ai>aj)
    {
        return max(b[bi]+solve2(ai,aj,bi+1,bj,x+1,k,a,b) , b[bj]+solve2(ai,aj,bi,bj-1,x+1,k,a,b));
    }
    if(bi>bj)
    {
        return max(a[ai]+solve2(ai+1,aj,bi,bj,x+1,k,a,b) , a[aj]+solve2(ai,aj-1,bi,bj,x+1,k,a,b));
    }
    if(x-k==1)
    {
        ll r1 = max(b[bi]+solve2(ai,aj,bi+1,bj,x+1,k,a,b) , b[bj]+solve2(ai,aj,bi,bj-1,x+1,k,a,b));
        ll r2 = max(a[ai]+solve2(ai+1,aj,bi,bj,x+1,k,a,b) , a[aj]+solve2(ai,aj-1,bi,bj,x+1,k,a,b));
        return max(r1,r2);
    }
    ll r1 = max(b[bi]+b[bj]+solve2(ai,aj,bi+1,bj-1,x+2,k,a,b) , b[bj]+a[aj]+solve2(ai,aj-1,bi,bj-1,x+2,k,a,b));
    ll r2 = max(a[ai]+a[aj]+solve2(ai+1,aj-1,bi,bj,x+2,k,a,b) , a[ai]+b[bi]+solve2(ai+1,aj,bi+1,bj,x+2,k,a,b));
    ll r3 = max(a[ai]+b[bj]+solve2(ai+1,aj,bi,bj-1,x+2,k,a,b) , a[aj]+b[bi]+solve2(ai,aj-1,bi+1,bj,x+2,k,a,b));
    return max(r3,max(r1,r2));

}

long long solve()
{
    int n,m,k;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    vector<ll> b(m);
    for(int i=0;i<m;i++)
        cin>>b[i];
    cin>>k;
    return solve2(0,n-1,0,m-1,-1,k,a,b);
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

