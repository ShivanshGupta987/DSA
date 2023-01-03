//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
    int get_rem(string s,int m){
        int rem = 0;
        for(int i=0;s[i];i++){
            rem = (rem*10 +(s[i]-'0'))%m;
        }
        return rem;
    }
public:
    string stringPartition(string s, int a, int b){
        // code here 
        int n = s.size();
        for(int len=1;len<n;len++){
            string x = s.substr(0,len), y = s.substr(len,n-len);
            if(!get_rem(x,a) && !get_rem(y,b)){
                // cout<<len<<" ";
                return x+" "+y;
            }
        }
        return "-1";
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {   
        int a,b;
        string S;
        cin >> S >> a >> b;
        Solution ob;
        cout << ob.stringPartition(S,a,b) << endl;
    }
    return 0; 
} 
// } Driver Code Ends