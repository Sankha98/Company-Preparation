// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find circular subarray with maximum sum
// arr: input array
// num: size of array
int circularSubarraySum(int arr[], int num)
{
    int max_sum = INT_MIN;
    int min_sum = INT_MAX;
    int array_sum = 0;
    int temp_maxSum = 0;
    int temp_minSum = 0;
    for (int i = 0; i < num; i++)
    {
        array_sum += arr[i];
        //temp_maxSum actually contain all the positive elements sum
        temp_maxSum += arr[i];
        //checking if max_sum is smaller or larger than temp_maxSum
        max_sum = (max_sum < temp_maxSum) ? temp_maxSum : max_sum;
        temp_maxSum = temp_maxSum < 0 ? 0 : temp_maxSum;
        temp_minSum += arr[i];
        //contain negative elements sum
        min_sum = (min_sum > temp_minSum) ? temp_minSum : min_sum;
        //temp_minSum is checking greater than 0 or not
        temp_minSum = temp_minSum > 0 ? 0 : temp_minSum;
    }
    if(array_sum == min_sum)
    {
        return max_sum;
    }
    else
    {
        return max(max_sum,(array_sum - min_sum));
    }
}

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num;
	    cin>>num;
	    int arr[num];
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	    
	    
	    cout << circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends