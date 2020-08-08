// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 
void frequencycount(vector<int>& arr,int n);

 // } Driver Code Ends


void frequencycount(vector<int>& arr,int n)
{ 
    for(int j = 0;j < n;j++)
    {
        arr[j] = arr[j] - 1;
    }
    for (int i = 0; i < n; i++)
    {
        arr[arr[i] % n] = arr[arr[i] % n] + n;
    }
    for(int i = 0;i < n;i++)
    {
        arr[i] = arr[i] / n;
    }
}


// { Driver Code Starts.

int main() 
{ 
	long long t;
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n; 
	    
	    vector<int> arr(n,0);
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i]; 
	    }

		frequencycount(arr,n); 
	    /*
        (for (int i =0; i<n; i++) 
			cout<<arr[i]<<" ";
	    cout<<endl;
        */
	}	
	return 0; 
}




  // } Driver Code Ends