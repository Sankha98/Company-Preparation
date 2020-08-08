// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
int NumberofElementsInIntersection(int a[], int b[], int n, int m);


// } Driver Code Ends


//User function template for C++

// Given two arrays A and B and their sizes N and M respectively 
int NumberofElementsInIntersection(int a[], int b[], int n, int m)
{
    int i;
    vector <int> v;
    map <int, int> mp;
    int x = 0;
    for (i = 0;i < n; i++)
    {
        mp[a[i]] = 1;
    }
    for (i = 0; i < m; i++)
    {
        if (mp[b[i]] == 1)
        {
            v.push_back(b[i]);
            mp[b[i]] = 0;
        }
    }
    for(int j = 0;j < v.size();j++)
    {
        x++;
    }
    return x;
}

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        int a[n], b[m];
        for (int i=0; i<n; i++)
            cin>>a[i];

        for (int i=0; i<m; i++)
            cin>>b[i];

        cout << NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}  // } Driver Code Ends