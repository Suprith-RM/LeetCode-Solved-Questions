class Solution {
    bool isPalindrome(string& str) {
        int left = 0;
        int right = str.length() - 1;

        while (left < right) {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

public:
    bool checkPalindromeFormation(string a, string b) {
        int i = 0, j = b.size() - 1;
        int m = a.size() - 1, n = 0;

        while (i < j && a[i] == b[j]) {
            i++, j--;
        }

        if (i >= j)
            return true;

        while (m > n && a[m] == b[n]) {
            m--, n++;
        }

        if (m <= n)
            return true;

        string c1 = a.substr(0, i) + b.substr(i);
        string c2 = a.substr(0, j + 1) + b.substr(j + 1);
        string c3 = b.substr(0, n) + a.substr(n);
        string c4 = b.substr(0, m + 1) + a.substr(m + 1);

        return isPalindrome(c1) ||
               isPalindrome(c2) ||
               isPalindrome(c3) ||
               isPalindrome(c4);
    }
};