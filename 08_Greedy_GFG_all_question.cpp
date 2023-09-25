
dshffsjfhsjf

fgg

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
       unordered_map<int,int>m;
       int mx=0;
        for(int i=0;i<arr.size();i++){
            int c=arr[i];
            if(m.find(c-difference)!=m.end())
            m[c]=m[c-difference]+1;
            else
            m[c]=1;
            mx=max(mx,m[c]);
        }
        return mx;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> m;
        int duplicate = 0;
        for(auto i= 0; i<nums.size(); ++i)
        ++m[nums[i]];
        
        for(auto i : m)
        {
            if(i.second > 1)
            {
                duplicate = i.first;
                break;
            }
        }
        return duplicate;
    }

};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
  while (node && node->next) {
      cout << node->val << "->";
      node = node->next;
  }

  if (node) {
    cout << node->val << endl;
  } else {
    cout << "Empty LinkedList" << endl;
  }
}

ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return head;
        
        ListNode* smallerHead=new ListNode(); //Head of the list with nodes <x
        ListNode* smallerTail=smallerHead; //Tail of the list with nodes <x
        
        ListNode* greaterHead=new ListNode();//Head of the list with nodes >=x
        ListNode* greaterTail=greaterHead; //Tail of the list with nodes >=x
        
        ListNode* curr = head;
        while (curr) {//partition into greater & smaller lists
            if (curr->val < x) {
                smallerTail->next = curr;
                smallerTail =smallerTail->next;
                cout<<curr->val<<"<"<<x<<":smaller\n";
                
            } 
            else {
                greaterTail->next = curr;
                greaterTail=greaterTail->next;
                cout<<curr->val<<">="<<x<<": greater\n";
                
            }
            cout<<"smaller:"; prettyPrintLinkedList(smallerHead);
            cout<<"greater:"; prettyPrintLinkedList(greaterHead);
            cout<<"-------\n";
            curr = curr->next;
        }
        
        greaterTail->next = NULL; 
        smallerTail->next = greaterHead->next;//Connect the smaller and the greater lists
        
        head = smallerHead->next; //Update the head of the list
       
        return head;
    }
int main() 
{
    ListNode* head=stringToListNode("[1,4,3,2,5,2]");
    int x=3;
    ListNode* ans=partition(head, x);
    cout<<"ans:\n";
    prettyPrintLinkedList(ans);
    return 0;
}


class Solution {
public:
    int change(int amount, vector<int>& coins) {
       int n = coins.size();
       vector<vector<int>>dp(n+1,vector<int>(amount+1,0));
       for(int i=0;i<=n;i++){
           dp[i][0]=1;
       }
       for(int i=1;i<=n;i++){
           for(int j=1;j<=amount;j++){
               if(j>=coins[i-1]){
                  dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                }
                else dp[i][j]=dp[i-1][j];
           }
       }
       return dp[n][amount];
    }
};

class Solution
{
public:
    bool c(vector<int> &v, vector<int> &dp, int i)
    {
        int n = v.size();
        if (i == v.size())
            return true;
        if (dp[i] != -1)
            return dp[i];

        if (i + 1 < n && v[i] == v[i + 1])
        {
            if (c(v, dp, i + 2))
                return dp[i] = true;
        }

        if (i + 2 < n && v[i] == v[i + 2] and v[i] == v[i + 1])
        {
            if (c(v, dp, i + 3))
                return dp[i] = true;
        }
        if (i + 2 < n && v[i] + 1 == v[i + 1] && v[i] + 2 == v[i + 2])
        {
            if (c(v, dp, i + 3))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    bool validPartition(vector<int> &v)
    {
        int n = v.size();
        vector<int> dp(n + 1, -1);
        return c(v, dp, 0);
    }
};


			// 😉😉😉😉Please upvote if it helps 😉😉😉😉
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        
        while(l <= r)
        {
            int mid = l + (r-l) / 2;
            if (nums[mid] == target)
                return true;
			// with duplicates we can have this contdition, just update left & right
            if((nums[l] == nums[mid]) && (nums[r] == nums[mid]))
            {
                l++;
                r--;
            }
			// first half
			// first half is in order
            else if(nums[l] <= nums[mid])
            {
				// target is in first  half
                if((nums[l] <= target) && (nums[mid] > target))
                    r = mid - 1;
                else
                    l = mid + 1;
            }
			// second half
			// second half is order
			// target is in second half
            else
            {
                if((nums[mid] < target) && (nums[r]>= target))
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return false;
    }
	// for github repository link go to my profile.
};

class Solution {
public:
    int minimizeMax(vector<int>& v, int p) {
       sort(v.begin(),v.end());
       int n = v.size();
       int ans = v[n-1]-v[0];
       int i=0,j=ans;
       while(i<=j){
           int m = (i+j)/2;
           int total = 0;
           int k = 0;
           while(k<n-1){
               if(v[k+1]-v[k]<=m){
                   total++;
                   k+=2;
               }
               else k++;
           }
           if(total>=p){
               ans = m;
               j = m-1;
           }
           else i = m+1;
       }
       return ans;
    }
};


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=0,c=matrix[0].size()-1;
        while(r<matrix.size() && c>=0){
            if(matrix[r][c]==target)
                return true;
            else if(matrix[r][c]<target)r++;
            else c--;
        }
        return false;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i , int n , int k , vector<int>& temp){
        if(k == 0){
            ans.push_back(temp);
            return ;
        }
        if(i == n) return ;
        dfs(i + 1 , n , k , temp);
        temp.push_back(i+1);
        dfs(i + 1 , n , k - 1 , temp);
        temp.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        dfs(0 , n , k , temp);
        return ans;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mp;
    void dfs(TreeNode* root, TreeNode* parent){
        if(!root) return;
        if(!parent) parent = root;
        else mp[root] = parent;
        dfs(root->left, root);
        dfs(root->right, root);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        queue<TreeNode*> q;
        set<TreeNode*> st;
        dfs(root,NULL);
        q.push(target);
        int cnt=0;
        vector<int> res;
        while(!q.empty()){
            int sz=q.size();
            if(cnt>k) break;
            while(sz--){
                auto node=q.front();
                q.pop();
                if(node->left!=NULL and !st.count(node->left)){
                    q.push(node->left);
                    st.insert(node->left);
                }
                if(node->right!=NULL and !st.count(node->right)){
                    q.push(node->right);
                    st.insert(node->right);
                }
                if(mp.count(node) and !st.count(mp[node])){
                    q.push(mp[node]);
                    st.insert(mp[node]);
                }
                st.insert(node);
                if(cnt==k){
                    res.push_back(node->val);
                }
            }
            cnt++;
        }
        return res;
    }
};

lass Solution {
public:

    void _permute(vector<int>& nums, int i,vector<vector<int>>& ans, vector<int> &temp, vector<bool>& used){
        if(i==nums.size()) ans.push_back(temp);

        for(int j=0; j<nums.size(); j++){
            if(!used[j]){
                temp.push_back(nums[j]);
                used[j] = true;
                // Recursively generate permutations with the remaining elements
                _permute(nums, i + 1, ans, temp, used);
                // Backtrack: Mark the element as unused and remove it from the temp permutation
                used[j] = false;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> used(nums.size(), false);
        _permute(nums, 0, ans, temp, used);

        return ans;

    }
};
class Solution {
public:
    std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people) {
        int n = req_skills.size();
        int m = people.size();
        
        std::unordered_map<std::string, int> skillToIndex;
        for (int i = 0; i < n; i++) {
            skillToIndex[req_skills[i]] = i;
        }
        
        std::vector<int> arr(m, 0);
        for (int i = 0; i < m; i++) {
            std::vector<std::string>& personSkills = people[i];
            int val = 0;
            for (const std::string& skill : personSkills) {
                val |= 1 << skillToIndex[skill];
            }
            arr[i] = val;
        }
        
        std::vector<bool> banned(m, false);
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                int val = arr[i] | arr[j];
                if (val == arr[i]) {
                    banned[j] = true;
                }
                else if (val == arr[j]) {
                    banned[i] = true;
                }
            }
        }
        
        std::vector<int> ans;
        helper(0, n, arr, std::vector<int>(), banned, ans);
        
        return ans;
    }
    
private:
    void helper(int cur, int n, const std::vector<int>& arr, std::vector<int> team, const std::vector<bool>& banned, std::vector<int>& ans) {
        if (cur == (1 << n) - 1) {
            if (ans.empty() || team.size() < ans.size()) {
                ans = team;
            }
            return;
        }
        
        if (!ans.empty() && team.size() >= ans.size()) {
            return;
        }
        
        int zero = 0;
        while (((cur >> zero) & 1) == 1) {
            zero++;
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (banned[i]) {
                continue;
            }
            
            if (((arr[i] >> zero) & 1) == 1) {
                team.push_back(i);
                helper(cur | arr[i], n, arr, team, banned, ans);
                team.pop_back();
            }
        }
    }
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string>();
        
        vector<string> digit2letters(10);
        
        digit2letters[2] = "abc";
        digit2letters[3] = "def";
        digit2letters[4] = "ghi";
        digit2letters[5] = "jkl";
        digit2letters[6] = "mno";
        digit2letters[7] = "pqrs";
        digit2letters[8] = "tuv";
        digit2letters[9] = "wxyz";
        
        vector<string> ans = {""};
        
        for(const char& c : digits){
            int d = c-'0';
            vector<string> olds = ans;
            ans.clear();
            for(const string& old : olds){
                for(const char& c : digit2letters[d]){
                    ans.push_back(old+c);
                }
            }
        }
        
        return ans;
    }
};


class LRUCache {
public:
class node
{
  public:
  int key;
  int val;
  node* next;
  node* prev;
  node(int _key,int _val)
  {
    key = _key;
    val = _val;
  }
};
node* head = new node(-1,-1);
node* tail = new node(-1,-1);

int size;
unordered_map<int,node*>mpp;
    LRUCache(int capacity) {
       size = capacity; 
       head->next = tail;
       tail->prev = head;  
    }

    void addNode(node* newNode){
       
       node* temp = head->next;
       newNode->next = temp;
       newNode->prev = head;
       head->next = newNode;
       temp->prev = newNode;
    }

    void deleteNode(node* delNode){
         
       node* delprev = delNode->prev;
       node* delnext = delNode->next;
       delprev->next = delnext;
       delnext->prev = delprev;
    }
    
    int get(int _key) {
        
        if(mpp.count(_key))
        {
          node* nde = mpp[_key];
          int curr = nde->val;
          mpp.erase(_key);
          deleteNode(nde);
          addNode(nde);
          mpp[_key] = head->next;
          return curr;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        
        if(mpp.count(_key))
        {
           node* nde = mpp[_key];
           mpp.erase(_key);
           deleteNode(nde);
        }
        if(mpp.size()==size)
        {
           mpp.erase(tail->prev->key);
           deleteNode(tail->prev);
        }
        addNode(new node(_key,value));
        mpp[_key] = head->next;
    }
};


class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,0);
        vector<int> dis(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(auto &x:graph[i]){
                adj[x].push_back(i);
                dis[i]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(dis[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            ans.push_back(node);
            q.pop();
            for(auto x:adj[node]){
                dis[x]--;
                if(dis[x]==0){
                    q.push(x);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        if(root->left==NULL && root->right==NULL)return 1;
        int dl=INT_MAX,dr=INT_MAX;
        if(root->left)
        dl=minDepth(root->left);
        if(root->right)
        dr=minDepth(root->right);

        return min(dl,dr)+1;
        
        
    }
};

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        vector<long long> store;
        for(int i=1;i<weights.size();i++){
            store.push_back(weights[i]+weights[i-1]);
        }
        sort(store.begin(),store.end());
        int n=store.size();
        long long mini=0;
        for(int i=0;i<k-1;i++){
            mini+= store[i];
        }

        long long maxi=0;
        for(int i=0;i<k-1;i++){
            maxi+= store[n-1-i];
        }
        return maxi - mini;
    }
};
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.length() != goal.length() || s.length() <= 1) {
            return false;
        }

        if (s == goal) {
            unordered_set<char> distinctChars(s.begin(), s.end());
            return distinctChars.size() < s.length();
        }

        vector<int> index;
        for (int i=0;i<s.length();i++) {
            if (s[i] != goal[i]) {
                index.push_back(i);
            }
        }

        if (index.size() != 2) {
            return false;
        }

        swap(s[index[0]], s[index[1]]);
        return s == goal;
    }
};
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& r) {
        int mx=0;
        for(int i=0;i<(1<<r.size());i++){
            vector<int>a(n,0);
            int t=0;
            for(int j=0;j<r.size();j++){
                if(i & (1<<j)){
                    t++;
                    a[r[j][0]]--;
                    a[r[j][1]]++;
                }
            }
            bool f=true;
            for(int j=0;j<n;j++){
                if(a[j]!=0){
                    f=false;
                    break;
                }
            }
            if(f)mx=max(mx,t);
        }
        return mx;
    }
};

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

class Solution {
public:
    int distributeCookies(std::vector<int>& cookies, int k) {
        int minUnfairness = std::numeric_limits<int>::max();
        std::vector<int> distribution(k, 0);
        
        backtrack(cookies, k, 0, minUnfairness, distribution);
        
        return minUnfairness;
    }
    
private:
    void backtrack(const std::vector<int>& cookies, int k, int i, int& minUnfairness, std::vector<int>& distribution) {
        if (i == cookies.size()) {
            minUnfairness = std::min(minUnfairness, getMax(distribution));
            return;
        }
        
        if (minUnfairness <= getMax(distribution)) {
            return;
        }
        
        for (int j = 0; j < k; j++) {
            distribution[j] += cookies[i];
            backtrack(cookies, k, i + 1, minUnfairness, distribution);
            distribution[j] -= cookies[i];
        }
    }
    
    int getMax(const std::vector<int>& distribution) {
        int max = std::numeric_limits<int>::min();
        for (int num : distribution) {
            max = std::max(max, num);
        }
        return max;
    }
};



#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<char, int> key_bit;
        int bit_start = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (islower(grid[i][j]))
                    key_bit[grid[i][j]] = bit_start++;
            }
        }

        int form_end = (1 << bit_start) - 1;
        int form_size = (1 << bit_start);

        vector<vector<vector<bool>>> memo(m, vector<vector<bool>>(n, vector<bool>(form_size, false)));

        vector<int> start;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '@')
                    start = { i, j, 0 }; // 0 denoting no key state
            }
        }

        queue<vector<int>> q;
        q.push(start);
        int Ashish = 0; // Step counter

        while (!q.empty()) {
            int size = q.size();
            for (int k = 0; k < size; k++) {
                int row = q.front()[0];
                int col = q.front()[1];
                int form = q.front()[2];
                q.pop();

                // Check if out of bounds
                if (row < 0 || row >= m || col < 0 || col >= n)
                    continue;

                // Check if position is blocked
                if (grid[row][col] == '#')
                    continue;

                // Check if the key is required but not collected
                if (isupper(grid[row][col])) {
                    if ((form & (1 << key_bit[tolower(grid[row][col])])) == 0)
                        continue;
                }

                // If the position contains a key, collect it
                if (islower(grid[row][col])) {
                    form = form | (1 << key_bit[grid[row][col]]);
                }

                // If all keys are collected, return the step count
                if (form == form_end)
                    return Ashish;

                // If the position and form combination has been visited, continue to the next iteration
                if (memo[row][col][form])
                    continue;
                memo[row][col][form] = true;

                // Add adjacent positions to the queue
                q.push({ row + 1, col, form });
                q.push({ row - 1, col, form });
                q.push({ row, col + 1, form });
                q.push({ row, col - 1, form });
            }
            Ashish++; // Increment step count
        }
        return -1;
    }
};




class Solution {
public:
    int equalPairs(vector<vector<int>>& v) {
        int n=v.size();
        int r=0;
        vector<vector<int>>c=v;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)swap(v[i][j],v[j][i]);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i]==c[j])r++;
            }
        }
        return r;
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




class Solution {
public:
    int dfs(int headId,vector<int>& informTime,vector<int> adj[]){

        int maxTime = 0;

        for(auto it:adj[headId])
           maxTime = max(maxTime,dfs(it,informTime,adj));

        return informTime[headId] + maxTime;   
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
            vector<int> adj[100005];

            for(int i=0;i<manager.size();i++)
                if(manager[i] != -1)
                  adj[manager[i]].push_back(i);
            
        return dfs(headID,informTime,adj);    
    }
};



class Solution {
public:

      void dfs(int s, int n, vector<vector<int>>& isConnected, vector<bool>&visited){
        visited[s] = true;
        
        
        vector<int>adj;
        for(int i=0; i<n; i++ ){
            int x =  isConnected[s][i];  // x = connection
            if(x == 1)
                adj.push_back(i);
        }
        
        for(auto x: adj){
            if(!visited[x]){
                dfs(x, n, isConnected, visited);
            }
        }
        
      }    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n=isConnected.size();
         vector<bool> visited(n,0);
         int ans=0;

         for(int i=0;i<isConnected.size();i++){
             if(!visited[i]){
                 ans++;
                 dfs(i,n,isConnected,visited);
             }
         }
       
        return ans;
    }
};




class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();

        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];

        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        for(int i = 2; i < n; i++){
            int x = coordinates[i][0];
            int y = coordinates[i][1];

            // y - y1 / x - x1 != y - y2 / x - x2
            // Division may cause division by zero error.

            if((y - y1) * (x - x2) != (y - y2) * (x - x1)){
                return false;
            } 
        }
        return true;
    }
};




class Solution {
public:
    bool canMakeArithmeticProgression(std::vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int diff = arr[1] - arr[0];

        for (int i = 2; i < arr.size(); i++) {
            if (arr[i] - arr[i-1] != diff) {
                return false;
            }
        }

        return true;
    }
};




class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
       int i=0;
       int j=grid[0].size()-1;
       int count=0;
       while(i<grid.size()&&j>=0)
       {
           if(grid[i][j]<0)
           {
               count+=(grid.size()-i);
               j--;
           }
           else if(grid[i][j]>=0)
           {
               i++;
           }
       }
       return count;
    }
};



class Solution {
public:
    long SUM(long n)
    {
        return n * (n + 1) / 2;
    }

    int maxValue(int n, int index, int maxSum)
    {
        auto check = [&](int mid)
        {
            long sum = 0;

            // sum for 0 to index will be counted below
            long reqLeft = mid, haveLeft = index + 1;
            if (index == 0)
            {
                sum += mid;
            }
            else
            {
                if (haveLeft >= reqLeft)
                {
                    sum += SUM(mid);
                    sum += haveLeft - reqLeft;
                }
                else
                {
                    sum += SUM(mid) - SUM(reqLeft - haveLeft);
                }
            }

            // sum for index + 1 to n - 1 will be counted below
            if (index != n - 1)
            {
                long reqRight = reqLeft - 1;
                long haveRight = n - index - 1;

                if (haveRight >= reqRight)
                {
                    sum += SUM(mid - 1);
                    sum += haveRight - reqRight;
                }
                else
                {
                    sum += SUM(mid - 1) - SUM(reqRight - haveRight);
                }
            }

            return sum <= maxSum;
        };

        long low = 1, high = maxSum, ans = -1;
        while (low <= high)
        {
            long mid = (low + high) / 2;
            if (check(mid))
                ans = mid, low = mid + 1;
            else
                high = mid - 1;
        }
        return ans;
    }
};


class SnapshotArray {
public:

    vector<map<int,int>>A;
    // snap_id
    int s_id = 0;

    SnapshotArray(int length) {
        
        // resizing the array to the given length
        A.resize(length);

        // intializing all the elements with 0;
        for(int i = 0; i < length; i++)
            A[i][0] = 0;
        
    }
    
    void set(int index, int val) {

      // setting value at the given index with current snap_id
        A[index][s_id] = val;
    }
    
    int snap() {
        s_id++;
        return  s_id - 1;
    }
    
    int get(int index, int snap_id) {

    // checks if a given snap_id exists in a specific snapshot
    // (A[index]) and returns the value associated with that snap_id
    //  if found. If the snap_id is not present, it returns the 
    //  closest value that is less than the snap_id from the
    //  previous snapshots.

        if(A[index].find(snap_id) == A[index].end())
        {
            auto it = --A[index].lower_bound(snap_id);
            return it->second;
        }
        return A[index][snap_id];
    }
};



class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int minDiff = INT_MAX;
        stack<TreeNode*> stack;
        TreeNode* node = root;
        TreeNode* prev = nullptr;
        
        while (node || !stack.empty()) {
            if (node) {
                stack.push(node);
                node = node->left;
            } else {
                node = stack.top();
                stack.pop();
                if (prev) {
                    minDiff = min(minDiff, node->val - prev->val);
                }
                prev = node;
                node = node->right;
            }
        }
        return minDiff;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int level=0;
        int mx= INT_MIN;
        int level_number;
        while(q.size()){
            int k=q.size();
            level++;
            int sum=0;
            while(k--){
                auto x =q.front();
                q.pop();
                sum+=x->val;
                if(x->left!=NULL){
                    q.push(x->left);
                }
                if(x->right!=NULL){
                    q.push(x->right);
                }
            }
            if(mx<sum){
                mx=sum;
                level_number=level;
            }
        }
        return level_number;
    }
};


class Solution {
    vector<vector<long long>> dp;
    long long MOD = 1e9 + 7;

    unsigned long long solve(vector<int> &nums) {
        if (nums.size() <= 1) return 1;
        vector<int> l, r;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[0]) r.push_back(nums[i]);
            else l.push_back(nums[i]);
        }
        int n = l.size(), m = r.size();
        return solve(l) * solve(r) % MOD * dp[n + m][n] % MOD;
    }

public:
    int numOfWays(vector<int> &nums) {
        dp = vector<vector<long long>>(nums.size() + 1, vector<long long>(nums.size() + 1, 0));
        for (int i = 1; i < nums.size() + 1; ++i) {
            dp[i][0] = 1;
            dp[i][1] = i;
            dp[i][i - 1] = i;
            dp[i][i] = 1;
        }
        for (int i = 2; i < nums.size() + 1; ++i) {
            for (int j = 2; j < nums.size() + 1; ++j) {
                if (i >= j) dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j] % MOD) % MOD;
                else break;
            }
        }
        return solve(nums) - 1;
    }
};





class Solution {
private:

int check(int curr, int left, vector<int>& arr1 ,vector<int>& arr2, vector <unordered_map<int,int> >& dp)
{
          if (curr == arr1.size())
            return 0;

          if (dp[curr].find(left) != dp[curr].end())
            return dp[curr][left];

          int exclude,include;

        // exclude stores the no. of ways for making array strictly 
       // increasing when not replacing the current element 

     // include stores the no. of ways for making the array strictly
    // increasing after replacing the current element


        if (arr1[curr] > left)    
            exclude = check(curr+1, arr1[curr], arr1, arr2, dp);
    
         else
            exclude = INT_MAX;

         int rep = upper_bound(arr2.begin(),arr2.end(), left) - arr2.begin();

           if (rep == arr2.size())
             include = INT_MAX;

           else
            include = check(curr+1, arr2[rep], arr1, arr2, dp);

             if (include == INT_MAX)
                dp[curr][left] = exclude;

             else
                dp[curr][left] = min(exclude,include+1);

    return dp[curr][left];
}

public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        
           sort(arr2.begin(), arr2.end());
           vector <unordered_map<int,int> > dp(2001);  

           int val = check(0, INT_MIN, arr1, arr2, dp);

        // if the value is INT_MAX than that means the array can not
      //   be strictly increasing by replacing any number of element

            if (val == INT_MAX)
                return -1;

        return val;
    }
};


class Solution {
private:
    int f(int i, int j, int prev, vector<vector<int>> &grid, vector<vector<int>> &dp){
        //out of boundary and if path is not increasing I can't make a possible path
        if(i<0 || j<0 || i>= grid.size() || j>= grid[0].size() || prev>= grid[i][j])
            return 0;

        //if I have answer, use that
        if(dp[i][j] != -1) return dp[i][j];
        
        //explore: go in all 4 direction to check increasing paths
        long long cnt = 1;

        cnt += f(i+1, j, grid[i][j], grid, dp)% mod;
        cnt += f(i-1, j, grid[i][j], grid, dp) % mod;
        cnt += f(i, j+1, grid[i][j], grid, dp) % mod;
        cnt += f(i, j-1,  grid[i][j], grid, dp) % mod;

        return dp[i][j] = cnt;
    }

public:
    int mod = 1e9+7;
    int countPaths(vector<vector<int>>& grid) {
        long long cnt = 0, n= grid.size(), m= grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1)); //dp table

        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                cnt += f(i, j, -1, grid, dp);
            }
        }

        return cnt%mod;
    }
};


class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr=0;
        int max_altitude=0;
        for(auto i:gain){
            curr+=i;
            max_altitude=max(curr,max_altitude);
        }
        return max_altitude;
        
    }
};


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {

         int n=nums.size();
         vector<long long int> pre(n),suff(n);

         pre[0]=nums[0];
         for(int i=1;i<n;i++)
            pre[i]=pre[i-1]+nums[i];
        
 
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
            suff[i]=suff[i+1]+nums[i];
        
 
        vector<int> ans;

        for(int i=0;i<n;++i){

            if(i-k<0 || i+k>=n)
                ans.push_back(-1);
            
 
            else{

           long long int sum = (long long int)((suff[i-k]-suff[i]) + (pre[i+k]-pre[i]) + nums[i]);
                sum=sum/(2*k+1);
                ans.push_back(sum);
            }
        }
 
        return ans;
    }
};

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) 
    {
        long long ans = LLONG_MAX; // Initialize ans with maximum possible value
        vector<long long> pref; // Prefix sum array
        vector<pair<long, long>> p; // Array of pairs (nums[i], cost[i])
        
        // Create pairs and store them in array p
        for(int i = 0; i < cost.size(); i++)
         {
            p.push_back({nums[i], cost[i]});
        }
        
        sort(p.begin(), p.end()); // Sort the pairs based on nums values
        
        pref.push_back(0); // Add initial 0 to prefix sum array
        // Calculate prefix sum of costs
        for(int i = 0; i < p.size(); i++)
         {
            pref.push_back(pref[i] + p[i].second);
        }
        long long left = 0, right = 0; // Initialize left and right costs
        for(int i = 0; i < nums.size(); i++)
         {
            if(i == 0)
             {
                left = 0;
                // Calculate the right cost from the second pair to the last pair
                for(int j = 1; j < cost.size(); j++)
                 {
                    right += (long long)(p[j].first - p[0].first) * (long long)p[j].second;
                }
                // Update ans if the current cost is smaller
                if(ans > right + left)
                 {
                    ans = left + right;
                }
                continue;
            }
            long long elevation = p[i].first - p[i - 1].first; // Calculate the elevation
            
            // Update right cost by subtracting the elevation cost and the remaining prefix sum
            right -= elevation * (long long)(p[i].second);
            right -= elevation * (pref[pref.size() - 1] - pref[i + 1]);
            // Update left cost by adding the elevation cost and the prefix sum
            left += elevation * (pref[i] - pref[0]);
            // Update ans if the current cost is smaller
            if(ans > right + left)
             {
                ans = left + right;
            }
        }
        return ans;
    }
};




class Solution {
public:

    
int getAns(vector<int> &Arr,int ind,int buy,int n,int fee,vector<vector<int>> &dp){

    if(ind==n) return 0; //base case
    
    if(dp[ind][buy]!=-1)
        return dp[ind][buy];
        
    int profit;
    
    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,fee,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,fee,dp));
    }
    
    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,fee,dp), Arr[ind] -fee + getAns(Arr,ind+1,0,n,fee,dp));
    }
    
    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& Arr, int fee) {

        vector<vector<int>> dp(Arr.size(),vector<int>(2,-1));
    
    if(Arr.size()==0) return 0;
    int ans = getAns(Arr,0,0,Arr.size(),fee,dp);
    return ans;
    }
};


class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 0;

            if(n <= 2)
             return n;
             
         unordered_map<int,int> dp[n+1];

         for(int i=1;i<n;i++){
             for(int j=0;j<i;j++){

                 int diff = nums[i]-nums[j];
                 int cnt = 1;

                 if(dp[j].count(diff))
                  cnt = dp[j][diff];

                  dp[i][diff] = 1 + cnt;  
                  ans = max(ans,dp[i][diff]);
             }
         }

        return ans;
    }
};




class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int sum = 0;
        for (int rod : rods) {
            sum += rod;
        }

        int dp[sum + 1];
        dp[0] = 0;

        // Initialize all other elements in dp[] to -1
        for (int i = 1; i <= sum; i++) {
            dp[i] = -1;
        }

        for (int rod : rods) {
            int dpCopy[sum + 1];
            // Copy the current state of dp[] to dpCopy[]
            copy(dp, dp + (sum + 1), dpCopy);

            for (int i = 0; i <= sum - rod; i++) {
                if (dpCopy[i] < 0) continue;

                // Case 1: Place the current rod on the same height billboard
                dp[i + rod] = max(dp[i + rod], dpCopy[i]);

                // Case 2: Place the current rod on the taller billboard
                // Calculate the absolute difference between current height and rod length
                dp[abs(i - rod)] = max(dp[abs(i - rod)], dpCopy[i] + min(i, rod));
            }
        }

        // Return the maximum height of the billboard stored at dp[0]
        return dp[0];
    }
};



class Solution {
public:
    int mod=1e9+7;
    
    int helper(vector<vector<int>>&dp,vector<int>&locations,int current,int &finish,int fuel, int n){

        if(fuel<0)
        return 0;

        if(dp[current][fuel]!=-1)
         return dp[current][fuel];

        int ans=0;

        if(current==finish)
        ans++;

        for(int next=0;next<n;next++)
            if(next!=current)
                ans=(ans%mod+helper(dp,locations,next,finish,fuel-abs(locations[current]-locations[next]),n)%mod)%mod;
         

        return dp[current][fuel]=ans%mod;
    }


    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {

        int n=locations.size();

        vector<vector<int>>dp(n,vector<int>(fuel+1,-1));

        return
		
		helper(dp,locations,start,finish,fuel,n);
    }
};




// TC - O((Candidates + k)Log(Candidates+k))
// SC - O(Candidates)

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {

        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;

        int cnt = 0;
        int i=0;
        int j=costs.size()-1;

        while(cnt<k){

            while(pq1.size()<candidates && i<=j) pq1.push(costs[i++]);
            while(pq2.size()<candidates && j>=i) pq2.push(costs[j--]);

            int cost1 = pq1.size()>0?pq1.top():INT_MAX;
            int cost2 = pq2.size()>0?pq2.top():INT_MAX;

            if(cost1<=cost2){

               ans += cost1;
               pq1.pop();
            }
            else{

              ans += cost2;
              pq2.pop();
            }

            cnt++;
        }



	    class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

          priority_queue<pair<int,pair<int,int>>> pq;
          int n = nums1.size();
          int m = nums2.size();

          for(int i=0;i<n;i++){
              for(int j=0; j<m ;j++){

                  int sum = nums1[i] + nums2[j];

                  if(pq.size() < k)
                    pq.push({sum,{nums1[i],nums2[j]}});

                   else if(sum < pq.top().first){

                        pq.pop();
                        pq.push({sum,{nums1[i],nums2[j]}});
                   }

                    else
                     break; 
              }
          }

          vector<vector<int>> ans;

           while(!pq.empty()){

               ans.push_back({pq.top().second.first,pq.top().second.second});
               pq.pop();
           }
        
        return ans;
    }
};




	    

        return ans;
    }
};

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, int>>> graph;
        
        // Build the graph using an adjacency list representation
        // Each edge is represented as a pair (neighbor node, edge index)
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0], v = edges[i][1], edgeIdx = i;
            graph[u].push_back({v, edgeIdx});
            graph[v].push_back({u, edgeIdx});
        }
        
        vector<double> probabilities(n, 0.0);
        probabilities[start] = 1.0;
        
        priority_queue<pair<double, int>> nodesToExplore;
        // Add the start node to the priority queue with probability 1.0
        nodesToExplore.push({1.0, start});
        
        while (!nodesToExplore.empty()) {
            auto [prob, u] = nodesToExplore.top();
            nodesToExplore.pop();
            
            // If we've reached the end node, return the probability
            if (u == end) 
                return prob;
            // If we've already explored this node with a higher probability, skip it
            if (probabilities[u] > prob) 
                continue;
                
            // Explore the neighbors of the current node
            for (auto [v, edgeIdx] : graph[u]) {
                double newProb = prob * succProb[edgeIdx];
                
                // Update the probability of the neighbor node if we've found a higher probability
                if (newProb > probabilities[v]) {
                    probabilities[v] = newProb;
                    
                    // Add the neighbor node to the priority queue with its new probability
                    nodesToExplore.push({newProb, v});
                }
            }
        }
        
        // If we've explored all nodes and haven't reached the end node, return 0.0
        return 0.0;
    }
};


class Solution {
public:
    int findNumberOfLIS(vector<int>& a) {
        int n=a.size();
        
        vector<int> dp(n,1), count(n,1);
        int max_len=0;
		
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i]>a[j]){
                    if(dp[i]<1+dp[j]){ // longer subsequence is possible than just inc in 1 by addition of a[i]
                        count[i]=count[j]; // becoming part of this new subsequence
                    }else if(dp[i]==1+dp[j]){
                        count[i]+=count[j]; // summing up all possible subequences ending at a[i] with same length
                    }
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            max_len=max(max_len,dp[i]);
        }
        
        int c=0;
        for(int i=0;i<n;i++){
            if(dp[i]==max_len) c += count[i];
        }
        
        return c;
    }
};

class Solution {
public:

double dp[30][30][105];
int X[8]={ 2, 1, -1, -2, -2, -1, 1, 2 };
int Y[8]={ 1, 2, 2, 1, -1, -2, -2, -1 };

double dfs(int i,int j,int k, int n)
{
    if(i < 0 || j < 0 ||i >= n || j >= n) return 0;
    if(k == 0) return 1;
    if(dp[i][j][k] != 0) return dp[i][j][k];

    double res = 0;

    for(int l = 0;l < 8; ++l)
    {
      int x = i + X[l];
      int y = j + Y[l];
      res += dfs(x,y,k-1,n);
    }
    return dp[i][j][k] += (res/8.0);
}

    double knightProbability(int n, int k, int row, int column) {

        memset(dp,0,sizeof(dp));
        return dfs(row,column,k,n); 
    }
};

class Solution {
public:
    bool canCross(std::vector<int>& stones) {
        int n = stones.size();

        std::unordered_map<int, std::unordered_set<int>> dp;
        for (int stone : stones) {
            dp[stone] = std::unordered_set<int>();
        }
        dp[0].insert(0);

        for (int i = 0; i < n; i++) {
            for (int k : dp[stones[i]]) {
                for (int step = k - 1; step <= k + 1; step++) {
                    if (step != 0 && dp.count(stones[i] + step)) {
                        dp[stones[i] + step].insert(step);
                    }
                }
            }
        }
        
        return !dp[stones.back()].empty();
    }
};

class MyStack {
public:
    queue<int>q;
    MyStack() {
        
    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for(int i=0; i<s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(q.size() == 0)
        {
            return -1;
        }
        
        int x = q.front();
        q.pop();
        return x;
    }
    
    int top() {
        if(q.size() == 0)
        {
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


class Solution:
    def minimumReplacement(self, nums: List[int]) -> int:
        n = len(nums)  # Get the length of the array
        operations = 0  # Initialize the operations counter

        prev_value = nums[n - 1]  # Initialize prev_value with the last element of the array

        # Iterate through the array in reverse order
        for i in range(n - 2, -1, -1):
            if nums[i] > prev_value:
                # Calculate how many times prev_value should be added to get nums[i]
                k = (nums[i] + prev_value - 1) // prev_value
                # Increment operations by k - 1
                operations += k - 1
                # Update prev_value to be nums[i] divided by k
                prev_value = nums[i] // k
            else:
                # If nums[i] is not greater than prev_value, update prev_value to nums[i]
                prev_value = nums[i]
        
        return operations  # Return the total number of operations
#Upvote if u like @pratikk_rathod @uncomment to save memory!!!



	class Solution {
public:
    int dp[101][101];
    int solve(int m,int n,int i,int j){
        if(i==m-1||j==n-1){
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=solve(m,n,i+1,j)+solve(m,n,i,j+1);
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,0,0);
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        } else {
            ListNode *slow = head, *fast = head->next;
            
            while (slow != fast) {
                if (fast == NULL || fast->next == NULL) {
                    return false;
                } else {
                    slow = slow->next;
                    fast = fast->next->next;
                }
            }
            return true;
        }
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;

        Node* original = head; // itr for original
        Node* cloned = nullptr; // itr for cloed
        Node* temp = nullptr; // temporary for node creation

        // First pass: clone nodes and link them next to origial
        while(original) {
            temp = new Node(original->val);
            temp->next = original->next;
            original->next=temp;
            original = temp->next;
        }

        original = head;
        Node* newHead = head->next;

        // Second pass: Assign random pointers to cloned nodes
        while(original) {
            if(original->random) {
                original->next->random = original->random->next;
            } else {
                original->next->random = nullptr;
            }
            original = original->next->next; // skip copy
        }
        
        original = head;

        // Third Pass: Seperate original and cloned 
        while(original) {
            temp = original->next; 
            original->next = temp->next; 
            original = original->next;

            if(original) {
                temp->next = original->next;
            } else {
                temp->next = nullptr;
            }
        }

    return newHead;
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int len=0;
        ListNode*temp=head;
        while(temp!=NULL){
            len++;
            temp=temp->next;
        }
        vector<ListNode*>v(k,NULL);
        int p=len/k;
        int extra=len%k;
        temp=head;
        int j=0;
        while(temp!=NULL){
            ListNode*c=temp;
            ListNode*dummy=new ListNode(-1);
            ListNode*curr=dummy;
            for(int i=0;i<p;i++){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
            }
            if(extra>0){
                curr->next=new ListNode(temp->val);
                temp=temp->next;
                curr=curr->next;
                extra--;
            }
            v[j]=dummy->next;
            j++;
        }
        return v;
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 0; i < left - 1; i++) {
            prev = prev->next;
        }

        ListNode* cur = prev->next;

        for (int i = 0; i < right - left; i++) {
            ListNode* temp = cur->next;
            cur->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy->next;        
    }
};

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> res;
        res.push_back({1});

        for (int i = 0; i < numRows - 1; i++) {
            std::vector<int> dummyRow = {0};
            dummyRow.insert(dummyRow.end(), res.back().begin(), res.back().end());
            dummyRow.push_back(0);
            std::vector<int> row;

            for (int j = 0; j < dummyRow.size() - 1; j++) {
                row.push_back(dummyRow[j] + dummyRow[j + 1]);
            }

            res.push_back(row);
        }

        return res;        
    }
};


class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // dp[i] represents the number of combinations to make sum 'i'
        vector<unsigned long long> dp(target + 1, 0);
        
        // There is one way to make sum 0, which is by not selecting any number.
        dp[0] = 1;
        
        for(int currentSum = 1; currentSum <= target; currentSum++) {
            for(int numIndex = 0; numIndex < nums.size(); numIndex++) {
                int currentNum = nums[numIndex];
                if(currentSum - currentNum >= 0) {
                    // dp[i] can be achieved by adding the combination count at dp[i - currentNum]
                    dp[currentSum] += dp[currentSum - currentNum];
                }
            }
        }
        
        // The final result is stored in dp[target]
        return dp[target];
    }
};

class Solution {
public:
    int countOrders(int n) {
        const int MOD = 1000000007;
        long long totalWays = 1;
        for (int orderNumber = 2; orderNumber <= n; orderNumber++) {
            totalWays = (totalWays * (2LL * orderNumber - 1) * orderNumber) % MOD;
        }
        return static_cast<int>(totalWays);        
    }
};

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupsizes) {
        unordered_map<int,vector<int>>u;
        for(int i=0;i<groupsizes.size();i++){
            u[groupsizes[i]].push_back(i);
        }
        vector<vector<int>>v;
        for(auto x:u){
            int k=x.first;
           vector<int>f=x.second;
           int c=f.size()/k;
           int l=0;
           for(int i=0;i<c;i++){
                vector<int>ans;
               for(int j=0;j<k;j++){
                ans.push_back(f[l]);
                l++;
               }
               v.push_back(ans);
           }
        }
        return v;
    }
};

class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> chars;
        for (char c : s) {
            chars[c]++;
        }

        unordered_set<int> freqSet;
        int count = 0;

        for (const auto& pair : chars) {
            int freq = pair.second;
            while (freq > 0 && freqSet.count(freq)) {
                freq--;
                count++;
            }
            freqSet.insert(freq);
        }

        return count;        
    }
};


class Solution {
public:
    int candy(vector<int>& ratings) {
       int n = ratings.size();
        int totalCandies = n;
        int i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int currentPeak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                currentPeak++;
                totalCandies += currentPeak;
                i++;
            }

            if (i == n) {
                return totalCandies;
            }

            int currentValley = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                currentValley++;
                totalCandies += currentValley;
                i++;
            }

            totalCandies -= min(currentPeak, currentValley);
        }

        return totalCandies;        
    }
};

class Solution {
private:
    // Create an adjacency list to represent the flights
    unordered_map<string, vector<string>> flightGraph;
    
    // Store the final itinerary
    vector<string> itinerary;

public:

    // Depth-First Search to traverse the flight itinerary
    void dfs(string airport) {
        vector<string> &destinations = flightGraph[airport];
        
        // Visit destinations in lexical order
        while (!destinations.empty()) {
            string nextDestination = destinations.back();
            destinations.pop_back();
            dfs(nextDestination);
        }
        
        // Add the current airport to the itinerary after visiting all destinations
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Populate the flight graph using ticket information
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to = tickets[i][1];

            flightGraph[from].push_back(to);
        }
        
        // Sort destinations in reverse order to visit lexical smaller destinations first
        for (auto &entry : flightGraph) {
            sort(entry.second.rbegin(), entry.second.rend());
        }
        
        // Start the DFS from the JFK airport
        dfs("JFK");
        
        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());
        
        return itinerary;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int min_cost = 0;
        std::vector<bool> visited(n, false);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;  // {cost, vertex}
        std::unordered_map<int, int> cache;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto edge = pq.top();
            pq.pop();
            int cost = edge.first;
            int u = edge.second;

            if (visited[u]) {
                continue;
            }

            visited[u] = true;
            min_cost += cost;

            for (int v = 0; v < n; v++) {
                if (!visited[v]) {
                    int dist = std::abs(points[u][0] - points[v][0]) + std::abs(points[u][1] - points[v][1]);
                    if (cache.find(v) == cache.end() || dist < cache[v]) {
                        cache[v] = dist;
                        pq.push({dist, v});
                    }
                }
            }
        }

        return min_cost;
    }
};



#include <vector>
#include <queue>
#include <climits>

class Solution {
public:
    std::vector<int> DIR = {0, 1, 0, -1, 0};
    
    int minimumEffortPath(std::vector<std::vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Initialize a 2D array to store distances with max values.
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, INT_MAX));
        
        // Create a min-heap to store distance, row, and column values.
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        
        // Initialize the min heap with starting point (distance, row, col).
        minHeap.push({0, 0, 0});
        
        // Set the distance to the starting point as 0.
        dist[0][0] = 0;
        
        while (!minHeap.empty()) {
            std::vector<int> top = minHeap.top();
            minHeap.pop();
            
            int d = top[0];
            int r = top[1];
            int c = top[2];
            
            // If this is an outdated version, skip it.
            if (d > dist[r][c]) continue;
            
            // If we reach the bottom right, return the distance.
            if (r == m - 1 && c == n - 1) return d;
            
            // Explore neighboring cells.
            for (int i = 0; i < 4; i++) {
                int nr = r + DIR[i];
                int nc = c + DIR[i + 1];
                
                // Check if the neighbor is within bounds.
                if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                    // Calculate the new distance.
                    int newDist = std::max(d, std::abs(heights[nr][nc] - heights[r][c]));
                    
                    // If the new distance is smaller, update the distance and add to the heap.
                    if (dist[nr][nc] > newDist) {
                        dist[nr][nc] = newDist;
                        minHeap.push({dist[nr][nc], nr, nc});
                    }
                }
            }
        }
        
        return 0;
    }
};

class Solution {
public:
    using int3 = tuple<int, int, int>; // (distance, vertex, mask)
    using int2 = pair<int, int>;       // (vertex, mask) -> path

    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        set<int2> path; // n is small 
        int&& allMask = (1<<n) - 1;
        
        if (n == 1) return 0;

        queue<int3> q;
        for (int i = 0; i < n; i++) {
            int mask = 1<<i;
            q.emplace(0, i, mask);
            path.insert({i, mask});
        }

        while (!q.empty()) {
            auto [d, i, mask] = q.front();
        //    cout<<"["<<d<<", "<<i<<", "<<mask<<"]\n";
            q.pop();
            if (mask==allMask) return d;
            
            for (int j : graph[i]) {
                int jMask= mask|(1<<j); //mask for each neighbor
                int2 edge={j, jMask};
                
                if (path.count(edge)==0) {
                    path.insert(edge);
                    q.emplace(d+1, j, jMask);
                }
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
      for(int i=0; i<mat.size(); i++) {
        int cur = 0;
        for(int j=0; j<mat[i].size(); j++) {
          if(mat[i][j]==1)
            cur++;
        }
        pq.push({cur, i});
      } 
      vector<int> ans;
      while(k--) {
        int top = pq.top().second;
        pq.pop();
        ans.push_back(top);
      }
      return ans;
    }
};

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int maxLength = -1, currSum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (l <= r && currSum > totalSum - x)
                currSum -= nums[l++];
            if (currSum == totalSum - x)
                maxLength = max(maxLength, r - l + 1);
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure nums1 is the smaller array
        if (nums1.size() > nums2.size()) {
            nums1.swap(nums2);
        }

        // Get the lengths of the two arrays
        int len1 = nums1.size();
        int len2 = nums2.size();

        // Set the range for binary search on nums1
        int left = 0;
        int right = len1;

        while (left <= right) {
            // Partition nums1 and nums2
            int partition1 = (left + right) / 2;
            int partition2 = (len1 + len2 + 1) / 2 - partition1;

            // Find the maximum elements on the left of the partition
            int maxLeft1 = partition1 > 0 ? nums1[partition1 - 1] : INT_MIN;
            int maxLeft2 = partition2 > 0 ? nums2[partition2 - 1] : INT_MIN;
            int maxLeft = max(maxLeft1, maxLeft2);

            // Find the minimum elements on the right of the partition
            int minRight1 = partition1 < len1 ? nums1[partition1] : INT_MAX;
            int minRight2 = partition2 < len2 ? nums2[partition2] : INT_MAX;
            int minRight = min(minRight1, minRight2);

            // Check if the partition is correct
            if (maxLeft <= minRight) {
                // If the total length is even, return the average of the two middle elements
                if ((len1 + len2) % 2 == 0) {
                    return (maxLeft + minRight) / 2.0;
                }
                // If the total length is odd, return the middle element
                else {
                    return maxLeft;
                }
            } else if (maxLeft1 > minRight2) {
                right = partition1 - 1;
            } else {
                left = partition1 + 1;
            }
        }

        return 0.0; // This should not be reached, just to satisfy C++'s return requirements        
    }
};


		
class Solution {
public:
    bool isSubsequence(string s, string t) {
        
    int j = 0; // For index of str1 (or subsequence
 
    // Traverse str2 and str1, and
    // compare current character
    // of str2 with first unmatched char
    // of str1, if matched
    // then move ahead in str1
    for (int i = 0; i < t.length() && j < s.length(); i++)
        if (s[j] == t[i])
            j++;
 
    // If all characters of str1 were found in str2
    return (j == s.length());
    }
};


class Solution {
private:
    unordered_map<string, int> chain_lengths;
    unordered_map<string, bool> word_set;

    int calculateChainLength(const string &word) {
        // If the word doesn't exist in the set
        if (word_set.find(word) == word_set.end())
            return 0;

        // If chain length for the word is already calculated
        if (chain_lengths.find(word) != chain_lengths.end())
            return chain_lengths[word];

        int chain_length = 1;

        // Try removing one character at a time from the word and calculate chain length
        for (int i = 0; i < word.size(); i++) {
            string new_word = word.substr(0, i) + word.substr(i + 1);
            chain_length = max(chain_length, 1 + calculateChainLength(new_word));
        }

        chain_lengths[word] = chain_length;
        return chain_length;
    }

public:
    int longestStrChain(vector<string> &words) {
        for (const auto &word : words) {
            word_set[word] = true;
        }

        int max_chain_length = -1;

        // Calculate the maximum chain length for each word
        for (const auto &word : words) {
            max_chain_length = max(max_chain_length, calculateChainLength(word));
        }

        return max_chain_length;
    }
};


class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        std::vector<std::vector<double>> tower(query_row + 1, std::vector<double>(query_row + 1, 0.0));
        tower[0][0] = static_cast<double>(poured);

        for (int row = 0; row < query_row; row++) {
            for (int glass = 0; glass <= row; glass++) {
                double excess = (tower[row][glass] - 1.0) / 2.0;
                if (excess > 0) {
                    tower[row + 1][glass] += excess;
                    tower[row + 1][glass + 1] += excess;
                }
            }
        }

        return std::min(1.0, tower[query_row][query_glass]);
    }
};


class Solution {
public:
    char findTheDifference(string s, string t) 
    {
      for(int i=0;i<s.size();i++)
		t[i+1]+=t[i]-s[i]; //Passing the diff: (t[i]-s[i]) to t[i+1]
      return t[t.size()-1]; //The diff will be carried over to the last element eventually
    }
};
