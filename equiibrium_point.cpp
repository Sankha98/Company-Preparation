/*
The idea is to get the total sum of the array first. Then Iterate through the array and keep updating the left sum which is initialized as zero. In the loop, we can get the right sum by subtracting the elements one by one. Thanks to Sambasiva for suggesting this solution and providing code for this.

1) Initialize leftsum  as 0
2) Get the total sum of the array as sum
3) Iterate through the array and for each index i, do following.
    a)  Update sum to get the right sum.  
           sum = sum - arr[i] 
       // sum is now right sum
    b) If leftsum is equal to sum, then return current index. 
       // update leftsum for next iteration.
    c) leftsum = leftsum + arr[i]
4) return -1 
// If we come out of loop without returning then
// there is no equilibrium index

*/
// { Driver Code Starts
#include <iostream>
using namespace std;

// Position this line where user code will be pasted.

int equilibriumPoint(long long a[], int n);

int main()
{

    long long t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends

// Function to find equilibrium point
// a: input array
// n: size of array
int equilibriumPoint(long long arr[], int n)
{

    // Your code here
    int right_sum = 0;
    int left_sum = 0;
    int i=-1,j=-1;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        left_sum += arr[i];
        right_sum += arr[j];
        while (left_sum < right_sum && i < j)
        {
            i++;
            left_sum += arr[i];
        }
        while (right_sum < left_sum && i < j)
        {
            j--;
            right_sum += arr[j];
        }
    }
    if (left_sum == right_sum)
    {
        return arr[i];
    }
    else
    {
        return -1;
    }
}