//******..1..Find first and last positions of an element in a sorted array




#include <bits/stdc++.h>
using namespace std;

void farstlastposition(vector<int> nums, int t)
{
    int fast = -1, last = -1;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != t)
        {
            continue;
        }
        if (fast == -1)
        {
            fast = i;
        }
        last = i;
    }
    if (fast != -1 && last != fast)
    {
        cout << fast << " , " << last;
    }
    else if (last == fast && fast >= 0)
    {
        cout << fast;
    }
    else
    {
        cout << "not found : ";
    }
}

int main()
{
    vector<int> v = {1, 2, 2, 2, 2, 3, 4, 7, 8, 8};
    cout << " input ";
    int c;
    cin >> c;
    farstlastposition(v, c);

    return 0;
}



// *****...2..Find a Fixed Point (Value equal to index) in a given array

#include <bits/stdc++.h>
using namespace std;

void fixedpoint(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == (i + 1))
        {
            cout << " index " << (i + 1) << " value = " << arr[i];
            break;
        }
    }
}

int main()
{
    vector<int> arr = {3, 23, 45, 4, 87};
    fixedpoint(arr);

    return 0;
}



// *****...3..Search in a rotated sorted array

#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int low, int high, int key)
{
    if (high < low)
        return -1;

    int mid = (low + high) / 2;
    if (key == arr[mid])
        return mid;

    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);

    return binarySearch(arr, low, (mid - 1), key);
}

int findPivot(int arr[], int low, int high)
{

    if (high < low)
        return -1;
    if (high == low)
        return low;

    int mid = (low + high) / 2;
    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;

    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);

    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);

    return findPivot(arr, mid + 1, high);
}

int pivotedBinarySearch(int arr[], int n, int key)
{
    int pivot = findPivot(arr, 0, n - 1);

    if (pivot == -1)
        return binarySearch(arr, 0, n - 1, key);

    if (arr[pivot] == key)
        return pivot;

    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);

    return binarySearch(arr, pivot + 1, n - 1, key);
}

int main()
{

    int arr1[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int key;
    cin >> key;

    cout << "Index of the element is : "
         << pivotedBinarySearch(arr1, n, key);

    return 0;
}




// ****...4..square root of an integer


#include <bits/stdc++.h>
using namespace std;

int countSquares(int x)
{
    int sqr = sqrt(x);
    int result = (int)(sqr);
    return result;
}
int main()
{

    int x;
    cin >> x;
    cout << (countSquares(x));

    return 0;
}




// ****...5..Maximum and minimum of an array using minimum number of comparisons
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1000, 11, 445, 330, 3000};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_val = 0;
    int min_val = arr[0];
    for (int i = 0; i < n; i++)
    {
        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }
    cout << "max val = " << max_val << endl
         << "min val = " << min_val;

    return 0;
}




// ****...7..Find the repeating and the missing

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    unordered_map<int, bool> nums;
    for (int i : arr)
    {
        if (nums.find(i) == nums.end())
        {
            nums[i] = true;
        }
        else
        {
            cout << "Repeating = " << i;
        }
    }
    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        if (nums.find(i) == nums.end())
        {
            cout << "Missing = " << i;
        }
    }

    return 0;
}




// ***...8..find majority element
#include <bits/stdc++.h>
using namespace std;

int find(int arr[], int n)
{
    int max_count = 0;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            index = i;
        }
    }
    if (max_count > n / 2)
    {
        cout << "majority array : " << arr[index];
    }
    else
    {
        cout << "not  majority array";
    }
}

int main()
{

    int arr[] = {1, 1, 2, 1, 3, 5, 1,5,5,5,5,5,5,5,5,5,5,5,5,};
    int n = sizeof(arr) / sizeof(arr[0]);

    find(arr, n);

    return 0;
}



// ***...9..Searching in an array where adjacent differ by at most k

#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int n, int x, int k)
{
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }
        i = i + max(1, abs(x - arr[i]) / k);
    }
    cout << "not found : ";
    return -1;
}

int main()
{
    int arr[] = {2, 4, 5, 7, 7, 6};
    int x;
    int k;
    cout << "enter x and k : ";
    cin >> x >> k;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Element " << x << " is present at index "
         << search(arr, n, x, k);

    return 0;
}


// ***...10..find a pair with a given difference
#include <bits/stdc++.h>
using namespace std;

void search(int arr[], int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (abs(arr[i] - arr[j]) == x)
            {
                count++;
                cout << arr[i] << " , " << arr[j] << endl;
            }
        }
    }
    if (count > 0)
    {
        cout << count;
    }
    else
    {
        cout << "not found : ";
    }
}

int main()
{
    int arr[] = {5, 20, 3, 2, 17, 80};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    cout << "enter element : ";
    cin >> x;
    search(arr, n, x);

    return 0;
}



// ***...12..Stickler Thief
#include <bits/stdc++.h>
using namespace std;

int findmaxmoney(int *arr, int n)
{
    if (n == 0)
        return 0;
    int val1 = arr[0];
    if (n == 1)
    {
        return val1;
    }
    int val2;
    val2 = max(arr[0], arr[1]);
    if (n == 2)
    {
        return val2;
    }
    int max_val;
    for (int i = 2; i < n; i++)
    {
        max_val = max(arr[i] + val1, val2);
        val1 = val2;
        val2 = max_val;
    }

    return max_val;
}

int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "max money is : " << findmaxmoney(arr, n);

    return 0;
}



// ***...13..Count triplet with sum smaller than a given value

#include <bits/stdc++.h>
using namespace std;
int searchcount(int arr[], int n, int sum)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = 2; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == sum)
                    count++;
            }
        }
    }
    return count;
    
}

int main()
{
    // int arr[] = {5, 1, 3, 4, 7};
    int arr[]={-2, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 2;
    cout << "max count : " << searchcount(arr, n, sum);

    return 0;
}




// ***...14..merge 2 sorted arrays
#include <bits/stdc++.h>
using namespace std;

void margesortedarray(int arr1[], int arr2[], int n1, int n2)
{
    vector<int> v;
    for (int i = 0; i < n1; i++)
    {
        v.push_back(arr1[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        v.push_back(arr2[i]);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 4, 6, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    margesortedarray(arr1, arr2, n1, n2);

    return 0;
}



// ***...15..print all subarrays with 0 sum
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findarray(int arr[], int n)
{
    vector<pair<int, int>> va;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == 0)
            {
                va.push_back({i, j});
            }
        }
    }
    return va;
}
void display(vector<pair<int, int>> va)
{
    for (auto it = va.begin(); it != va.end(); it++)
    {
        cout << "Subarray found from Index " << it->first
             << " to " << it->second << endl;
    }
}

int main()
{
    int arr[] = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function Call
    vector<pair<int, int>> output = findarray(arr, n);

    // if we didn’t find any subarray with 0 sum,
    // then subarray doesn’t exists
    if (output.size() == 0)
    {
        cout << "No subarray exists";
    }
    else
    {
        display(output);
    }
    return 0;
}



// ***...16...Product array Puzzle
#include <bits/stdc++.h>
using namespace std;

void findarray(int arr[], int n)
{
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int pro = 1;
        for (int j = 0; j < n; j++)

        {
            if (i == j)
                continue;
            pro = pro * arr[j];
        }

        v.push_back(abs(pro));
    }
    for (auto it : v)
    {
        cout << it << " ";
    }
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    // cout << n;
    findarray(arr, n);

    return 0;
}




// ***...17..Sort array according to count of set bits
#include <bits/stdc++.h>
using namespace std;

int setBitCount(int num)
{
    int count = 0;
    while (num)
    {
        if (num & 1)
            count++;
        num >>= 1;
    }
    return count;
}

void sortBySetBitCount(int arr[], int n)
{
    multimap<int, int> count;
    for (int i = 0; i < n; ++i)
    {
        count.insert({(-1) *
                          setBitCount(arr[i]),
                      arr[i]});
    }

    for (auto i : count)
        cout << i.second << " ";
    cout << "\n";
}

int main()
{

    int arr[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    sortBySetBitCount(arr, n);

    return 0;
}



// ***...18...minimum no. of swaps required to sort the array

#include <bits/stdc++.h>
using namespace std;

int minSwaps(int arr[], int n)
{

    pair<int, int> arrPos[n];
    for (int i = 0; i < n; i++)
    {
        arrPos[i].first = arr[i];
        arrPos[i].second = i;
    }

    sort(arrPos, arrPos + n);

    vector<bool> vis(n, false);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {

        if (vis[i] || arrPos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;
        while (!vis[j])
        {
            vis[j] = 1;

            j = arrPos[j].second;
            cycle_size++;
        }

        if (cycle_size > 0)
        {
            ans += (cycle_size - 1);
        }
    }

    return ans;
}

int main()
{
    int arr[] = {1, 5, 4, 3, 2};
    int n = (sizeof(arr) / sizeof(int));
    cout << minSwaps(arr, n);
    return 0;
}



// ***...19..Bishu and Soldiers

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    sort(A, A + n);
    int q;
    cin >> q;
    int power;
    for (int j = 0; j < q; j++)
    {
        cin >> power;
        int i = 0;
        int count = 0, sum = 0;
        while (A[i] <= power && i < n)
        {
            count++;
            sum += A[i];
            i++;
        }
        cout << count << " " << sum << endl;
    }
    return 0;
}



// ***...21...Kth smallest number again

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &range)
{
    int n = range.size();
    vector<vector<int>> fin;
    for (int i = 0; i < n - 1; i++)
    {
        if (range[i][1] >= range[i + 1][0])
        {
            range[i + 1][0] = min(range[i][0], range[i + 1][0]);
            range[i + 1][1] = max(range[i][1], range[i + 1][1]);
        }
        else
        {
            fin.push_back(range[i]);
        }
    }
    fin.push_back(range[n - 1]);
    return fin;
}

vector<int> kthSmallestNum(vector<vector<int>> &range, vector<int> queries)
{

    // sort the ranges
    sort(range.begin(), range.end());

    // merge the overlapping intervals
    vector<vector<int>> merged = mergeIntervals(range);

    // set to store the cumulative sum of number of elements in each range
    // eg {1 4} {6 8} {9 10} would store {4 7 9} in set.
    set<int> s;
    int cumsum = 0;
    for (auto cur_range : merged)
    {
        int num_ele = cur_range[1] - cur_range[0] + 1;
        cumsum += num_ele;
        s.insert(cumsum);
    }

    // final vector to store the result of each query
    vector<int> fin;

    // for each query get the lower bound of required kth smallest element.
    //  go to the index returned by lower_bound and get the required element
    for (auto q : queries)
    {
        auto it = s.lower_bound(q);
        if (it == s.end())
            fin.push_back(-1);

        // if the required element is in first range
        else if (it == s.begin())
        {
            fin.push_back(merged[0][0] + q - 1);
        }

        // if the required element is in ith range. then discard previous range elements
        //  if previous elements are prevele. then look for k=q-prevele in the current range
        else
        {
            int prevele = *prev(it);
            int kth = q - prevele;
            int idx = distance(s.begin(), it);
            fin.push_back(merged[idx][0] + kth - 1);
        }
    }

    return fin;
}

// Driver\'s Function
int main()
{
    vector<vector<int>> range = {{1, 4}, {6, 8}};
    int n = range.size();
    vector<int> queries = {2, 6, 10};
    int q = queries.size();

    vector<int> ans = kthSmallestNum(range, queries);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}



// ***...22..Find pivot element in a sorted array
#include <bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int h, int key)
{
    if (l > h)
        return -1;

    int mid = (l + h) / 2;
    if (arr[mid] == key)
        return mid;

    /* If arr[l...mid] is sorted */
    if (arr[l] <= arr[mid])
    {
        /* As this subarray is sorted, we can quickly
        check if key lies in half or other half */
        if (key >= arr[l] && key <= arr[mid])
            return search(arr, l, mid - 1, key);
        /*If key not lies in first half subarray,
        Divide other half into two subarrays,
        such that we can quickly check if key lies
        in other half */
        return search(arr, mid + 1, h, key);
    }

    /* If arr[l..mid] first subarray is not sorted, then
    arr[mid... h] must be sorted subarray */
    if (key >= arr[mid] && key <= arr[h])
        return search(arr, mid + 1, h, key);

    return search(arr, l, mid - 1, key);
}

// Driver program
int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    int i = search(arr, 0, n - 1, key);

    if (i != -1)
        cout << "Index: " << i << endl;
    else
        cout << "Key not found";
}




// ***...23.. Program to find kth element from two sorted arrays

#include <iostream>
using namespace std;

int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    while (i < m)
        sorted1[d++] = arr1[i++];
    while (j < n)
        sorted1[d++] = arr2[j++];
    return sorted1[k - 1];
}

// Driver Code
int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    int k = 5;
    cout << kth(arr1, arr2, 5, 4, k);
    return 0;
}


// ***...24...Aggressive cows
#include <bits/stdc++.h>
using namespace std;

// Function to check if it is possible
// to position the cow x distance apart
bool ok(vector<int> &v, int x, int c)
{
    int n = v.size();

    int count = 1;
    int d = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] - d >= x)
        {
            d = v[i];
            count++;
        }
        else
        {
            continue;
        }
    }
    if (count >= c)
    {
        return true;
    }
    return false;
}

int aggressive_cows(vector<int> &v, int n, int k)
{

    int l = 1;
    int r = 1e9;
    int ans = -1;

    while (r >= l)
    {
        int mid = l + (r - l) / 2;
        if (ok(v, mid, k))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int K = 3;
    vector<int> v = {1, 5, 1, 2, 8, 4, 9};

    int N = v.size();
    sort(v.begin(), v.end());

    int ans = aggressive_cows(v, N, K);
    cout << ans << endl;

    return 0;
}





// ***...25..Book Allocation Problem
// C++ program for optimal allocation of pages
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n, int m, int curr_min)
{
    int studentsRequired = 1;
    int curr_sum = 0;

    for (int i = 0; i < n; i++)
    {

        if (arr[i] > curr_min)
            return false;

        if (curr_sum + arr[i] > curr_min)
        {
            studentsRequired++;

            curr_sum = arr[i];

            if (studentsRequired > m)
                return false;
        }

        else
            curr_sum += arr[i];
    }
    return true;
}

int findPages(int arr[], int n, int m)
{
    long long sum = 0;

    if (n < m)
        return -1;
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        mx = max(mx, INT_MIN);
    }

    int start = mx, end = sum;
    int result = INT_MAX;

    while (start <= end)
    {

        int mid = (start + end) / 2;
        if (isPossible(arr, n, m, mid))
        {

            result = mid;

            end = mid - 1;
        }

        else

            start = mid + 1;
    }

    return result;
}

// Drivers code
int main()
{
    // Number of pages in books
    int arr[] = {12, 34, 67, 90};
    int n = sizeof arr / sizeof arr[0];
    int m = 2; // No. of students

    cout << "Minimum number of pages = "
         << findPages(arr, n, m) << endl;
    return 0;
}





// ***...26..EKOSPOJ
#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int bsearch(int a[], int n, int k)
{
    int lo;
    int hi;
    int mid;
    int i;
    long long int count;
    lo = 1;
    hi = a[n - 1];

    while (lo < hi)
    {
        mid = lo + (hi - lo + 1) / 2;
        count = 0;
        for (i = 0; i < n; i++)
        {
            if (a[i] > mid)
            {
                count = count + (a[i] - mid);
            }
        }

        if (count >= k)
        {
            lo = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }

    return lo;
}
int main()
{
    long long int k;
    int n;
    int t;

    int i;
    int ans;

    scanf("%d%lld", &n, &k);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    sort(a, a + n);

    ans = bsearch(a, n, k);

    printf("%d\n", ans);
}





























