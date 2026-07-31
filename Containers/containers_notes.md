# C++ STL Containers Notes

# What is STL?

**STL (Standard Template Library)** is a collection of **pre-built classes and algorithms** provided by C++ to make programming easier and more efficient.

Instead of writing your own data structures like stacks, queues, linked lists, or hash tables, you can use the STL implementations, which are optimized and thoroughly tested.

STL is mainly divided into three parts:

- **Containers** → Store data
- **Iterators** → Traverse data
- **Algorithms** → Perform operations like sorting, searching, reversing, counting, etc.

---

# What are Containers?

A **Container** is an object that stores a collection of elements.

Think of a container as a "box" that holds data.

Example:

```cpp
vector<int> numbers = {10, 20, 30};
```

Here, `vector` is the container and it stores three integers.

---

# Why do we use Containers?

Without STL containers, programmers would have to implement every data structure manually.

For example:

- Dynamic Arrays
- Linked Lists
- Trees
- Hash Tables
- Stacks
- Queues

Implementing these every time would be time-consuming and error-prone.

STL provides ready-made implementations that are:

- Fast
- Efficient
- Memory optimized
- Easy to use
- Widely used in interviews and competitive programming

---

# Types of STL Containers

STL containers are divided into four categories:

```
STL Containers
│
├── Sequence Containers
│
├── Associative Containers
│
├── Unordered Associative Containers
│
└── Container Adapters
```

---

# 1. Sequence Containers

Sequence containers store elements **in the order they are inserted**.

Every element has a position (index or node).

Examples:

- vector
- deque
- list
- array
- forward_list

Example:

```
10 20 30 40 50
```

The order remains the same.

Sequence containers are mainly used when ordering matters.

---

# 2. Associative Containers

Associative containers store elements in **sorted order** automatically.

They use balanced binary search trees (usually Red-Black Trees).

Examples:

- set
- multiset
- map
- multimap

Example:

Inserted:

```
40 10 30 20
```

Stored:

```
10 20 30 40
```

Sorting happens automatically.

---

# 3. Unordered Associative Containers

These containers use **hash tables**.

Elements are **not stored in sorted order**.

Searching, insertion, and deletion are usually O(1).

Examples:

- unordered_set
- unordered_multiset
- unordered_map
- unordered_multimap

Example:

Inserted:

```
40 10 30 20
```

Stored:

```
30 40 20 10
```

Order is unpredictable.

---

# 4. Container Adapters

Container adapters provide a restricted interface built on top of another container.

Examples:

- stack
- queue
- priority_queue

These containers expose only specific operations.

For example:

Stack:

```
Push
Push
Push

↓

Top
```

Queue:

```
Front → → → Back
```

---

# Classification Table

| Category | Containers |
|-----------|------------|
| Sequence | vector, deque, list, array, forward_list |
| Associative | set, multiset, map, multimap |
| Unordered Associative | unordered_set, unordered_multiset, unordered_map, unordered_multimap |
| Container Adapters | stack, queue, priority_queue |

---

# Sequence Containers

Sequence containers store elements one after another.

They preserve insertion order.

Different sequence containers differ in how they store data internally.

---

## 1. vector

A vector is a **dynamic array**.

Unlike normal arrays, vectors can grow and shrink automatically.

### Characteristics

- Dynamic size
- Random access
- Fast insertion at the end
- Contiguous memory

Example:

```
Index

0   1   2   3

10  20  30  40
```

### Advantages

- Fast random access
- Efficient memory
- Most commonly used STL container

### Disadvantages

- Inserting in the middle is expensive
- Deleting from the middle is expensive

---

## 2. deque

Deque means **Double Ended Queue**.

Insertion and deletion can happen from both ends.

```
Front

↓

10 20 30 40

↑

Back
```

Advantages:

- Fast insertion at front
- Fast insertion at back

---

## 3. list

A list is implemented as a **Doubly Linked List**.

Each node stores:

```
Previous Pointer
Data
Next Pointer
```

Advantages:

- Fast insertion anywhere
- Fast deletion anywhere

Disadvantages:

- No random access
- More memory required

---

## 4. forward_list

A singly linked list.

Each node stores:

```
Data
Next Pointer
```

Uses less memory than `list`.

---

## 5. array

A fixed-size container.

Size cannot change.

Example:

```
10 20 30 40
```

Advantages:

- Very fast
- No dynamic memory allocation

Disadvantages:

- Fixed size

---

# Associative Containers

Associative containers automatically keep data sorted.

They are implemented using balanced binary search trees.

---

## set

Stores only unique values.

Automatically sorts them.

Example:

Inserted:

```
5 1 4 2 5
```

Stored:

```
1 2 4 5
```

Duplicate removed.

---

## multiset

Allows duplicate values.

Example:

Inserted:

```
5 1 5 2
```

Stored:

```
1 2 5 5
```

---

## map

Stores key-value pairs.

Example:

```
Roll Number → Name

101 → Rahul

102 → Priya

103 → Aman
```

Keys are unique.

Automatically sorted by key.

---

## multimap

Same as map.

Difference:

Multiple values can have the same key.

---

# Unordered Associative Containers

Implemented using hash tables.

No sorting.

Average O(1) operations.

---

## unordered_set

Unique elements.

No sorting.

Example:

```
50 10 30 20
```

Storage order is unpredictable.

---

## unordered_multiset

Allows duplicates.

No sorting.

---

## unordered_map

Stores key-value pairs.

Keys are unique.

Very fast lookup.

Most commonly used in interview questions.

Example:

```
Name → Marks

Rahul → 95

Priya → 90
```

---

## unordered_multimap

Allows duplicate keys.

Uses hashing.

---

# Container Adapters

These containers are built using other containers.

---

## stack

Follows **LIFO (Last In First Out)**.

Example:

```
Push 10

Push 20

Push 30

Top

↓

30
20
10
```

Examples:

- Browser history
- Undo operation
- Function calls

---

## queue

Follows **FIFO (First In First Out)**.

Example:

```
Front

↓

10 20 30 40

↑

Back
```

Examples:

- Ticket booking
- Printer queue
- CPU scheduling

---

## priority_queue

Stores elements according to priority.

By default:

Largest element stays on top.

Example:

Inserted:

```
10 50 20 80
```

Top:

```
80
```

Implemented using a heap.

---

# Choosing the Right Container

| Situation | Best Container |
|-----------|----------------|
| Dynamic Array | vector |
| Insert/Delete at Front | deque |
| Frequent Insert/Delete Anywhere | list |
| Fixed Size Data | array |
| Unique Sorted Data | set |
| Duplicate Sorted Data | multiset |
| Key-Value Sorted | map |
| Fast Key Lookup | unordered_map |
| Unique Fast Lookup | unordered_set |
| LIFO Operations | stack |
| FIFO Operations | queue |
| Highest Priority First | priority_queue |

---

# Complexity Comparison

| Container | Search | Insert | Delete |
|-----------|--------|--------|--------|
| vector | O(n) | O(1) at end | O(n) |
| deque | O(n) | O(1) at both ends | O(1) at both ends |
| list | O(n) | O(1) | O(1) |
| set | O(log n) | O(log n) | O(log n) |
| map | O(log n) | O(log n) | O(log n) |
| unordered_set | O(1) Average | O(1) Average | O(1) Average |
| unordered_map | O(1) Average | O(1) Average | O(1) Average |
| stack | O(1) | O(1) | O(1) |
| queue | O(1) | O(1) | O(1) |
| priority_queue | O(n) Search | O(log n) | O(log n) |

---

# Summary

- **Sequence Containers** preserve insertion order.
- **Associative Containers** automatically sort elements.
- **Unordered Associative Containers** use hash tables for fast access.
- **Container Adapters** provide specialized interfaces such as stack, queue, and priority queue.
- **vector** is the most frequently used STL container.
- **unordered_map** is one of the most important containers for coding interviews due to its average O(1) lookup time.
- Choosing the correct container depends on your use case, such as fast lookup, ordered storage, dynamic resizing, or insertion/deletion performance.