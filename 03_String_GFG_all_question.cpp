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



// 15...Find next greater number with same set of digits. [Very Very IMP]
#include <bits/stdc++.h>
using namespace std;

// Function to find the next permutation
void nextPermutation(vector<int>& arr)
{
	next_permutation(arr.begin(),arr.end());
}

// Driver code
int main()
{

	// Given input array
	vector<int> arr = { 1, 2, 3, 6, 5, 4 };

	// Function call
	nextPermutation(arr);

	// Printing the answer
	for (auto i : arr) {
		cout << i << " ";
	}

	return 0;
}



// 16...Balanced Parenthesis problem.[Imp]
// C++ program to check for balanced brackets.

#include <bits/stdc++.h>
using namespace std;

// Function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
	// Declare a stack to hold the previous brackets.
	stack<char> temp;
	for (int i = 0; i < expr.length(); i++) {
		if (temp.empty()) {
			
			// If the stack is empty
			// just push the current bracket
			temp.push(expr[i]);
		}
		else if ((temp.top() == '(' && expr[i] == ')')
				|| (temp.top() == '{' && expr[i] == '}')
				|| (temp.top() == '[' && expr[i] == ']')) {
			
			// If we found any complete pair of bracket
			// then pop
			temp.pop();
		}
		else {
			temp.push(expr[i]);
		}
	}
	if (temp.empty()) {
		
		// If stack is empty return true
		return true;
	}
	return false;
}

// Driver code
int main()
{
	string expr = "{()}[]";

	// Function call
	if (areBracketsBalanced(expr))
		cout << "Balanced";
	else
		cout << "Not Balanced";
	return 0;
}



// 17...Word break Problem[ Very Imp]

#include <iostream>
using namespace std;



int dictionaryContains(string word)
{
	string dictionary[] = {"mobile","samsung","sam","sung",
							"man","mango","icecream","and",
							"go","i","like","ice","cream"};
	int size = sizeof(dictionary)/sizeof(dictionary[0]);
	for (int i = 0; i < size; i++)
		if (dictionary[i].compare(word) == 0)
		return true;
	return false;
}

bool wordBreak(string str)
{
	int size = str.size();

	// Base case
	if (size == 0) return true;

	// Try all prefixes of lengths from 1 to size
	for (int i=1; i<=size; i++)
	{
		// The parameter for dictionaryContains is
		// str.substr(0, i) which is prefix (of input
		// string) of length 'i'. We first check whether
		// current prefix is in dictionary. Then we
		// recursively check for remaining string
		// str.substr(i, size-i) which is suffix of
		// length size-i
		if (dictionaryContains( str.substr(0, i) ) &&
			wordBreak( str.substr(i, size-i) ))
			return true;
	}

	// If we have tried all prefixes and
	// none of them worked
	return false;
}


int main()
{
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("")? cout <<"Yes\n": cout << "No\n";
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
	return 0;
}



// 18...Rabin Karp Algo
/* Following program is a C++ implementation of Rabin Karp
Algorithm given in the CLRS book */
#include <bits/stdc++.h>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

/* pat -> pattern
	txt -> text
	q -> A prime number
*/
void search(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; // hash value for pattern
	int t = 0; // hash value for txt
	int h = 1;

	// The value of h would be "pow(d, M-1)%q"
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;

	// Calculate the hash value of pattern and first
	// window of text
	for (i = 0; i < M; i++) {
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	// Slide the pattern over text one by one
	for (i = 0; i <= N - M; i++) {

		// Check the hash values of current window of text
		// and pattern. If the hash values match then only
		// check for characters one by one
		if (p == t) {
			/* Check for characters one by one */
			for (j = 0; j < M; j++) {
				if (txt[i + j] != pat[j]) {
					break;
				}
			}

			// if p == t and pat[0...M-1] = txt[i, i+1,
			// ...i+M-1]

			if (j == M)
				cout << "Pattern found at index " << i
					<< endl;
		}

		// Calculate hash value for next window of text:
		// Remove leading digit, add trailing digit
		if (i < N - M) {
			t = (d * (t - txt[i] * h) + txt[i + M]) % q;

			// We might get negative value of t, converting
			// it to positive
			if (t < 0)
				t = (t + q);
		}
	}
}

/* Driver code */
int main()
{
	char txt[] = "GEEKS FOR GEEKS";
	char pat[] = "GEEK";

	// we mod to avoid overflowing of value but we should
	// take as big q as possible to avoid the collison
	int q = INT_MAX;

	// Function Call
	search(pat, txt, q);
	return 0;
}



// 19...KMP Algo
// C++ program for implementation of KMP pattern searching
// algorithm
#include <bits/stdc++.h>

void computeLPSArray(char* pat, int M, int* lps);

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	// create lps[] that will hold the longest prefix suffix
	// values for pattern
	int lps[M];

	// Preprocess the pattern (calculate lps[] array)
	computeLPSArray(pat, M, lps);

	int i = 0; // index for txt[]
	int j = 0; // index for pat[]
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}

		// mismatch after j matches
		else if (i < N && pat[j] != txt[i]) {
			// Do not match lps[0..lps[j-1]] characters,
			// they will match anyway
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* lps)
{
	// length of the previous longest prefix suffix
	int len = 0;

	lps[0] = 0; // lps[0] is always 0

	// the loop calculates lps[i] for i = 1 to M-1
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else // (pat[i] != pat[len])
		{
			// This is tricky. Consider the example.
			// AAACAAAA and i = 7. The idea is similar
			// to search step.
			if (len != 0) {
				len = lps[len - 1];

				// Also, note that we do not increment
				// i here
			}
			else // if (len == 0)
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

// Driver code
int main()
{
	char txt[] = "ABABDABACDABABCABAB";
	char pat[] = "ABABCABAB";
	KMPSearch(pat, txt);
	return 0;
}






// 20...Convert a Sentence into its equivalent mobile numeric keypad sequence.




#include <bits/stdc++.h>
using namespace std;

// Function which computes the sequence
string printSequence(string arr[], string input)
{
    string output = "";

    // length of input string
    int n = input.length();
    for (int i = 0; i < n; i++) {
        // Checking for space
        if (input[i] == ' ')
            output = output + "0";

        else {
            // Calculating index for each
            // character
            int position = input[i] - 'A';
            output = output + arr[position];
        }
    }

    // Output sequence
    return output;
}

// Driver Code
int main()
{
    // storing the sequence in array
    string str[]
        = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };

    string input = "GEEKSFORGEEKS";
    cout << printSequence(str, input);
    return 0;
}






// 21...Minimum number of bracket reversals needed to make an expression balanced.


#include <bits/stdc++.h>
using namespace std;

int countMinReversals(string expr)
{
	int len = expr.length();

	if (len % 2)
		return -1;


	stack<char> s;
	for (int i = 0; i < len; i++) {
		if (expr[i] == '}' && !s.empty()) {
			if (s.top() == '{')
				s.pop();
			else
				s.push(expr[i]);
		}
		else
			s.push(expr[i]);
	}

	// Length of the reduced expression
	// red_len = (m+n)
	int red_len = s.size();

	// count opening brackets at the end of
	// stack
	int n = 0;
	while (!s.empty() && s.top() == '{') {
		s.pop();
		n++;
	}

	// return ceil(m/2) + ceil(n/2) which is
	// actually equal to (m+n)/2 + n%2 when
	// m+n is even.
	return (red_len / 2 + n % 2);
}

// Driver program to test above function
int main()
{
	string expr = "}}{{";
	cout << countMinReversals(expr);
	return 0;
}



// 22...Count All Palindromic Subsequence in a given String.

#include <cstring>
#include <iostream>
using namespace std;

// Function return the total palindromic subsequence
int countPS(string str)
{
	int N = str.length();

	// create a 2D array to store the count of palindromic
	// subsequence
	int cps[N + 1][N + 1];
	memset(cps, 0, sizeof(cps));

	// palindromic subsequence of length 1
	for (int i = 0; i < N; i++)
		cps[i][i] = 1;

	// check subsequence of length L is palindrome or not
	for (int L = 2; L <= N; L++) {
		for (int i = 0; i <= N-L; i++) {
			int k = L + i - 1;
			if (str[i] == str[k])
				cps[i][k]
					= cps[i][k - 1] + cps[i + 1][k] + 1;
			else
				cps[i][k] = cps[i][k - 1] + cps[i + 1][k]
							- cps[i + 1][k - 1];
		}
	}

	// return total palindromic subsequence
	return cps[0][N - 1];
}

// Driver program
int main()
{
	string str = "abcb";
	cout << "Total palindromic subsequence are : "
		<< countPS(str) << endl;
	return 0;
}



// 23...Count of number of given string in 2D character array

#include <bits/stdc++.h>
using namespace std;

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(*a))


int internalSearch(string needle, int row,
				int col, string hay[],
				int row_max, int col_max, int xx)
{
	int found = 0;

	if (row >= 0 && row <= row_max && col >= 0 &&
		col <= col_max && needle[xx] == hay[row][col])
	{
		char match = needle[xx];
		xx += 1;

		hay[row][col] = 0;

		if (needle[xx] == 0)
		{
			found = 1;
		}
		else
		{

			// through Backtrack searching
			// in every directions
			found += internalSearch(needle, row,
									col + 1, hay,
									row_max, col_max,xx);
			found += internalSearch(needle, row, col - 1,
									hay, row_max, col_max,xx);
			found += internalSearch(needle, row + 1, col,
									hay, row_max, col_max,xx);
			found += internalSearch(needle, row - 1, col,
									hay, row_max, col_max,xx);
		}
		hay[row][col] = match;
	}
	return found;
}

// Function to search the string in 2d array
int searchString(string needle, int row, int col,
				string str[], int row_count,
								int col_count)
{
	int found = 0;
	int r, c;

	for (r = 0; r < row_count; ++r)
	{
		for (c = 0; c < col_count; ++c)
		{
			found += internalSearch(needle, r, c, str,
									row_count - 1,
									col_count - 1, 0);
		}
	}
	return found;
}

// Driver code
int main()
{
	string needle = "MAGIC";
	string input[] = { "BBABBM",
					"CBMBBA",
					"IBABBG",
					"GOZBBI",
					"ABBBBC",
					"MCIGAM" };
	string str[ARRAY_SIZE(input)];
	int i;
	for (i = 0; i < ARRAY_SIZE(input); ++i)
	{
		str[i] = input[i];
	}

	cout << "count: " << searchString(needle, 0, 0, str,
									ARRAY_SIZE(str),
									str[0].size()) << endl;
	return 0;
}




// 24....Search a Word in a 2D Grid of characters.
// C++ programs to search a word in a 2D grid
#include <bits/stdc++.h>
using namespace std;

// For searching in all 8 direction
int x[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int y[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// This function searches in
// all 8-direction from point
// (row, col) in grid[][]
bool search2D(char *grid, int row, int col,
			string word, int R, int C)
{
	// If first character of word doesn't
	// match with given starting point in grid.
	if (*(grid+row*C+col) != word[0])
		return false;

	int len = word.length();

	// Search word in all 8 directions
	// starting from (row, col)
	for (int dir = 0; dir < 8; dir++) {
		// Initialize starting point
		// for current direction
		int k, rd = row + x[dir], cd = col + y[dir];

		// First character is already checked,
		// match remaining characters
		for (k = 1; k < len; k++) {
			// If out of bound break
			if (rd >= R || rd < 0 || cd >= C || cd < 0)
				break;

			// If not matched, break
			if (*(grid+rd*C+cd) != word[k])
				break;

			// Moving in particular direction
			rd += x[dir], cd += y[dir];
		}

		// If all character matched, then value of k must
		// be equal to length of word
		if (k == len)
			return true;
	}
	return false;
}

// Searches given word in a given
// matrix in all 8 directions
void patternSearch(char *grid, string word,
				int R, int C)
{
	// Consider every point as starting
	// point and search given word
	for (int row = 0; row < R; row++)
		for (int col = 0; col < C; col++)
			if (search2D(grid, row, col, word, R, C))
				cout << "pattern found at "
					<< row << ", "
					<< col << endl;
}

// Driver program
int main()
{
	int R = 3, C = 13;
	char grid[R][C] = { "GEEKSFORGEEKS",
						"GEEKSQUIZGEEK",
						"IDEQAPRACTICE" };

	patternSearch((char *)grid, "GEEKS", R, C);
	cout << endl;
	patternSearch((char *)grid, "EEE", R, C);
	return 0;
}





// 25...Boyer Moore Algorithm for Pattern Searching.

#include <bits/stdc++.h>
using namespace std;
#define NO_OF_CHARS 256

void badCharHeuristic(string str, int size,
                      int badchar[NO_OF_CHARS])
{
    int i;

    for (i = 0; i < NO_OF_CHARS; i++)
        badchar[i] = -1;

    for (i = 0; i < size; i++)
        badchar[(int)str[i]] = i;
}

void search(string txt, string pat)
{
    int m = pat.size();
    int n = txt.size();

    int badchar[NO_OF_CHARS];

    badCharHeuristic(pat, m, badchar);

    int s = 0;
    while (s <= (n - m))
    {
        int j = m - 1;

        while (j >= 0 && pat[j] == txt[s + j])
            j--;

        if (j < 0)
        {
            cout << "pattern occurs at shift = " << s << endl;

            s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
        }

        else

            s += max(1, j - badchar[txt[s + j]]);
    }
}

int main()
{
    string txt = "ABAAABCD";
    string pat = "ABC";
    search(txt, pat);
    return 0;
}


// 26...Converting Roman Numerals to Decimal


#include <bits/stdc++.h>
using namespace std;

int romanToInt(string s)
{
    int ans = 0;
    unordered_map<char, int> mp{
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

    for (int i = 0; i < s.size(); i++)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            // for cases such as IV,CM, XL, etc...
            ans = ans - mp[s[i]];
        }
        else
        {
            ans = ans + mp[s[i]];
        }
    }
    return ans;
}

int main()
{
    string str;
    cout << "enter the roman number: ";
    cin >> str;
    cout << romanToInt(str);

    return 0;
}




// 27...Longest Common Prefix

#include <bits\stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int a = strs.size();
    string n = strs[0], m = strs[a - 1], ans = "";
    for (int i = 0; i < n.size(); i++)
    {
        if (n[i] == m[i])
        {
            ans += n[i];
        }
        else
            break;
    }
    return ans;
}
int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    cout << longestCommonPrefix(strs);

    return 0;
}


// 28...

#include <bits/stdc++.h>
using namespace std;

int minFlips(string s)
{
    int n = s.size();
    vector<vector<int>> cnt(2, vector<int>(2, 0));

    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0'][i % 2]++;
    }
    int ans = cnt[1][0] + cnt[0][1];
    ans = min(ans, cnt[0][0] + cnt[1][1]);
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - '0'][i % 2]--;
        cnt[s[i] - '0'][(n + i) % 2]++;
        ans = min(ans, cnt[1][0] + cnt[0][1]);
        ans = min(ans, cnt[0][0] + cnt[1][1]);
    }
    return ans;
}

int main()
{
    string s = "111000";
    cout<<minFlips(s);

    return 0;
}



// 29....Second most repeated string in a sequence
#include <bits/stdc++.h>
using namespace std;

string secMostRepeated(vector<string> seq)
{

    unordered_map<string, int> occ;
    for (int i = 0; i < seq.size(); i++)
        occ[seq[i]]++;

    int first_max = INT_MIN, sec_max = INT_MIN;
    for (auto it = occ.begin(); it != occ.end(); it++)
    {
        if (it->second > first_max)
        {
            sec_max = first_max;
            first_max = it->second;
        }

        else if (it->second > sec_max &&
                 it->second != first_max)
            sec_max = it->second;
    }

    for (auto it = occ.begin(); it != occ.end(); it++)
        if (it->second == sec_max)
            return it->first;
}

int main()
{
    vector<string> seq = {"ccc", "aaa", "ccc",
                          "ddd", "aaa", "aaa"};
    cout << secMostRepeated(seq);
    return 0;
}



// 30...Minimum number of swaps for bracket balancing.

#include <bits/stdc++.h>
using namespace std;

long swapCount(string chars)
{

    int countLeft = 0, countRight = 0;

    int swap = 0, imbalance = 0;

    for (int i = 0; i < chars.length(); i++)
    {
        if (chars[i] == '[')
        {

            countLeft++;

            if (imbalance > 0)
            {

                swap += imbalance;

                imbalance--;
            }
        }
        else if (chars[i] == ']')
        {

            countRight++;

            imbalance = (countRight - countLeft);
        }
    }
    return swap;
}

int main()
{
    string s = "[]][][";
    cout << swapCount(s) << endl;

    s = "[[][]]";
    cout << swapCount(s) << endl;

    return 0;
}



// 31....Find the longest common subsequence between two strings.

#include <bits/stdc++.h>
using namespace std;

int lcs(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + lcs(X, Y, m - 1, n - 1);
    else
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n));
}

int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";

    int m = strlen(X);
    int n = strlen(Y);

    cout << "Length of LCS is " << lcs(X, Y, m, n);

    return 0;
}





// 32....Program to generate all possible valid IP addresses from given  string.

#include <bits/stdc++.h>
using namespace std;

int is_valid(string ip)
{
    vector<string> ips;
    string ex = "";
    for (int i = 0; i < ip.size(); i++)
    {
        if (ip[i] == '.')
        {
            ips.push_back(ex);
            ex = "";
        }
        else
        {
            ex = ex + ip[i];
        }
    }
    ips.push_back(ex);

    for (int i = 0; i < ips.size(); i++)
    {

        if (ips[i].length() > 3 || stoi(ips[i]) < 0 || stoi(ips[i]) > 255)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) == 0)
            return 0;

        if (ips[i].length() > 1 && stoi(ips[i]) != 0 && ips[i][0] == '0')
            return 0;
    }
    return 1;
}

void convert(string ip)
{
    int l = ip.length();

    if (l > 12 || l < 4)
    {
        cout << "Not Valid IP Address";
    }

    string check = ip;
    vector<string> ans;

    for (int i = 1; i < l - 2; i++)
    {
        for (int j = i + 1; j < l - 1; j++)
        {
            for (int k = j + 1; k < l; k++)
            {
                check = check.substr(0, k) + "." + check.substr(k);
                check = check.substr(0, j) + "." + check.substr(j);
                check = check.substr(0, i) + "." + check.substr(i);

                if (is_valid(check))
                {
                    ans.push_back(check);
                    std::cout << check << '\n';
                }
                check = ip;
            }
        }
    }
}

int main()
{
    string A = "25525511135";
    string B = "25505011535";

    convert(A);
    convert(B);

    return 0;
}



// 33....Write a program tofind the smallest window that contains all characters of string itself.

#include <bits/stdc++.h>
using namespace std;

const int MAX_CHARS = 256;

string findSubString(string str)
{
    int n = str.length();

    int dist_count = 0;
    unordered_map<int, int> hash_map;
    for (int i = 0; i < n; i++)
    {
        hash_map[str[i]]++;
    }

    dist_count = hash_map.size();
    int size = INT_MAX;
    string res;

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        int visited[256] = {0};
        string sub_str = "";
        for (int j = i; j < n; j++)
        {
            if (visited[str[j]] == 0)
            {
                count++;
                visited[str[j]] = 1;
            }
            sub_str += str[j];
            if (count == dist_count)
                break;
        }
        if (sub_str.length() < size && count == dist_count)
        {
            res = sub_str;
            size = res.length();
        }
    }
    return res;
}

int main()
{
    string str = "aabcbcdbca";
    cout << "Smallest window containing all distinct"
            " characters is: "
         << findSubString(str);
    return 0;
}




// 34....Rearrange characters in a string such that no two adjacent are same


#include <bits/stdc++.h>
using namespace std;

const int MAX_CHAR = 26;

struct Key {

	int freq; // store frequency of character
	char ch;

	// Function for priority_queue to store Key
	// according to freq
	bool operator<(const Key& k) const
	{
		return freq < k.freq;
	}
};

// Function to rearrange character of a string
// so that no char repeat twice
void rearrangeString(string str)
{
	int N = str.length();

	// Store frequencies of all characters in string
	int count[MAX_CHAR] = { 0 };
	for (int i = 0; i < N; i++)
		count[str[i] - 'a']++;

	// Insert all characters with their frequencies
	// into a priority_queue
	priority_queue<Key> pq;
	for (char c = 'a'; c <= 'z'; c++) {
		int val = c - 'a';
		if (count[val]) {
			pq.push(Key{ count[val], c });
		}
	}

	// 'str' that will store resultant value
	str = "";

	// work as the previous visited element
	// initial previous element be. ( '#' and
	// it's frequency '-1' )
	Key prev{ -1, '#' };

	// traverse queue
	while (!pq.empty()) {
		// pop top element from queue and add it
		// to string.
		Key k = pq.top();
		pq.pop();
		str = str + k.ch;

		// IF frequency of previous character is less
		// than zero that means it is useless, we
		// need not to push it
		if (prev.freq > 0)
			pq.push(prev);

		// Make current character as the previous 'char'
		// decrease frequency by 'one'
		(k.freq)--;
		prev = k;
	}

	// If length of the resultant string and original
	// string is not same then string is not valid
	if (N != str.length())
		cout << " Not possible " << endl;

	else // valid string
		cout << str << endl;
}

// Driver's code
int main()
{
	string str = "bbbaa";

	// Function call
	rearrangeString(str);
	return 0;
}




// 35....Minimum characters to be added at front to make string palindrome

#include <bits/stdc++.h>
using namespace std;

bool ispalindrome(string s)
{
    int l = s.length();
    int j;

    for (int i = 0, j = l - 1; i <= j; i++, j--)
    {
        if (s[i] != s[j])
            return false;
    }
    return true;
}

int main()
{
    string s = "BABABAA";
    int cnt = 0;
    int flag = 0;

    while (s.length() > 0)
    {

        if (ispalindrome(s))
        {
            flag = 1;
            break;
        }
        else
        {
            cnt++;

            s.erase(s.begin() + s.length() - 1);
        }
    }

    if (flag)
        cout << cnt;
}





// 36....Given a sequence of words, print all anagrams together
// C++ program to print anagrams
// together using dictionary
#include <bits/stdc++.h>
using namespace std;

void printAnagrams(string arr[], int size)
{
    unordered_map<string, vector<string>> map;

    // Loop over all words
    for (int i = 0; i < size; i++)
    {

        string word = arr[i];
        char letters[word.size() + 1];
        strcpy(letters, word.c_str());
        sort(letters, letters + word.size() + 1);
        string newWord = "";
        for (int i = 0; i < word.size() + 1; i++)
        {
            newWord += letters[i];
        }

        if (map.find(newWord) != map.end())
        {
            map[newWord].push_back(word);
        }
        else
        {

            vector<string> words;
            words.push_back(word);
            map[newWord] = words;
        }
    }

    unordered_map<string, vector<string>>::iterator it;
    for (it = map.begin(); it != map.end(); it++)
    {
        vector<string> values = map[it->first];
        if (values.size() > 1)
        {
            cout << "[";
            for (int i = 0; i < values.size() - 1; i++)
            {
                cout << values[i] << ", ";
            }
            cout << values[values.size() - 1];
            cout << "]";
        }
    }
}

// Driver code
int main()
{
    string arr[] = {"cat", "dog", "tac", "god", "act"};
    int size = sizeof(arr) / sizeof(arr[0]);

    printAnagrams(arr, size);

    return 0;
}





// 37....Find the smallest window in a string containing all characters of another string
#include <bits/stdc++.h>
using namespace std;

string Minimum_Window(string s, string t)
{

    int m[256] = {0};

    int ans = INT_MAX; // length of ans
    int start = 0;     // starting index of ans
    int count = 0;

    // creating map
    for (int i = 0; i < t.length(); i++)
    {
        if (m[t[i]] == 0)
            count++;
        m[t[i]]++;
    }

    // References of Window
    int i = 0;
    int j = 0;

    // Traversing the window
    while (j < s.length())
    {
        // Calculations
        m[s[j]]--;
        if (m[s[j]] == 0)
            count--;

        // Condition matching
        if (count == 0)
        {
            while (count == 0)
            {
                // Sorting ans
                if (ans > j - i + 1)
                {
                    ans = min(ans, j - i + 1);
                    start = i;
                }
                // Sliding I
                // Calculation for removing I

                m[s[i]]++;
                if (m[s[i]] > 0)
                    count++;

                i++;
            }
        }
        j++;
    }

    if (ans != INT_MAX)
        return s.substr(start, ans);
    else
        return "-1";
}

int main()
{
    string s = "this is a test string";
    string t = "tist";

    cout << Minimum_Window(s, t);
    return 0;
}



// Recursive Program to remove consecutive
// duplicates from string S.
#include <bits/stdc++.h>
using namespace std;

// A recursive function that removes
// consecutive duplicates from string S
void removeDuplicates(char* S)
{
	// When string is empty, return
	if (S[0] == '\0')
		return;

	// if the adjacent characters are same
	if (S[0] == S[1]) {

		// Shift character by one to left
		int i = 0;
		while (S[i] != '\0') {
			S[i] = S[i + 1];
			i++;
		}

		// Check on Updated String S
		removeDuplicates(S);
	}

	// If the adjacent characters are not same
	// Check from S+1 string address
	removeDuplicates(S + 1);
}

// Driver Program
int main()
{
	char S1[] = "geeksforgeeks";
	removeDuplicates(S1);
	cout << S1 << endl;

	char S2[] = "aabcca";
	removeDuplicates(S2);
	cout << S2 << endl;

	return 0;
}



// 39....String matching where one string contains wildcard characters

#include <bits/stdc++.h>
using namespace std;

string removeDuplicates(string s)
{

    int n = s.length();
    string str = "";

    if (n == 0)
        return str;

    for (int i = 0; i < n - 1; i++)
    {

        if (s[i] != s[i + 1])
        {
            str += s[i];
        }
    }

    str.push_back(s[n - 1]);
    return str;
}

int main()
{

    string s1 = "geeksforgeeks";
    cout << removeDuplicates(s1) << endl;

    string s2 = "aabcca";
    cout << removeDuplicates(s2) << endl;

    return 0;
}




// 40....Function to find Number of customers who could not get a computer
// C++ program to find number of customers who couldn't get a resource.
#include <iostream>
#include <cstring>
using namespace std;

#define MAX_CHAR 26

int runCustomerSimulation(int n, const char *seq)
{

    char seen[MAX_CHAR] = {0};

    int res = 0;

    int occupied = 0; // To keep track of occupied computers

    // Traverse the input sequence
    for (int i = 0; seq[i]; i++)
    {
        // Find index of current character in seen[0...25]
        int ind = seq[i] - 'A';

        // If First occurrence of 'seq[i]'
        if (seen[ind] == 0)
        {
            // set the current character as seen
            seen[ind] = 1;

            if (occupied < n)
            {
                occupied++;

                // Set the current character as occupying a computer
                seen[ind] = 2;
            }

            // Else this customer cannot get a computer,
            // increment result
            else
                res++;
        }

        // If this is second occurrence of 'seq[i]'
        else
        {
            // Decrement occupied only if this customer
            // was using a computer
            if (seen[ind] == 2)
                occupied--;
            seen[ind] = 0;
        }
    }
    return res;
}

// Driver program
int main()
{
    cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl;
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl;
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl;
    cout << runCustomerSimulation(1, "ABCBCA") << endl;
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl;
    return 0;
}



// 41....Transform One String to Another using Minimum Number of Given Operation

// C++ program to find minimum number of operations required
// to transform one string to other
#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of operations required to
// transform A to B.
int minOps(string &A, string &B)
{
    int m = A.length(), n = B.length();

    // This parts checks whether conversion is possible or not
    if (n != m)
        return -1;
    int count[256];
    memset(count, 0, sizeof(count));
    // count characters in A
    for (int i = 0; i < n; i++)
        count[A[i]]++;
    // subtract count for every character in B
    for (int i = 0; i < n; i++)
        count[B[i]]--;
    // Check if all counts become 0
    for (int i = 0; i < 256; i++)
        if (count[i])
            return -1;

    // This part calculates the number of operations
    // required
    int res = 0;
    for (int i = n - 1, j = n - 1; i >= 0;)
    {
        // If there is a mismatch, then keep incrementing
        // result 'res' until B[j] is not found in A[0..i]
        while (i >= 0 && A[i] != B[j])
        {
            i--;
            res++;
        }
        // If A[i] and B[j] match
        if (i >= 0)
        {
            i--;
            j--;
        }
    }
    return res;
}

// Driver program
int main()
{
    string A = "EACBD";
    string B = "EABCD";
    cout << "Minimum number of operations required is " << minOps(A, B);
    return 0;
}





// 42.....Check if two given strings are isomorphic to each other

// C++ program to check if two strings are isomorphic
#include <bits/stdc++.h>
using namespace std;
#define MAX_CHARS 256

// This function returns true if str1 and str2 are
// isomorphic
bool areIsomorphic(string str1, string str2)
{

	int m = str1.length(), n = str2.length();

	// Length of both strings must be same for one to one
	// correspondence
	if (m != n)
		return false;

	// To mark visited characters in str2
	bool marked[MAX_CHARS] = { false };

	// To store mapping of every character from str1 to
	// that of str2. Initialize all entries of map as -1.
	int map[MAX_CHARS];
	memset(map, -1, sizeof(map));

	// Process all characters one by on
	for (int i = 0; i < n; i++) {
		// If current character of str1 is seen first
		// time in it.
		if (map[str1[i]] == -1) {
			// If current character of str2 is already
			// seen, one to one mapping not possible
			if (marked[str2[i]] == true)
				return false;

			// Mark current character of str2 as visited
			marked[str2[i]] = true;

			// Store mapping of current characters
			map[str1[i]] = str2[i];
		}

		// If this is not first appearance of current
		// character in str1, then check if previous
		// appearance mapped to same character of str2
		else if (map[str1[i]] != str2[i])
			return false;
	}

	return true;
}

// Driver program
int main()
{
	cout << (areIsomorphic("aab", "xxy") ? "True" : "False")
		<< endl;
	return 0;
}




// 43.....Recursively print all sentences that can be formed from list of word lists


// C++ program to print all possible sentences from a list of word list
#include <iostream>
#include <string>

#define R 3
#define C 3
using namespace std;

// A recursive function to print all possible sentences that can be formed
// from a list of word list
void printUtil(string arr[R][C], int m, int n, string output[R])
{
	// Add current word to output array
	output[m] = arr[m][n];

	// If this is last word of current output sentence, then print
	// the output sentence
	if (m==R-1)
	{
		for (int i=0; i<R; i++)
		cout << output[i] << " ";
		cout << endl;
		return;
	}

	// Recur for next row
	for (int i=0; i<C; i++)
	if (arr[m+1][i] != "")
		printUtil(arr, m+1, i, output);
}

// A wrapper over printUtil()
void print(string arr[R][C])
{
// Create an array to store sentence
string output[R];

// Consider all words for first row as starting points and
// print all sentences
for (int i=0; i<C; i++)
	if (arr[0][i] != "")
		printUtil(arr, 0, i, output);
}

// Driver program to test above functions
int main()
{
string arr[R][C] = {{"you", "we"},
						{"have", "are"},
						{"sleep", "eat", "drink"}};

print(arr);

return 0;
}

\










