// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

int threeSumClosest(vector<int> , int );

int main() {
    int t;
    cin >> t;
    while(t--) {
        
        int n,target;
        cin >> n >> target;
        
        vector<int> vec(n);
        
        for(int i = 0 ; i < n ; ++ i ) 
            cin >> vec[i];
        
        cout << threeSumClosest(vec, target) << "\n";
    }
}


 // } Driver Code Ends


// User function template for C++

// arr : given vector of elements
// target : given sum value

int threeSumClosest(vector<int> arr, int target) 
{
    int n = arr.size();
    int closest_sum = INT_MAX;
    // Sort the array
    sort(arr.begin(),arr.end());
    // Fix the smallest number among
    // the three integers
    for (int i = 0; i < n - 2; i++)
    {
        // Two pointers initially pointing at
        // the last and the element
        // next to the fixed element
        int l = i + 1;
        int r = n - 1;
        while(l < r)
        {
            int sum = arr[l] + arr[r] + arr[i];
            // If the sum is more closer than
            // the current closest sum
            if(abs(sum - target) <= abs(target - closest_sum))
            {
                if(abs(sum - target) == abs(target - closest_sum))
                {
                    closest_sum = max(closest_sum,sum);
                }
                else
                {
                    closest_sum = sum;
                }
            }
            if(sum < target) // If sum is lesser then target then increment the first pointer to get a larger sum
            {
                l++;
            }
            else // else sum is greater then target then decrement the second pointer to get a smaller sum
            {
                r--;
            }
        }
    }
    return closest_sum;
}
// { Driver Code Starts.
  // } Driver Code Ends