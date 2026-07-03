# Binary Search Handbook — Part 3

## Rotated Sorted Arrays, Pattern Recognition & Personal Learning Ledger

### *(My Personal Binary Search Handbook)*

---

# Chapter 11 — Rotated Sorted Arrays

This chapter initially looked completely different from everything I had learned before.

The array was no longer completely sorted.

My first thought was:

> "Binary Search should not work anymore because the array is unsorted."

That assumption was wrong.

The biggest realization of this chapter was:

> **The array is not completely unsorted.**

It consists of **two individually sorted halves**.

Because of this hidden structure, Binary Search still remains possible.

Understanding this idea was far more important than memorizing any conditions.

---

# The Hidden Structure

Consider

```text
5 6 7 8 1 2 3 4
```

At first glance, the array appears random.

Looking carefully,

it is actually

```text
5 6 7 8
```

and

```text
1 2 3 4
```

Both halves are perfectly sorted.

Only their order has changed.

This observation explains why Binary Search can still eliminate half of the search space.

---

# The Fundamental Invariant

During every iteration,

**at least one half is guaranteed to be sorted.**

This is the property that makes Binary Search possible.

The goal is no longer simply comparing the target with `mid`.

The goal is now:

1. Identify the sorted half.
2. Decide whether the target can lie inside it.
3. Eliminate the impossible half.

Everything else follows naturally.

---

# Search in Rotated Sorted Array

Initially I tried remembering several different conditions.

Eventually I stopped memorizing and started reasoning.

The first question became:

> Which half is sorted?

One common approach is

```cpp
arr[l] <= arr[mid]
```

If this is true,

the left half is sorted.

Otherwise,

the right half must be sorted.

---

## Important Interview Discussion

One interviewer-style discussion changed my confidence.

I was asked:

> Why not identify the right sorted half first?

Initially I thought this might be a trick question.

After reasoning with examples, I realized:

Checking

```cpp
arr[l] <= arr[mid]
```

and checking

```cpp
arr[mid] <= arr[r]
```

are simply two different viewpoints.

Both are logically correct.

One identifies the left sorted half first.

The other identifies the right sorted half first.

The algorithm remains equivalent.

The lesson was:

**Trust reasoning. Verify with examples. Don't abandon a correct idea because the question sounds difficult.**

---

## Personal Mistake

Initially I wrote

```cpp
arr[l] < arr[mid]
```

instead of

```cpp
arr[l] <= arr[mid]
```

At first, this looked like a tiny implementation error.

Eventually I understood the conceptual reason.

Imagine the search space has only one element on the left.

Then

```text
l == mid
```

A single element is still a sorted half.

Using `<` incorrectly rejects this valid case.

This taught me that small comparison operators often encode important invariants.

---

## Reasoning Mistake vs Coding Mistake

Another mistake I made was mixing left-half inequalities with right-half inequalities.

The important realization was:

My reasoning was actually correct.

I had simply written the wrong comparison while coding.

This distinction matters.

Conceptual mistakes require deeper revision.

Typing or implementation mistakes require more careful coding practice.

I should never confuse the two.

---

## Another Important Realization

The very first condition should be

```cpp
if(arr[mid] == target)
```

Only after eliminating the possibility that the middle element is the answer should I spend effort identifying the sorted half.

This keeps the reasoning clean and avoids unnecessary work.

---

# Find Minimum in Rotated Sorted Array

At first this looked similar to the previous problem.

Eventually I realized the objective had changed.

Previously,

I was searching for a target.

Now,

I was searching for the smallest element.

The algorithm changes because the objective changes.

---

## Key Invariant

Compare

```cpp
arr[mid]
```

with

```cpp
arr[r]
```

If

```cpp
arr[mid] > arr[r]
```

the minimum must lie to the right.

Otherwise,

the minimum is either

* at `mid`, or
* somewhere to the left.

The important point is that this reasoning applies to the **current search space**, not necessarily to the original array.

That refinement made my understanding much stronger.

---

# Search in Rotated Sorted Array II (Duplicates)

This was the final Binary Search pattern.

Everything worked perfectly until duplicates appeared.

Then the usual invariant failed.

---

## Biggest Realization

When

```cpp
arr[l] == arr[mid] == arr[r]
```

I lose information.

I cannot determine which half is sorted.

Neither comparison tells me anything useful.

This is the only situation where Binary Search temporarily loses its power to discard half the search space.

---

## Handling Ambiguity

The correct response is not to guess.

Instead,

remove the ambiguity.

```cpp
l++;
r--;
```

Then repeat with a new search space.

This preserves correctness.

---

## Personal Mistake

Initially, after changing

```cpp
l
```

and

```cpp
r
```

I continued executing the rest of the iteration using the old

```cpp
mid
```

Eventually I understood why this is wrong.

`mid` was computed using the previous boundaries.

After changing the search space,

a new midpoint must be calculated.

Using

```cpp
continue;
```

forces the next iteration to recompute everything consistently.

---

## Complexity Discussion

This also answered an important interview question.

Normally Binary Search removes half the search space.

With many duplicates,

I sometimes remove only two elements.

For example,

```text
1 1 1 1 1 1 1
```

The search space shrinks very slowly.

Therefore,

Worst Case:

```text
O(n)
```

Average Case:

```text
O(log n)
```

Understanding *why* the complexity changes is more important than memorizing the result.

---

# Chapter 12 — Pattern Recognition

This became the most valuable lesson of the entire Binary Search topic.

Instead of asking

"Have I solved this exact problem before?"

I now ask

"What family does this belong to?"

This single habit dramatically reduces memorization.

---

## Family 1 — Standard Binary Search

Search directly inside a sorted array.

---

## Family 2 — Boundary Search

Search for the first or last valid position.

Examples:

* Lower Bound
* Upper Bound
* First Occurrence
* Last Occurrence

---

## Family 3 — Binary Search on Answer

Search the answer itself.

Requirements:

* A valid answer range.
* A monotonic feasibility condition.
* A helper that returns YES or NO.

---

## Family 4 — Rotated Sorted Array

Look for the hidden sorted half.

Use it to eliminate half of the search space.

---

# My Personal Mistake Ledger

These are the mistakes that mattered most during my learning.

### Binary Search Fundamentals

* I initially focused too much on memorizing conditions.
* Eventually I learned to derive them from the invariant.

---

### Binary Search on Answer

* I confused finding an answer with checking whether an answer was feasible.
* I expected the helper function to solve the problem.
* Eventually I understood that the helper only verifies a candidate answer.

---

### Allocate Books

* Initially thought books should be divided equally.
* Eventually understood the helper only checks feasibility under a page limit.

---

### Aggressive Cows

* Treated distance like an accumulated quantity.
* Eventually understood every decision depends only on the last placed cow.

---

### Pattern Recognition

One of the biggest changes in my thinking.

I stopped memorizing problems.

I started recognizing invariants.

The stories changed.

The algorithms rarely did.

---

### Rotated Arrays

* Initially mixed the logic for finding the minimum with the logic for searching a target.
* Learned that the objective determines the invariant.

---

### Duplicates

* Learned that equality destroys information.
* When no useful information exists, shrink the boundaries instead of guessing.

---

### C++ Function Control Flow

A small but important language lesson.

`return` immediately exits the current function.

Any statement written after a `return` inside the same function is unreachable.

This became important while implementing Binary Search correctly.

---

# Interview Checklist

Before writing a single line of code, I should ask:

1. What is my search space?
2. Is Binary Search actually applicable?
3. What invariant allows me to discard half?
4. Am I searching an array or an answer?
5. If searching an answer, what is the feasibility function?
6. Am I looking for the first feasible answer or the last feasible answer?
7. If the array is rotated, which half is guaranteed to be sorted?
8. Can duplicates remove that guarantee?
9. Can I explain every comparison instead of memorizing it?

If I cannot answer these questions, I should continue reasoning before coding.

---

# Final Reflection

Binary Search is no longer just an algorithm to me.

It is a way of reasoning about problems.

Across these problems, the greatest lesson was not learning different implementations.

The greatest lesson was learning to identify invariants, recognize patterns, and justify every decision.

Whenever I face a new Binary Search problem in the future, I should remember one principle above all others:

> **Do not start by writing code. Start by understanding the search space, discovering the invariant, and proving why one half can be discarded.**

If I can answer those questions confidently, the implementation will follow naturally.
