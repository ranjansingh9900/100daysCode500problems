// ******// 1..Reverse the array

#include <iostream>

using namespace std;

void printff(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        // cout<<endl;
    }
}


class Solution {
public:
    int largestVariance(string s) {
        vector<int> arr(26); // Array to store the frequency of each letter (a-z)
        for(auto x : s) {
            arr[x - 'a']++; // Increment the count for the corresponding letter
        }
        int ans = 0; // Variable to store the maximum variance found
        for(char i = 'a'; i <= 'z'; i++) { // Iterate through each letter i
            for(char j = 'a'; j <= 'z'; j++) { // Iterate through each letter j
                // Skip if j is the same as i or either i or j has a frequency of 0
                if(j == i || arr[i - 'a'] == 0 || arr[j - 'a'] == 0)
                    continue;
                for(int k = 1; k <= 2; k++) { // Perform the calculation twice (forward and backward)
                    int A1 = 0; // Counter for letter i
                    int A2 = 0; // Counter for letter j
                    for(auto x : s) {
                        if(x == i)
                            A1++; // Increment A1 if the current letter is i
                        if(x == j)
                            A2++; // Increment A2 if the current letter is j
                        if(A2 > A1) {
                            A1 = 0;
                            A2 = 0; // Reset A1 and A2 if A2 becomes greater than A1
                        }
                        if(A1 > 0 && A2 > 0)
                            ans = max(ans, A1 - A2); // Update the maximum variance if A1 - A2 is greater
                    }
                    reverse(s.begin(), s.end()); // Reverse the string for the next iteration
                }
            }
        }
        return ans; // Return the maximum variance found
    }
};

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size(),m =v[0].size();
        if(v[0][0] || v[n-1][m-1])return 0;
        vector<vector<int>>dp(n,vector<int>(m,0));
        dp[0][0]=1;
        for(int i=1;i<n;i++){
            if(v[i][0])dp[i][0]=0;
            else dp[i][0]=dp[i-1][0];
        }
        for(int i=1;i<m;i++){
            if(v[0][i])dp[0][i]=0;
            else dp[0][i]=dp[0][i-1];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(!v[i][j])dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[n-1][m-1];
    }
};



class Solution {
public:
    int maxConsecutiveAnswers(string s, int k) {
        int n = s.size();
        int start = 0;
        int end = 0;
        int t = 0, f = 0; // Counters for 'T' and 'F' characters
        int ans = 0; // Maximum consecutive answers

        while (end < n) {
            // Update counters based on the current character
            t += (s[end] == 'T');
            f += (s[end] == 'F');

            while (t > k && f > k) {
                // If both counters exceed 'k', move the start pointer and adjust counters
                if (s[start] == 'T')
                    t--;
                else
                    f--;
                start++;
            }

            ans = max(ans, end - start + 1); // Update the maximum consecutive answers
            end++;
        }

        return ans;
    }
};




// way1
/**void reverseArray(int arr[],int strat ,int end){
    while (strat<end)
    {
        int temp=arr[strat];
        arr[strat]=arr[end];
        arr[end]=temp;
        strat++;
        end--;
    }



}
**/
// way2
void reverseArray(int arr[], int strat, int end)
{
    if (strat >= end)
        return;
    int temp = arr[strat];
    arr[strat] = arr[end];
    arr[end] = temp;
    reverseArray(arr, strat + 1, end - 1);
}

int main()
{

    int arr[] = {10, 20, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    printff(arr, n);

    cout << endl;

    reverseArray(arr, 0, 5);
    cout << endl;

    printff(arr, n);

    return 0;
}




// ******//Maximum and minimum of an array using minimum number of comparisons



#include <iostream>
using namespace std;

struct Pair
{
    int min;
    int max;
};

Pair getmaxmin(int arr[], int n)
{
    struct Pair minmax;
    int i;
    if (n == 1)
    {
        minmax.min = arr[0];
        minmax.max = arr[0];
        return minmax;
    }
    if (arr[1] > arr[0])
    {
        minmax.max = arr[1];
        minmax.min = arr[0];
    }
    else
    {
        minmax.max = arr[0];
        minmax.min = arr[1];
    }
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > minmax.max)
        {
            minmax.max = arr[i];
        }
        else if (arr[i] < minmax.min)
        {
            minmax.min = arr[i];
        }
    }
    return minmax;
}

int main()
{
    int arr[] = {34, 5, 6, 22, 44, 66, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    struct Pair minmax=getmaxmin(arr,n);
    cout<<"max element : "<<minmax.max<<endl;
    cout<<"min element : "<<minmax.min;

    return 0;
}






******//Find the "Kth" max and min element of an array 



#include <bits/stdc++.h>
using namespace std;

int kthsmallerElement(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[k - 1];
}
int kthlargestElement(int arr[], int n, int k)
{
    sort(arr, arr + n);
    return arr[n - k];
}

int main()
{

    int arr[] = {0, 4, 55, 77, 3, 66, 7, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    cout << "kth smaller element : " << kthsmallerElement(arr, size, k)<<endl;
    cout << "kth lergest element : " << kthlargestElement(arr, size, k);

    return 0;
}




******//..Sort an array of 0s, 1s and 2s 


#include <bits/stdc++.h>
using namespace std;

void display(int arr[], int n)
{
    int i = 0;
    while (i < n)
    {
        cout << arr[i] << " ";
        i++;
    }
}
void sortarr(int arr[], int n)
{
    int count = 0, count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++)
    {
        switch (arr[i])
        {
        case 0:
            count++;
            break;
        case 1:
            count1++;
            break;
        case 2:
            count2++;
            break;
        }
    }
    int i = 0;
    while (count > 0)
    {
        /* code */
        arr[i++] = 0;
        count--;
    }
    while (count1 > 0)
    {
        /* code */
        arr[i++] = 1;
        count1--;
    }
    while (count2 > 0)
    {
        /* code */
        arr[i++] = 2;
        count2--;
    }

    // display(arr,n);
}

int main()
{
    int arr[] = {0, 2, 2, 2, 1, 0, 0, 2, 1, 0, 2};
    int size = sizeof(arr) / sizeof(arr[0]);
    display(arr, size);
    sortarr(arr, size);
    cout << endl;
    display(arr, size);

    return 0;
}



******//....Move all the negative elements to one side of the array 


#include<bits/stdc++.h>
using namespace std;

void arrang(vector<int>&arr){
    sort(arr.begin(),arr.end());
}

int main(){

    vector<int>arr={-1,-3,5,-5,-6,3,0,-10,4,6};
    arrang(arr);
    for(int a:arr){
        cout<<a<<" ";
    }

    return 0;
}






*******///...Find the Union and Intersection of the two sorted arrays.




#include <bits/stdc++.h>
using namespace std;

// union uisng set

int getunion(int arr[], int arr1[], int n, int m)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr1[i]);
    }
    cout << "union using set " << endl;

    for (int value : s)
    {
        cout << value << " ";
    }
    cout << endl;
}

// union using map

void getunion1(int arr[], int arr1[], int n, int m)
{
    std::map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp.insert({arr[i], i});
    }
    for (int i = 0; i < m; i++)
    {
        mp.insert({arr1[i], i});
    }
    cout << "union using map" << endl;
    for (auto itr = mp.begin(); itr != mp.end(); itr++)
    {
        cout << itr->first << " ";
    }
}

// intersection using set

void intersectioin(int arr[], int arr1[], int n, int m)
{

    set<int> sp;
    for (int i = 0; i < n; i++)
    {
        sp.insert({arr[i]});
    }
    for (int i = 0; i < m; i++)
    {
        if (sp.find(arr1[i]) != sp.end())
        {
            sp.erase(arr1[i]);

            cout << arr1[i] << " ";
        }
    }
}

int main()
{
    int arr[] = {1, 4, 5, 6, 2, 45, 63, 5};
    int arr1[] = {1, 4, 5, 3, 5, 2, 46, 56, 35};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(arr1) / sizeof(arr1[0]);
    getunion(arr, arr1, n, m);
    cout << endl;
    getunion1(arr, arr1, n, m);
    cout << endl;
    cout << "intersection " << endl;
    intersectioin(arr, arr1, n, m);

    return 0;
}



******///... Write a program to cyclically rotate an array by one.


#include <bits/stdc++.h>
using namespace std;

void rotate(int arr[], int n)
{
    int x = arr[n - 1];
    for (int i = n - 1; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    rotate(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}



******///.... find Largest sum contiguous Subarray [V. IMP]



// kadane's algorithm

/*The idea of Kadane’s algorithm is to maintain a variable max_ending_here that stores the
maximum sum contiguous subarray ending at current index and a variable max_so_far stores the maximum sum
 of contiguous subarray found so far, Everytime there is a positive-sum value in max_ending_here
compare it with max_so_far and update max_so_far if it is greater than max_so_far
*/

#include <bits/stdc++.h>
using namespace std;

int maxsubarraysum(int arr[], int n)
{
    int msf = INT_MIN, meh = 0;
    for (int i = 0; i < n; i++)
    {
        meh = meh + arr[i];
        if (msf < meh)
            msf = meh;
        // cout << msf << " ";
        if (meh < 0)
            meh = 0;
    }
    cout << endl;

    return msf;
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[] = {2, -2, 4, -6, -4, 2 - 8, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    display(arr, n);
    cout << endl;
    cout << "max sub array sum : " << maxsubarraysum(arr, n);
    // display(arr, n);

    return 0;
}



*****///....Minimise the maximum difference between heights [V.IMP]



#include <bits/stdc++.h>
using namespace std;

int getmindiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = arr[n - 1] - arr[0];
    int tempmin, tempmax;
    tempmin = arr[0];
    tempmax = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] - k < 0)
        {
            continue;
        }
        tempmin = min(arr[0] + k, arr[i] - k);
        tempmax = max(arr[i - 1] + k, arr[n - 1] - k);
        ans = min(ans, tempmax - tempmin);
    }
    return ans;
}

int main()
{
    int k = 6, n = 6;
    int arr[n] = {7, 4, 8, 8, 8, 9};
    int ans = getmindiff(arr, n, k);
    cout << ans;

    return 0;
}


******////...Minimum no. of Jumps to reach end of an array



#include <bits/stdc++.h>
using namespace std;

int minjumps(int arr[], int n)
{
    if (n == 1)
        return 0;
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--)
    {
        if (i + arr[i] >= n - 1)
        {
            int sub_res = minjumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 4, 6, 8, 4, 9, 5, 3, 2, 8, 9, 6, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "minmum number of jumps to";
    cout << "reach the end is " << minjumps(arr, n);

    return 0;

}


// *******///...find duplicate in an array of N+1 Integers



#include<bits/stdc++.h>
using namespace std;


void printRepeating(int arr[],int n){
    for(int i=0;i<n;i++){
        int index=arr[i]%n;
        arr[index]+=n;
    }
    for(int i=0;i<n;i++){
        if((arr[i]/n)>=2){
            cout<<i<<" ";
        }
    }
}

int main(){
    int arr[]={1,6,3,1,3,6,6};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<"The repeation elements are : \n";
    printRepeating(arr,n);
    return 0;
}




// *******////...Merge 2 sorted arrays without using Extra space.



#include <bits/stdc++.h>
using namespace std;

void marge(int arr1[], int arr2[], int n, int m)
{
    for (int i = m - 1; i >= 0; i--)
    {
        int j, last = arr1[n - 1];
        for (j = n - 2; j >= 0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j + 1] = arr1[j];
        }
        if (last > arr2[i])
        {
            arr1[j + 1] = arr2[i];
            arr2[i] = last;
        }
    }
}

int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int arr2[] = {2, 3, 8, 13};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);
    marge(arr1, arr2, n, m);

    cout << "After merging \nFirst array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << "\nsecond Array : ";

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}





// *******////...Kadane's Algo [V.V.V.V.V IMP]

#include <bits/stdc++.h>
using namespace std;

// void kadanesalo(vector<int> &v)
// {

//     int sum = 0;
//     int maxi = v[0];
//     for (int i = 0; i < v.size(); i++)
//     {
//         sum = sum + v[i];
//         maxi = max(sum, maxi);
//         if (sum < 0)
//         {
//             sum = 0;
//         }
//     }
//     cout << maxi;
//     // return maxi;
// }
int maxsubarraysum(int arr[], int n)
{
    int msf = INT_MIN, meh = 0;
    for (int i = 0; i < n; i++)
    {
        meh = meh + arr[i];
        if (msf < meh)
            msf = meh;
        // cout << msf << " ";
        if (meh < 0)
            meh = 0;
    }
    cout << endl;

    return msf;
}

int main()
{

    int v[] = {1, 2, 3, -2, 5};
    int n = sizeof(v) / sizeof(v[0]);
    cout << maxsubarraysum(v, n);
    // kadanesalo(&v);
    // cout<<x;

    return 0;
}



// ******////...Merge Intervals



#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int s, e;
};

bool mycomp(Interval a, Interval b) { return a.s < b.s; }

void mergeIntervals(Interval arr[], int n)
{

    sort(arr, arr + n, mycomp);

    int index = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[index].e >= arr[i].s)
        {
            arr[index].e = max(arr[index].e, arr[i].e);
        }
        else
        {
            index++;
            arr[index] = arr[i];
        }
    }
    cout << "\n The Merhged Intervals are: ";
    for (int i = 0; i <= index; i++)
    {
        cout << "[" << arr[i].s << ", " << arr[i].e << "] "<<endl;
    }
}

int main()
{
    Interval arr[] = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}




// ******////...Next Permutation


#include <bits/stdc++.h>
using namespace std;

void nextpermutation(vector<int> &arr)
{
    int n = arr.size(), i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }
    if (i < 0)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
        }
        swap(arr[i], arr[j]);
        reverse(arr.begin() + i + 1, arr.end());
    }
}

int main()
{

    vector<int> arr = {1, 2, 3, 4, 6, 5, 4};
    nextpermutation(arr);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}



// *******////...Count Inversion


#include <bits/stdc++.h>
using namespace std;

int getInvCount(int arr[], int n)
{
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                inv_count++;
            }
        }
    }
    return inv_count;
}

int main()
{
    int arr[] = {1, 20, 6, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Number of inversion are " << getInvCount(arr, n);
    return 0;

    return 0;
}


#include <bits/stdc++.h>
using namespace std;

//******..find all pairs on integer array whose sum is equal to given number

int getcount(int arr[], int n, int k)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] + arr[j] == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 3, 5, 7, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << " enter the sum ";
    cin >> k;
    cout << " cout equal : " << getcount(arr, n, k);

    return 0;
}



// *******////....Rearrange the array in alternating positive and negative items with O(1) extra space


#include <bits/stdc++.h>
using namespace std;

int commonarray(int arr1[], int n1, int arr2[], int n2, int arr3[], int n3)
{
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2 && k < n3)
    {
        if (arr1[i] == arr2[j] && arr2[j] == arr3[k])
            cout << arr1[i] << " ";
        i++;
        j++;
        k++;
    }
    if (arr1[i] < arr2[j])
    {
        i++;
    }
    else if (arr2[j] < arr3[k])
    {
        j++;
    }
    else
    {
        k++;
    }
}

int main()
{
    int arr1[] = {1, 2, 4, 5, 6, 7};
    int arr2[] = {1, 2, 7, 8, 50};
    int arr3[] = {1, 2, 4, 5, 6, 7, 8, 9};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    commonarray(arr1, n1, arr2, n2, arr3, n3);

    return 0;
}




// ******//...Rearrange the array in alternating positive and negative items with O(1) extra space


#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> nn, int n)
{
    int p = 1, neg = 0;
    vector<int> nums(n, 0);
    for (auto val : nn)
    {
        if (val > 0)
        {
            nums[p] = val;
            p += 2;
        }
        if (val < 0)
        {
            nums[neg] = val;
            neg += 2;
        }
    }
    for (int value : nums)
    {
        cout << value << " ";
    }
}

int main()
{

    vector<int> nn = {-1, -3, -2, -6, 1, 5, 4, 3};
    int n = nn.size();
    arrange(nn, n);

    return 0;
}




// ******//...Rearrange the array in alternating positive and negative items with O(1) extra space


#include <bits/stdc++.h>
using namespace std;

void arrange(vector<int> nn, int n)
{
    int p = 1, neg = 0;
    vector<int> nums(n, 0);
    for (auto val : nn)
    {
        if (val > 0)
        {
            nums[p] = val;
            p += 2;
        }
        if (val < 0)
        {
            nums[neg] = val;
            neg += 2;
        }
    }
    for (int value : nums)
    {
        cout << value << " ";
    }
}

int main()
{

    vector<int> nn = {-1, -3, -2, -6, 1, 5, 4, 3};
    int n = nn.size();
    arrange(nn, n);

    return 0;
}



// ******////Find if there is any subarray with sum equal to 0

#include <bits/stdc++.h>
using namespace std;

bool subexist(int arr[], int n)
{
    unordered_set<int> sumset;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || sumset.find(sum) != sumset.end())
            return true;

        sumset.insert(sum);
    }
    return false;
}

int main()
{

    int arr[] = {-3, 2, 3, 1, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subexist(arr, n))
    {
        cout << "found a subarray with 0 sum";
    }
    else
    {
        cout << "No such sub Array Exists!";
    }

    return 0;
}




// ******/////...Find factorial of a large number

#include <bits/stdc++.h>
using namespace std;
#define MAX 500

int multiply(int x, int res[], int rs);

void factorial(int n)
{
    int res[MAX];
    res[0] = 1;
    int rs = 1;
    for (int x = 2; x <= n; x++)
    {
        rs = multiply(x, res, rs);
    }
    cout << "Factorial of given number is \n";
    for (int i = rs - 1; i >= 0; i--)
    {
        cout << res[i];
    }
}

int multiply(int x, int res[], int rs)
{
    int carry = 0;
    for (int i = 0; i < rs; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }
    while (carry)
    {
        res[rs] = carry % 10;
        carry = carry / 10;
        rs++;
    }
    return rs;
}

int main()
{
    int n;
    cout << "enter the number: ";
    cin >> n;
    factorial(n);

    return 0;
}








// *******////....find maximum product subarray

#include <bits/stdc++.h>
using namespace std;

int maxproduct(vector<int> &nums)
{
    int curr_product = 1, res = INT_MAX;
    for (auto i : nums)
    {
        curr_product *= i;
        res = max(curr_product, res);
        if (curr_product == 0)
        {
            curr_product = 1;
        }
    }
    curr_product = 1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        curr_product = curr_product * nums[i];
        res = max(curr_product, res);
        if (curr_product == 0)
        {
            curr_product = 1;
        }
    }
    return res;
}

int main()
{
    vector<int> nums = {2,3,-2,4};
    cout << maxproduct(nums);

    return 0;
}





// ********//////...Find longest coinsecutive subsequence

#include <bits/stdc++.h>
using namespace std;

int longestcoinsub(int arr[], int n)
{
    int ans = 0, count = 0;
    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            v.push_back(arr[i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i > 0 && v[i] == v[i - 1] + 1)
        {
            count++;
        }
        else
        {
            count = 1;
        }
        ans = max(ans, count);
    }
    return ans;
}
int main()
{
    int arr[] = {1, 2, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Find longest coinsecutive subsequence : " << longestcoinsub(arr, n);

    return 0;
}





// ********////....Given an array of size n and a number k, fin all elements that appear more than " n/k " times.

#include <bits/stdc++.h>
using namespace std;

void morethannbyk(int arr[], int n, int k)
{
    int x = n / k;
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    for (auto i : freq)
    {
        if (i.second > x)
        {
            cout << i.first << endl;
        }
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    morethannbyk(arr, n, k);

    return 0;
}




// *******////..Find whether an array is a subset of another array

#include <bits/stdc++.h>
using namespace std;

bool subarrset(int arr1[], int n, int arr2[], int m)
{
    set<int> hashset;
    for (int i = 0; i < n; i++)
    {
        hashset.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        if (hashset.find(arr2[i]) == hashset.end())
        {
            return false;
        }
        return true;
    }
}

int main()
{
    int arr1[] = {11,1,13,21,3,7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {11,3,7,1};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    if (subarrset(arr1, n, arr2, m))
    {
        cout << "it subarray ";
    }
    else
    {
        cout << " false :";
    }

    return 0;
}



// *******//////...Find the triplet that sum to a given value

#include <bits/stdc++.h>
using namespace std;
bool findtriplet(int arr[], int m, int sum)
{
    for (int i = 0; i < m - 2; i++)
    {
        for (int j = i + 1; j < m - 1; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                {
                    cout << "triplet is " << arr[i] << ", " << arr[j] << ", " << arr[k] << " = " << sum;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{

    int arr[] = {1, 4, 45, 6, 10, 8};
    int m = sizeof(arr) / sizeof(arr[0]);
    int c;
    cin >> c;
    if (findtriplet(arr, m, c))
    {
    }
    else
    {
        cout << "not find:";
    }
}



// ******/////....Trapping Rain water problem

#include <bits/stdc++.h>
using namespace std;

int trappingwater(int arr[], int n)
{
    int lmax[n];
    lmax[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        int temp = max(arr[i], lmax[i - 1]);
        lmax[i] = temp;
    }
    int rmax[n];
    rmax[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = max(arr[i], rmax[i + 1]);
        rmax[i] = temp;
    }
    int water;
    for (int i = 1; i < n - 1; i++)
    {
        water += min(lmax[i], rmax[i]) - arr[i];
    }
    return water;
}
int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int arr[]={3, 0, 2, 0, 4};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "trap water = " << trappingwater(arr, n);

    return 0;
}




// *******////...Chocolate Distribution problem


#include <bits/stdc++.h>
using namespace std;

int findmindiff(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    sort(arr, arr + n);
    if (n < m)
        return -1;
    int min = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < min)
            min = diff;
    }
    return min;
}
int main()
{
    int arr[] = {12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50};
    int m = 7;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Min diff " << findmindiff(arr, n, m);
    return 0;

    return 0;
}




// *******////...Smallest Subarray with sum greater than a given value

#include <bits/stdc++.h>
using namespace std;

void smallersubarraywithsum(int arr[], int n, int k)
{
    int sum = 0, minlenght = n + 1, start = 0, end = 0;
    while (end < n)
    {
        while (sum <= k && end < n)
        {
            sum += arr[end++];
        }
        while (sum > k && start < n)
        {
            if (end - start < minlenght)
            {
                minlenght = end - start;
            }
            sum -= arr[start++];
        }
    }
    cout << minlenght;
    // return minlenght;
}

int mian()
{
    int arr[] = {1, 4, 45, 6, 10, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cin >> k;
    smallersubarraywithsum(arr, n, k);
    // if (x == x)
    // {
    //     cout << x;
    // }
    // else
    // {
    //     cout << "its not possible";
    // }

    return 0;
}





// ******////..Three way partitioning of an array around a given value

#include <bits/stdc++.h>
using namespace std;

void threewaypartition(int arr[], int n, int lowval, int highval)
{
    int start = 0, end = n - 1;
    for (int i = 0; i <= end;)
    {
        if (arr[i] < lowval)
        {
            if (i == start)
            {
                start++;
                i++;
            }
            else
            {
                swap(arr[i++], arr[start++]);
            }
        }
        else if (arr[i] > highval)
        {
            swap(arr[i], arr[end--]);
        }
        else
            i++;
    }
}

int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr) / sizeof(arr[0]);
    threewaypartition(arr, n, 10, 20);
    cout << " Modified array \n";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}






// ********/////....Minimum swaps required bring elements less equal K together

#include <bits/stdc++.h>
using namespace std;

int minswap(int *arr, int n, int k)
{

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
            ++count;
    }
    int bad = 0;
    for (int i = 0; i < count; ++i)
    {
        if (arr[i] > k)
        {
            ++bad;
        }
    }
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {
        if (arr[i] > k)
        {
            --bad;
        }
        if (arr[j] > k)
        {
            ++bad;
        }
        ans = min(ans, bad);
    }
    return ans;
}

int main()
{

    int arr[] = {2, 1, 5, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << minswap(arr, n, k) << "\n";

    int arr1[] = {2, 7, 9, 5, 8, 7, 4};
    n = sizeof(arr1) / sizeof(arr1[0]);
    k = 5;
    cout << minswap(arr1, n, k);

    return 0;
}





// ******/////...Minimum no. of operations required to make an array palindrome

#include <bits/stdc++.h>
using namespace std;
bool isplindrome(int N)
{
    string str = " " + N;
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        if (str[i] != str[len - 1 - i])
            return false;
    }
    return true;
}

bool isPalinArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        bool ans = isplindrome(arr[i]);
        if (ans == false)
            return false;
    }
    return true;
}

int main()
{
    // int arr[] = {121, 131, 20};
    int arr[]={111, 121, 222, 333, 444};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool res = isPalinArray(arr, n);
    if (res == true)
    {
        cout << "Array is palimarray";
    }
    else
    {
        cout << "Array is  not a palinArray";
    }

    return 0;
}






// *******////...Minimum no. of operations required to make an array palindrome

#include <bits/stdc++.h>
using namespace std;
double getMedian(int ar1[], int ar2[], int n)
{
    int i = 0; 
            
    int j = 0; 
    int count;
    int m1 = -1, m2 = -1;

    for (count = 0; count <= n; count++) {
       
        if (i == n) {
            m1 = m2;
            m2 = ar2[0];
            break;
        }


        else if (j == n) {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
       
        if (ar1[i] <= ar2[j]) {
        
            m1 = m2;
            m2 = ar1[i];
            i++;
        }
        else {
          
            m1 = m2;
            m2 = ar2[j];
            j++;
        }
    }

    return (1.0 * (m1 + m2)) / 2;
}


int main()
{
    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};

    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
        cout << "Median is " << getMedian(ar1, ar2, n1);
    else
        cout << "Doesn't work for arrays"
             << " of unequal size";
    getchar();
    return 0;
}





// *******/////.Median of 2 sorted arrays of different size

#include <bits/stdc++.h>
using namespace std;

int Solution(int arr[], int n)
{

    if (n % 2 == 0)
    {
        int z = n / 2;
        int e = arr[z];
        int q = arr[z - 1];
        int ans = (e + q) / 2;
        return ans;
    }
    else
    {
        int z = round(n / 2);
        return arr[z];
    }
}

int main()
{

    int arr1[] = {-5, 3, 6, 12, 15};
    int arr2[] = {-12, -10, -6, -3, 4, 10};

    int i = sizeof(arr1) / sizeof(arr1[0]);
    int j = sizeof(arr2) / sizeof(arr2[0]);

    int arr3[i + j];
    int l = i + j;
    for (int k = 0; k < i; k++)
    {
        arr3[k] = arr1[k];
    }

    int a = 0;
    for (int k = i; k < l; k++)
    {
        arr3[k] = arr2[a++];
    }

    sort(arr3, arr3 + l);

    cout << "Median = " << Solution(arr3, l);
}














