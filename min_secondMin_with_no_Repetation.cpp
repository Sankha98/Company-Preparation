#include<bits/stdc++.h>
using namespace std;
vector < int > smallestAndSecondSmallest(int,int[]);
// int no_repeatition(int arr[],int n)
// {
//     int *temp = NULL;
//     temp = new int[n];
//     int j = 0;
//     for(int i = 1;i < n-1;i++)
//     {
//         if(arr[i] == arr[i-1])
//         {
//             temp[j++] = arr[i];
//         }
//     }
//     temp[j++] = arr[n - 1];
//     for(int i = 0;i < j;i++)
//     {
//         arr[i] = temp[i];
//     }
//     return j;
// }
vector < int > smallestAndSecondSmallest(int sizeOfArray,int arr[])
{
    vector < int > temp;
    int min = INT_MAX;
    int min2 = INT_MAX;
    int n;
    // n = no_repeatition(arr,sizeOfArray);
    for(int i = 0;i < sizeOfArray;i++)
    {
        if(arr[i] < min)
        {
            min2 = min;
            min = arr[i];
            //min2 = min;
            //temp = min;
        }
        else if((arr[i] < min2) && (arr[i] != min))
        {
            min2 = arr[i];
            //temp = min2;
        }
    }
    temp.push_back(min);
    if(min2 == INT_MAX)
    {
        min2 = -1; 
    }
    //temp.push_back(min);
    temp.push_back(min2);
    return temp;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0;i < n;i++)
        {
            cin >> arr[i];
        }
        vector < int > ans = smallestAndSecondSmallest(n,arr);
        cout << ans[0] << ' ' << ans[1] << endl;
    }
    return 0;
}