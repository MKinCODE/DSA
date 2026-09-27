<h2><a href="https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses">1190. Reverse Substrings Between Each Pair of Parentheses</a></h2>

<p>You are given a string <code>s</code> that consists of lower case English letters and brackets.</p>

<p>Reverse the strings in each pair of matching parentheses, starting from the innermost one.</p>

<p>Your result should <strong>not</strong> contain any brackets.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> s = "(abcd)"
<strong>Output:</strong> "dcba"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> s = "(u(love)i)"
<strong>Output:</strong> "iloveu"
<strong>Explanation:</strong> The substring "love" is reversed first, then the whole string is reversed.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> s = "(ed(et(oc))el)"
<strong>Output:</strong> "leetcode"
<strong>Explanation:</strong> First, we reverse the substring "oc", then "etco", and finally, the whole string.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 2000</code></li>
	<li><code>s</code> only contains lower case English characters and parentheses.</li>
	<li>It is guaranteed that all parentheses are balanced.</li>
</ul>


---

# 🛍️ Reverse-Substrings-Between-Each-Pair-of-Parentheses | Explained

## Approach 1: Stack Simulation (Innermost-First Reversal)

### Intuition
Think of nested parentheses like a set of Russian nesting dolls or an "Undo" stack in an editor. Whenever you encounter nested instructions, the innermost task must finish before the outer context can resume. 

By pushing characters onto a stack, we naturally preserve their sequence. When a closing bracket `')'` is encountered, the top of the stack holds the innermost string enclosed by the most recent opening bracket `'('`. Because a stack follows the Last-In, First-Out (LIFO) order, popping characters until we hit `'('` automatically reverses their relative order. We discard the opening bracket and push those reversed characters back onto the stack so they can be processed again if enclosed in an outer pair of parentheses.

### Algorithm Visualized

```mermaid
flowchart TD
    A[Start: Read character s[x]] --> B{Is s[x] == ')'?}
    B -- No --> C[Push s[x] to Stack]
    B -- Yes --> D[Pop from Stack into 'curr' until '(']
    D --> E[Pop matching '(' from Stack]
    E --> F[Push characters of 'curr' back onto Stack]
    C --> G{More characters in s?}
    F --> G
    G -- Yes --> A
    G -- No --> H[Pop all elements to construct final string]
    H --> I[Return ans]
```

### Approach
1. **Initialize a Stack:** Create a character stack `st` to hold characters and opening brackets.
2. **Iterate Through the Input String:**
   - If the current character is **not** a closing parenthesis `')'`, push it directly onto the stack.
   - If the current character **is** `')'`, enter the reversal phase:
     - Pop characters off the stack and append them to a temporary string `curr` until the matching `'('` is reached. Because elements are popped from top to bottom, this collection step naturally reverses the substring.
     - Pop and discard the `'('`.
     - Push the characters from `curr` back onto the stack from index `0` to `curr.length() - 1` so they are available for any outer parentheses reversals.
3. **Build the Final Result:**
   - Once all characters in `s` are processed, the stack contains only the final characters (all parentheses have been matched and discarded).
   - Empty the stack by repeatedly prepending each character (`ans = st.top() + ans`) to restore the original left-to-right order.
4. **Return:** Return the assembled string `ans`.

### Detailed Code Analysis

- **Lines 4–5:**
  ```cpp
  stack<char> st;
  for(int x=0; x<s.length(); x++){
  ```
  Initializes an empty stack of characters `st`. The loop traverses the input string `s` from index `0` to `s.length() - 1`.

- **Lines 6–12:**
  ```cpp
  if(s[x]==')'){
      string curr = "";
      while(st.top()!='('){
          curr+=st.top();
          st.pop();
      }
      st.pop();
  ```
  When `s[x] == ')'`, an innermost enclosure has ended. A local string `curr` is created. The `while` loop extracts characters from the top of the stack and appends them to `curr` until the opening parenthesis `'('` is encountered. Because stack popping retrieves the most recently pushed character first, `curr` accumulates the substring in reverse order. After the loop, `st.pop()` discards the opening parenthesis `'('`.

- **Lines 13–16:**
  ```cpp
      for(int j=0; j<curr.length(); j++){
          st.push(curr[j]);
      }
  }
  ```
  The characters in `curr` are re-pushed onto the stack in the order they were extracted. If this substring is part of a larger, outer parenthesized group (e.g., `"(u(love)i)"`), these re-pushed characters will participate in the subsequent outer reversal.

- **Lines 17–18:**
  ```cpp
  else st.push(s[x]);
  ```
  If `s[x]` is any character other than `')'` (including letters and `'('`), it is pushed onto the stack.

- **Lines 19–24:**
  ```cpp
  string ans = "";
  while(!st.empty()){
      ans = st.top() + ans;
      st.pop();
  }
  return ans;
  ```
  After processing all characters of `s`, the stack contains the resolved sequence. Popping from the stack yields characters from right to left. Prepending `st.top()` to `ans` restores the correct left-to-right sequence. Finally, `ans` is returned.

### Code
```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;
        for(int x = 0; x < s.length(); x++){
            if(s[x] == ')'){
                string curr = "";
                while(st.top() != '('){
                    curr += st.top();
                    st.pop();
                }
                st.pop(); // Remove the matching '('
                for(int j = 0; j < curr.length(); j++){
                    st.push(curr[j]);
                }
            }
            else {
                st.push(s[x]);
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};
```

### Complexity
- **Time Complexity:** $\mathcal{O}(N^2)$ in the worst case.
  - In a deeply nested structure like `((((abcd))))`, each character can be pushed and popped multiple times proportional to the nesting depth, giving $\mathcal{O}(N^2)$ stack operations.
  - Furthermore, `ans = st.top() + ans` performs string prepending inside a loop, which creates a new string of size $\mathcal{O}(K)$ on each iteration, contributing $\mathcal{O}(N^2)$ in the final reconstruction step.
- **Space Complexity:** $\mathcal{O}(N)$.
  - The stack `st` holds at most $N$ characters at any point.
  - The auxiliary string `curr` holds at most $N$ characters during reversals.

---

## 🕵️‍♂️ Follow-up Questions

### 1. How can this problem be solved in linear time $\mathcal{O}(N)$?
We can solve this in $\mathcal{O}(N)$ using the **Wormhole / Teleportation Technique**:
1. Precompute pair indices: Use a stack in a first pass to find matching pairs of parentheses and store their indices in an array/map `pair[i]`.
2. Traverse with a direction flag: Start from index `0` moving forward (`step = 1`). Whenever a parenthesis is hit, teleport to its paired index `pair[i]` and reverse the direction (`step = -step`). When landing on a regular letter, append it to the result. This visits each character at most twice, achieving $\mathcal{O}(N)$ time and $\mathcal{O}(N)$ auxiliary space.

### 2. How can we optimize the current solution without changing the overall approach?
- **Avoid string prepending:** Replace `ans = st.top() + ans` with `ans += st.top()`, and call `std::reverse(ans.begin(), ans.end())` once at the very end. Prepending in C++ reallocates and shifts memory every time ($\mathcal{O}(N^2)$ total), whereas appending and reversing takes $\mathcal{O}(N)$ total time.
- **Use `std::string` as a stack:** In C++, `std::string` supports `push_back()` and `pop_back()`. Using `std::string` directly as the stack eliminates the overhead of `std::stack<char>` and avoids constructing intermediate strings for final output.