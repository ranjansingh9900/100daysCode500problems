

// 1..*******/////....Spiral traversal on a Matrix



#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4
void print(int arr[R][C], int i, int j, int m, int n)
{
    if (i >= m or j >= n)
    {
        return;
    }
    for (int p = j; p < n; p++)
    {
        cout << arr[i][p] << " ";
    }
    for (int p = i + 1; p < m; p++)
    {
        cout << arr[p][n - 1] << " ";
    }
    if ((m - 1) != i)
    {
        for (int p = n - 2; p >= j; p--)
        {
            cout << arr[m - 1][p] << " ";
        }
    }
    if ((n - 1) != j)
    {
        for (int p = m - 2; p > i; p--)
        {
            cout << arr[p][j] << " ";
        }
    }
    print(arr, i + 1, j + 1, m - 1, n - 1);
}

int main()
{

    int arr[R][C] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    print(arr, 0, 0, R, C);

    return 0;
}





// 2..********/////....Search an element in a matriix

#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int r = 0, c = matrix[0].size() - 1;
    while (r < matrix.size() && c >= 0)
    {
        if (matrix[r][c] == target)
            return true;
        else if (matrix[r][c] < target)
            r++;
        else
            c--;
    }
    return false;
}

int main()
{
    vector<vector<int>> arr = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    int t;
    cin >> t;
    if (searchMatrix(arr, t))
    {
        cout << "element find = " << t;
    }
    else
    {
        cout << "not find";
    }

    return 0;
}




// *******/////...3.Find median in a row wise sorted matrix

#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

int binarymedian(int arr[][MAX], int r, int c)
{
    int min = INT_MAX, max = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        if (arr[i][0] < min)
            min = arr[i][0];
        if (arr[i][c - 1] > max)
            max = arr[i][c - 1];
    }
    int desired = (r * c + 1) / 2;
    int place = 0;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        for (int i = 0; i < r; ++i)
            place += upper_bound(arr[i], arr[i] + c, mid) - arr[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}

int main()
{
    int r = 3, c = 3;
    int arr[][MAX] = {{1, 3, 5}, {2, 6, 9}, {3, 7, 10}};
    cout << binarymedian(arr, r, c);
    return 0;
}




// *******/////...4.Find row with maximum no. of 1's

#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int rowwithmax1s(bool matrix[R][C])
{
    int row = -1;
    int countmax = 0;
    for (int i = 0; i < R; i++)
    {
        int count = 0;
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] == 1)
            {
                count++;
            }
        }
        if (count > countmax)
        {
            countmax == count;
            row = i;
        }
    }
    return row;
}

int main()
{
    bool matrix[R][C] = {{0, 1, 1, 1}, {0, 0, 1, 1}, {1, 1, 1, 1}, {0, 0, 0, 0}};
    cout << " Index of row with maximum 1s is : " << rowwithmax1s(matrix) << endl;

    return 0;
}


// *******/////..5..Print elements in sorted order using row-column wise sorted matrix
#include <bits/stdc++.h>
using namespace std;
#define R 4
#define C 4

void sortted(int arr[R][C], int r, int c)
{
    vector<int> nums;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            nums.push_back(arr[i][j]);
        }
    }
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

int main()
{
    int arr[R][C] = {{100, 200, 300, 400}, {15, 25, 35, 45}, {27, 29, 37, 48}, {32, 33, 39, 50}};
    sortted(arr, 4, 4);

    return 0;
}



// ******////..6...Maximum size rectangle

#include <bits/stdc++.h>
using namespace std;

#define R 4
#define C 4

int maxhisto(int row[])
{
    stack<int> res;
    int top;
    int max_area = 0;
    int area = 0;
    int i = 0;
    while (i < C)
    {
        if (res.empty() || row[res.top()] <= row[i])
        {
            res.push(i++);
        }
        else
        {
            top = row[res.top()];
            res.pop();
            area = top * i;
            if (!res.empty())
                area = top * (i - res.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!res.empty())
    {
        top = row[res.top()];
        res.pop();
        area = top * i;
        if (!res.empty())
        {
            area = top * (i - res.top() - 1);
        }
        max_area = max(area, max_area);
    }
    return max_area;
}

int maxrectangle(int arr[R][C])
{
    int res = maxhisto(arr[0]);
    for (int i = 1; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (arr[i][j])
            {
                arr[i][j] += arr[i - 1][j];
            }
        }
        res = max(res, maxhisto(arr[i]));
    }
    return res;
}

int main()
{
    int arr[R][C] = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};
    cout << "area of maximum restangke is " << maxrectangle(arr);

    return 0;
}





// *******////....7..Find a specific pair in matrix

#include <bits/stdc++.h>
using namespace std;
#define N 5

int findMaxValue(int mat[][N])
{

    int maxValue = INT_MIN;

    int maxArr[N][N];

    maxArr[N - 1][N - 1] = mat[N - 1][N - 1];

    int maxv = mat[N - 1][N - 1];
    for (int j = N - 2; j >= 0; j--)
    {
        if (mat[N - 1][j] > maxv)
            maxv = mat[N - 1][j];
        maxArr[N - 1][j] = maxv;
    }

    maxv = mat[N - 1][N - 1];
    for (int i = N - 2; i >= 0; i--)
    {
        if (mat[i][N - 1] > maxv)
            maxv = mat[i][N - 1];
        maxArr[i][N - 1] = maxv;
    }

    for (int i = N - 2; i >= 0; i--)
    {
        for (int j = N - 2; j >= 0; j--)
        {

            if (maxArr[i + 1][j + 1] - mat[i][j] >
                maxValue)
                maxValue = maxArr[i + 1][j + 1] - mat[i][j];

            maxArr[i][j] = max(mat[i][j],
                               max(maxArr[i][j + 1],
                                   maxArr[i + 1][j]));
        }
    }

    return maxValue;
}

int main()
{
    int mat[N][N] = {
        {1, 2, -1, -4, -20},
        {-8, -3, 4, 2, 1},
        {3, 8, 6, 1, 3},
        {-4, -1, 1, 7, -6},
        {0, -4, 10, -5, 1}};
    cout << "Maximum Value is "
         << findMaxValue(mat);

    return 0;
}







// ******/////...8..Rotate matrix by 90 degrees

#include <bits/stdc++.h>
using namespace std;
void rototematrix(vector<vector<int>> &matrix)
{
    int size = matrix.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size - i - 1; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[size - 1 - j][i];
            matrix[size - 1 - i][size - 1 - j] = matrix[j][size - 1 - i];
            matrix[j][size - 1 - i] = temp;
        }
    }
    int k = matrix.size();
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}


int main()
{

    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16}};
    rototematrix(matrix);

    return 0;
}



*******/////...9..Kth smallest element in a row-cpumn wise sorted matrix

#include <bits/stdc++.h>
using namespace std;

int kthpostion(vector<vector<int>> matrix, int k)
{
    vector<int> v;
    int size = matrix.size();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(), v.end());
    return v[k - 1];
}

int main()
{

    vector<vector<int>> matrix = {{10, 20, 30, 40}, {15, 25, 35, 45}, {25, 29, 37, 48}, {32, 33, 39, 50}};
    cout << "enter the kth position : ";
    int k;
    cin >> k;
    cout << k << "th elements is : " << kthpostion(matrix, k);

    return 0;
}







// *******////....10..Common elements in all rows of a given matrix

#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

void commimelements(int matrix[M][N])
{
    unordered_map<int, int> map;
    for (int j = 0; j < N; j++)
    {
        map[matrix[0][j]] = 1;
    }
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[matrix[i][j]] = i)
            {
                map[matrix[i][j]] = i + 1;
                if (i == M - 1 && map[matrix[i][j]] == M)
                    cout << matrix[i][j] << " ";
            }
        }
    }
}

int main()
{
    int matrix[M][N] = {{1, 2, 1, 4, 8}, {3, 7, 8, 5, 1}, {8, 7, 7, 3, 1}, {8, 1, 2, 7, 9}};

    commimelements(matrix);

    return 0;
}






