# C++ STL Queue Notes

# What is a Queue?

A **queue** is a **container adapter** provided by the C++ Standard Template Library (STL).

It stores elements in **FIFO (First In First Out)** order.

This means:

- The **first element inserted** is the **first element removed**.

Think of a queue like people standing in a line for a ticket.

```
Front                               Back

↓

10 → 20 → 30 → 40

                   ↑
```

- New elements are inserted at the **Back (Rear)**.
- Elements are removed from the **Front**.

Header File

```cpp
#include <queue>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use Queue?

A queue is used whenever the **order of processing matters**.

Examples:

- Printer Queue
- Ticket Reservation
- CPU Scheduling
- Breadth First Search (BFS)
- Task Scheduling
- Message Queues
- Call Center Systems

---

# FIFO Principle

Queue follows

```
FIFO

First In

↓

First Out
```

Example

Insert

```
10

↓

10 20

↓

10 20 30

↓

10 20 30 40
```

Remove

```
10 removed

↓

20 30 40
```

The oldest element always leaves first.

---

# Internal Working

By default,

A queue is implemented using a **deque (double-ended queue)** internally.

```
queue

↓

deque

↓

Memory
```

Although it uses a deque internally, the queue exposes only a restricted interface.

You can only perform operations from the front and the back.

---

# Characteristics of Queue

- FIFO Data Structure
- Dynamic Size
- Fast insertion
- Fast deletion
- No random access
- No indexing
- No iterators

---

# Creating a Queue

```cpp
queue<int> q;
```

Initially

```
Size = 0

Empty = true
```

---

# Queue Operations

---

## push()

Adds an element at the **back** of the queue.

Syntax

```cpp
q.push(value);
```

Example

```cpp
q.push(10);
q.push(20);
q.push(30);
```

Queue

```
Front

↓

10 20 30

         ↑

       Back
```

Time Complexity

```
O(1)
```

---

## pop()

Removes the element from the **front**.

Syntax

```cpp
q.pop();
```

Before

```
10 20 30
```

After

```
20 30
```

Notice

`pop()` **does not return** the removed element.

To access it first use

```cpp
q.front();
```

Time Complexity

```
O(1)
```

---

## front()

Returns the first element.

Syntax

```cpp
q.front();
```

Example

```
10 20 30
```

Output

```
10
```

Time Complexity

```
O(1)
```

---

## back()

Returns the last element.

Syntax

```cpp
q.back();
```

Example

```
10 20 30
```

Output

```
30
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
q.size();
```

Example

```
10 20 30
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

Checks whether the queue is empty.

Syntax

```cpp
q.empty();
```

Returns

```
true
```

or

```
false
```

Example

```
Queue

10 20

↓

false
```

After removing everything

```
{}

↓

true
```

Time Complexity

```
O(1)
```

---

## swap()

Swaps two queues.

Syntax

```cpp
q1.swap(q2);
```

Before

```
Queue 1

10 20 30

Queue 2

100 200 300
```

After

```
Queue 1

100 200 300

Queue 2

10 20 30
```

Time Complexity

```
O(1)
```

---

# Traversing a Queue

Unlike vectors and lists,

A queue **does not provide iterators**.

The only way to display elements is by making a copy.

Example

```cpp
queue<int> temp=q;

while(!temp.empty())
{
    cout<<temp.front()<<" ";
    temp.pop();
}
```

Original queue remains unchanged.

---

# Queue Memory Representation

```
Front                         Back

↓

+----+----+----+----+

|10 |20 |30 |40 |

+----+----+----+----+

                      ↑

                   push()
```

Removing

```
Front

↓

10 removed

↓

20 30 40
```

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| push() | O(1) |
| pop() | O(1) |
| front() | O(1) |
| back() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |

---

# Queue vs Stack

| Queue | Stack |
|---------|--------|
| FIFO | LIFO |
| Insertion at Back | Insertion at Top |
| Deletion from Front | Deletion from Top |
| front() | top() |
| back() | No back() |

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

Stack

```
Push

10

20

30

Pop

30
```

---

# Limitations of Queue

Queue does **not support**

```cpp
q[0]
```

```cpp
q.at(0)
```

```cpp
q.begin()
```

```cpp
q.end()
```

```cpp
for(int x:q)
```

These operations are **invalid** because a queue hides its underlying container.

---

# Applications of Queue

Queues are used in

- Breadth First Search (BFS)
- CPU Scheduling
- Printer Queue
- Ticket Reservation System
- Call Center Management
- Process Scheduling
- Task Scheduling
- Message Passing Systems
- Web Server Request Handling
- Streaming Data Processing

---

# Interview Points

- Queue follows **FIFO (First In First Out)**.
- Elements are inserted using `push()` at the back.
- Elements are removed using `pop()` from the front.
- `front()` returns the first element.
- `back()` returns the last element.
- `pop()` removes an element but **does not return** it.
- Queue does **not** support indexing (`q[0]`) or random access.
- Queue does **not** expose iterators, so you cannot use range-based `for` loops or iterator traversal.
- By default, `std::queue` is implemented using a **`std::deque`** as its underlying container.
- All primary queue operations (`push`, `pop`, `front`, `back`, `size`, `empty`) have **O(1)** time complexity.

---

# Summary

- **Queue** is a container adapter that follows the **FIFO (First In First Out)** principle.
- New elements are added at the **back** and removed from the **front**.
- It is ideal for scenarios where elements must be processed in the order they arrive.
- It provides fast insertion and deletion but does not allow random access or iteration.
- Common functions include `push()`, `pop()`, `front()`, `back()`, `size()`, `empty()`, and `swap()`.
- Queues are widely used in scheduling algorithms, BFS, request handling, and many real-world systems.