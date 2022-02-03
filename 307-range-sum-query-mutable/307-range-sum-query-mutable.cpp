#define vi vector<int>
class NumArray {
public:
     vector<int>st;
     vector<int>arr;
     int n;
    public:
      void ST(vi & arr){
          n=arr.size();
          this->arr=arr;
          
          // Height of ST
          int x=(int)ceil(log2(n));
          int max_size= 2*pow(2,x)-1;
          st.resize(max_size);
          constructST(0,n-1,0);
     }

     int constructST( int ss , int se , int si){
      if(ss==se)  return st[si]=arr[ss];
      int mid= ss+ (se-ss)/2;
      return st[si]= constructST(ss,mid,si*2+1) + constructST(mid+1,se,si*2+2);
     }

     int getSum(int qs,int qe,int ss,int se,int si){
         if(qs>se || ss>qe )return 0;

         if(qs<=ss && qe>=se)return st[si];
         int mid = ss + (se-ss)/2;

         return getSum(qs,qe,ss,mid,2*si+1) + getSum(qs,qe,mid+1,se,2*si+2);
     }
    
     
     void update(int ss, int se, int i ,int si, int diff){
         if(i<ss || i>se) return;
         st[si]+= diff;
         if(ss<se){
             int mid= ss+ (se-ss)/2;
             update(ss,mid,i,2*si+1,diff);
             update(mid+1,se,i,2*si+2,diff);
         }
     }
     void update(int i,int val){
            int diff=val-arr[i];
             arr[i]=val;
         update(0,n-1,i,0,diff);
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
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */