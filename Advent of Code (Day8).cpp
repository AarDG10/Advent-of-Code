#include<iostream>
#include<vector>
#include<string>
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
    getline(cin,s);
    while(s!="AARD")
    {
        v.push_back(s);
        getline(cin,s);
    }
    map<string,string>lmap,rmap;
    string track="LRLRRRLRRRLLLRLRRLLRLRRRLRLRRRLRLRRRLRLRRRLRRRLRLLRRRLRLRLRRLRRLRLRRLRRLRRLLRRRLRRRLRRLRRLRRLRRRLLRRLRLRRLRLRRLRRLRLRRLRRLLRLRRRLRRLRRRLLRLRLRLLRLLRLLRLRRLLRRLRLRLRRLRLLRRRLLRRRLRRLLRRRLRRRLRLRRRLLRRRLRLRRRLLLRRRLRLRLRRRLRRRLRRRLRLRRLLLRRLRRRLLRLRRRLRLRLLLRRLRLRRRLRLRRRR";
    int sett=0;
    for(int i=0;i<v.size();i++)  //mapping
    {
        string a=v[i];
        string c1,c2,cmst;
        flag=0;
        for(int j=0;j<a.size();j++)
        {
            if(i>2 && j<=2 && a[j]>=65 && a[j]<=90)
            {
                cmst.push_back(a[j]);
                sett=1;
            }
            else if(a[j]==',' || (a[j]>=65 && a[j]<=90))
            {
                if(a[j]==',')
                {
                    flag=1;
                }
                if(flag && a[j]>=65 && a[j]<=90)
                {
                    c1.push_back(a[j]);
                }
                else if(!flag && a[j]>=65 && a[j]<=90)
                {
                    c2.push_back(a[j]);
                }
            }
        }
        rmap[cmst]=c1;
        lmap[cmst]=c2;
        //cout<<cmst<<" "<<lmap[cmst]<<" "<<rmap[cmst]<<endl;
    }
    //cout<<track<<endl;
    ll cnt=0;
    string::iterator it=track.begin();
    string curr="AAA";
    while(curr!="ZZZ")
    {
        if(*it=='R')
        {
            curr=rmap[curr];
        }
        else if(*it=='L')
        {
            curr=lmap[curr];
        }
        if(it==track.end()-1) it=track.begin();
        else it++;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
