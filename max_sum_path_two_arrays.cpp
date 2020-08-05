#include<bits/stdc++.h>
using namespace std;

int max_path_sum(int arr[], int arr1[], int n, int m)
{
    int sum1 = 0;
    int sum2 = 0;
    int result = 0;
    // initialize indexes for arr[] and arr1[]
    int i = 0;
    int j = 0;
    // vector < int > temp;
    // Below 3 loops are similar to merge in merge sort
    while(i < n && j < m)
    {
        // Add elements of arr[] to sum1
        if(arr[i] < arr1[j])
        {
            sum1 += arr[i];
            i++;
        }
        // Add elements of arr1[] to sum1
        else if(arr[i] > arr1[j])
        {
            sum2 += arr1[j];
            j++;
        }
        // we reached a common point
        else
        {
            // Take the maximum of two sums and add to result
            result += max(sum2,sum1);
            sum1 = 0;
            sum2 = 0;
            // Keep updating result while there are more common
            // elements
            result += arr[i];
            i++;
            j++;
        }
    }
    // Add remaining elements of arr[]
    while (i < n)
    {
        sum1 += arr[i];
        i++;
    }
    // Add remaining elements of arr1[]
    while (j < m)
    {
        sum2 += arr1[j];
        j++;
    }
    // Add maximum of two sums of remaining elements
    result += max(sum1,sum2);
    return result;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m;
        cin >> n >> m;
        fflush(stdin);
        int arr[n],arr1[m];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr1[i];
        }
        int result = max_path_sum(arr.arr1,n,m);
        cout << result << endl;
    }
    return 0;
}