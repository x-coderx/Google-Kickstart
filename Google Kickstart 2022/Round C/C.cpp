#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


vector<int> solve()
{
    int n,l;
    cin>>n>>l;
    vector<pair<int,int> > p(l+1,{0,0});
    for(int i=1;i<=n;i++)
    {
        int ant, d;
        cin>>ant>>d;
        if(d)
            p[ant] = {i,0};
        else
            p[ant] = {0,i};
    }

    int x = n;
    vector<int> res;
    while(x)
    {
        vector<pair<int,int> > temp(l+1,{0,0});
        for(int i=0;i<=l;i++)
        {
            if(i==0 && p[i].second!=0)
            {
                res.pb(p[i].second);
                x--;
                continue;
            }
            if(i==l && p[i].first!=0)
            {
                res.pb(p[i].first);
                x--;
                continue;
            }
            if(p[i].first!=0 && p[i+1].second!=0)
            {
                temp[i].second = p[i].first;
                p[i].first = 0;
                temp[i+1].first = p[i+1].second;
                p[i+1].second = 0;
                i++;
                continue;
            }
            if(p[i].first !=0 && p[i].second!=0)
            {
                int temp1 = p[i].first, temp2 = p[i].second;
                temp[i-1].second = temp1;
                temp[i+1].first = temp2;
                continue;
            }

            if(p[i].first!=0)
            {
                temp[i+1].first = p[i].first;
                continue;
            }
            if(p[i].second!=0)
            {
                temp[i-1].second = p[i].second;
                continue;
            }
        }
        p = temp;
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
        for(int i=0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
    }
    return 0;
}

