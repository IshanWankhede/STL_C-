# C++ STL Priority Queue Notes

# What is a Priority Queue?

A **Priority Queue** is a **container adapter** provided by the C++ Standard Template Library (STL).

Unlike a normal queue (FIFO), elements are removed based on their **priority**, **not** on the order in which they were inserted.

By default, the element with the **highest value** has the highest priority.

Header File

```cpp
#include <queue>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use Priority Queue?

A normal queue removes elements in FIFO order.

Priority Queue removes the element with the **highest priority** first.

Examples:

- CPU Scheduling
- Task Scheduling
- Dijkstra's Algorithm
- Prim's Algorithm
- Huffman Coding
- Event Simulation
- Hospital Emergency System
- Operating System Scheduling

---

# Types of Priority Queue

## 1. Max Heap (Default)

The **largest element** always comes first.

Declaration

```cpp
priority_queue<int> pq;
```

Example

Insert

```
40 10 50 20 30
```

Removal Order

```
50

40

30

20

10
```

---

## 2. Min Heap

The **smallest element** always comes first.

Declaration

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

Example

Insert

```
40 10 50 20 30
```

Removal Order

```
10

20

30

40

50
```

---

# Internal Working

A Priority Queue is implemented using a **Binary Heap**.

By default,

```
priority_queue

↓

Binary Heap

↓

vector
```

The heap is stored inside a **vector**.

---

# Binary Heap

A Binary Heap is a **Complete Binary Tree**.

Example

Insert

```
40

10

50

20

30
```

Max Heap

```
          50
         /  \
       30    40
      / \
    10   20
```

The root always contains the highest priority element.

---

# Characteristics

- Dynamic Size
- Highest Priority Element at Top
- Fast Insertion
- Fast Deletion
- No Random Access
- No Iterators
- Heap Based

---

# Creating a Priority Queue

## Max Heap

```cpp
priority_queue<int> pq;
```

Initially

```
Size = 0

Empty = true
```

---

## Min Heap

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

---

# Priority Queue Functions

---

## push()

Adds an element.

Syntax

```cpp
pq.push(value);
```

Example

```cpp
pq.push(40);
pq.push(10);
pq.push(50);
```

Max Heap

```
Top

↓

50
```

Time Complexity

```
O(log n)
```

---

## pop()

Removes the highest priority element.

Syntax

```cpp
pq.pop();
```

Before

```
50

40

30

20
```

After

```
40

30

20
```

> **Note:** `pop()` removes the element but **does not return** it. Use `top()` first if you need its value.

Time Complexity

```
O(log n)
```

---

## top()

Returns the highest priority element.

Syntax

```cpp
pq.top();
```

Example

```
50

40

30
```

Output

```
50
```

Time Complexity

```
O(1)
```

---

## size()

Returns the number of elements.

Syntax

```cpp
pq.size();
```

Example

```
50

40

30
```

Output

```
Size = 3
```

Time Complexity

```
O(1)
```

---

## empty()

Checks whether the priority queue is empty.

Syntax

```cpp
pq.empty();
```

Returns

```
true
```

or

```
false
```

Time Complexity

```
O(1)
```

---

## swap()

Swaps two priority queues.

Syntax

```cpp
pq1.swap(pq2);
```

Time Complexity

```
O(1)
```

---

# Max Heap Example

```cpp
priority_queue<int> pq;

pq.push(40);
pq.push(10);
pq.push(50);
pq.push(20);
```

Output

```
Top = 50
```

Removing Elements

```
50

40

20

10
```

---

# Min Heap Example

```cpp
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(40);
pq.push(10);
pq.push(50);
pq.push(20);
```

Output

```
Top = 10
```

Removing Elements

```
10

20

40

50
```

---

# Traversing a Priority Queue

A Priority Queue **does not provide iterators**.

To display all elements, make a copy.

```cpp
priority_queue<int> temp = pq;

while(!temp.empty())
{
    cout << temp.top() << " ";
    temp.pop();
}
```

The original priority queue remains unchanged.

---

# Heap Representation

Suppose we insert

```
40

10

50

20

30
```

Heap

```
          50
         /  \
       30    40
      / \
    10   20
```

Array Representation

```
50 30 40 10 20
```

The heap is internally stored in a vector.

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| push() | O(log n) |
| pop() | O(log n) |
| top() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |

---

# Queue vs Priority Queue

| Queue | Priority Queue |
|--------|----------------|
| FIFO | Highest Priority First |
| First inserted removed first | Highest priority removed first |
| front() | top() |
| Order is preserved | Order depends on priority |

Example

Queue

```
Insert

10

20

30

Remove

10
```

Priority Queue

```
Insert

10

20

30

Remove

30
```

---

# Max Heap vs Min Heap

| Max Heap | Min Heap |
|-----------|-----------|
| Largest element on top | Smallest element on top |
| Default Priority Queue | Uses `greater<int>` |
| Highest value removed first | Lowest value removed first |

---

# Limitations

Priority Queue does **not support**

```cpp
pq[0]
```

```cpp
pq.at(0)
```

```cpp
pq.begin()
```

```cpp
pq.end()
```

```cpp
for(int x : pq)
```

These operations are invalid because the underlying heap structure is hidden.

---

# Applications

Priority Queues are used in

- Dijkstra's Shortest Path Algorithm
- Prim's Minimum Spanning Tree Algorithm
- Huffman Coding
- CPU Scheduling
- Task Scheduling
- Event Simulation
- Hospital Emergency Systems
- Network Routing
- AI Search Algorithms (A*)
- Job Scheduling

---

# Interview Points

- `priority_queue` is a **container adapter**.
- By default, it behaves as a **Max Heap**.
- It is implemented using a **Binary Heap** stored inside a `vector`.
- `top()` returns the highest priority element.
- `pop()` removes the highest priority element but does **not** return it.
- It does **not** support indexing, iterators, or range-based `for` loops.
- To create a **Min Heap**, use:

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

- `push()` and `pop()` take **O(log n)** time because the heap property must be maintained.
- `top()`, `size()`, and `empty()` take **O(1)** time.

---

# Summary

- **Priority Queue** is a container adapter that removes elements based on **priority** instead of insertion order.
- By default, it is a **Max Heap**, where the largest element is always at the top.
- It can also be configured as a **Min Heap** using `greater<int>`.
- It is internally implemented using a **Binary Heap** stored in a `vector`.
- It provides efficient insertion and deletion while always keeping the highest-priority element accessible.
- Common functions include `push()`, `pop()`, `top()`, `size()`, `empty()`, and `swap()`.
- Priority queues are widely used in graph algorithms, scheduling systems, simulations, and many optimization problems.