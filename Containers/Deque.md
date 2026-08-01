# C++ STL Deque Notes

# What is a Deque?

A **Deque (Double Ended Queue)** is a sequence container provided by the C++ Standard Template Library (STL).

A deque allows insertion and deletion from **both the front and the back** efficiently.

Think of it as a combination of a **vector** and a **queue**.

```
Front                           Back

↓

10 20 30 40

                  ↑
```

You can:

- Insert at the Front
- Insert at the Back
- Delete from the Front
- Delete from the Back

Header File

```cpp
#include <deque>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use Deque?

A vector allows fast insertion only at the end.

A queue allows insertion at the back and deletion at the front.

A deque combines both advantages.

Use deque when you need fast operations from **both ends**.

---

# Characteristics of Deque

- Dynamic Size
- Random Access Supported
- Fast insertion at Front
- Fast insertion at Back
- Fast deletion at Front
- Fast deletion at Back
- Supports Iterators
- Supports Indexing

---

# Internal Working

Unlike a vector,

A deque is **not stored in one contiguous block of memory**.

Instead, it is stored as multiple fixed-size memory blocks connected internally.

```
+-----------+

10 20 30

+-----------+

↓

+-----------+

40 50 60

+-----------+

↓

+-----------+

70 80

+-----------+
```

This allows efficient insertion and deletion from both ends.

---

# Advantages of Deque

- Dynamic Size
- Fast insertion at front
- Fast insertion at back
- Fast deletion at front
- Fast deletion at back
- Supports indexing
- Supports iterators
- Better than vector for front operations

---

# Disadvantages of Deque

- Uses more memory than vector
- Slightly slower random access than vector
- Memory is not contiguous

---

# Vector vs Deque

| Vector | Deque |
|---------|-------|
| Contiguous Memory | Multiple Memory Blocks |
| Fast Back Insertion | Fast Front & Back Insertion |
| Slow Front Insertion | Fast Front Insertion |
| Supports Random Access | Supports Random Access |

---

# Creating a Deque

## Empty Deque

```cpp
deque<int> dq;
```

---

## Deque with Size

```cpp
deque<int> dq(5);
```

Output

```
0 0 0 0 0
```

---

## Deque with Initial Value

```cpp
deque<int> dq(5,100);
```

Output

```
100 100 100 100 100
```

---

## Copy Constructor

```cpp
deque<int> dq2(dq1);
```

---

# Deque Functions

---

## push_back()

Adds an element at the back.

```cpp
dq.push_back(10);
```

Time Complexity

```
O(1)
```

---

## push_front()

Adds an element at the front.

```cpp
dq.push_front(5);
```

Time Complexity

```
O(1)
```

---

## pop_back()

Removes the last element.

```cpp
dq.pop_back();
```

Time Complexity

```
O(1)
```

---

## pop_front()

Removes the first element.

```cpp
dq.pop_front();
```

Time Complexity

```
O(1)
```

---

## front()

Returns the first element.

```cpp
dq.front();
```

Time Complexity

```
O(1)
```

---

## back()

Returns the last element.

```cpp
dq.back();
```

Time Complexity

```
O(1)
```

---

## size()

Returns the number of elements.

```cpp
dq.size();
```

Time Complexity

```
O(1)
```

---

## empty()

Checks whether the deque is empty.

```cpp
dq.empty();
```

Returns

```
true
```

or

```
false
```

---

## clear()

Removes all elements.

```cpp
dq.clear();
```

Time Complexity

```
O(n)
```

---

## insert()

Inserts an element before a given iterator.

```cpp
dq.insert(dq.begin()+2,50);
```

Example

Before

```
10 20 30 40
```

After

```
10 20 50 30 40
```

Time Complexity

```
O(n)
```

---

## erase()

Removes an element or a range.

```cpp
dq.erase(dq.begin()+2);
```

Range

```cpp
dq.erase(dq.begin()+1,dq.begin()+3);
```

Time Complexity

```
O(n)
```

---

## swap()

Swaps two deques.

```cpp
dq1.swap(dq2);
```

Time Complexity

```
O(1)
```

---

## resize()

Changes the size of the deque.

```cpp
dq.resize(5);
```

Time Complexity

```
O(n)
```

---

# Accessing Elements

## [] Operator

```cpp
dq[2];
```

Returns

```
Third element
```

Time Complexity

```
O(1)
```

---

## at()

```cpp
dq.at(2);
```

Performs bounds checking.

Throws an exception if the index is invalid.

---

# Traversing a Deque

## Using Index

```cpp
for(int i=0;i<dq.size();i++)
{
    cout<<dq[i];
}
```

---

## Range-Based Loop

```cpp
for(int x:dq)
{
    cout<<x;
}
```

---

## Iterator

```cpp
deque<int>::iterator it;

for(it=dq.begin();it!=dq.end();it++)
{
    cout<<*it;
}
```

---

## Reverse Iterator

```cpp
deque<int>::reverse_iterator it;

for(it=dq.rbegin();it!=dq.rend();it++)
{
    cout<<*it;
}
```

---

# Iterators

## begin()

Returns iterator to first element.

```cpp
dq.begin();
```

---

## end()

Returns iterator after the last element.

```cpp
dq.end();
```

---

## rbegin()

Returns reverse iterator to the last element.

```cpp
dq.rbegin();
```

---

## rend()

Returns reverse iterator before the first element.

```cpp
dq.rend();
```

---

# Memory Representation

Unlike vectors,

A deque stores data in multiple memory blocks.

```
Block 1

10 20

↓

Block 2

30 40

↓

Block 3

50 60
```

Random access is still supported through an internal indexing mechanism.

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| push_back() | O(1) |
| push_front() | O(1) |
| pop_back() | O(1) |
| pop_front() | O(1) |
| front() | O(1) |
| back() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| clear() | O(n) |
| insert() | O(n) |
| erase() | O(n) |
| resize() | O(n) |
| swap() | O(1) |
| operator[] | O(1) |
| at() | O(1) |
| begin() | O(1) |
| end() | O(1) |
| rbegin() | O(1) |
| rend() | O(1) |

---

# Applications of Deque

Deques are used in:

- Sliding Window Problems
- Browser History
- Task Scheduling
- LRU Cache
- BFS Algorithms
- Undo/Redo Systems
- Job Scheduling
- Double Ended Processing

---

# Interview Points

- Deque stands for **Double Ended Queue**.
- It allows insertion and deletion from **both the front and the back** in **O(1)** time.
- Unlike a vector, a deque is **not stored in one contiguous memory block**.
- It still supports **random access** using `[]` and `at()`.
- `push_front()` is efficient in a deque but expensive in a vector.
- A deque provides iterators and supports STL algorithms.
- `std::queue` uses `std::deque` as its default underlying container.

---

# Summary

- **Deque (Double Ended Queue)** is a dynamic sequence container.
- It allows efficient insertion and deletion at **both ends**.
- It supports random access, iterators, and indexing.
- It is more flexible than a vector when front operations are required.
- Common functions include `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `front()`, `back()`, `insert()`, `erase()`, `resize()`, `swap()`, `clear()`, `begin()`, and `end()`.
- Deques are widely used in sliding window algorithms, BFS, scheduling systems, and cache implementations.