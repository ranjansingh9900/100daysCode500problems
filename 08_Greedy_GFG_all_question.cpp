
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



   //  the TC of the code is O(n*log(k)) for initialization and O(log(k)) for each add() operation.
   // The space complexity is O(k).

class KthLargest {
public:
     
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {

         sz = k;

        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }

       
        
    }
    
    int add(int val) {
        
       pq.push(val);
        while(pq.size()>sz){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */




class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        priority_queue<pair<int,int>> nums2_max;
        // lets push all the elements of nums2 along with idxs into priority queue to get largest elements of nums2
        for(int i=0;i<n;i++){
            nums2_max.push({nums2[i] , i});
        }
        long long curr_sum = 0 , mini = INT_MAX , ans = 0;
        priority_queue<int,vector<int>,greater<int>>temp;
        // 'temp' priority queue stores the elements of nums1 that are contibuting curr_sum
        
        // let's get the top k elements from nums2 and the minimum of those elements will be stored in 'mini'
        // also the sum of corresponding element's nums1 we will store in 'curr_sum'
        while(k--){
            auto top = nums2_max.top();
            nums2_max.pop();
            mini = top.first;
            curr_sum+= nums1[top.second];
            temp.push( nums1[top.second]);
        }
        ans = curr_sum*mini; // setting the curr_sum*mini as answer considering k top indices of nums2        
        // Now we will remove that element/index which is contributing least in sum
        // and add a element which will be corresponding the next(k+1 for first iteration) element
        while(nums2_max.size()){
            curr_sum-=temp.top();    temp.pop();       // removing a element which is contributing least to curr_sum
            auto top = nums2_max.top();     nums2_max.pop();
            mini = top.first;
            curr_sum+= nums1[top.second];
            ans = max(ans , curr_sum*mini);
            temp.push(nums1[top.second]);
        }
        return ans;
    }
};




class Solution:
    def new21Game(self, n: int, k: int, maxPts: int) -> float:
        if k == 0 or n >= k + maxPts:
            return 1.0
        
        windowSum = 1.0
        probability = 0.0
        
        dp = [0.0] * (n + 1)
        dp[0] = 1.0
        
        for i in range(1, n + 1):
            dp[i] = windowSum / maxPts
            
            if i < k:
                windowSum += dp[i]
            else:
                probability += dp[i]
            
            if i >= maxPts:
                windowSum -= dp[i - maxPts]
        
        return probability




class Solution {
public:

        int dp[101][201];

    int helper(int i,int m,vector<int>& piles){

         if(i >= piles.size())
         return 0;

         if(dp[i][m] != -1)
         return dp[i][m];

         int total = 0;
         int ans = INT_MIN;

         for(int j=0;j<2*m;j++){

             if(i+j < piles.size())
              total += piles[i+j];

              ans = max(ans,total - helper(i+j+1,max(m,j+1),piles));  
         }

        return dp[i][m] = ans;
    }
    int stoneGameII(vector<int>& piles) {


        memset(dp,-1,sizeof dp);
        
        int sum = 0;
        for(auto x:piles)
         sum += x;

        
         int diff = helper(0,1,piles);
        
        return (sum+diff)/2;
    }
};



class Solution {
public:
    int minCost(int n, std::vector<int>& cuts) {
        std::sort(cuts.begin(), cuts.end());
        int m = cuts.size();
        std::vector<std::vector<int>> dp(m + 2, std::vector<int>(m + 2, 0));

        for (int l = 2; l <= m + 1; l++) {
            for (int i = 0; i + l <= m + 1; i++) {
                int j = i + l;
                dp[i][j] = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j]);
                }
                int left = (i == 0) ? 0 : cuts[i - 1];
                int right = (j == m + 1) ? n : cuts[j - 1];
                dp[i][j] += right - left;
            }
        }

        return dp[0][m + 1];
    }
};




/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

 class ParkingSystem {
public:
    int sizes[3];
    
    ParkingSystem(int big, int medium, int small) {
        sizes[0] = big;
        sizes[1] = medium;
        sizes[2] = small;
    }
    
    bool addCar(int carType) {
        if(sizes[carType-1] > 0){
            sizes[carType-1]--;
            return true;
        }
        else    return false;
    }
};



class MyHashSet {
private:
    std::vector<bool> mp;

public:
    MyHashSet() {
        mp.resize(1000001, false);
    }

    void add(int key) {
        mp[key] = true;
    }

    void remove(int key) {
        mp[key] = false;
    }

    bool contains(int key) {
        return mp[key];
    }
};


class UndergroundSystem {
public:
        // id -> {station name,time}
        unordered_map<int,pair<string,int>>checkInStation; 

        // Route -> {total time,count}
        unordered_map<string,pair<int,int>> checkOutStation;

    UndergroundSystem() {
    }
    
    void checkIn(int id, string stationName, int t) {
          checkInStation[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
         
          auto cIn = checkInStation[id];
           checkInStation.erase(id);

           string route = cIn.first + "_" + stationName;

           checkOutStation[route].first += t - cIn.second;
           checkOutStation[route].second += 1;  
    }
    
    double getAverageTime(string startStation, string endStation) {
          
           string route  = startStation + "_" + endStation;
           auto time = checkOutStation[route];

        return (double)time.first/time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */



class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        
        if(grid[0][0]==1)return -1;
        
        if(grid[0][0]==0 && grid.size()==1 && grid[0].size()==1)return 1;
        
        vector<vector<bool>>visited(grid.size(),vector<bool>(grid.size(),false));
        visited[0][0]=true;
        while(!q.empty())
        {
            pair<int,int>p = q.front().first; 
            int x = p.first; 
            int y= p.second; 
            int lengthOfPath = q.front().second; 
            q.pop();
            
            vector<pair<int,int>>neighbours = {{0,1}, {0,-1}, {1,0}, {-1,0},
                                               {1,1}, {-1,-1}, {1,-1}, {-1,1}};
            
            for(pair<int,int>neighbour: neighbours)
            {
                int newx = neighbour.first + x;
                int newy = neighbour.second+ y;
                
         if(newx>=0 && newy>=0 && newx<grid.size() && newy<grid[0].size() && grid[newx][newy]==0 && !visited[newx][newy]){

                    q.push({{newx,newy},lengthOfPath+1});
                    visited[newx][newy] = true;
                    
                    if(newx==grid.size()-1 && newy==grid[0].size()-1)
                     return lengthOfPath+1;
           
                }      
            }
        }
        
        return -1;
        
    }
};




class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        const int n = bombs.size();
        vector<vector<int>> v(n);

        for (int i = 0; i < n; i++) 
        {
            long long r = (long long) bombs[i][2] * bombs[i][2];
            for (int j = 0; j < n; j++) 
            {
                if (i != j) 
                {
                    if ((long long) ((long long) bombs[i][0] - bombs[j][0]) * ((long long) bombs[i][0] - bombs[j][0]) + 
                        (long long) (bombs[i][1] - bombs[j][1]) * ((long long) bombs[i][1] - bombs[j][1]) <= r) 
                    {
                        v[i].push_back(j);
                    }
                }
            }
        }

        int ans = 1;
        for (int i = 0; i < n; i++) 
        {
            vector<bool> vis(n, false);
            int mx = 0;
            queue<int> q;
            q.push(i);

            while (!q.empty()) 
            {
                int s = q.size();
                for (int j = 0; j < s; j++) 
                {
                    int x = q.front();
                    q.pop();
                    vis[x] = true;
                    mx++;
                    for (auto p : v[x]) 
                    {
                        if (!vis[p]) {
                            q.push(p);
                            vis[p] = true;
                        }
                    }
                }
            }
            ans = max(ans, mx);
        }

        return ans;
    }
};






