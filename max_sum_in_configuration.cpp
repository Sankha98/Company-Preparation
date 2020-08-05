/*
Method1: 0(n2)
1.Rotate the array for all values from 0 to n.
2.Caluclate the sum for each rotations.
3.Check if the maximum sum is greater than the current sum then update the maximum sum.

int result = INT_MIN;
    //int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = 0;j < n;j++)
        {
            int index = (i + j) % n;
            sum += j * arr[index];
        }
        result = max(result,sum);
    }
    return result;
*/
/*

Approach: Let's assume the case of a sorted array. As we know for an array the maximum sum will be when the array is sorted in ascending order. In case of a sorted rotated array, we can rotate the array to make it in ascending order. So, in this case, the pivot element is needed to be found following which the maximum sum can be calculated.

Algorithm:
Find the pivot of the array: if arr[i] > arr[(i+1)%n] then it is the pivot element. (i+1)%n is used to check for the last and first element.
After getting pivot the sum can be calculated by finding the difference with the pivot which will be the multiplier and multiply it with the current element while calculating the sum

// function to find pivot 
int findPivot(int arr[], int n) 
{ 
    int i; 
    for(i = 0; i < n; i++) 
    { 
        if(arr[i] > arr[(i + 1) % n]) 
            return i; 
    } 
} 

// function definition 
int maxSum(int arr[], int n) 
{ 
    int sum = 0; 
    int i; 
    int pivot = findPivot(arr, n); 

    // difference in pivot and index of 
    // last element of array 
    int diff = n - 1 - pivot; 
    for(i = 0; i < n; i++) 
    { 
        sum = sum + ((i + diff) % n) * arr[i]; 
    } 
    return sum; 
}

*/

/*
Method2:(o(n))
Approach: The basic approach is to calculate the sum of new rotation from the previous rotations. This brings up a similarity where only the multipliers of first and last element change drastically and the multiplier of every other element increases or decreases by 1. So in this way, the sum of next rotation can be calculated from the sum of present rotation.

Algorithm: The idea is to compute the value of a rotation using values of previous rotation. When an array is rotated by one, following changes happen in sum of i*arr[i].
Multiplier of arr[i-1] changes from 0 to n-1, i.e., arr[i-1] * (n-1) is added to current value.
Multipliers of other terms is decremented by 1. i.e., (cum_sum - arr[i-1]) is subtracted from current value where cum_sum is sum of all numbers.
*/
#include<bits/stdc++.h>
using namespace std;
int max_sum(int arr[],int n)
{
    int value = 0;
    int sum = 0;
    int result;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        value += i *arr[i];
    }
    result = value;
    for (int i = 1; i < n; i++)
    {
        int next_value = value - (sum - arr[i - 1]) + arr[i - 1] * (n - 1);
        value = next_value;
        result = max(result,next_value);
    }
    //result = max(result,next_value);
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << max_sum(arr,n) << endl;
    }
    return 0;
}