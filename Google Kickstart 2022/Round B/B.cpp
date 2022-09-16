#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

bool pal(int i)
{
    string temp = to_string(i);
    string temp2 = temp;
    reverse(all(temp));
    return temp==temp2;
}


long long solve()
{
    ll a;
    cin>>a;
    ll count = 0ll;
    ll s = sqrt(a);
    for(int i=1;i<=sqrt(a);i++)
    {
        if(a%i==0)
        {
            count+=(pal(i)+pal(a/i));
        }
    }
    if(s*s == a && pal(s))
        count--;
    return count;
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

