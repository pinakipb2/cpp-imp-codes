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

int un_kp(int price[], int length[], int n, int max_len)
{
    int dp[n+1][max_len+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<max_len+1;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
        }
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<max_len+1;j++)
        {
            if(length[i-1] <= j)
            {
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);  // Only change is in this line
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][max_len];
}

int main()
{
    clock_t begin = clock();
    pinakipb2();
    // Code begins
    
    int price[] = { 1, 5, 8, 9, 10, 17, 17, 20 };   // mapped to value in 0/1 knapsack
    int n = sizeof(price) / sizeof(price[0]);
    int length[n];                              // mapped to weight in 0/1 knapsack
    for (int i = 0; i < n; i++)
        length[i] = i + 1;          // generating length array if not given
    int Max_len = n;        // mapped to W in 0/1 knapsack { in most of the cases max_len is equal to n }
    // Max_len = 4;        // output : 10  { max_len given explicitly }
    cout << "Maxmum obtained value  is " << un_kp(price, length, n, Max_len) << endl;
    
    // Code ends
    // execution time
    #ifndef ONLINE_JUDGE
        clock_t end = clock();
        cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
    #endif
    return 0;
}