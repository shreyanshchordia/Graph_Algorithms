# The Knight’s Tour Problem
<p>Another classic problem that can be used to illustrate a second common graph algorithm is called the “knight’s tour.” The knight’s tour puzzle is played on a chess board with a single chess piece, the knight. The object of the puzzle is to find a sequence of moves that allow the knight to visit every square on the board exactly once. One such sequence is called a “tour.” The knight’s tour puzzle has fascinated chess players, mathematicians and computer scientists alike for many years. The upper bound on the number of possible legal tours for an eight-by-eight chessboard is known to be 1.305×1035; however, there are even more possible dead ends. Clearly this is a problem that requires some real brains, some real computing power, or both.</p>

<p>Although researchers have studied many different algorithms to solve the knight’s tour problem, a graph search is one of the easiest to understand and program.</p>

<p> Each square on the chessboard can be represented as a node in the graph. Each legal move by the knight can be represented as an edge in the graph. As show in image below</p>

<p align='center'>
  <img src='https://runestone.academy/runestone/books/published/pythonds/_images/knightmoves.png'></img>
</p>

<p> figure below shows the complete graph of possible moves on an eight-by-eight board. There are exactly 336 edges in the graph. Notice that the vertices corresponding to the edges of the board have fewer connections (legal moves) than the vertices in the middle of the board.
</p>

<p align='center'>
  <img src='https://runestone.academy/runestone/books/published/pythonds/_images/bigknight.png'></img>
</p>
