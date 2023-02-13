// ********///...1..Reverse a String



#include <bits/stdc++.h>
using namespace std;

void reverse(string &str)
{
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        swap(str[i++], str[j--]);
    }
}

int main()
{
    string str = "ranjan singh";
    reverse(str);
    cout << str;

    return 0;
}





// *******///...2..Palindrome String
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "acbbca";
    int i = 0, j = str.size() - 1;
    while (i < j)
    {
        if (str[i++] != str[j--])
        {
            cout << "its not palindrome : ";
            return 0;
        }
    }
    cout << "its a palindrome : " << str;

    return 0;
}


// ********////...4..Why strings are immutable in Java?
./*
Why String is Immutable or Final in Java
In object-oriented programming, the immutable string or objects that cannot be modified once it is created. But we can only change the
 reference to the object. We restrict to change the object itself. The String is immutable in Java because of the security, synchronization
  and concurrency, caching, and class loading. The reason of making string final is to destroy the immutability and to not allow others 
  to extend it.
The String objects are cached in the String pool, and it makes the String immutable. The cached String literals are accessed by multiple 
clients. So, there is always a risk, where action performs by one client affects all other clients. For example, if one client performs 
an action and changes the string value from Pressure to PRESSURE, all remaining clients will also read that value. For the performance reason,
 caching of String objects was important, so to remove that risk, we have to make the String Immutable.
 
These are some more reasons of making String immutable:
o	The String pool cannot be possible if String is not immutable in Java. A lot of heap space is saved by JRE. The same string variable 
can be referred to by more than one string variable in the pool. String interning can also not be possible if the 
String would not be immutable.
o	If we don't make the String immutable, it will pose a serious security threat to the application. 
For example, database usernames, passwords are passed as strings to receive database connections. 
The socket programming host and port descriptions are also passed as strings. 
The String is immutable, so its value cannot be changed. 
If the String doesn't remain immutable, any hacker can cause a security issue in the application by changing the reference value.
o	The String is safe for multithreading because of its immutableness. 
Different threads can access a single "String instance". 
It removes the synchronization for thread safety because we make strings thread-safe implicitly.
o	Immutability gives the security of loading the correct class by Classloader. For example, suppose we have an instance where we try to load java.sql.Connection class but the changes in the referenced value to the myhacked.Connection class does unwanted things to our database.
Let's understand the concept of immutable through an example.
ImmutableString.java
1.	import java.util.*;
2. class ImmutableString
{
    3. public static void main(String args[])
    {
        4. String NewString = "Hello";
        5. NewString.concat("World");
        6. System.out.println(NewString);
        7.
    }
    8.
} Output :

    Description : We can understand the above example with the help of the following diagram :

    In the string constant pool,
    the Hello remains unchanged,
    and a new string object is created with HelloWorld.It shows that the strings are immutable.The reference variable points to the Hello not to the HelloWorld.If we want that it refers to the HelloWorld,
    we have to explicitly assign it to that variable.For example : 1. import java.util.*
    ;
2. class ImmutableString
{
    3. public static void main(String args[])
    {
        4. String NewString = "Hello";
        5. NewString = NewString.concat("World");
        6. System.out.println(NewString);
        7.
    }
    8.
} Output:
*/


//*******...3..Find Duplicate characters in a string

#include <bits/stdc++.h>
using namespace std;

void finduplicate(string &str)
{
    int s = str.size();
    map<char, int> mp;
    for (int i = 0; i < s; i++)
    {
        mp[str[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            cout << it.first << " count = " << it.second << endl;
        }
    }
}

int main()
{

    string str = "RRRGGGFGFHGHGH";
    finduplicate(str);
    return 0;
}



// ******///...5..Write a Code to check whether one string is a rotation of another

#include <bits/stdc++.h>
using namespace std;

bool stringrotation(string s, string goal)
{
    if (s.length() != goal.length())
        return 0;

    string str = s + s;
    size_t found = str.find(goal);
    if (found != string::npos)
        return true;
    else
        return false;
}

int main()
{
    string s = "abede";
    string goal = "cdeab";
    if (stringrotation(s, goal))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }

    return 0;
}



//******...6..Write a Program to check whether a string is a valid shuffle of two strings or not

#include <bits/stdc++.h>
using namespace std;

bool isshuffled(string a, string b)
{
    int n = a.length();
    int m = b.length();
    if (n > m)
    {
        return false;
    }
    else
    {
        sort(a.begin(), a.end());
        for (int i = 0; i < m; i++)
        {
            if (i + n - 1 >= m)
                return false;
            string str = "";
            for (int j = 0; j < n; j++)
            {
                str.push_back(b[i + j]);
            }
            sort(str.begin(), str.end());
            if (str == a)
            {
                return true;
            }
        }
    }
}

int main()
{
    string str1 = "geekforgeeks";
    string str2 = "ekegorfkeegsgeek";
    if (isshuffled(str1, str2))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;

    return 0;
}





//*******...7..Count and Say problem

#include <bits/stdc++.h>
using namespace std;

string countAndSay(int n)
{
    if (n == 1)
    {
        return "1";
    }
    string say = countAndSay(n - 1) + "#";
    int cnt = 1;
    char cur = say[0];
    string res = "";
    for (int i = 1; i < say.length(); i++)
    {
        if (cur != say[i])
        {
            res += (to_string(cnt) + cur);
            cnt = 1;
            cur = say[i];
        }
        else
        {
            cnt++;
        }
    }
    return res;
}

int main()
{
    int N = 3;
    cout << countAndSay(N) << endl;

    return 0;
}



//*******...8..Write a program to find the longest Palindrome in a string.[ Longest palindromic Substring]

#include <bits/stdc++.h>
using namespace std;
void printsubstring(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
    {
        cout << str[i];
    }
}

int longestpal(string str)
{
    int n = str.size();
    int maxlenght = 1, start = 0;
    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            int flag = 1;
            for (int k = 0; k < (j - i + 1) / 2; k++)
            {
                if (str[i + k] != str[j - k])
                {
                    flag = 0;
                }
                if (flag && (j - i + 1) > maxlenght)
                {
                    start = i;
                    maxlenght = j - i + 1;
                }
            }
        }
    }
    cout << "longest palindrome substring is: ";
    printsubstring(str, start, start + maxlenght - 1);
    return maxlenght;
}
int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestpal(str);

    return 0;
}


// ******...9..Find Longest Recurring Subsequence in String

// #include <bits/stdc++.h>
// using namespace std;

// int repicningstroing(string s)
// {
//     vector<int> dict(256, -1);
//     int maxlen = 0, start = -1;
//     for (int i = 0; i < s.size(); i++)
//     {
//         if (dict[s[i]] > start)
//             start = dict[s[i]];
//         dict[s[i]] = i;
//         maxlen = max(maxlen, i - start);
//     }
//     return maxlen;
// }

// int characterReplacement(string s,int k)
// {
//     map<char, int> m; // storing characters  and their count
//     int l = 0, max_Occurance = 0, res = 0;

//     for (int i = 0; i < s.size(); i++)
//     {

//         m[s[i]]++;                                   // adding value to map
//         max_Occurance = max(max_Occurance, m[s[i]]); // updating the maximum occuring element

//         if (i - l + 1 - max_Occurance > k)
//         {              // if we get more operations in sliding window (invalid)
//             m[s[l]]--; // decreasing count from map
//             l++;       // increment  previous pointer
//         }
//         else
//             res = max(res, i - l + 1); // update result
//     }
//     return res;
// }

// int main()
// {
//     string s;
//     cin >> s;
//     cout << characterReplacement(s,3);

//     return 0;
// }




// A C++ solution for longest palindrome
#include <bits/stdc++.h>
using namespace std;

// Function to print a substring str[low..high]
void printSubStr(string str, int low, int high)
{
	for (int i = low; i <= high; ++i)
		cout << str[i];
}

// This function prints the
// longest palindrome substring
// It also returns the length
// of the longest palindrome
int longestPalSubstr(string str)
{
	// get length of input string
	int n = str.size();

	// All substrings of length 1
	// are palindromes
	int maxLength = 1, start = 0;

	// Nested loop to mark start and end index
	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			int flag = 1;

			// Check palindrome
			for (int k = 0; k < (j - i + 1) / 2; k++)
				if (str[i + k] != str[j - k])
					flag = 0;

			// Palindrome
			if (flag && (j - i + 1) > maxLength) {
				start = i;
				maxLength = j - i + 1;
			}
		}
	}

	cout << "Longest palindrome substring is: ";
	printSubStr(str, start, start + maxLength - 1);

	// return length of LPS
	return maxLength;
}

// Driver Code
int main()
{
	string str = "forgeeksskeegfor";
	cout << "\nLength is: "
		<< longestPalSubstr(str);
	return 0;
}



// ***...10...Print all Subsequences of a string.

#include <bits/stdc++.h>
using namespace std;

unordered_set<string> st;

void subsequence(string str)
{

    for (int i = 0; i < str.length(); i++)
    {

        for (int j = str.length(); j > i; j--)
        {
            string sub_str = str.substr(i, j);
            st.insert(sub_str);

            for (int k = 1; k < sub_str.length(); k++)
            {
                string sb = sub_str;

                sb.erase(sb.begin() + k);
                subsequence(sb);
            }
        }
    }
}

// Driver Code
int main()
{
    string s = "aabc";
    subsequence(s);
    for (auto i : st)
        cout << i << " ";
    cout << endl;

    return 0;
}



// ***...11...Print all the permutations of the given string

#include <bits/stdc++.h>
using namespace std;

void permute(string &a, int l, int r)
{
    // Base case
    if (l == r)
        cout << a << endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {

            // Swapping done
            swap(a[l], a[i]);

            // Recursion called
            permute(a, l + 1, r);

            // backtrack
            swap(a[l], a[i]);
        }
    }
}

// Driver Code
int main()
{
    string str = "ABC";
    int n = str.size();

    // Function call
    permute(str, 0, n - 1);
    return 0;
}



// ***...12...Split the Binary string into two substring with equal 0’s and 1’s

#include <bits/stdc++.h>
using namespace std;

int maxSubStr(string str, int n)
{

    int count0 = 0, count1 = 0;

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0')
        {
            count0++;
        }
        else
        {
            count1++;
        }
        if (count0 == count1)
        {
            cnt++;
        }
    }

    // It is not possible to
    // split the string
    if (count0 != count1)
    {
        return -1;
    }

    return cnt;
}

// Driver code
int main()
{
    string str = "0100110101";
    int n = str.length();

    cout << maxSubStr(str, n);

    return 0;
}



// ***...13....Word Wrap Problem [VERY IMP].

#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int printSolution(int p[], int n);

void solveWordWrap(int l[], int n, int M)
{

    int extras[n + 1][n + 1];

    int lc[n + 1][n + 1];

    int c[n + 1];

    int p[n + 1];

    int i, j;

    for (i = 1; i <= n; i++)
    {
        extras[i][i] = M - l[i - 1];
        for (j = i + 1; j <= n; j++)
            extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
    }

    for (i = 1; i <= n; i++)
    {
        for (j = i; j <= n; j++)
        {
            if (extras[i][j] < 0)
                lc[i][j] = INF;
            else if (j == n && extras[i][j] >= 0)
                lc[i][j] = 0;
            else
                lc[i][j] = extras[i][j] * extras[i][j];
        }
    }

    // Calculate minimum cost and find minimum cost arrangement.
    // The value c[j] indicates optimized cost to arrange words
    // from word number 1 to j.
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i - 1] != INF && lc[i][j] != INF &&
                (c[i - 1] + lc[i][j] < c[j]))
            {
                c[j] = c[i - 1] + lc[i][j];
                p[j] = i;
            }
        }
    }

    printSolution(p, n);
}

int printSolution(int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution(p, p[n] - 1) + 1;
    cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
    return k;
}

// Driver program to test above functions
int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l) / sizeof(l[0]);
    int M = 6;
    solveWordWrap(l, n, M);
    return 0;
}



// ***...14..EDIT Distance [Very Imp]

#include <bits/stdc++.h>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{

    int dp[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {

            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else if (str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];

            else
                dp[i][j] = 1 + min(dp[i][j - 1],      // Insert
                                   dp[i - 1][j],      // Remove
                                   dp[i - 1][j - 1]); // Replace
        }
    }

    return dp[m][n];
}

// Driver code
int main()
{
    // your code goes here
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(),
                       str2.length());

    return 0;
}







