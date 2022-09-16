#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int n;
        cin>>n;
        vector<string> v(n);
        int res = 0;
        for(int i=0;i<n;i++)
        {
            getline(cin,v[i]);
        }
        for(int i=0;i<n-1;i++)
        {
            int temp = i;
            for(int j=i+1;j<n;j++)
            {
                if(v[temp]>v[j])
                    temp = j;
            }
            if(temp!=i)
            {
                swap(v[temp],v[i]);
                res++;
            }
        }
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}
