#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()


string solve()
{
    string n;
    cin>>n;
    ll sum=0;
    vector<int> res;
    for(char c : n)
    {
        sum+=(c-'0');
    }
    int num1 = sum%9;
    int num2 = 9-sum%9;
    if((sum+num1)%9)
        num1 = INT_MAX;
     if((sum+num2)%9)
        num2 = INT_MAX;
    int num = min(num1,num2);
    char c = '0'+num;
    if(c=='0')
    {
        n.insert(n.begin()+0,c);
        swap(n[0],n[1]);
        return n;
    }
    bool flag = true;
    for(int i=0;i<n.size();i++)
    {
        if(c<n[i])
        {
            n.insert(n.begin()+i,c);
            flag=false;
            break;
        }
    }
    if(flag)
        n.push_back(c);
    return n;
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

