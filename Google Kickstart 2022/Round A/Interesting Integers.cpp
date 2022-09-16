#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

ll bigpow(ll a , ll b)
{
    ll pow = 1ll;
    while(b)
    {
        if(b&1)
            pow*=a;
        a*=a;
        b>>=1;
    }
    return pow;
}

int zero(ll x)
{
    int index,i=1;
    while(x)
    {
        if(x%10==0)
        {
            index = i;
        }
        i++;
        x/=10;
    }
    return index;
}

ll generatenum(ll x)
{
    int index = zero(x);
    ll help = bigpow(10,index);
    x-=x%help;
    ll help2 = 0ll;
    while(index--)
    {
        help2*=10;
        help2+=1;
    }
    return x+help2;
}

array<ll,3> fun(ll x)
{
    array<ll,3>check;
    check[0] = 1ll;
    check[1] = 0ll;
    while(x)
    {
        check[0]*=x%10;
        check[1]+=x%10;
        x/=10;
    }
    check[2] = check[0]%check[1];
    return check;
}

long long solve()
{
    ll l, r,count = 0ll;
    cin>>l>>r;
    array<ll,3> res = fun(l);
    int j = l%10;
    while(l<=r)
    {
        if(l>=1 && l<=9)
        {
            count++;
            l++;
            continue;
        }
        if(res[0] == 0)
        {
            ll temp = generatenum(l);
            if(temp>r)
                temp=r+1;
            count+=(temp-l);
            l = temp;
            res = fun(l);
            continue;
        }
        if(res[2]==0)
            count++;
        j=l%10;
        l++;
        if(j!=0)
            res[0]/=j;
        res[1]++;
        j=l%10;
        res[0]*=j;
        res[2]=res[0]%res[1];
    }
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
