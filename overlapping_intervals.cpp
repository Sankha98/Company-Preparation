// { Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> , int );

// User code will be pasted here

int main()
{
    
    int t;
    cin>>t;
    while(t--)
    {
        vector<pair<int,int> > arr,res;
        int n,x,y;
        cin>>n;

        for(int i=0;i<n;i++)
        {
            cin>>x>>y;
            arr.push_back(make_pair(x,y));
        }
        
        res = overlappedInterval(arr,n);
        
        
        for(int i=0;i<res.size();i++)
            cout << res[i].first << " " << res[i].second << " " ;
            
        cout<<endl;
    }
}
// } Driver Code Ends


//User function template for C++

vector<pair<int,int>> overlappedInterval(vector<pair<int,int>> vec, int n) {
    //code here
    //pair<int,int> p[n] ; 
    //for(auto &i : p) cin >> i.first >> i.second ;
    sort(vec.begin(),vec.end());
    vector<pair<int,int>> ans;
    ans.push_back(vec[0]) ;
    for(int i = 1 ; i < n ; i++)
    {
        if(ans.back().second >= vec[i].first)
        {
            ans.back().second = max(vec[i].second,ans.back().second);
        } 
        else
        {   
            ans.push_back(vec[i]);
        }
    }
    return ans;
}