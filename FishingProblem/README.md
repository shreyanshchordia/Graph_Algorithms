# Fishing Problem

### Given:
Fishing Spots: 1 to N   
3 Gates with gate position and number of fishermen waiting to get in.   
Distance between gate and nearest spot = 1 m    
Distance between consecutive spots = 1 m    

### Problem:
Fishermen are waiting at the gates to get in and occupy nearest fishing spot. Only 1 gate can be opened at a time and all fishermen of that gate must occupy spots before next gate is open.  
There could be 2 spots closest to the gate. Assign only 1 spot to the last fisherman in such a way that we get minimum walking distance. For rest of the fishermen, ignore and assign any one.

Write a program to return sum of minimum distance need to walk for fishermen.   

Distance is calculated as **Gate to Nearest Spot + Nearest Spot to Closest Vacant Spot.**   

If the gate is at position 4, then fishermen occupying spot 4 will walk 1 m, fishermen occupying spot 3 or 5 will walk 2 m (1m for gate to spot 4 + 1 m for spot 4 to spot 3 or 5).

## Example:

Input format:   

*No. of testcases*    
*No. of Fishing Spots*      
*No. of Gate No. 1 index and number of fishermen at the gate*   
*No. of Gate No. 2 index and number of fishermen at the gate*    
*No. of Gate No. 3 index and number of fishermen at the gate*    

Input Example:

1
10
4 5
6 2
10 2

<p align="center">
  <img src="https://github.com/shreyanshchordia/GraphsUsingCPP/blob/master/img/FishInput.png?raw=true">
</p>

<p align="center">
  <img src="https://github.com/shreyanshchordia/GraphsUsingCPP/blob/master/img/Fisher1.png?raw=true">
</p>

<p align="center">
  <img src="https://github.com/shreyanshchordia/GraphsUsingCPP/blob/master/img/Fisher2.png?raw=true">
</p>

<p align="center">
  <img src="https://github.com/shreyanshchordia/GraphsUsingCPP/blob/master/img/Fisher3.png?raw=true">
</p>

**Hence the best solution is 18.**

## Approach:

1. Generating the walking distance for every pattern of opening doors.

2. Place fishermen to the nearest vacant spot in order to get best solution for a particular pattern of opening doors.

3. For the last fisherman at every door, check the nearest spot at left as well as right. If both spots are equidistant then consider 
both the spots for generating the solution since any of the spots can lead to a smaller distance, as demonstrated in the example above.

4. Return the minimum of costs for all the different possible patterns of opening the 3 doors.

