#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    sort(all(v));
    reverse(all(v));
    long double res = 0.000000;
    for(int i=0;i<m-1;i++)
        res+=v[i];
    int temp = n-m+1;
    if(temp%2)
        res+=v[n-m-1+(temp/2)];
    else
        res+= ((long double)(v[n-m+(temp/2)]+v[n-m-1+(temp/2)])/2);
    cout<<fixed<<setprecision(6)<<res<<endl;
    return;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        cout<<"Case #"<<z<<": ";
        solve();
    }
    return 0;
}

