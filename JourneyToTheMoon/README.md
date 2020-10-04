Journey to the Moon
===================
#### Problem statement
The member states of the UN are planning to send  people to the moon. They want them to be from different countries. You will be given a list of pairs of astronaut ID's. 
Each pair is made of astronauts from the same country. Determine how many pairs of astronauts from different countries they can choose from.

For example, we have the following data on 2 pairs of astronauts, and 4 astronauts total, numbered  through .

1   2

2   3

Astronauts by country are [0] and [1,2,3]. There are 3 pairs to choose from: [0,1],[0,2] and [0,3].
#### Function Description
Complete the journeyToMoon function in the editor below. It should return an integer that represents the number of valid pairs that can be formed.

journeyToMoon has the following parameter(s):
* n: an integer that denotes the number of astronauts
* astronaut: a 2D array where each element astronaut[i] is a 2 element integer array that represents the ID's of two astronauts from the same country
#### Input format
The first line contains two integers n and p, the number of astronauts and the number of pairs.
Each of the next p lines contains 2 space-separated integers denoting astronaut ID's of two who share the same nationality.
#### Constraints
* 1 <= n <= 10<sup>5</sup>
* 1 <= p <= 10<sup>4</sup>
#### Output format
An integer that denotes the number of ways to choose a pair of astronauts from different coutries.
#### Sample input 0
5  3

0  1

2  3

0  4
#### Sample output 0
6
#### Explanation 0
Persons numbered [0,1,4] belong to one country, and those numbered [2,3] belong to another. The UN has 6 ways of choosing a pair:

[0,2], [0,3], [1,2], [1,3], [4,2], [4,3]
#### Sample Input 1
4  1

0  2
#### Sample output 1
5
#### Explanation 1
Persons numbered [0,2] belong to the same country, but persons 1 and 3 don't share countries with anyone else. The UN has 5 ways of choosing a pair:

[0,1], [0,3], [1,2], [1,3], [2,3]

#### Link for references
https://www.hackerrank.com/challenges/journey-to-the-moon/editorial
#### Algorithm Used
This problem can be thought of as a graph problem. The very first step is to compute how many different countries are there. For this, we apply Depth First Search to calculate how many different connected components are present in the graph where the vertices are represented by the people and the people from the same country form one connected component. After we get how many connected components are present, say M, we just need to calculate the number of ways of selecting two persons from two different connected component. Let us assume that component i contains Mi people. So, for the number of ways selecting two persons from different components, we subtract the number of ways of selecting two persons from the same component from the total numbers of ways of selecting two persons i.e.

Ways = N choose 2 - (∑(Mi Choose 2) for i = 1 to M)
