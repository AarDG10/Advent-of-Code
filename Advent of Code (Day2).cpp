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
    int id=0,flag=0;
    string s;
    getline(cin,s);
    while(s!="AARD")
    {
        id++;
        int sett=0;
        int bleu=0,vert=0,rouge=0;
        int k=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==':')
            {
                sett=1;
            }
            if(sett && s[i]>=48 && s[i]<=57)
            {
                if(s[i+1]>=48 && s[i+1]<=57)
                {
                    k=10*(s[i]-48);
                    k+=(s[i+1]-48);
                    if(s[i+3]=='b')
                    {
                        bleu=max(bleu,k);
                    }
                    else if(s[i+3]=='g')
                    {
                        vert=max(vert,k);
                    }
                    else if(s[i+3]=='r')
                    {
                        rouge=max(rouge,k);
                    }
                    //cout<<k<<endl;
                }
                else
                {
                    k=(s[i]-48);
                    if(s[i+2]=='b')
                    {
                        bleu=max(bleu,k);
                    }
                    else if(s[i+2]=='g')
                    {
                        vert=max(vert,k);
                    }
                    else if(s[i+2]=='r')
                    {
                        rouge=max(rouge,k);
                    }
                    //cout<<k<<endl;
                }
            }
        }
        if(bleu<=14 && vert<=13 && rouge<=12)
        {
            //cout<<id<<endl;
            sum+=id;
        }
        getline(cin,s);
    }
    cout<<sum<<endl;
    return 0;
}
