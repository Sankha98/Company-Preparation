// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the subarray with given sum k
// arr: input array
// n: size of array
void subarraySum(int arr[], int n, int sum){
    
    /* Initialize curr_sum as value of  
    first element and starting point as 0 */
    int curr_sum = arr[0], start = 0, i; 
  
    /* Add elements one by one to curr_sum and  
    if the curr_sum exceeds the sum, 
    then remove starting element */
    for (i = 1; i <= n; i++) { 
        // If curr_sum exceeds the sum, 
        // then remove the starting elements 
        while (curr_sum > sum && start < i - 1) { 
            curr_sum = curr_sum - arr[start]; 
            start++; 
        } 
  
        // If curr_sum becomes equal to sum, 
        // then return true 
        if (curr_sum == sum) { 
            cout << start + 1 << " " << i; 
            return; 
        } 
  
        // Add this element to curr_sum 
        if (i < n) 
            curr_sum = curr_sum + arr[i]; 
    } 
    cout << "-1";
}


// { Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        int arr[n];
        
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        subarraySum(arr, n, s);
        cout<<endl;
        
    }
	return 0;
}  // } Driver Code Ends