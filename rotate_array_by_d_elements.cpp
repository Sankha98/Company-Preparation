/*
https://www.geeksforgeeks.org/array-rotation/
*/


#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return (gcd(b, a % b));
}

int rotateArr(int arr[], int d, int n)
{
    d = d % n;
    int size = gcd(d, n);
    for (int i = 0; i < size; i++)
    {
        /* code */
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
        while (1)
        {
            int k = j + d;
            if (k >= n)
            {
                k = k - n;
            }
            if (k == i)
            {
                break;
            }
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int d, n;
        cin >> n >> d;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        rotateArr(arr, d, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}