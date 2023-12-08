#include<iostream>
#include<vector>
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
    getline(cin,s);
    while(s!="AARD")
    {
        v.push_back(s);
        getline(cin,s);
    }
    int vecsize=v.size()-1;
    //vector<vector<char>>tes;
    for(int i=0;i<v.size();i++)
    {
        string a=v[i];
        int strize=a.size()-1;
        k=0,flag=0;
        for(int j=0;j<a.size();j++)
        {
            if(a[j]>=48 && a[j]<=57)
            {
                if(j-1>=0 && a[j-1]!='.' && (a[j-1]<48 || a[j-1]>57))  //left
                {
                    flag=1;
                }
                if(i-1>=0 && v[i-1][j]!='.' && (v[i-1][j]<48 || v[i-1][j]>57))  //top
                {
                    flag=1;
                }
                if(i+1<=vecsize && v[i+1][j]!='.' && (v[i+1][j]<48 || v[i+1][j]>57))  //bottom
                {
                    flag=1;
                }
                if(i-1>=0 && j-1>=0 && v[i-1][j-1]!='.' && (v[i-1][j-1]<48 || v[i-1][j-1]>57))  //top-left
                {
                    flag=1;
                }
                if(i-1>=0 && j+1<=strize && v[i-1][j+1]!='.' && (v[i-1][j+1]<48 || v[i-1][j+1]>57))  //top-right
                {
                    flag=1;
                }
                if(i+1<=vecsize && j+1<=strize && v[i+1][j+1]!='.' && (v[i+1][j+1]<48 || v[i+1][j+1]>57)) //bottom-right
                {
                    flag=1;
                }
                if(i+1<=vecsize && j-1>=0 && v[i+1][j-1]!='.' && (v[i+1][j-1]<48 || v[i+1][j-1]>57))  //bottom-left
                {
                    flag=1;
                }
                if(j+1<=strize && a[j+1]!='.' && (a[j+1]<48 || a[j+1]>57))
                {
                    flag=1;
                }
                if(j+1==a.size())
                {
                    if(flag)
                    {
                        k+=(a[j]-48);
                        //cout<<k<<endl;
                        sum+=k;
                        flag=0;
                    }
                }
                else
                {
                    if(j+1<=strize && a[j+1]>=48 && a[j+1]<=57)  //next digit
                    {
                        if(j+2<=strize && a[j+2]>=48 && a[j+2]<=57)
                        {
                            k+=100*(a[j]-48);
                        }
                        else
                        {
                            k+=10*(a[j]-48);
                        }
                    }
                    else
                    {
                        k+=(a[j]-48);
                        if(flag)
                        {
                            sum+=k;
                            flag=0;
                        }
                        k=0;
                    }
                }
            }
            else
            {
                if(flag)
                {
                    //cout<<k<<endl;
                    sum+=k;
                }
                k=0;
                flag=0;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
