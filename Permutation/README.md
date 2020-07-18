# Permutation Problem

Given a permutation of 1 to n, you need to perform some operations to make it into increasing order. Each operation is to reverse an interval a1, a2, ...., ax (1 <= x <= n) (a prefix). Your goal is to minimize the number of operations.

## Input

The first line contains an integer  (1 <= n <= 8).

The second line contains  space separated integers, representing the sequence .

## Output

An integer representing the answer, that is, the minimum number of operations needed to make the permutation into increasing order.

## Sample

Input :

3  
3 1 2

Output :

2

## Explanation
A possible way is to reverse [1,3] , and then [1,2].
