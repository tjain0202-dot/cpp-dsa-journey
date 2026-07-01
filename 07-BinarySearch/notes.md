# Binary Search Notes

## Prerequisites

- Array must be sorted.
- Search space is reduced by half every iteration.

---

# Time Complexity

| Algorithm | Time | Space |
|-----------|------|-------|
| Binary Search | O(log n) | O(1) |

---

# Safe Mid Formula

```cpp
int mid = l + (r - l) / 2;
```

Avoid

```cpp
int mid = (l + r) / 2;
```

Reason:
- `l + r` may overflow for very large values.

---

# Standard Binary Search

Goal:
- Find exact target.

Condition

```cpp
while (l <= r)
```

Cases

```
nums[mid] == target
    return mid

nums[mid] < target
    l = mid + 1

nums[mid] > target
    r = mid - 1
```

Return

```
-1
```

---

# Search Insert Position

Goal

Return

- target index if present
- otherwise insertion position

Idea

When binary search finishes,

```
l
```

is exactly the insertion index.

Return

```cpp
return l;
```

---

# First Occurrence

Goal

Find leftmost occurrence.

Condition

```cpp
if(nums[mid] >= target)
    r = mid - 1;
else
    l = mid + 1;
```

Return

```cpp
l
```

---

# Last Occurrence

Goal

Find rightmost occurrence.

Condition

```cpp
if(nums[mid] <= target)
    l = mid + 1;
else
    r = mid - 1;
```

Return

```cpp
r
```

---

# Lower Bound

Definition

First element

```
>= target
```

Return

```cpp
l
```

Equivalent to STL

```cpp
lower_bound(begin,end,target)
```

---

# Upper Bound

Definition

First element

```
> target
```

Return

```cpp
l
```

Equivalent to STL

```cpp
upper_bound(begin,end,target)
```

---

# Count Occurrences

Formula

```cpp
lastOccurrence - firstOccurrence + 1
```

---

# Important Observations

✔ Binary Search always shrinks the search space.

✔ Never do

```cpp
l++;
r--;
```

because that becomes linear shrinking.

Instead

```cpp
l = mid + 1;
r = mid - 1;
```

---

# Common Mistakes

❌ mid = (l+r)/2

❌ while(l<r)

❌ Using Binary Search on an unsorted array

❌ Returning r instead of l for Lower Bound

❌ Returning l instead of r for Last Occurrence

❌ Forgetting that lower_bound and upper_bound may return end()

---

# STL Mapping

| Problem | Return |
|---------|--------|
| Binary Search | index / -1 |
| Search Insert | l |
| First Occurrence | lower_bound |
| Last Occurrence | upper_bound - 1 |
| Lower Bound | first >= target |
| Upper Bound | first > target |