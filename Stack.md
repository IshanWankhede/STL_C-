# C++ STL Stack Notes

# What is a Stack?

A **stack** is a **container adapter** provided by the C++ Standard Template Library (STL).

It stores elements using the **LIFO (Last In First Out)** principle.

This means:

- The **last element inserted** is the **first element removed**.

Think of a stack like a pile of books or plates.

```
        Top
         ↓
      +-----+
      | 40  |
      +-----+
      | 30  |
      +-----+
      | 20  |
      +-----+
      | 10  |
      +-----+
```

- New elements are inserted only at the **Top**.
- Elements are removed only from the **Top**.

Header File

```cpp
#include <stack>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use a Stack?

A stack is useful whenever the **most recently added element must be processed first**.

Common applications include:

- Function call stack
- Undo/Redo operations
- Browser Back button
- Expression evaluation
- Parentheses matching
- Depth First Search (DFS)
- Backtracking algorithms
- Syntax parsing

---

# LIFO Principle

Stack follows

```
LIFO

Last In

↓

First Out
```

Example

Push

```
10

↓

10 20

↓

10 20 30

↓

10 20 30 40
```

Pop

```
40 removed

↓

10 20 30
```

The newest element always leaves first.

---

# Internal Working

By default,

A stack is implemented using a **deque (double-ended queue)** internally.

```
stack

↓

deque

↓

Memory
```

You can also create a stack using a `vector` or a `list` as the underlying container.

Example

```cpp
stack<int, vector<int>> st;
```

or

```cpp
stack<int, list<int>> st;
```

However, the default container is `deque`.

---

# Characteristics of Stack

- LIFO Data Structure
- Dynamic Size
- Fast insertion
- Fast deletion
- Access only to the top element
- No indexing
- No iterators
- No random access

---

# Creating a Stack

```cpp
stack<int> st;
```

Initially

```
Size = 0

Empty = true
```

---

# Stack Operations

---

## push()

Adds an element to the **top** of the stack.

Syntax

```cpp
st.push(value);
```

Example

```cpp
st.push(10);
st.push(20);
st.push(30);
```

Stack

```
Top

↓

30

20

10
```

Time Complexity

```
O(1)
```

---

## pop()

Removes the **top** element.

Syntax

```cpp
st.pop();
```

Before

```
30

20

10
```

After

```
20

10
```

> **Note:** `pop()` **does not return** the removed element. Use `top()` first if you need its value.

Time Complexity

```
O(1)
```

---

## top()

Returns the top element without removing it.

Syntax

```cpp
st.top();
```

Example

```
30

20

10
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
st.size();
```

Example

```
30

20

10
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

Checks whether the stack is empty.

Syntax

```cpp
st.empty();
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
Stack

30

20

10

↓

false
```

After removing all elements

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

Swaps the contents of two stacks.

Syntax

```cpp
st1.swap(st2);
```

Before

```
Stack 1

3
2
1

Stack 2

300
200
100
```

After

```
Stack 1

300
200
100

Stack 2

3
2
1
```

Time Complexity

```
O(1)
```

---

# Traversing a Stack

A stack **does not provide iterators**.

The only way to display elements is by making a copy.

Example

```cpp
stack<int> temp = st;

while(!temp.empty())
{
    cout << temp.top() << " ";
    temp.pop();
}
```

The original stack remains unchanged.

---

# Stack Memory Representation

```
          Top
           ↓
      +------+
      |  50  | ← push()
      +------+
      |  40  |
      +------+
      |  30  |
      +------+
      |  20  |
      +------+
      |  10  |
      +------+
```

Removing

```
Top

↓

50 removed

↓

40
30
20
10
```

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| push() | O(1) |
| pop() | O(1) |
| top() | O(1) |
| size() | O(1) |
| empty() | O(1) |
| swap() | O(1) |

---

# Stack vs Queue

| Stack | Queue |
|--------|-------|
| LIFO | FIFO |
| Insertion at Top | Insertion at Back |
| Deletion from Top | Deletion from Front |
| `top()` | `front()` |
| Only Top is Accessible | Front and Back are Accessible |

Example

Stack

```
Push

10

20

30

Pop

30
```

Queue

```
Insert

10

20

30

Remove

10
```

---

# Limitations of Stack

Stack does **not support**

```cpp
st[0]
```

```cpp
st.at(0)
```

```cpp
st.begin()
```

```cpp
st.end()
```

```cpp
for(int x : st)
```

These operations are **invalid** because a stack hides its underlying container.

---

# Applications of Stack

Stacks are widely used in:

- Function Call Stack
- Recursive Function Execution
- Undo / Redo Operations
- Browser Back Navigation
- Parentheses Matching
- Expression Evaluation (Prefix, Infix, Postfix)
- Depth First Search (DFS)
- Backtracking Problems
- Syntax Parsing in Compilers
- String Reversal

---

# Interview Points

- Stack follows **LIFO (Last In First Out)**.
- Elements are inserted using `push()` and removed using `pop()`.
- `top()` returns the top element without removing it.
- `pop()` removes the top element but **does not return** it.
- A stack does **not** support indexing or random access.
- A stack does **not** expose iterators, so you cannot use range-based `for` loops.
- By default, `std::stack` uses a **`std::deque`** as its underlying container, but it can also use `std::vector` or `std::list`.
- All primary stack operations (`push`, `pop`, `top`, `size`, `empty`) have **O(1)** time complexity.

---

# Summary

- **Stack** is a container adapter that follows the **LIFO (Last In First Out)** principle.
- New elements are added and removed only from the **top**.
- It is ideal for scenarios where the most recently added item must be processed first.
- It provides fast insertion and deletion but does not allow random access or iteration.
- Common functions include `push()`, `pop()`, `top()`, `size()`, `empty()`, and `swap()`.
- Stacks are fundamental data structures used in recursion, DFS, expression evaluation, undo functionality, compiler design, and many other applications.