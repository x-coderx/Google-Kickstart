#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

int n;
vt<ll> v;


int solve()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        ll temp;
        cin>>temp;
        v.push_back(temp);
    }

    vt<vt<int> > d(n);

    int k=0;

    int dif = v[0]-v[1];

    d[k].push_back(dif);

    for(int i=1;i<n-1;i++)
    {
        int temp = v[i]-v[i+1];
        if(dif!=temp)
        {
            k++;
            dif = temp;
        }
        d[k].pb(dif);
    }

    int max_val = -1;

    for(int i=0;i<n-1;i++)
    {
        if(d[i].size()==0)
            break;
        int dif = d[i][0];
        int count = d[i].size()+1;
        if(d[i+1].size()!=0)
        {
            if(d[i+1].size()==2 && d[i+2][0] == dif && v[count]-v[count+2])
        }
    }

    return max_val;
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

