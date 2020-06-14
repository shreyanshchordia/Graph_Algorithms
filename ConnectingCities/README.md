# Connecting Cities

## Problem Statement

The problem is straightforward. We need to connect cities via expressways. The cost of building an expressway between two cities may vary.

Our task is to connect all the cities, in such a way that it is fine if there is no direct expressway between two cities yet a route must exist to go from one city to the other.

But the task of connecting cities has to be optimized by finding a plan of construction with minimum cost. 

Hence our aim is to:

1. Build an expressway plan that connects all cities.
2. Minimize the cost of construction.
3. Return the minimum cost.

Input:    

-> Number of testcases (T)

-> -> IN EACH TEST CASE   
-> -> Number of cities to be connected (N) -- Number of expressways that can be built (M)

-> -> -> FOR EACH EXPRESSWAY    
-> -> -> Point 1 of expressway -- Point 2 of expressway -- Cost of making expressway

## Example

**Input**

Testcases   
1   
Number of cities      
5   
Number of expressways that can be built   
8   
A)  Point 1 B)  Point 2 C)  Cost of building the expressway (for all M expressways)    
1 2 4   
1 3 9   
1 4 21    
2 3 8   
2 4 17    
3 4 16    
5 2 20    
5 4 30    

**Output**

48

Hence all the 5 cities can be connected in the minimum cost of 48 units.

We connect:    
1 -- 2 (4)    
2 -- 3 (8)    
3 -- 4 (16)   
5 -- 2 (20)   

Hence minimum cost required to connect all cities is 48.
