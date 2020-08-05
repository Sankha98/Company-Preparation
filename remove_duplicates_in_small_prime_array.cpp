#include<bits/stdc++.h>
using namespace std;
vector<int> removeDuplicate(vector<int>& arr, int n)
{
    // Loop invariant: Elements from vect[0]
    // to vect[res_ind-1] are unique.
    int p = 1;
    int j;
    for (int i = 1; i < n; i++)
    {
        for (j = 0; j < i; j++)
        {
            if(arr[i] == arr[j])
            {
                break;
            }
        }
        if(i == j)
        {
            arr[p] = arr[i];
            p++;
        }
    }
    arr.erase(arr.begin() + p,arr.end());
    return arr;

    /*
    // Sort the vector
    sort(arr.begin(), arr.end());

    // unique() removes adjacent duplicates.
    // unique function puts all unique elements at
    // the beginning and returns iterator pointing
    // to the first element after unique element.
    // Erase function removes elements between two
    // given iterators
    arr.erase(unique(arr.begin(), arr.end()),arr.end());   
    return arr;
   */
  /*
    sort(arr.begin(),arr.end());
    set<int> s(arr.begin(),arr.end());
    arr.assign(s.begin(),s.end());
    return arr;
    */
/*

    This approach only works when the product of all distinct primes is fewer than 10^18 and all the numbers in the array should be prime. The property of primes of having no divisors except 1 or that number itself is used to arrive at the solution. As the array elements are removed from the array, keep a value(product) which will contain the product of all distinct primes found previously in the array, so that if the element divides the product then it can be surely proved that the element has previously occurred in the array and hence the number will be rejected.

Algorithm:

Initially keep a variable (p = 1).
Traverse the array from start to end.
While traversing, check whether p is divisible by the i-th element. If true, then erase that element.
Else keep that element and update the product by multiplying that element with the product (p = p * arr[i])

   int val = arr[0];
   int p = 1;
   for (int i = 1; i < n; i++)
   {
       if(val % arr[i] != 0)
       {
           arr[p] = arr[i];
           p++;
           val *= arr[i];
       }
        arr.erase(arr.begin()+p,arr.end());
   }
   return arr;
   */
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        vector<int>result = removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}