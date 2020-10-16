# Eight Puzzle Solver

## Problem Statement

Eight Puzzle is a problem wherein there is a 3 by 3 grid and 9 tiles in total.
The tiles include numbers from 1 to 8 and a blank tile.

The initial state of the puzzle is any random state that can be solvable. One simple example is given below:

1 2 3

4 5 _

7 8 6

The user can only move Blank Tile so that he can arrange the 9 tiles in the following manner:

1 2 3

4 5 6

7 8 _

Here, _ denotes the blank tile. The user can solve the puzzle by shifting the blank tile in Bottom direction.

This process can be automated using various Graph Algorithms. 

The Python Script contains OOP approach to implement the Puzzle Solver using various algorithms such as Breadth First Search, Depth First Search, Uniform Cost Search and A Star Search.

While A Star search results in the Shortest Path to the answer, Uniform Cost Search is a bit faster than it on some of the input values.

## Instructions

- The Python script runs in Python 3+ and doesn't require external libraries other than the default ones that are already installed.
- Use the Solver class to instantiate a Puzzle Solver by providing a 1D List that denotes the initial state of the 8 puzzle problem.
- Use any desired method to solve the problem.

I have added sample codes in the comments. Please do refer them before using the script. Also, the methods are well documented.

## References

An extended version of this puzzle is the 15 Puzzle available [here](https://en.wikipedia.org/wiki/15_puzzle).

