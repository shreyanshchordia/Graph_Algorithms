Brief Description of the problem:

We are given m x n matrix which can have a number between 0 and 7. 

Each number represents a pipe with a shape as follows:

<p align='center'>
  <img src='https://github.com/shreyanshchordia/cpp/blob/master/img/pipes.png?raw=true'></img>
</p>
Two pipes are considered connected if their end points connect. For e.g.
If matrix is as follows:
0040
1360
5000

Pipe 1 and 3{1 opens to right. 3 opens to left} are connected. 
Other connected pipes are 3 and 6(3 opens to right. 6 opens to left).

4 and 6 are not connected as 6 does not open to top, and 4 does not open to bottom.

1 and 5 are also not connected as even though 1 opens to bottom, 5 is not open to top.

Given this matrix, start point (X, Y) and length of probe tool “L”,
find out how many pipes{matrix elements} can be reached if the depth of search 
cannot be more than probe tool "L".
