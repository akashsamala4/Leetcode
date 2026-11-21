class Solution:
    def majorityElement(self, nums: list[int]) -> int:
        candidate = 0
        balance = 0
        for value in nums:
            if balance == 0:
                candidate = value
            if value == candidate:
                balance += 1
            else:
                balance -= 1
        return candidate    