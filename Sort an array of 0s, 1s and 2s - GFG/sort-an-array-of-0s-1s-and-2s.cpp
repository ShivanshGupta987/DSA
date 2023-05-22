//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int nums[], int n)
    {
        // code here 
        int i=0,j=0;
        for(int k=0;k<n;k++){
            if(nums[k]==0){
                swap(nums[j],nums[k]);
                swap(nums[i],nums[j]);
                i++;j++;
            }
            else if(nums[k]==1){
                swap(nums[j],nums[k]);
                j++;
            }
        }
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends