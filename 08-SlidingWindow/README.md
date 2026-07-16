# Sliding Window (Phase 1)

## Overview

Sliding Window is a technique used to process contiguous subarrays or substrings efficiently by maintaining a window instead of recomputing results for every possible subarray.

The key idea is to update the current window incrementally as it moves through the array, reducing many O(n²) brute-force solutions to O(n).

---

# Patterns Covered

## 1. Standard Sliding Window

Purpose:
- Understand how a window moves over an array.

Concept:
- Maintain two pointers representing the current window.
- Expand and/or shrink the window depending on the problem.

---

## 2. Fixed Size Sliding Window

Window size is predetermined.

General process:

1. Expand the window.
2. Maintain information about the current window (sum, count, frequency, etc.).
3. Once the window reaches size `k`, compute the answer.
4. Remove the leftmost element.
5. Slide the window forward.

Typical complexity:

- Time: O(n)
- Space: O(1) or O(k)

Problems completed:

- Maximum Sum of Size K
- Count Windows Divisible by M
- Maximum Number of Even Digits

---

## 3. Variable Size Sliding Window (Positive Numbers)

Window size is unknown.

Instead of maintaining a fixed length, maintain a property.

Example property:

- Sum ≥ Target

General process:

1. Expand the window by moving the right pointer.
2. Update the current state.
3. Once the window becomes valid, shrink it from the left while it remains valid.
4. Record the answer whenever appropriate.

Typical complexity:

- Time: O(n)
- Space: O(1)

---

# Core Invariant

The window always represents the current contiguous region being processed.

During execution:

- Left pointer marks the beginning of the window.
- Right pointer marks the end of the window.
- Every pointer movement preserves the intended window property.

---

# Fixed vs Variable Window

| Fixed Size | Variable Size |
|------------|---------------|
| Window length is constant | Window length changes |
| Slide after reaching size `k` | Shrink only after satisfying a condition |
| Used when `k` is known | Used when the required size is unknown |

---

# Sliding Window vs Two Pointers

Every Sliding Window algorithm uses two pointers.

However, not every Two Pointer algorithm is a Sliding Window algorithm.

Sliding Window specifically maintains a **contiguous window**.

General Two Pointer problems may simply maintain a relationship between pointers without representing a window.

---

# Common Interview Signals

Think about Sliding Window when you see:

- Contiguous subarray
- Contiguous substring
- Window of size `k`
- Longest
- Shortest
- Maximum
- Minimum
- Sum
- Count

---

# Time Complexity

Most Sliding Window algorithms run in:

- Time: O(n)

Reason:

Although both pointers move independently, each pointer only moves forward and never moves backward.

---

# Problems Completed

- Standard Sliding Window
- Fixed Window
- Count Windows Divisible by M
- Maximum Number of Even Digits
- Variable Sliding Window (Positive Numbers)

---

# Phase Status

✅ Phase 1 Completed

Future topics (Phase 2):

- Longest Substring Without Repeating Characters
- Fruit Into Baskets
- Longest Repeating Character Replacement
- Minimum Window Substring
- HashMap-based Sliding Window
- Sliding Window with Negative Numbers