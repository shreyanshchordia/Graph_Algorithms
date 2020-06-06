# Tower Construction

Four 5G base station towers needs to be installed in a  Landscape which is divided as hexagon cells as shown in Fig below, which also contains number of people living in each cell. Need to find four cells  to install the 5G towers which can cover maximum number of people  combining all four cells, with below conditions
Only one tower can be placed in a cell
Each of the four chosen cell should be neighbor to atleast one of the remaining 3 cells. 
All four cells should be connected  (like  one island)

## For Example

### Input 

<p align="center">
  <img src="https://github.com/shreyanshchordia/cpp/blob/master/img/TowerInput.png?raw=true">
</p>

### Output
Square of  Maximum number of people covered by 4 towers (Fig 2)

<p align="center">
  <img src="https://github.com/shreyanshchordia/cpp/blob/master/img/TowerOutput.png?raw=true">
</p>

## Approach

There can be a variety of approaches to get solution to this question. But for all kinds of approach, one thing is common, that we need to
find a path of size 4 for every point in the space. 

1. I start from the first point, marking it as visited.
2. Generate all possible neighbours for the point. Note that this is not a normal graph. It is a hexagonally
designed graph, hence the neighbour generation differs. 
    
    [ Hint : neighbour generation differs, depending on whether the column number is odd or even]

3. Selecting the best neighbour (the neighbour with the highest value)
4. Adding the best neighbour to the branch, marking it visited and reducing the depth of probing (tells me that I have already visited 2 points
hence I have to stop after 2 more points).

    Since the final solution can be a tree as well, hence pure DFS or BFS cannot be applied. Hence, once a neighbour is selected we again have
    to quest for a new neighbour if probing length isn't zero such that the best neighbour can come from the neighbours of any visited point in the
    previously generated path.

5. Now searching for a new neighbour, considering every point in the already generated path again. 
6. Repeating 1-5 for every single point in the space, and hence finally landing to the best solution.
