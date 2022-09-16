#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int> > &v)
{
    int r = v.size(),c = v[0].size();
    vector< vector<int> > temp(c,vector<int> (r));
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            temp[c-j-1][i] = v[i][j];
        }
    }
    v.swap(temp);
}

long long count(vector<vector<int> > v)
{
    int r = v.size(),c = v[0].size();
    vector<vector<int> > a(r,vector<int> (c)),b(r,vector<int> (c));
    long long ans = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if(i==0)
                a[i][j]=v[i][j];
            else
            {
                if(v[i][j])
                    a[i][j]=1+a[i-1][j];
            }
            if(j==0)
                b[i][j] = v[i][j];
            else
            {
                if(v[i][j])
                    b[i][j] = 1+b[i][j-1];
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            long long row = a[i][j], col = b[i][j];
            if(row==0 || col ==0)
                continue;
            if(row>2)
                ans+=min(row/2,col)-1;
            if(col>2)
                ans+=min(col/2,row)-1;
        }
    }
    return ans;
}

long long solve(vector<vector<int> > &v)
{
    long long ans = 0ll;
    ans+=count(v);
    rotate(v);
    ans+=count(v);
    rotate(v);
    ans+=count(v);
    rotate(v);
    ans+=count(v);
    return ans;
}

int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > v(r,vector<int> (c));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                cin>>v[i][j];
            }
        }
        cout<<"Case #"<<z<<": "<<solve(v)<<endl;
    }
    return 0;
}
