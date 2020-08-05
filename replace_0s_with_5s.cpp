/*
Replace all ‘0’ with ‘5’ in an input Integer
Here all the 0s are replaced by 5.
i/p: 1020 -> o/p: 1525 = 1020 + 505,can be written as 1020 + 5 * 10 ^ 2 + 5 * 10 ^ 0
so solution will be if a 0 digit encountered, find the place value of that digit and mutiply with 5 and find the sum for all 0s in the number
add that sum to the input number to find the output number
Algorithm:

Create a variable sum = 0 to store the sum, place = 1 to store the place value of current digit and create a copy of input variable
If the number is zero return 5
Iterate the next step while the input variable is greater than 0
Extract the last digit (n%10) and if the digit is zero, then update sum = sum + place*5, remove the last digit from the numbern = n/10 and update place = place * 10
Return the sum.
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
// #define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
 
void c_p_c()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
 
int convertFive(int n)
{
    int sum = 0;
    int count = 1;
    int number = n;
    if(n == 0)
    {
        sum += (5 * count);
    }
    while(n > 0)
    {
        if(n % 10 == 0)
        {
            sum += (5 * count); 
        }
        n = n / 10;
        count = count * 10;
    }
    return sum;
} 
int main()
{
    c_p_c();
    int result;
    w(t)
    {
        int n;
        cin >> n;
        // int result = 0;
        result = n + convertFive(n);
        cout << result << endl;
    }
    // cout << result << endl;
    return 0;
}