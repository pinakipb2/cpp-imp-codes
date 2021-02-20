//Code Written by Pinaki Bhattacharjee
#include<bits/stdc++.h>
using namespace std;

// typedef
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

// #define
#define LOCAL
#define MAX 10000
#define PI 2*acos(0.0)
#define endl "\n"
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define DEBUG(x) cerr << #x << " = " << x << endl;

// constants
const int MOD = (int) 1e9 + 7;

// debugger
#ifdef LOCAL
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
    #define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << ": " << arg1 << " | ";
    __f(comma + 1, args...);
}

// fast I-O
void pinakipb2()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int findMin(int arr[],int n)
{
    // finding the sum of the whole array
    ll sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    // creating the dp
    bool dp[n+1][sum+1];
    // generating the subset sum
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                dp[i][j] = false;
            if(j==0)
                dp[i][j] = true;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = (dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // storing into vectors the value upto sum/2 where dp is true
    vector<ll> v;
    for(int i=0;i<=sum/2;i++)
    {
        if(dp[n][i])
            v.pb(i);
    }
    ll mn = INT_MAX;
    // finding the minimum from the vector
    for(int i=0;i<v.size();i++)
    {
        mn = min(mn,sum-(2*v[i]));      // sum-(2*v[i]) is the difference between sum of partition 1 and sum of partition 2
    }
    return mn;      // returning the minimum value
}

int main()
{
    clock_t begin = clock();
    pinakipb2();
    // Code begins
    
    int arr[] = {3, 1, 4, 2, 2, 1};
    // int arr[] = {1,3,6};
    // int arr[] = {1,6,11,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    ll ans = findMin(arr,n);
    cout<<ans<<endl;
    
    // Code ends
    // execution time
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}