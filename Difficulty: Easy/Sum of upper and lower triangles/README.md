<h2><a href="https://www.geeksforgeeks.org/problems/sum-of-upper-and-lower-triangles-1587115621/1">Sum of upper and lower triangles</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a square matrix <strong>mat[][]</strong>&nbsp;of size <strong>n*n</strong>, return&nbsp;</span><span style="font-size: 18px;">an array of two elements containing two values: </span><span style="font-size: 18px;">the sum of Upper Triangle elements and the sum of Lower Triangle elements. Upper Triangle consists of elements on the diagonal and above it. The lower triangle consists of elements on the diagonal and below it.&nbsp;</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 3, mat[][] = [[6, 5, 4],
&nbsp;                      [1, 2, 5],
&nbsp;                      [7, 9, 7]]
<strong>Output:</strong> [29, 32]
<strong>Explanation:</strong> <br></span><span style="font-size: 18px;">Upper triangular matrix:
6 5 4
&nbsp;&nbsp;2 5
&nbsp;&nbsp;&nbsp; 7
Sum of these elements is 6 + 5 + 4 + 2 + 5 + 7 = 29.<br></span><span style="font-size: 18px;">Lower triangular matrix:
6
1 2
7 9 7
Sum of these elements is 6 + 1 + 2 + 7 + 9 + 7 = 32.</span></pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong> n = 2, mat[][] = [[1, 2],
&nbsp;                      [3, 4]]
<strong>Output:</strong> [7, 8]
<strong>Explanation: <br></strong>Upper triangular matrix:
1 2
&nbsp; 4
Sum of these elements are 1 + 2 + 4 = 7.
Lower triangular matrix:
1
3 4
Sum of these elements are 1 + 3 + 4 = 8.</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong>&nbsp;<br>1&nbsp;</span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;">&nbsp;n </span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;"> 500</span><sup><br></sup><span style="font-size: 18px;">1&nbsp;</span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;"> mat[i][j]&nbsp;</span><span style="font-size: 18px;">≤</span><span style="font-size: 18px;"> 1000</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Matrix</code>&nbsp;<code>Data Structures</code>&nbsp;