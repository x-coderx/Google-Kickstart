#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

ll check(ll x, ll d)
{
    return min(x,d-x);
}

long long solve()
{
    int n;
    cin>>n;
    ll d;
    cin>>d;
    vector<ll> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int l=0,r=n-1;
    ll ans = 0ll;
    while(l<=r)
    {
        ll t1 = check(v[l],d), t2 = check(v[r],d);
        if(t1<t2)
        {
            ans+=t1;
            v[r]-=t1;
            while(v[l]==t1 && l<=r)
            {
                v[l]=0;
                l++;
            }
        }
        else if(t1>t2)
        {
            ans+=t2;
            v[l]-=t2;
            while(v[r]==t2 && l<=r)
            {
                v[r]=0;
                r--;
            }
        }
        else
        {
            ans+=t1;
            while(v[l]==t1 && l<=r)
            {
                v[l]=0;
                l++;
            }
            while(v[r]==t1 && l<=r)
            {
                v[r] = 0;
                r--;
            }
        }
    }
    return ans;
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

