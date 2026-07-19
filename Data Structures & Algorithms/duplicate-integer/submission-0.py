class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        a=nums
        s1=set(nums)
        if len(a)==len(s1):
            return False
        return True