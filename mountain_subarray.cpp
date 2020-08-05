/*
Approach:The problem has multiple queries so for each query the solution should be calculated with least possible time complexity. So create two extra spaces of the length of the original array. For every element find the last index on the left side which is increasing i.e. greater than its previous element and find the element on the right side will store the first index on the right side which is decreasing i.e. greater than its next element. If these value can be calculated for every index in constant time then for every given range the answer can be given in constant time.

Algorithm:
Create two extra spaces of length n,left and right and a extra variable lastptr

Initilize left[0] = 0 and lastptr = 0

Traverse the original array from second index to the end

For every index check if it is greater than the pervious element, if yes then update the lastptr with the current index.

For every index store the lastptr in left[i]

initilize right[N-1] = N-1 and lastptr = N-1

Traverse the original array from second last index to the start

For every index check if it is greater than the next element, if yes then update the lastptr with the current index.

For every index store the lastptr in right[i]

Now process the queries

for every query l, r, if right[l] >= left[r] then print yes else no
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,int q);

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        auto v = processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}// } Driver Code Ends


vector<bool> processQueries(int a[], int n, vector<pair<int, int>> &queries,int q) 
{
    // code here
    vector<bool> res;
    int left[n], right[n];
        left[0] = 0;
        right[n-1] = n-1;
        int lastInc = 0;
        int lastDec = n-1;
        for(int i=1; i<n; i++)
        {
            if(a[i]>a[i-1])
            lastInc = i;
            
 
            left[i] = lastInc;
        }
        for(int i=n-2; i>=0; i--)
        {
            if(a[i]>a[i+1])
            lastDec = i;
            
            right[i] = lastDec;

        }
        
    for(int i=0; i<q; i++)
    {
        int l = queries[i].first;
        int r = queries[i].second;
        if(right[l]>=left[r])
        res.push_back(true);
        else
        res.push_back(false);
    }
    return res;
}