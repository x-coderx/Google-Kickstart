#include<bits/stdc++.h>
using namespace std;

//temperatures need to be distinct and we should know the range of temperatures.

int main()
{
    int n;
    cin>>n;
    int max_temp = 101;
    vector<int> temp(n);
    vector<int> t(101);
    vector<int> res(n);
    for(int i=0;i<n;i++)
    {
        cin>>temp[i];
        t[temp[i]] = i;
    }

    for(int i=0;i<n;i++)
    {
        for(int j= temp[i]+1;j<101;i++)
        {
            if(t[j] > i)
                res[i] = t[j]-i;
        }
    }

    for(int i=0;i<n;i++)
        cout<<res[i]<<" ";
    return 0;
}
