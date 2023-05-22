
dshffsjfhsjf

fgg
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++)
            (senate[i] == 'R')?q1.push(i):q2.push(i);
        while(!q1.empty() && !q2.empty()){
            int r_index = q1.front(), d_index = q2.front();
            q1.pop(), q2.pop();
            (r_index < d_index)?q1.push(r_index + n):q2.push(d_index + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
    }
};



class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        left, right = 0, len(nums) - 1
        count = 0
        mod = 10 ** 9 + 7
        
        while left <= right:
            if nums[left] + nums[right] > target:
                right -= 1
            else:
                count += pow(2, right - left, mod)
                left += 1
        
        return count % mod

\



int formingMagicSquare(vector<vector<int>> s) {
    // List of all possible 3x3 magic squares
    vector<vector<vector<int>>> magicSquares = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    
    // Calculate the cost of converting s to each magic square
    vector<int> costs;
    for (auto magicSquare : magicSquares) {
        int cost = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cost += abs(s[i][j] - magicSquare[i][j]);
            }
        }
        costs.push_back(cost);
    }
    
    // Return the minimum cost
    return *min_element(costs.begin(), costs.end());
}
dshffsjfhsjf

fgg
class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> q1, q2;
        int n = senate.length();
        for(int i = 0; i<n; i++)
            (senate[i] == 'R')?q1.push(i):q2.push(i);
        while(!q1.empty() && !q2.empty()){
            int r_index = q1.front(), d_index = q2.front();
            q1.pop(), q2.pop();
            (r_index < d_index)?q1.push(r_index + n):q2.push(d_index + n);
        }
        return (q1.size() > q2.size())? "Radiant" : "Dire";
    }
};



class Solution:
    def numSubseq(self, nums: List[int], target: int) -> int:
        nums.sort()
        left, right = 0, len(nums) - 1
        count = 0
        mod = 10 ** 9 + 7
        
        while left <= right:
            if nums[left] + nums[right] > target:
                right -= 1
            else:
                count += pow(2, right - left, mod)
                left += 1
        
        return count % mod

\



int formingMagicSquare(vector<vector<int>> s) {
    // List of all possible 3x3 magic squares
    vector<vector<vector<int>>> magicSquares = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };
    
    // Calculate the cost of converting s to each magic square
    vector<int> costs;
    for (auto magicSquare : magicSquares) {
        int cost = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cost += abs(s[i][j] - magicSquare[i][j]);
            }
        }
        costs.push_back(cost);
    }
    
    // Return the minimum cost
    return *min_element(costs.begin(), costs.end());
}





class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
     {
        int n=matrix.size();
        int m=matrix[0].size();
        int l=0,r=m-1,b=n-1,top=0;
        int d=1;
        vector<int>v;
        while(l<=r && top<=b)
        {

            if(d==1)
            {
                for(int i=l;i<=r;i++)
                {
                    v.push_back(matrix[top][i]);}
                    d=2;
                    top++;
                    
                
            }
            else if(d==2)
            {
                for(int i=top;i<=b;i++ )
                {
                    v.push_back(matrix[i][r]);}
                    d=3;
                    r--;
                

            }
            else if(d==3)
            {
                for(int i=r;i>=l;i--)
                {
                    v.push_back(matrix[b][i]);}
                    d=4;
                    b--;
                
            }
            else if(d==4)
            {
                for(int i=b;i>=top;i--)
                {
                    v.push_back(matrix[i][l]);
                    
                }
                d=1;
                l++;
            }
        }

        
        return v;
     
    }
};



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>res(n,vector<int>(n));
        int top=0;int left=0;
        int right=n-1;int bottom=n-1;
        int a=1;
        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){//top
                
                res[top][i]=a;
                a++;
            }
            top++;
            for(int i=top;i<=bottom;i++){//right
                res[i][right]=a;
                a++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){//bottom in reverse
                res[bottom][i]=a;
                a++;
            }
            bottom--;
            }
            if(left<=right){
                for(int i=bottom;i>=top;i--){//left in reverse
                res[i][left]=a;
                a++;
            }
            left++;
            }
        }
        return res;
        
    }
};


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hurdleRace' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY height
 */

int hurdleRace(int k, vector<int> height) {

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string height_temp_temp;
    getline(cin, height_temp_temp);

    vector<string> height_temp = split(rtrim(height_temp_temp));

    vector<int> height(n);

    for (int i = 0; i < n; i++) {
        int height_item = stoi(height_temp[i]);

        height[i] = height_item;
    }

    int result = hurdleRace(k, height);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
  return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}



class Solution 
{
    public:
    int dp[1<<14];
    int gcd(int num1,int num2)
    {
        if(num2==0) return num1;
        return gcd(num2,num1%num2);
    }
    int dfs(vector<int>& nums,int state,int current)
    {
        if(current==0) return 0;
        if(dp[state]) return dp[state];
        int result=0,n=nums.size();
        
        vector<int> total;
		
		//remaining element
        for(int i=0;i<n;i++)
            if(state&(1<<i))
                total.push_back(i);
				
        
        for(int i=0;i<total.size();i++)
            for(int j=i+1;j<total.size();j++)
                result=max(result,gcd(nums[total[i]],nums[total[j]])*current+dfs(nums,(state&(~((1<<total[i])|(1<<total[j])))),current-1));
        
        dp[state]=result;
        return result;
    }
    int maxScore(vector<int>& nums) 
    {
        memset(dp,0,sizeof(dp));
        return dfs(nums,(1<<14)-1,nums.size()/2);
    }
};




class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *left_ptr = head, *right_ptr = head;
        for (int i = 0; i < k-1; i++) {
            right_ptr = right_ptr->next;
        }
        
        ListNode *end_ptr = right_ptr;
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }
        
        swap(end_ptr->val, left_ptr->val);
        
        return head;
    }
};





/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)return head;
        if(head!=NULL && head->next!=NULL){
            swap(head->val,head->next->val);
            swapPairs(head->next->next);
        }
        return head;
    }
    // return head;
};




/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        stack<int>s;
	    
	    
	    
        while(temp){
            s.push(temp->val);
            temp=temp->next;
        }
       int mx=0;
       while(s.size()){
           mx=max(mx,s.top()+head->val);
           head=head->next;
           s.pop();
       }
       return mx;
    }
};


class Solution {
private :
    bool bfs(int start,vector<int>& color , vector<vector<int>>& graph){

          queue<int> q;
          q.push(start);

          while(!q.empty()){

              int node = q.front();
              q.pop();

              for(auto it:graph[node]){

                  if(color[it] == -1){
                      color[it] = !color[node];
                      q.push(it);
                  }
                  else if(color[it] == color[node])
                   return false;
              }
          }

        return true;  
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

          int n = graph.size();
          vector<int> color(n,-1);

           for(int i=0;i<n;i++){
               if(!bfs(i,color,graph))
                return false;
           }

        return true;
    }
};




class Solution {
public:
void dfs(string start,string end,map<string,double>& mp,map<string,vector<string>>& graph,double& val,map<string,int>& visited,bool& found){
        visited[start]=1;
    
        if(found==true)
            return ;
        for(auto child:graph[start]){
            if(visited[child]!=1){
                // cout<<start<<" "<<child<<"\n";
                val*=mp[start+"->"+child];
                if(end==child){
                    // cout<<end<<" -- "<<child<<"\n";
                    found=true;
                    return ;
                }
                dfs(child,end,mp,graph,val,visited,found);
                if(found==true){
                    return ;
                }
                else{
                    val/=mp[start+"->"+child];
                }
            }
        }
       
        
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        map<string,double> mp;
        map<string,vector<string>> graph;
        for(int i=0;i<equations.size();i++){
            string u=equations[i][0];
            string v=equations[i][1];
            mp[u+"->"+v]=values[i];
            mp[v+"->"+u]=1/values[i];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        for(int i=0;i<queries.size();i++){
            string start=queries[i][0];
            string end=queries[i][1];
            if(graph.find(start)==graph.end()||graph.find(end)==graph.end()){
                ans.push_back(-1);
            }
            else{
                // ans.push_back(1);
                double val=1;
                map<string,int> visited;
                bool found=false;
                if(start==end){
                    found=true;
                }
                else
                dfs(start,end,mp,graph,val,visited,found);
                if(found==true)
                ans.push_back(val);
                else
                    ans.push_back(-1);
                
            }
        }
        return ans;
    }
};





class Solution {
public:
            
          //   Time Complexity - O(k * r * c)
         //  Space Complexity -  O(r * c)
        //   k is the number of cells representing the starting island
       //    r is the number of row 
      //   c is the number of column 



      const int dx[4]={-1,1,0,0};
      const int dy[4]={0,0,-1,1};
    //boundary checks
    bool  isValid(int i,int j,int r,int c){
          return (i<r && j<c && i>=0 && j>=0);
    }
 
    void changeIslandType(int i,int j,int r,int c,vector<vector<int>>& grid){

        if(i>=r || j>=c || i<0 || j<0 || grid[i][j]==0 || grid[i][j]==2)return;
        grid[i][j]=2;
        for(int x=0;x<4;++x){
            int nr=i+dx[x];
            int nc=j+dy[x];
            changeIslandType(nr,nc,r,c, grid);
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
 
        int r=grid.size();
        int c=grid[0].size();
        queue<pair<int,int>>q;
 
        int change=0;
        bool check=false;
        //change the islands
        for(int i=0;i<r;++i){

            for(int j=0;j<c;++j){

               if(grid[i][j]){
                   changeIslandType(i,j,r,c,grid);
                   check=true;
                   break;
               }
            }

            if(check)
            break;
        }
 
        //get the new islands in queue
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
               if(grid[i][j]==2){
                q.push({i,j});       
               }
            }
        }
 
 
        while(!q.empty()){
            change++;
         int sz=q.size();

            while(sz--){
               auto node=q.front();
               q.pop();
                //4 directions
               for(int x=0;x<4;++x){
                   int nr=node.first+dx[x];
                   int nc=node.second+dy[x];
 
                   if(isValid(nr,nc,r,c) ){
                       
                         if( grid[nr][nc]==0){
                             grid[nr][nc]=2;
                             q.push({nr,nc});
                         }

                         if(grid[nr][nc]==1)
                         return change-1; 
                   }  
               }     
            }
        }
 
       return 0; 
 
    }
};



Vclass Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        unordered_map<int,int>mp;
        vector<int> Res;
       
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> m;
        for( auto i : mp)
        {
            m.push(make_pair( i.second, i.first));
        }
        
        for( int i =0;i<k ; i++)
        {
            Res.push_back( m.top().second);
            m.pop();
        }
      
        return Res;
    }
};



