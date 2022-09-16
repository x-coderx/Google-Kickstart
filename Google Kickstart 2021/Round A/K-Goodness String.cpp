#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int count=0;
        for(int i=0;i<n/2;i++)
        {
            if(s[i]!=s[n-i-1])
                count++;
        }
        cout<<"Case #"<<z<<": "<<abs(k-count)<<endl;
    }
    return 0;
}

