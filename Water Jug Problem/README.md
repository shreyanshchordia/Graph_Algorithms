# Water Jug Problem

## Problem Statement

You are given a m litre jug and a n litre jug . Both the jugs are initially empty. The jugs don’t have markings to allow measuring smaller quantities. You have to use the jugs to measure d litres of water where d is less than n.
(X, Y) corresponds to a state where X refers to amount of water in Jug1 and Y refers to amount of water in Jug2
Determine the path from initial state (xi, yi) to final state (xf, yf), where (xi, yi) is (0, 0) which indicates both Jugs are initially empty and (xf, yf) indicates a state which could be (0, d) or (d, 0).

The operations you can perform are:

1. Empty a Jug, (X, Y)->(0, Y) Empty Jug 1
2. Fill a Jug, (0, 0)->(X, 0) Fill Jug 1
3. Pour water from one jug to the other until one of the jugs is either empty or full, (X, Y) -> (X-d, Y+d)

## Example

Input: 

m = 4, n = 3, d = 2

Output: 

(0, 0), (0, 3), (4, 0), (4, 3), (3, 0), (1, 3), (3, 3), (4, 2), (0, 2) 