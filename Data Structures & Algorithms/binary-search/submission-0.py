class Solution:
    def search(self, nums: List[int], target: int) -> int:
        n=nums
        for i in range(len(n)):
            if n[i]==target:
                return i
        return -1