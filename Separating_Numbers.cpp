/*
 This is one of those problems that can be more easily solved in reverse:

What our tree will look like after all queries ? just all disconnected nodes
Now for each query (starting from last one) we can connect nodes u and v if they share same color
This can be done using DSU (a.k.a. Union Find) data structure, for each node u we save parent of the node and the size of the set containing the node (initially parent is -1 or null and size is 1)
Then joining 2 nodes we can check how much paths will get destroyed simply by multiplying the sizes of trees where u and v belong
Total complexity: O(n * log n)*

(*assumes DSU uses only 1 optimization (path compression / size compression), if using both it will be faster, if using none O(n^2))
 */
 #include<bits/stdc++.h>
 using namespace std;
#define ll long long int
vector<int> v1[300002];
int vis[300002] =
 { 0 };
 int xx[100002];
int yy[100002];
int arr[300002] =
{ 0 };

void dfs(int par)
{
 vis[par] = 1;

xx[arr[par]]++;
for (auto child : v1[par])
{
    if (vis[child] == 0)
    {
        dfs(child);
    }
}
}

 void dfs1(int par)
{
vis[par] = 1;

yy[arr[par]]++;
for (auto child : v1[par])
{
    if (vis[child] == 0)
    {
        dfs1(child);
    }
}
 }

 int main()
{

ios_base::sync_with_stdio
 (false);
cin.tie(NULL);
int n, i, a, b, x;
cin >> n;
int a1[n + 1];
int b1[n + 1];

for (i = 1; i <= n - 1; 
i++)
{
    cin >> a >> b;
    a1[i] = a;
    b1[i] = b;
    v1[a].push_back(b);
    v1[b].push_back(a);
}

for (i = 1; i <= n; i++)
{
    cin >> arr[i];
}

int y, z, k;
//vector<int>::iterator it;
//vector<int>::iterator it1;

for (i = 1; i <= n - 1; 
 i++)
{
    cin >> z;
    x = a1[z];
    y = b1[z];
    //  cout << "hi" << '\n';

    v1[x].erase(remove(v1[x].begin(), v1[x].end(), y), v1[x].end());
    v1[y].erase(remove(v1[y].begin(), v1[y].end(), x), v1[y].end());

    //it = remove(v1[x].begin(), v1[x].end(), y);
    //it1 = remove(v1[y].begin(), v1[y].end(), x);

    dfs(x);
    dfs1(y);
    long long int sum = 0;

    for (k = 1; k <= n; k++)
    {
        if (xx[k] > 0 && yy[k] > 0)
        {
            sum = sum + xx[k] * yy[k];
        }
    }
    cout << sum << '\n';
    memset(xx, 0, sizeof(xx));
    memset(yy, 0, sizeof(yy));
    memset(vis, 0, sizeof(vis));

}

}