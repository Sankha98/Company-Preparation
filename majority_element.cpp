// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// Function to find majority element in the array
// a: input array
// size: size of input array
int FindCandidate(int arr[],int n)
{
    int index = 0;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if(arr[index] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count == 0)
        {
            index = i;
            count = 1;
        }
    }
    return arr[index];
}
bool Solve(int arr[],int size,int k)
{
    int count = 0;
    for (int i = 0; i < size; i++)  
    {
        if(arr[i] == k)
        {
            count++;
        }
        
    }
    if(count > size / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int majorityElement(int a[], int size)
{
    /*
    Time Complexity and space Complexity: 0(n) 
    int count = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[a[i]]++;
    }
    int result = -1;
    for(auto it : mp)
    {
        if(count < it.second)
        {
            result = it.second;
            count = it.second;
        }
    }
    return result;
    */
   int candidate = FindCandidate(a,size);
   if(Solve(a,size,candidate))
   {
       return candidate;
   }
   else
   {
       return -1;
   }
}

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends