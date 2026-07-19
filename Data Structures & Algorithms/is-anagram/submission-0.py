class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        j=sorted(s)
        k=sorted(t)

        if j==k:
            return True
        return False
