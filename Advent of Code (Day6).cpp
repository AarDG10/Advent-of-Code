#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum=0;
    int k=0,flag=0;
    string s;
    vector<string>v;
    vector<int>time,dist;
    getline(cin,s);
    while(s!="AARD")
    {
        v.push_back(s);
        getline(cin,s);
    }
    for(int i=0;i<2;i++)
    {
        if(k!=0) time.push_back(k);
        k=0;
        string a=v[i];
        for(int j=0;j<a.size();j++)
        {
            if(i==0)
            {
                if(a[j]<48 || a[j]>57)
                {
                    if(k!=0)
                    {
                        time.push_back(k);
                    }
                    k=0;
                }
                else
                {
                    if(j+1<a.size() && a[j+1]>=48 && a[j+1]<=57)
                    {
                        k+=10*(a[j]-48);
                    }
                    else
                    {
                        k+=(a[j]-48);
                    }
                }
            }
            else
            {
                if(a[j]<48 || a[j]>57)
                {
                    if(k!=0)
                    {
                        dist.push_back(k);
                    }
                    k=0;
                }
                else
                {
                    if(j+1<a.size() && a[j+1]>=48 && a[j+1]<=57)
                    {
                        if(j+2<a.size() && a[j+2]>=48 && a[j+2]<=57)
                        {
                            if(j+3<a.size() && a[j+3]>=48 && a[j+3]<=57)
                            {
                                k+=1000*(a[j]-48);
                            }
                            else
                            {
                                k+=100*(a[j]-48);
                            }
                        }
                        else
                        {
                            k+=10*(a[j]-48);
                        }
                    }
                    else
                    {
                        k+=(a[j]-48);
                    }
                }
            }
        }
    }
    int check=0;
    vector<int>path;
    int cnt=0;
    if(k!=0) dist.push_back(k);
    for(int i=0;i<time.size();i++)
    {
        int total=time[i];
        check=0,cnt=0;
        while(total--)
        {
            int avg=(time[i]-cnt)*cnt;
            //cout<<avg<<" ";
            if(avg>dist[i]) check++;
            cnt++;
        }
        //cout<<endl;
        if(check!=0) path.push_back(check);
    }
    ll prod=1;
    for(auto i:path) prod*=i;
    //cout<<endl;
    cout<<prod<<endl;
    return 0;
}
