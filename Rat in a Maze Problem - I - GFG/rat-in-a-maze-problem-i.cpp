// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    vector<string>res;
    void helper(vector<vector<int>>&m,int n,int i,int j,string &path){
       if(i==n-1 && j==n-1){res.push_back(path);return;}
       if(i<0 || i>=n || j<0 || j>=n)return;
       if(m[i][j]==0)return;

       
       m[i][j]=0;
       
       path.push_back('L');
       helper(m,n,i,j-1,path);
       path.pop_back();
       
       path.push_back('R');
       helper(m,n,i,j+1,path);
       path.pop_back();
       
       path.push_back('U');
       helper(m,n,i-1,j,path);
       path.pop_back();
       
       path.push_back('D');
       helper(m,n,i+1,j,path);
       path.pop_back();
       
       m[i][j]=1;
       
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        if(m[0][0]==0 || m[n-1][n-1]==0)return {};
        string path;
        helper(m,n,0,0,path);
        sort(res.begin(),res.end());
        return res;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends