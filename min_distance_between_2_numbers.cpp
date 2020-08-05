/*
Method 1:

Approach: The task is to find the distance between two given numbers, So find the distance between any two elements using nested loops. The outer loop for selecting the first element (x) and the inner loop for traversing the array in search for the other element (y) and taking the minimum distance between them.
Algorithm:
Create a variable m = INT_MAX
Run a nested loop, the outer loop runs from start to end (loop counter i), the inner loop runs from i+1 to end (loop counter j).
If the ith element is x and jth element is y or vice versa, update m as m = min(m,j-i)
Print the value of m as minimum distance

Method 2:
// Efficient
Approach: So the basic approach is to check only consecutive pairs of x and y. For every element x or y, check the index of the previous occurrence of x or y and if the previous occurring element is not similar to current element update the minimum distance. But a question arises what if an x is preceded by another x and that is preceded by a y, then how to get the minimum distance between pairs. By analyzing closely it can be seen that every x followed by a y or vice versa can only be the closest pair (minimum distance) so ignore all other pairs.
Algorithm:
Create a variable prev=-1 and m= INT_MAX
Traverse through the array from start to end.
If the current element is x or y, prev is not equal to -1 and array[prev] is not equal to current element then update m = max(current_index – prev, m), i.e. find the distance between consecutive pairs and update m with it.
print the value of m


*/
#include<bits/stdc++.h>
using namespace std;
/* not effcient */
/*
int minDist(int arr[],int n,int x,int y)
{
    int min_dist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if( (x == arr[i] && y == arr[j] || y == arr[i] && x == arr[j]) && min_dist > abs(i-j)) 
            { 
                min_dist = abs(i-j); 
            } 
            else
            {
                min_dist = -1;
            }
            
        }
    }
    return min_dist;
}
*/




int minDist(int arr[],int n,int x,int y)
{
    int position = -1;
    int min_dist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == x || arr[i] == y)
        {
            if (position != -1 && arr[i] != arr[position])
            {
                min_dist = min(min_dist,abs(i - position));
            }
            position = i;
        }
    }
    if(min_dist == INT_MAX)
    {
        return -1;    
    }
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
        int x,y;
        cin >> x >> y;
        cout << minDist(arr,n,x,y) << endl;
    }
    return 0;
}