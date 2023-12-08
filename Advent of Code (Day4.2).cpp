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
    vector<int>v;
    getline(cin,s);
    while(s!="AARD")
    {
        int cnt=0;
        map<int,int>m,a;
        int flag=0,sett=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==':')
            {
                sett=1;
            }
            if(s[i]=='|')
            {
                flag=1;
            }
            if(!flag && sett)
            {
                k=0;
                if(s[i]>=48 && s[i]<=57)
                {
                    if(i+1<s.size() && s[i+1]>=48 && s[i]<=57)
                    {
                        k=10*(s[i]-48);
                        k+=(s[i+1]-48);
                        i++;
                    }
                    else
                    {
                        k=(s[i]-48);
                    }
                    m[k]++;
                }
            }
            else if(sett && flag)
            {
                k=0;
                if(s[i]>=48 && s[i]<=57)
                {
                    if(i+1<s.size() && s[i+1]>=48 && s[i]<=57)
                    {
                        k=10*(s[i]-48);
                        k+=(s[i+1]-48);
                        i++;
                    }
                    else
                    {
                        k=(s[i]-48);
                    }
                    a[k]++;
                }
            }
            if(a[k]>0 && m[k]>0)
            {
                cnt++;
            }
        }
        v.push_back(cnt);
        getline(cin,s);
    }
    vector<int>nov(v.size(),0);
    nov[0]=1;
    for(int i=1;i<v.size();i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+v[j]>=i)
            {
                nov[i]+=nov[j];
            }
        }
        nov[i]++;
    }
    for(int i=0;i<nov.size();i++)
    {
        sum+=nov[i];
    }
    cout<<sum<<endl;
    return 0;
}
