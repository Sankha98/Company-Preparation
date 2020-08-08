// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std;
vector<int> SortBinaryArray(vector<int> binArray);


 // } Driver Code Ends


//User function template for C++

// binArray is an array that consists only 0s and 1s
// return sorted binary array 
vector<int> SortBinaryArray(vector<int> binArray)
{
    // Your code goes here
    int n = binArray.size();
    vector<int>temp;
    int count = 0;
    //int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(binArray[i] == 0)
        {
            count++;
            //temp.push_back(binArray[i]);
        }
    }
    for (int i = 0; i < count; i++)
    {
        temp.push_back(0);
    }
    for (int i = count; i < n; i++)
    {
        temp.push_back(1);
    }
    return temp;
}


// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int> binArray(n);
	    
	    for(int i = 0; i  < n; i++)
	      cin>>binArray[i];
	      
	  	vector<int> result = SortBinaryArray(binArray);
	  	for(int i=0; i<n; i++)
	  	    cout<<result[i]<<" ";
	      
	    cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends