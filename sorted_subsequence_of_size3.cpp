/*
Approach: This can be solved in a very simple way. To find an element which has an element smaller than itself on its left side of the array, check if that element is the smallest element while traversing the array from starting index i.e., (0), and to check if there is an element greater than itself on its right side of the array check whether that element is the largest element while traversing from the end of the array i.e., (n-1). If the element is not the smallest element from 0 to that index then it has an element smaller than itself on it left side, and similarly if the element is not the largest element from that index to the last index then there is a larger element on its right side.

Algorithm
Create an auxiliary array smaller[0..n-1]. smaller[i] stores the index of a number which is smaller than arr[i] and is on left side. The array contains -1 if there is no such element.

Create another auxiliary array greater[0..n-1]. greater[i] stores the index of a number which is greater than arr[i] and is on right side of arr[i]. The array contains -1 if there is no such element.

Finally traverse both smaller[] and greater[] and find the index [i] for which both smaller[i] and greater[i] are not equal to -1.
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2, int n, int m) {

    if (m == 0) return true;
    if (n == 0) return false;

    if (v1[n - 1] == v2[m - 1]) return isSubSequence(v1, v2, n - 1, m - 1);

    return isSubSequence(v1, v2, n - 1, m);
}

vector<int> find3Numbers(vector<int>, int);

// Driver program to test above function
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        auto res = find3Numbers(a, n);

        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and
                   isSubSequence(a, res, n, res.size())) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}// } Driver Code Ends


/*The function returns a vector containing the
increasing sub-sequence of length 3 if present
else returns an empty vector */
vector<int> find3Numbers(vector<int> arr, int n) {
    // Your code here
    int max = n - 1;
    int min = 0;
    int *left = new int[n];
    int *right = new int [n];
    vector<int> res;
    left[0] = -1;
    right[n - 1] = -1;
    for (int i = 1; i < n; i++)
    {
        if(arr[i] <= arr[min])
        {
            min = i;
            left[i] = -1;
            //arr[0] = arr[i];

/*
if we use the two '//' line code then get this error
Input:
11
39 70 46 51 46 14 5 74 40 25 86

Its Correct output is:
1

And Your Code's output is:
-1

*/
        }
        else
        {
            left[i] = min;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if(arr[i] >= arr[max])
        {
            max = i;
            right[i] = -1;
            //arr[n-1] = arr[i];
        }
        else
        {
            right[i] = max;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(left[i] != -1 && right[i] != -1)
        {
            res.push_back(arr[left[i]]);
            res.push_back(arr[i]);
            res.push_back(arr[right[i]]);
            //return res;
            //cout << arr[left[i]] << " " << arr[i] << " " << arr[right[i]];
            //return;      
            break;     
        }
    }
    delete[]left;
    delete[]right;
    return res;
}