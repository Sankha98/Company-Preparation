#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        ll size = sqrt(n) + 1;
        //cout << size;
        ll count = 0;
        for (ll i = 0; i < size - 1; i++)
        {
            for (ll j = i + 1; j < size; j++)
            {
                /* code */
                if((i * i) + (j * j) == n)
                {
                    count++;
                }
            }           
        }
        if(n == 0)
        {
            count = 1;
        }
        cout << count << endl;
    }
    return 0;
}
