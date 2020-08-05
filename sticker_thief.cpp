/*
Approach 1: Time complexity and space complexity both 0(n)
1. Create an extra space dp, DP array to store the sub-problems.
2.Tackle some basic cases, if the length of the array is 0, print 0, if the length of the array is 1, print the first element, if the length of the array is 2, print maximum of two elements.
3.Update dp[0] as array[0] and dp[1] as maximum of array[0] and array[1]
4.Traverse the array from the second element to the end of array.
5. For every index, update dp[i] as maximum of dp[i-2] + array[i] and dp[i-1], this step defines the two cases, if an element is selected then the previous element cannot be selected and if an element is not selected then the previous element can be selected.
6. Print the value dp[n-1]


*/ 
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


 // } Driver Code Ends


// Function to return maximum of sum without adjacent elements
ll FindMaxSum(ll arr[], ll n)
{
    if(n == 0)
    {
        return 0;
    }
    ll value;
    value = arr[0];
    if(n == 1)
    {
        return value;
    }
    ll value1 = max(arr[0],arr[1]);
    if(n == 2)
    {
        return value1;
    }
    ll result;
    for (int i = 2; i < n; i++)
    {
        result = max(arr[i] + value,value1);
        value = value1;
        value1 = result;
    }
    return result;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
		for(ll i=0;i<n;++i)
			cin>>a[i];
		cout<<FindMaxSum(a,n)<<endl;
	}
	return 0;
}