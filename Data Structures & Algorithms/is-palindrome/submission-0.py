class Solution:
    def isPalindrome(self, s: str) -> bool:
        res = "".join(ch.lower() for ch in s if ch.isalnum())
        return res == res[::-1]