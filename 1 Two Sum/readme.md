# 1 Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

**Input:** numbers={2, 7, 11, 15}, target=9

**Output:** index1=1, index2=2

#### Tags:
Array, Hash Tables

#### Traps:
1. what about when the target is negetive?

#### My solutions:
1, Using vector as the value of map, in case there appears duplicated number.