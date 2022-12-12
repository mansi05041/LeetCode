<h2><a href="https://leetcode.com/problems/next-greater-element-i/">496. Next Greater Element I</a></h2><h3>Easy</h3><hr><div>
  <p>The <strong>next greater element</strong> of some element <code>x</code> in an array is the <strong>first greater</strong> element that is <strong>to the right</strong>
   of <code>x</code> in the same array.</p>
  <p>You are given two <strong>distinct 0-indexed</strong> integer arrays <code>nums1</code> and <code>nums2</code>, where <code>nums1</code> is a subset of 
    <code>nums2</code></p>
  <p>For each <code>0 <= i < nums1.length</code>, find the index <code>j</code> such that <code>nums1[i] == nums2[j]</code> 
    and determine the <strong>next greater element</strong> of <code>nums2[j]</code> in <code>nums2</code>. If there is no next greater element, then the answer for this query is <code>-1</code>.</p>
  <p>Return an array <code>ans</code> of length <code>nums1.length</code> such that <code>ans[i]</code> is the next greater element as described above.</p>
  
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong>nums1 = [4,1,2], nums2 = [1,3,4,2]
<strong>Output:</strong> [-1,3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
- 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
- 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums1 = [2,4], nums2 = [1,2,3,4]
<strong>Output:</strong> [3,-1]
<strong>Explanation:</strong> The next greater element for each value of nums1 is as follows:
- 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
- 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums1.length &lt;= nums2.length &lt;= 1000</code></li>
  <li>0 &lt;= nums1[i], nums2[i] &lt;= 104</li>
  <li>All integers in <code>nums1</code> and <code>nums2</code> are unique.</li>
  <li>All the integers of nums1 also appear in <code>nums2</code>.
</ul>
</div>
