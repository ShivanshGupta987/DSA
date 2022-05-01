class Solution {

        // TC : O(N)
        // N -> NO. OF NODES IN THE TREE
        // SC : O(H)
        // H -> HEIGHT OF THE TREE

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
     
            vector<int>inDegree(n);
            
            for(int i=0;i<n;i++){
                    if((leftChild[i]!=-1 && inDegree[leftChild[i]]++ ==1) || 
                      (rightChild[i]!=-1 && inDegree[rightChild[i]]++ == 1 ) )
                            return false;
            }
            
            int root=-1;
            for(int i=0;i<n;i++){
                    if(inDegree[i]==0){
                            if(root!=-1) return false;
                            root=i;   
                    }
            }
            vector<bool>visited(n,false);
            
            bool res= dfs(root,leftChild,rightChild,visited);
          
            if(res){
                    for(bool v : visited)
                            if(!v)return false;
                    return true;
            }
            else return false;
    }

private:
        bool dfs(int root, vector<int>& leftChild,
                 vector<int>& rightChild, vector<bool>& visited){
                
                if(root==-1) return true;
                if(visited[root]) return false;
                visited[root]=true;
                return dfs(leftChild[root],leftChild,rightChild,visited) 
                        && dfs(rightChild[root],leftChild,rightChild,visited);
        }
        
};