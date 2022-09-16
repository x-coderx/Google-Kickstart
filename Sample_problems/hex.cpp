#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num_cases;
    cin>>num_cases;
    for(int i=0;i<num_cases;i++)
    {
        //getting work data
        int n;
        cin>>n;

        vector<string> h(n);

        int count_b = 0,count_r = 0;

        for(int j=0;j<n;j++)
        {
            cin>>h[j];
            for(int k=0;k<n;k++)
            {
                if(h[j][k]=='B')
                    count_b++;
                if(h[j][k]=='R')
                    count_r++;
            }
        }


        cout<<"Case #"<<i+1<<": ";
        if(n==1)
        {
            if(h[0][0]=='B')
                cout<<"Blue wins"<<endl;
            else if(h[0][0]=='R')
                cout<<"Red wins"<<endl;
            else if(h[0][0]=='.')
                cout<<"Nobody wins"<<endl;

        }

        else if(abs(count_b-count_r)>=2)
            cout<<"Impossible"<<endl;

        else
            cout<<"To be Solved!"<<endl;
    }
    return 0;
}
