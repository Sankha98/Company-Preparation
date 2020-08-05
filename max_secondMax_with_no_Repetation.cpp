/*
Algorithm:
1) Initialize two variables first and second to INT_MIN as
   first = second = INT_MIN
2) Start traversing the array,
   a) If the current element in array say arr[i] is greater
      than first. Then update first and second as,
      second = first
      first = arr[i]
   b) If the current element is in between first and second,
      then update second to store the value of current variable as
      second = arr[i]
3) Return the value stored in second.
*/

#include<bits/stdc++.h>
using namespace std;
vector < int > largestAndSecondLargest(int,int[]);
// int no_repeatition(int arr[],int n)
// {
//     int *temp = NULL;
//     temp = new int[n];
//     int j = 0;
//     for(int i = 1;i < n-1;i++)
//     {
//         if(arr[i] == arr[i-1])
//         {
//             temp[j++] = arr[i];
//         }
//     }
//     temp[j++] = arr[n - 1];
//     for(int i = 0;i < j;i++)
//     {
//         arr[i] = temp[i];
//     }
//     return j;
// }
vector < int > largestAndSecondLargest(int sizeOfArray,int arr[])
{
    vector < int > temp;
    int max = INT_MIN;
    int max2 = INT_MIN;
    int n;
    // n = no_repeatition(arr,sizeOfArray);
    for(int i = 0;i < sizeOfArray;i++)
    {
        if(arr[i] > max)
        {
            max2 = max;
            max = arr[i];
            //max2 = max;
            //temp = max;
        }
        else if((arr[i] > max2) && (arr[i] != max))
        {
            max2 = arr[i];
            //temp = max2;
        }
    }
    temp.push_back(max);
    if(max2 == INT_MIN)
    {
        max2 = -1; 
    }
    //temp.push_back(max);
    temp.push_back(max2);
    return temp;
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
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        vector < int > ans = largestAndSecondLargest(n,arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }
    return 0;
}