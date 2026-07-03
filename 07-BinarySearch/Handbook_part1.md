# Binary Search Handbook — Part 1

## Foundations, Standard Binary Search & Boundary Search

### *(My Personal Learning Ledger)*

---

# Why I Learned Binary Search This Way

I deliberately chose not to memorize solutions.

Instead, for every new problem, I first tried to derive the algorithm myself. Even when my logic was incomplete or incorrect, that struggle became part of my understanding.

Therefore, these notes are **not** generic Binary Search notes.

They record:

* How I thought.
* Where my reasoning failed.
* How the correct invariant was discovered.
* Interview discussions that changed my understanding.
* Mental models that allow me to solve unseen problems.

The goal of this handbook is not to remember solutions.

The goal is to become capable of deriving them again during an interview.

---

# Chapter 1 — What Binary Search Actually Is

When I first learned Binary Search, I thought it was simply:

> "Search an element in a sorted array."

Eventually I realized that this definition is far too narrow.

Binary Search is actually a method of repeatedly eliminating half of a search space whenever a property guarantees that one half cannot contain the answer.

The important part is **not** the array.

The important part is the ability to safely discard half of the search space.

This realization completely changed how I viewed Binary Search problems.

---

# The Three Questions I Must Ask Before Coding

Every Binary Search problem should begin with these questions.

### 1. What exactly is my search space?

Sometimes it is:

* array indices

Sometimes it is:

* possible answers

Sometimes it is:

* positions

Sometimes it is:

* distances

Sometimes it is:

* capacities

If I cannot identify the search space, I should not start coding.

---

### 2. Why can I eliminate half?

This is the most important question.

Binary Search only works because some property guarantees that one half cannot contain the answer.

If I cannot explain **why** one half can be discarded, then I am probably forcing Binary Search onto the wrong problem.

---

### 3. What invariant always remains true?

Every Binary Search problem has an invariant.

The invariant is the property that remains true after every iteration.

Instead of memorizing conditions like:

```cpp
arr[mid] <= arr[r]
```

I should ask:

"What truth is this condition proving?"

The invariant is what I should remember.

The code naturally follows.

---

# Binary Search Workflow

Before writing any code, I should mentally follow this order.

1. Identify the search space.
2. Identify the invariant.
3. Decide how to eliminate half.
4. Write the Binary Search.

Coding should always be the last step.

Reasoning comes first.

---

# Chapter 2 — Standard Binary Search

This is the first Binary Search pattern.

Unlike later problems, here I am searching directly inside a sorted array.

The search space consists of indices.

Every comparison immediately removes half of the remaining elements.

---

## Mental Model

Imagine looking for a word inside a dictionary.

You never start from page one.

You open near the middle.

One comparison tells you which half can never contain the answer.

You immediately throw that half away.

That is Binary Search.

---

## Invariant

At every iteration:

> If the target exists, it is guaranteed to lie inside the current search space `[l, r]`.

Everything outside this interval has already been proven impossible.

That is why updating `l` and `r` is safe.

---

## Why Mid Is Calculated Carefully

Instead of writing

```cpp
mid = (l + r) / 2;
```

I learned to write

```cpp
mid = l + (r - l) / 2;
```

Reason:

Adding two large integers may overflow.

Although many interview questions never reach that limit, writing the safer expression is considered good practice and demonstrates awareness of integer overflow.

---

## Why Binary Search Works

Suppose

```text
1 3 5 7 9 11
```

Target = 7

First comparison:

Compare target with middle.

Immediately three numbers become impossible answers.

One comparison removed half the search space.

That is why the complexity becomes

O(log n).

---

# Chapter 3 — Boundary Search Family

Initially these looked like different problems.

* First Occurrence
* Last Occurrence
* Lower Bound
* Upper Bound
* Count Occurrences

Eventually I realized they belong to the same family.

The only thing changing is the boundary I want to preserve.

The Binary Search itself never changes dramatically.

Only the invariant changes.

---

## Lower Bound

Definition:

Find the first position where the value is greater than or equal to the target.

The important realization is that Binary Search is no longer searching for equality.

Instead it is searching for the earliest valid position.

This small shift completely changes how I think about the problem.

---

## Upper Bound

Definition:

Find the first position where the value becomes strictly greater than the target.

Again,

the search is for a boundary.

Not an exact value.

---

## First Occurrence

Initially I thought finding one occurrence was enough.

Eventually I understood that even after finding the target, the search is not necessarily finished.

There may still be another valid occurrence on the left.

Therefore finding the target does not always terminate the search.

The invariant determines whether we continue.

---

## Last Occurrence

Exactly the opposite reasoning.

After finding the target,

there may still be another occurrence on the right.

Again,

the invariant decides the direction.

---

## Count Occurrences

One of the biggest simplifications I learned was:

Never count manually.

Instead,

```
Count = Last Occurrence - First Occurrence + 1
```

This converts a counting problem into two boundary problems.

Pattern recognition is more valuable than writing loops.

---

# Biggest Lesson From Boundary Search

Initially I saw five separate problems.

Eventually I realized there is only one idea.

The desired boundary changes.

The Binary Search remains almost identical.

Whenever multiple problems differ only in what boundary they preserve,

they belong to the same pattern family.

Recognizing families is far more valuable than memorizing five different solutions.

---

# Revision Summary

By the end of these topics, I should remember the following:

* Binary Search is about eliminating half of a valid search space.
* The search space is not always an array.
* Every Binary Search problem is built around an invariant.
* Coding comes after reasoning.
* Lower Bound, Upper Bound, First Occurrence, Last Occurrence, and Count Occurrences are members of one family.
* Memorizing conditions is less useful than understanding the invariant behind them.

This foundation is the base upon which every later Binary Search pattern—Binary Search on Answer and Rotated Arrays—is built.
