class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indeg(numCourses);
        vector<vector<int>>adj(numCourses);

        for(auto prereq : prerequisites){
            int u = prereq[0], v = prereq[1];
            adj[u].push_back(v);
            indeg[v]++;
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }

        int cnt = 0;
        while(!q.empty()){
            cnt++;
            int course = q.front();
            q.pop();
            for(auto child_course: adj[course]){
                if(--indeg[child_course]==0) q.push(child_course);
            }
        }
        if(cnt==numCourses)  return true;
        else return false;
    }
};