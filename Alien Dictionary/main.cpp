// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

string findOrder(string[], int, int);
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s[n];
        for (int i = 0; i < n; i++) cin >> s[i];

        string ss = findOrder(s, n, k);
        order = "";
        for (int i = 0; i < ss.size(); i++) order += ss[i];

        string temp[n];
        std::copy(s, s + n, temp);
        sort(temp, temp + n, f);

        bool f = true;
        for (int i = 0; i < n; i++)
            if (s[i] != temp[i]) f = false;

        cout << f;
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


// User function Template for C++

/*
dict : array of strings denoting the words in alien langauge
N : Size of the dictionary
K : Number of characters
*/
void dfs(vector<bool> &visited,string &s,vector<int>v[],int node)
{
    visited[node]=true;
    for(auto it:v[node])
    if(!visited[it]) dfs(visited,s,v,it);
    s.insert(s.begin(),'a'+char(node));
}
string findOrder(string dict[], int N, int K) {
    // Your code here
    vector<int> v[K];
    for(int i=0;i<N-1;i++)
    {
        for(int j=0;j<min(dict[i].size(),dict[i+1].size());j++)
            if(dict[i][j]!=dict[i+1][j])
            {
                v[dict[i][j]-'a'].push_back(dict[i+1][j]-'a');
                break;
            }
            
    }
    string s;
 vector<bool>visited(K,false);
    for(int i=0;i<K;i++)
    if(!visited[i]) dfs(visited,s,v,i);
    return s;
}
