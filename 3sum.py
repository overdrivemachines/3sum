from typing import List
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        result = []
        nums.sort()
        print("Sorted:", nums)
        for i, num in enumerate(nums):
            # skip this loop if current num is same as previous num
            if num != nums[i-1]:
                # now find the pair that adds up to -num
                # using 2 pointer (left and right) approach
                left = i + 1
                right = len(nums) - 1
                while (left < right):
                    # Checking total
                    print("nums[", i, "]: ", num, ": ", nums[left], " + ", nums[right])
                    total = (nums[left] + nums[right])
                    if (total < (num * -1)):
                        left += 1
                    elif (total > (num * -1)):
                        right -= 1
                    else:
                        result.append([num, nums[left], nums[right]])
                        print("Inserted ", [num, nums[left], nums[right]])
                        left += 1
                        right = len(nums) - 1

        return result

s = Solution()
# nums = [-1,0,1,2,-1,-4]
nums = [0,0,0,0]
print(s.threeSum(nums))
