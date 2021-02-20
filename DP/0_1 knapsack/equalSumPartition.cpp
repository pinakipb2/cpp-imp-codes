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

bool subsetSum(int arr[],int n,int sum)
{
    bool dp[n+1][sum+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
            {
                dp[i][j] = false;
            }
            if(j==0)
            {
                dp[i][j] = true;
            }
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1] <= j)
            {
                dp[i][j] = ((dp[i-1][j-arr[i-1]]) || (dp[i-1][j]));
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool equalSumPartition(int arr[],int n)
{
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
        return false;
    else
    {
        return subsetSum(arr,n,sum/2);
    }
}

int main()
{
    clock_t begin = clock();
    pinakipb2();
    // Code begins
    
    int arr[] = {1, 5, 11, 5};
    // int arr[] = {1, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    bool ans = equalSumPartition(arr,n);
    cout<<ans<<endl;
    
    // Code ends
    // execution time
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}