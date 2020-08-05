// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find the maximum difference of j-i
// arr[]: input array
// n: size of array

int maxIndexDiff(int arr[], int n) 
{ 
    
    int ans = 0;
    int minm[n];
    int maxm[n];
    minm[0] = arr[0];
    maxm[n - 1] = arr[n - 1];
    for(int i = 1; i < n; i++)
    {
        minm[i] = min(minm[i - 1],  arr[i]);
    }   
    for(int i = n - 2; i >= 0; i--)
    { 
        maxm[i] = max(maxm[i+1], arr[i]);
    }

    int l=0, r=0;
    while(l < n && r < n)
    {   
    // cout<<l<<" "<<r<<endl; 
        while(maxm[r] >= arr[l] && r < n)
        {
            r++;
        }
        ans = max(ans, r - l - 1);
        
        if(minm[r] == arr[l]) 
        {
            l = r;
        }
        else 
        {
            int temp = arr[l];
            while(minm[l] == temp && l < n)
            {
                l++;
            }
        }
    }
    return ans;
}

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    cin>>T;
    while(T--){
        int num;
        cin>>num;
        int arr[num];
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        
        if(num ==1 ){
            cout<<0<<endl;
            continue;
        }
        cout<<maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends

