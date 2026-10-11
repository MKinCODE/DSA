<h2><a href="https://leetcode.com/problems/subarray-sums-divisible-by-k">974. Subarray Sums Divisible by K</a></h2>

<p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of non-empty <strong>subarrays</strong> that have a sum divisible by </em><code>k</code>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,5,0,-2,-3,1], k = 5
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5], k = 9
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>


---

# 🛍️ Subarray-Sums-Divisible-by-K | Explained

## Approach 1: Prefix Sum with Normalized Modulo Hashing
### Intuition
Imagine you are walking along a circular track marked with $k$ checkpoints (numbered $0$ to $k - 1$). Every time you take a step, your position on the track shifts by that value. If you visit checkpoint $r$ at step $i$, and later find yourself standing at that exact same checkpoint $r$ at step $j$, the total distance traveled between step $i$ and step $j$ must complete a full set of laps around the track. In other words, the distance between them is an exact multiple of $k$.

Mathematically, a subarray sum from index $i$ to $j$ is given by:
$$\text{SubarraySum}(i, j) = \text{PrefixSum}[j] - \text{PrefixSum}[i - 1]$$

For this difference to be divisible by $k$:
$$(\text{PrefixSum}[j] - \text{PrefixSum}[i - 1]) \pmod k = 0 \iff \text{PrefixSum}[j] \pmod k = \text{PrefixSum}[i - 1] \pmod k$$

Whenever two prefix sums share the same remainder modulo $k$, the subarray bounded between them is evenly divisible by $k$.

### Algorithm Visualized
```mermaid
flowchart TD
    A[Start: Initialize um[0] = 1, sum = 0, ans = 0] --> B[Loop: For each x in nums]
    B --> C[Accumulate sum: sum += x]
    C --> D["Normalize Remainder: curr = ((sum % k) + k) % k"]
    D --> E{curr exists in um?}
    E -- Yes --> F["ans += um[curr]"]
    E -- No --> G[Skip addition]
    F --> H["um[curr]++"]
    G --> H
    H --> I{More elements?}
    I -- Yes --> B
    I -- No --> J[Return ans]
```

### Approach
1. **Maintain a Running Prefix Sum:** Traverse `nums` while keeping a cumulative running sum.
2. **Handle Negative Modulo:** In C++, the `%` operator computes truncated division remainder rather than Euclidean remainder. A negative number modulo $k$ produces a negative result (e.g., `-7 % 5 = -2`). To normalize this into the valid non-negative range $[0, k - 1]$, use the transformation:
   $$\text{curr} = ((\text{sum} \pmod k) + k) \pmod k$$
3. **Map Frequency of Remainders:** Store remainder frequencies in a hash map `um`.
4. **Base Case:** Initialize `um[0] = 1` before starting the loop. This represents an empty prefix with sum $0$, which accounts for any subarray starting from index $0$ that is itself directly divisible by $k$.
5. **Count Valid Subarrays:** For each calculated `curr`, every prior occurrence of `curr` marks the start of a valid subarray ending at the current index. Add `um[curr]` to `ans`, then increment `um[curr]`.

### Detailed Code Analysis
- **Lines 4–5 (`unordered_map<int,int> um; um[0]=1;`):**
  A hash map is instantiated to record the frequency of each normalized remainder. Setting `um[0] = 1` handles the boundary condition. Without this, a prefix sum that is already divisible by $k$ would fail to count as a valid subarray unless another sum with remainder 0 had already been recorded.
- **Lines 6–7 (`long long sum=0; int ans=0;`):**
  `sum` tracks the continuous accumulation of values. Using `long long` guards against 32-bit signed integer overflow during accumulation. `ans` stores the cumulative number of valid subarrays found.
- **Lines 8–10 (`for(int x:nums) { sum+=x; int curr = ((sum%k)+k)%k;`):**
  For every element `x`:
  - `sum += x;` extends the prefix sum.
  - `((sum % k) + k) % k` standardizes the remainder. If `sum % k` is negative, adding `k` brings it into $(0, k)$, and the secondary `% k` guarantees that positive values stay within $[0, k - 1]$.
- **Lines 12–14 (`if(um.find(curr)!=um.end()) ans+=um[curr]; um[curr]++;`):**
  Checks whether this exact normalized remainder has been encountered. If found, all previously encountered prefixes with remainder `curr` pair up with the current prefix to form valid subarrays, so `ans` increases by `um[curr]`. Afterwards, `um[curr]++` updates the map to include the current prefix for future pairs.
- **Line 16 (`return ans;`):**
  Returns the final aggregated count of matching subarrays.

### Code
```cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        um[0]=1;
        long long sum=0;
        int ans=0;
        for(int x:nums){
            sum+=x;
            int curr = ((sum%k)+k)%k;

            if(um.find(curr)!=um.end())
                ans+=um[curr];
            um[curr]++;
        }
        return ans;
    }
};
```

### Complexity
- **Time:** $\mathcal{O}(N)$ on average. Traversing $N$ elements requires $O(1)$ average-time lookups and insertions in `std::unordered_map`. (In the worst case with hash collisions, map operations degrade to $\mathcal{O}(N)$, giving $\mathcal{O}(N^2)$ worst-case time).
- **Space:** $\mathcal{O}(\min(N, k))$. The hash map stores at most $k$ distinct remainders ($0$ through $k - 1$) or at most $N + 1$ unique remainders if $N < k$.

---

## 🕵️‍♂️ Follow-up Questions (Optional)

1. **How can you optimize this solution to guarantee strict $\mathcal{O}(N)$ worst-case time and avoid hash map overhead?**
   - **Answer:** Since the remainder `curr` is strictly bounded within the range $[0, k - 1]$, an array or `std::vector<int> remainder_count(k, 0)` can replace `std::unordered_map`. This eliminates hash collisions, provides $\mathcal{O}(1)$ direct memory access, improves cache locality, and guarantees $\mathcal{O}(N)$ worst-case time with $\mathcal{O}(k)$ space.

2. **How would the logic change if the problem asked for the *longest* subarray divisible by $k$ instead of the total count?**
   - **Answer:** Instead of tracking remainder *frequencies*, store the *first index* where each remainder occurred (`unordered_map<int, int> first_seen`). When remainder `curr` appears again at index $i$, the length is $i - \text{first\_seen}[\text{curr}]$. Maximize this difference across all steps instead of adding frequencies to `ans`.