// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


//arr1,arr2 : the arrays
// n, m: size of arrays
vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    //Your code here
    //return vector with correct order of elements
    int i = 0;
    int j = 0;
    int prev;
    vector<int> v;
    while (i < n && j < m)
    {
        if(arr1[i] < arr2[j])
        {
            prev = arr1[i];
            v.push_back(arr1[i]);
            i++;
            while (arr1[i] == prev)
            {
                i++;
            }
        }
        else if(arr1[i] > arr2[j])
        {
            prev = arr2[j];
            v.push_back(arr2[j]);
            j++;
            while (arr2[j] == prev)
            {
                j++;
            }
        }
        else
        {
            prev = arr2[j];
            v.push_back(arr2[j]);
            j++;
            i++;
            while (arr1[i] == prev)
            {
                i++;
            }
            while (arr2[j] == prev)
            {
                j++;
            }
        }
    }
    while (i < n)
    {
        prev = arr1[i];
        v.push_back(arr1[i]);
        i++;
        while (arr1[i] == prev)
        {
            i++;
        }
    }
    while (j < m)
    {
        prev = arr2[j];
        v.push_back(arr2[j]);
        j++;
        while (arr2[j] == prev)
        {
            j++;
        }
    }
    return v;
}

// { Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--){
	    
	    
	    
	    int N, M;
	    cin >>N >> M;
	    
	    int arr1[N];
	    int arr2[M];
	    
	    for(int i = 0;i<N;i++){
	        cin >> arr1[i];
	    }
	    
	    for(int i = 0;i<M;i++){
	        cin >> arr2[i];
	    }
	    
	    vector<int> ans = findUnion(arr1,arr2, N, M);
	    for(int i: ans)cout<<i<<' ';
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends