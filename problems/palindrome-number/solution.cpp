class Solution {
public:
    bool isPalindrome(int x) {
        // 1) Quick rejects
        // negative → not palindrome
        // ending in 0 but not 0 itself → not palindrome (e.g. 10, 100)
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int rev = 0;

        // 2) Reverse only half of the digits
        // Stop when rev >= x (we've consumed half or slightly more)
        while (x > rev) {
            int d = x % 10;      // last digit
            x /= 10;             // drop last digit from x
            rev = rev * 10 + d;  // append digit to reversed half
        }

        // 3) For even #digits: x == rev
        //    For odd #digits: middle digit sits in rev, so drop it: rev/10
        return (x == rev) || (x == rev / 10);
    }
};
