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





//*****





