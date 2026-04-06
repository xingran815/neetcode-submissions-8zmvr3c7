class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        min_p = 1
        max_p = 1
        res = nums[0]

        for n in nums:
            tmp = min(max_p*n, min_p*n, n)
            max_p = max(max_p*n, min_p*n, n)
            min_p = tmp
            res = max(res, max_p)
            print(f"res is {res}, max_p is {max_p}, min_p is {min_p}, n is {n}.")

        return res
        