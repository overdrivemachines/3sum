from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()

        for i, num in enumerate(nums):
            # check if current number is the same as previous number
            if i > 0 and num == nums[i - 1]:
                continue

            # 2 pointers:
            l, r = i + 1, len(nums) - 1
            while l < r:
                threeSum = num + nums[l] + nums[r]
                if threeSum > 0:
                    r -= 1
                elif threeSum < 0:
                    l += 1
                else:
                    res.append([num, nums[l], nums[r]])
                    # Update the pointer
                    l += 1
                    while nums[l] == nums[l - 1] and l < r:
                        l += 1
        return res


s = Solution()
# nums = [-1,0,1,2,-1,-4]
nums = [0, 0, 0, 0]
print(s.threeSum(nums))
