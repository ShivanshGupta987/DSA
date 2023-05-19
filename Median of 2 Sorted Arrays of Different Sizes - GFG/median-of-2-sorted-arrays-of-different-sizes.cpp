//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& arr1, vector<int>& arr2)
    {
        // Your code goes here
        int n1=arr1.size(), n2 = arr2.size();
        if(n2<n1) return MedianOfArrays(arr2,arr1);
        int low=0, high=n1;
        
        int k = (n1+n2+1)/2 ; // ind of median in the array(first median
        // in case of even len combined array)
        while(low<=high){
            int mid = (low+high)/2;
            int cut1 = mid; // cur pos in arr1
            int cut2 = k-cut1; // cut pos in arr2
            
            int left1 = cut1==0? INT_MIN : arr1[cut1-1];
            int left2 = cut2==0? INT_MIN : arr2[cut2-1];
            int right1 = cut1==n1? INT_MAX : arr1[cut1];
            int right2 = cut2==n2? INT_MAX : arr2[cut2];
            
            
            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2==0){
                    return (max(left1,left2)+min(right1,right2))/2.0;
                }
                else return max(left1,left2);
            }
            else if(left1>right2){
                high = mid-1;
            }
            else  low = mid+1;
        }
        return 0.0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends