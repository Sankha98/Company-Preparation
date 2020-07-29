#include <bits/stdc++.h>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int countPairs(vector<int> numbers, int k) 
{
     if(k < 0)
     { 
        return 0;
     }
    unordered_map <int,int> mp;
    int len = numbers.size();
    int count = 0;
    for(int i = 0;i < len; ++i)
    {
        if(mp.count(numbers[i]) > 0)
        {
            mp[numbers[i]] += 1;
        }
        else
        {
            mp[numbers[i]] = 1;
        }
    }
    for(int i = 0;i < len; ++i)
    {
        if(k == 0)
        {
            if(mp.count(numbers[i]) > 0 && mp[numbers[i]] > 1)
            {
                count++;
                mp[numbers[i]] = 0;
            }
        }
        else
        {
            if(mp.count(numbers[i] - k) > 0 && mp[numbers[i]] > 0)
            {
                count++;
                mp[numbers[i]] = 0;
            }
        }
    }
    return count;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string numbers_count_temp;
    getline(cin, numbers_count_temp);

    int numbers_count = stoi(ltrim(rtrim(numbers_count_temp)));

    vector<int> numbers(numbers_count);

    for (int i = 0; i < numbers_count; i++) {
        string numbers_item_temp;
        getline(cin, numbers_item_temp);

        int numbers_item = stoi(ltrim(rtrim(numbers_item_temp)));

        numbers[i] = numbers_item;
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    int result = countPairs(numbers, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}