#include <bits/stdc++.h>
//testing stuff
using namespace std;
typedef long long ll;
int temp1,temp2;
char temp;
#define N 998244353
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pi pair<int,int>
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,pre=0; cin >> n;
    ll coins=0;
    priority_queue < pair< int,int > , vector <pi>, greater <pi>> pq;
    for(int i=0;i<n-2;i++)
    {
        // cout << "Hi" << endl;
        cin >> temp >> temp1;
        if(temp=='d') 
        {
            coins+=temp1;
            pq.push(mp(temp1,i));
            pre++;
        }
        else if(temp=='p')
        {
            while(pre>=temp1)
            {
                pair<int,int> p=pq.top();
                coins-=p.f;
                pq.pop();
                pre--;
            }
        }
    }
    cin >> temp >> temp1;
    vector <int> v;
    if(temp1>pq.size()) cout << -1 << endl;
    else
    {
        cout << coins << endl << pq.size() << endl;
        int l=pq.size();
        while(!pq.empty())
        {
            pair <int,int> p=pq.top();
            v.pb(p.s);
            pq.pop();
        }
        sort(v.begin(),v.end());
        for(int i=0;i<l;i++) cout << v[i]+2 << " ";
        cout << endl;
    }
}
