#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

double solve()
{
    int r,a,b;
    cin>>r>>a>>b;
    double sum = 0;
    bool flag = 0;
    while(r)
    {
        sum = sum + (double)(M_PI*(double)r*(double)r);
        if(!flag)
        {
            r*=a;
        }
        else
            r/=b;
        flag = !flag;
    }
    return sum;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        double res = solve();
        cout<<"Case #"<<z<<": "<<fixed<<setprecision(6)<<res<<endl;
    }
    return 0;
}

