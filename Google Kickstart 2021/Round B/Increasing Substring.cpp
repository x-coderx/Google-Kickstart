#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    for(int i=0;i<n;i++)
    {
        int count = 1;
        for(int j=i;j>0;j--)
        {
            if(s[j]>s[j-1])
                count++;
            else
                break;
        }
        cout<<count<<" ";
    }
    cout<<endl;
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

