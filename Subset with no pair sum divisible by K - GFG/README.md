# Subset with no pair sum divisible by K
## Easy
<div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array of integers the task is to&nbsp;find maximum size of a subset such that sum of each pair of this subset is not divisible by K.</span><br>
&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input :</strong> 
arr[] = [3, 7, 2, 9, 1]       
K = 3
<strong>Output : </strong>
3
<strong>Explanation:</strong>
Maximum size subset whose each pair sum
is not divisible by K is [3, 7, 1] because,
3+7 = 10,   
3+1 = 4,   
7+1 = 8 
These all are not divisible by 3.
It is not possible to get a subset of size
bigger than 3 with the above-mentioned property.</span></pre>

<div>&nbsp;</div>

<div><span style="font-size:18px"><strong>Example 2:</strong></span></div>

<pre><span style="font-size:18px"><strong>Input :</strong>
arr[] = [3, 17, 12, 9, 11, 15]
K = 5
<strong>Output :</strong>
4 </span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>subsetPairNotDivisibleByK()</strong>&nbsp;which takes the array <strong>A[]</strong>, its size <strong>N </strong>and an integer <strong>K </strong>as inputs and returns the required answer.</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(N+K)<br>
<strong>Expected Auxiliary Space:</strong> O(K)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;= N, K &lt;=10<sup>5</sup><br>
1&lt;= Arr[] &lt;=10<sup>6</sup></span></p>
</div>