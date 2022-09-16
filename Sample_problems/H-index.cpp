#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num_cases;
    cin>>num_cases;
    for(int i=0;i<num_cases;i++)
    {
        //get working data
        int num_papers;
        cin>>num_papers;

        vector<int> citations(num_papers);
        for(int j=0;j<num_papers;j++)
            cin>>citations[j];


        //optimization #3
        priority_queue<int, vector<int>, greater<int> > pq;
        int h_index = 0;
        int temp_index = 1;
        int count_citation = 0;
        cout<<"Case #"<<i+1<<": ";
        for(int i=0;i<num_papers;i++)
        {
            while(!pq.empty() && pq.top()<temp_index)
            {
                pq.pop();
                count_citation--;
            }
            if(citations[i]>=temp_index)
            {
                pq.push(citations[i]);
                count_citation++;
            }
            if(count_citation>=temp_index)
            {
                h_index = temp_index++;
            }
            cout<<h_index<<" ";
        }


        //optimization #2
        /*
        int num = 0;
        int h_index = 0;
        int temp_index = 1;
        for(int j=0;j<num_papers;j++)
        {
            num|=citations[j];
            if(num&temp_index)
            {
                h_index = temp_index++;
            }
            cout<<h_index<<" ";
        }*/


        //optimization #1
        /*
        cout<<"Case #"<<i+1<<": ";
        int h_index = 0;
        int temp_index = 1;
        vector<int> work(num_papers);
        for(int j=0;j<num_papers;j++)
        {
            int check = (citations[j]>num_papers) ? num_papers : citations[j];
            for(int k=0;k<check;k++)
                work[k]++;
            if(work[temp_index-1]>=temp_index)
            {
                h_index=temp_index;
                temp_index++;
            }
            cout<<h_index<<" ";
        }*/


        //naive approach
        /*
        cout<<"Case #"<<i+1<<": 1 ";
        int h_index = 1;
        int temp_index = 2;
        for(int j=1;j<num_papers;j++)
        {
            int count_citation = 0;
            for(int k=0;k<=j;k++)
            {
                if(citations[k]>=temp_index)
                    count_citation++;
            }
            if(count_citation>=temp_index)
            {
                h_index=temp_index;
                temp_index++;
            }
            cout<<h_index<<" ";
        }*/

        cout<<endl;
    }
    return 0;
}
