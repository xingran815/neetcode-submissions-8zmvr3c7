class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        max_sum = nums[0]
        cur_sum = 0

        for num in nums:
            cur_sum = max(cur_sum, 0) + num
            max_sum = max(cur_sum, max_sum)

        return max_sum
