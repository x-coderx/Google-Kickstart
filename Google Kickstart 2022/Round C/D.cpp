#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

vector<ll> f(401);
ll m = 1000000007;
bool check(string s)
{
    string temp = s;
    reverse(all(s));
    return (s==temp)? true : false;
}

long long solve2(string s, int n)
{
    if(n==1)
        return 2ll;
    ll ans =(check(s)?1:0);
    for(int i=0;i<n;i++)
    {
        string temp = s.substr(0,i)+s.substr(i+1,n-i);
        ans+=solve2(temp,n-1);
    }
    return ans;
}
long long solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    ll ans = solve2(s,n);
    int d = __gcd(ans,f[n]);
    int x = ans/d;
    int y = f[n]/d;
    for(long long i=0ll;i<1000000007;i++)
    {
        if((i*y)%m == x%m)
            return i;
    }
    return m;
}

int main()
{
    ll num = 1;
    for(int i=1;i<401;i++)
    {
        num = num*i%m;
        f[i] = num;
    }
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        long long res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;

    }
    return 0;
}

