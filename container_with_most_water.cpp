/*

Algorithm:
1.Keep two index, first = 0 and last = n-1 and a value max_area that stores the maximum area.
2.Run a loop until first is less than the last.
3.Update the max_area with maximum of max_area and min(array[first] , array[last])*(last-first)
4.if the value at array[first] is greater tha array[last] then update last as last - 1 else update first as first + 1
5.Print the maximum area.
*/

#include<iostream>
using namespace std;
int maxArea(int A[], int len);

 // } Driver Code Ends


//User function template for C++

long long maxArea(long long A[], int len)
{
    // Your code goes here
    long long left = 0;
    long long right = len - 1;
    long long maxArea = 0;
    while(left < right)
    {
        maxArea = max(maxArea,(min(A[left], A[right]) * (right - left)));
        if(A[left] > A[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return maxArea;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends