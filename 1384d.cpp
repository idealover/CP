#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll temp1,temp2,temp;
char tempc;

#define forn(i,n) for(int i=0;i<int(n);i++)

#define N 1000000007
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pi pair<int,int>
#define pl pair<ll,ll>
#define int ll
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)

ll binpow(ll a, ll b)
{
    a%=N;b=b%(N-1);
    ll res=1;
    while(b>0)
    {
        if(b&1) res=res*a%N;
        a=a*a%N;
        b>>=1;
    }
    return res%N;
}

int gcd(int a,int b)
{
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
}

// struct DSU {
//     vector<int> sz;
//     vector<int> parent;
 
//     void make_set(int v) {
//         parent[v] = v;
//         sz[v] = 1;
//     }
 
//     int find_set(int v) {
//         if (v == parent[v])
//             return v;
//         return parent[v] = find_set(parent[v]);
//     }
 
//     void union_sets(int a, int b) {
//         a = find_set(a);
//         b = find_set(b);
//         if (a != b) {
//             if (sz[a] < sz[b])
//                 swap(a, b);
//             parent[b] = a;
//             sz[a] += sz[b];
//         }
//     }
 
//     DSU(int n) {
//         sz.resize(n+1);
//         parent.resize(n+1);
//         for (int i = 1; i <= n; i++) make_set(i);
//     }
// };

int val(int n)
{
    int count=0;
    while(n)
    {
        n/=2;
        count++;

    }
    return count-1;
}

signed main()
{
    // fast;
    int t; cin >> t;
    // cout << "Hi";
    while(t--)
    {
        int n; cin >> n;
        if(n==1)
        {
            cout << 0 << endl;
            continue;
        }
        if(n==2)
        {
            cout << 1 << endl << 0 << endl;
            continue;
        }
        if(n==3)
        {
            cout << 1 << endl << 1 << endl;
            continue;
        }
        cout << val(n) << endl;
        forn(i,val(n)-2) cout << (int)pow(2,i) << " ";
        if(pow(2,val(n))+pow(2,val(n)-1)<=n) cout << (int)pow(2,val(n)-2) << " " << n-((int)pow(2,val(n))+(int)pow(2,val(n)-1))+1 << endl;
        else 
        {
            int diff=n-(int)pow(2,val(n))+1;
            cout << (int)diff/2 << " " << diff%2 << endl;
        }
    }
}
