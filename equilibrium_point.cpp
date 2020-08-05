/*
1.Initialise prefix_sum = 0
2.get the total sum of the array as suffix_sum
3.iterate through the array an for each index
a)update suffix_sum to get the right suffix_sum
suffix_sum -= a[i]
b)if prefix_sum == suffix_sum then return current position
c)prefix_sum += a[i]
4. return -1
*/
#include <iostream>
using namespace std;

int equilibriumPoint(long long a[], int n);

int main() {

    long long t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        long long a[n];

        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        cout << equilibriumPoint(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
int equilibriumPoint(long long a[], int n)
{
    int prefix_sum = 0;
    int suffix_sum = 0;
    int position = 0;
    for (int i = 0; i < n; i++)
    {
        suffix_sum += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        suffix_sum -= a[i];
        position++;
        if(prefix_sum == suffix_sum)
        {
            return position;
        }
        prefix_sum += a[i];
    }    
    return -1;
}