#include<bits/stdc++.h>
using namespace std;

long long check()
{
    string s,f;
    cin>>s>>f;
    long long res = 0ll;
    for(auto& x : s)
    {
        int temp = 26;
        for(auto &y : f)
        {
            int i = x-'a', j = y-'a';
            temp = min(temp,abs(i-j));
            temp = min(temp,26-abs(i-j));
        }
        res+=temp;
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long long res = check();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}
