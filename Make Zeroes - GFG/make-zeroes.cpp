//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void MakeZeros(vector<vector<int> >& matrix) {
        // Code here
        int m = matrix.size(), n = matrix[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]>0)continue;
                int sum = 0;
                if(i>0) sum += max(0,matrix[i-1][j]);
                if(i+1<m) sum += max(0,matrix[i+1][j]);
                if(j>0) sum += max(0,matrix[i][j-1]);
                if(j+1<n) sum += max(0,matrix[i][j+1]);
                matrix[i][j] = -sum;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<0){
                    if(i>0) matrix[i-1][j] = 0;
                    if(j>0) matrix[i][j-1] = 0;
                    if(i+1<m) matrix[i+1][j] = min(0,matrix[i+1][j]);
                    if(j+1<n) matrix[i][j+1] = min(0,matrix[i][j+1]);
                    matrix[i][j] = -matrix[i][j];
                }
            }
        }
        
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		ob.MakeZeros(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cout << matrix[i][j] <<" ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends