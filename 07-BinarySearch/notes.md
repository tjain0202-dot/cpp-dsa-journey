---

# Binary Search on Answer

## What changes?

Normal Binary Search searches over **array indices**.

Binary Search on Answer searches over the **possible answers**.

The answer space must satisfy the **monotonic property**.

---

## General Pattern

1. Identify the answer space.
2. Choose `low` and `high`.
3. Write a feasibility function.
4. Binary Search over the answer space.

Template

```cpp
while(low <= high)
{
    int mid = low + (high-low)/2;

    if(feasible(mid))
    {
        // depends on problem
    }
    else
    {
        // opposite direction
    }
}
```

---

# Allocate Books

## Answer Space

```
low = largest book

high = total pages
```

Reason

A student must receive complete books.

The answer can never be

- smaller than the largest book
- larger than the total pages

---

## Feasibility Function

Maintain

```cpp
currentPages
studentsUsed
```

When

```cpp
currentPages + arr[i] > limit
```

move to the next student.

---

## Early Exit

```cpp
if(arr[i] > limit)
    return false;
```

Reason

A single book already exceeds the allowed limit.

---

## Binary Search Direction

Goal

Find the **minimum feasible** answer.

```
Possible
    search left

Not Possible
    search right
```

Return

```cpp
low
```

---

# Aggressive Cows

## Answer Space

```
low = 1

high = lastStall - firstStall
```

Reason

We search over **distances**, not stall positions.

---

## Preprocessing

Always sort the stalls.

```cpp
sort(stalls, stalls + size);
```

Reason

The greedy placement only works when stalls are visited from left to right.

---

## Feasibility Function

Maintain

```cpp
lastCowPlaced

cowsPlaced
```

When

```cpp
stalls[i] - lastCowPlaced >= distance
```

place another cow.

---

## Early Exit

```cpp
if(cowsPlaced == m)
    return true;
```

Reason

The moment all cows are placed, the answer is already proven.

---

## Binary Search Direction

Goal

Find the **maximum feasible** answer.

```
Possible
    search right

Not Possible
    search left
```

Return

```cpp
high
```

---

# My Common Mistakes

## Mistake 1

Started coding before identifying the answer space.

Correct approach:

First ask

```
What am I binary searching on?
```

---

## Mistake 2

Tried to prove the answer instead of checking feasibility.

Correct approach:

The feasibility function should answer only one question.

```
Is this value possible?
```

---

## Mistake 3

Confused stall position with distance.

Wrong

```cpp
if(stalls[i] < distance)
```

Correct

```cpp
if(stalls[i] - lastCowPlaced >= distance)
```

Only the distance between cows matters.

---

## Mistake 4

Stored

```cpp
lastCowPlaced = 1;
```

Correct

```cpp
lastCowPlaced = stalls[0];
```

Store the position of the last placed cow.

---

## Mistake 5

Forgot that some problems require sorting before Binary Search.

Always check whether the greedy traversal depends on sorted order.

---

## Mistake 6

Confused Binary Search direction.

### First Feasible

```
true  -> left

false -> right

return low
```

Examples

- Search Insert Position
- Lower Bound
- Allocate Books
- Ship Packages
- Koko Eating Bananas

---

### Last Feasible

```
true  -> right

false -> left

return high
```

Examples

- Aggressive Cows

---

# Binary Search on Answer Checklist

Before writing code, answer these questions.

□ What is the answer space?

□ What are `low` and `high`?

□ Is the property monotonic?

□ What should the feasibility function return?

□ What state variables should it maintain?

□ Am I searching for the first feasible answer or the last feasible answer?

□ Is preprocessing (sorting) required?