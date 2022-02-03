#define vi vector<int>
class NumArray {
         vector<int>st;  // segment tree
     int n;  // no. of the elements in the given array
    public:
       void ST(vi & arr){
          n=arr.size();
          
          // Height of ST
          int x=(int)ceil(log2(n));
          int max_size= 2*pow(2,x)-1;
          st.resize(max_size);
          constructST(0,n-1,0,arr);
     }

     int constructST( int ss , int se , int si, vi &arr){
      if(ss==se)  return st[si]=arr[ss];
      int mid= ss+ (se-ss)/2;
      return st[si]= constructST(ss,mid,si*2+1, arr) + constructST(mid+1,se,si*2+2,arr);
     }

     int getSum(int qs,int qe,int ss,int se,int si){
         if(qs>se || ss>qe )return 0;

         if(qs<=ss && qe>=se)return st[si];
         int mid = ss + (se-ss)/2;

         return getSum(qs,qe,ss,mid,2*si+1) + getSum(qs,qe,mid+1,se,2*si+2);
     }
     
     
    NumArray(vector<int>& nums) {
        ST(nums);
    }
    
    int sumRange(int qs, int qe) {
        return getSum(qs,qe,0,n-1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */