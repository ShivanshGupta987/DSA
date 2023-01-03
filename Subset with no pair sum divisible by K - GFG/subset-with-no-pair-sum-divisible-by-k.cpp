//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int subsetPairNotDivisibleByK(int arr[], int N, int K) ;

//  Driver code to test above methods
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int a[n+5];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << subsetPairNotDivisibleByK(a, n, k) << "\n";
    }
    return 0;
}
// } Driver Code Ends


int subsetPairNotDivisibleByK(int arr[], int n, int k) 
{
    vector<int>cnt(k);
    for(int i=0;i<n;i++){
        cnt[arr[i]%k]++;
    }
    int ans=(cnt[0]>=1);
    for(int i=1;i<=k/2;i++){
        if(i==k/2 && k%2==0){
            if(cnt[k/2])ans++;
            continue;
        }
        ans+=max(cnt[k-i],cnt[i]);
    }
    
    return ans;
}