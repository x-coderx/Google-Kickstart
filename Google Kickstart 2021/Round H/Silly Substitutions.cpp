#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

auto next(char c)
{
        return c=='9'?'0':c+1;
}

string solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res = "";
    vector<int> l(n),r(n);
    iota(all(l),-1);
    iota(all(r),1);
    vector<bool> d(n,false);
    vector<vector<int> >a(10);

    int count=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0'+i && next('0'+i)==s[r[j]])
            {
                a[i].pb(j);
                count++;
            }
        }
    }

    int index = 0;
    while(count)
    {
        //cout<<"HI"<<endl;
        while(a[index].size())
        {
            //cout<<"hello"<<endl;
            int x = a[index].back();
            int y = r[x];
            a[index].pop_back();
            count--;

            if(s[x]!='0'+index || s[y]!=next(s[x]))
                continue;

            if(l[x]>=0)
            {
                r[l[x]]=y;
            }
            l[y] = l[x];
            d[x] = true;
            s[y] = next(s[y]);
            if(l[y]>=0 && next(s[l[y]]) == s[y])
            {
                a[(index+1)%10].pb(l[y]);
                count++;
            }
            if(r[y]<n && next(s[y])==s[r[y]])
            {
                a[(index+2)%10].pb(y);
                count++;
            }
        }
        index = (index+1)%10;
    }
    for(int i=0;i<n;i++)
        if(!d[i])
            res.pb(s[i]);
    return res;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        string res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}

