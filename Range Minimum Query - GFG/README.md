# Range Minimum Query
##  Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:20px">Given an array<strong> A[ ] </strong>and its size <strong>N</strong> your task is to complete two functions &nbsp;a <strong>constructST</strong>&nbsp; function&nbsp;which builds the segment tree &nbsp;and a function&nbsp;<strong>RMQ</strong> which finds range minimum&nbsp;query in a segment tree .<br>
<br>
<strong>Input</strong>:<br>
The task is to complete two&nbsp;functions&nbsp;<strong>constructST</strong>&nbsp;and <strong>RMQ</strong> .<br>
The constructST&nbsp;function&nbsp;builds the segment tree and takes two arguments the array <strong>A[ ]</strong> and the size of the array <strong>N&nbsp;</strong>.<br>
It returns a pointer to the first element of the segment tree array .&nbsp;<br>
The <strong>RMQ </strong>function&nbsp;takes 4&nbsp;arguments the first being the segment tree <strong>st </strong>constructed, second being the size <strong>N</strong> and then third and forth arguments are the range of query <strong>a</strong> and<strong> b</strong>&nbsp;.The function RMQ returns the <strong>min</strong> of the elements in the array from index range a and b.&nbsp;There are multiple test cases. For each test case, this method will be called individually.<br>
<br>
<strong>Output:</strong><br>
The function <strong>RMQ</strong> should return the min element in the array from range <strong>a</strong> to <strong>b</strong> .<br>
<br>
<strong>Constraints:</strong><br>
1&lt;=T&lt;=100<br>
1&lt;=N&lt;=10^3+1<br>
1&lt;=Q(no of queries)&lt;=10000<br>
0&lt;=a&lt;=b<br>
<strong>Example:<br>
Input (To be used only for expected output)&nbsp;</strong><br>
1<br>
4<br>
1 2 3 4<br>
2<br>
0 2 2 3<br>
<br>
<strong>Output</strong><br>
1 3<br>
<br>
<strong>Explanation<br>
1.</strong> For query 1 ie 0 2 the element in this range are 1 2 3 and the min element is 1 &nbsp;<br>
<strong>2.</strong> For query 2 ie 2 3 the&nbsp;element in this range are 3 4 and the min element is 3&nbsp;</span></p>
 <p></p>
            </div>