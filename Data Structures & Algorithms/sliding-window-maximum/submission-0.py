class Solution:
    def maxSlidingWindow(self, nums, k):
        result = []
        i = 0
        j = k - 1

        while j < len(nums):
            window = nums[i:j+1]   # current window nikal le
            result.append(max(window))  # seedha max nikal le is window ka
            i += 1
            j += 1

        return result