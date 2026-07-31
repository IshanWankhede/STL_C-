# C++ STL List Notes

# What is a List?

A **list** is a sequence container provided by the C++ Standard Template Library (STL).

Unlike a vector, a list stores elements as **nodes** connected using pointers.

A list is implemented as a **Doubly Linked List**, where each node contains:

- Data
- Pointer to the previous node
- Pointer to the next node

Header File:

```cpp
#include <list>
```

Namespace:

```cpp
using namespace std;
```

---

# Why Use a List?

A vector stores data in contiguous memory.

When inserting or deleting elements in the middle of a vector, all remaining elements must be shifted, making these operations expensive.

A list avoids this problem because elements are stored as separate nodes connected by pointers.

Insertion and deletion only require changing pointers.

---

# Internal Structure

Each node contains three parts.

```
+---------+-----------+---------+
| Previous|   Data    |  Next   |
+---------+-----------+---------+
```

Example:

```
NULL

↓

+------+------+------+      +------+------+------+      +------+------+------+
| Prev | 10 | Next | -----> | Prev | 20 | Next | -----> | Prev | 30 | Next |
+------+------+------+      +------+------+------+      +------+------+------+
      ^                           ^                           ^
      |                           |                           |
      +---------------------------+---------------------------+
                          Previous Links

                                                     ↓

                                                   NULL
```

---

# Advantages of List

- Dynamic size
- Fast insertion
- Fast deletion
- Efficient insertion at front
- Efficient insertion at back
- No memory reallocation
- No shifting of elements

---

# Disadvantages of List

- More memory is required because every node stores two pointers.
- No random access.
- Cannot use indexing like `list[0]`.
- Slower traversal because nodes are not stored contiguously.
- Cache performance is poorer than vectors.

---

# Vector vs List

| Vector | List |
|---------|------|
| Dynamic Array | Doubly Linked List |
| Contiguous Memory | Non-Contiguous Memory |
| Random Access Supported | Random Access Not Supported |
| Fast Searching by Index | Sequential Traversal |
| Slow Insert/Delete in Middle | Fast Insert/Delete Anywhere (given an iterator) |
| Less Memory | More Memory |

---

# Creating a List

## Empty List

```cpp
list<int> l;
```

---

## List with Size

```cpp
list<int> l(5);
```

Creates

```
0 0 0 0 0
```

---

## List with Initial Value

```cpp
list<int> l(5,100);
```

Creates

```
100 100 100 100 100
```

---

## Copy Constructor

```cpp
list<int> l2(l1);
```

Copies all elements.

---

# List Functions

---

## push_back()

Adds an element at the end.

```cpp
l.push_back(10);
```

Example

Before

```
10 20
```

After

```
10 20 30
```

Time Complexity

```
O(1)
```

---

## push_front()

Adds an element at the beginning.

```cpp
l.push_front(5);
```

Before

```
10 20 30
```

After

```
5 10 20 30
```

Time Complexity

```
O(1)
```

---

## pop_back()

Removes the last element.

```cpp
l.pop_back();
```

Before

```
10 20 30
```

After

```
10 20
```

Time Complexity

```
O(1)
```

---

## pop_front()

Removes the first element.

```cpp
l.pop_front();
```

Before

```
10 20 30
```

After

```
20 30
```

Time Complexity

```
O(1)
```

---

## front()

Returns the first element.

```cpp
l.front();
```

Output

```
10
```

---

## back()

Returns the last element.

```cpp
l.back();
```

Output

```
30
```

---

## size()

Returns the number of elements.

```cpp
l.size();
```

Example

```
10 20 30
```

```
Size = 3
```

---

## empty()

Checks whether the list is empty.

```cpp
l.empty();
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
l.clear();
```

Before

```
10 20 30
```

After

```
{}
```

Size becomes 0.

---

## insert()

Inserts an element before a given iterator.

Syntax

```cpp
l.insert(position,value);
```

Example

```cpp
auto it=l.begin();

++it;

l.insert(it,15);
```

Before

```
10 20 30
```

After

```
10 15 20 30
```

Time Complexity

```
O(1)
```

---

## erase()

Removes the element at a given iterator.

Syntax

```cpp
l.erase(iterator);
```

Example

Before

```
10 20 30
```

Erase second element

After

```
10 30
```

Time Complexity

```
O(1)
```

---

## remove()

Removes **all occurrences** of a value.

Syntax

```cpp
l.remove(value);
```

Example

Before

```
10 20 30 20 40
```

```cpp
l.remove(20);
```

After

```
10 30 40
```

Time Complexity

```
O(n)
```

---

## reverse()

Reverses the list.

```cpp
l.reverse();
```

Before

```
10 20 30 40
```

After

```
40 30 20 10
```

Time Complexity

```
O(n)
```

---

## sort()

Sorts the list.

```cpp
l.sort();
```

Before

```
40 10 30 20
```

After

```
10 20 30 40
```

Time Complexity

```
O(n log n)
```

---

## unique()

Removes **consecutive duplicate** elements.

```cpp
l.unique();
```

Before

```
10 10 20 20 30 30
```

After

```
10 20 30
```

> **Note:** `unique()` removes only **adjacent (consecutive)** duplicates. If duplicates are not next to each other (e.g., `10 20 10`), they are **not removed**. To remove all duplicates, sort the list first and then call `unique()`.

Time Complexity

```
O(n)
```

---

## swap()

Exchanges two lists.

```cpp
l1.swap(l2);
```

Before

```
l1

10 20

l2

100 200
```

After

```
l1

100 200

l2

10 20
```

Time Complexity

```
O(1)
```

---

# Traversing a List

## Range-Based Loop

```cpp
for(int x:l)
{
    cout<<x;
}
```

---

## Iterator

```cpp
list<int>::iterator it;

for(it=l.begin();it!=l.end();it++)
{
    cout<<*it;
}
```

---

## Reverse Iterator

```cpp
list<int>::reverse_iterator it;

for(it=l.rbegin();it!=l.rend();it++)
{
    cout<<*it;
}
```

---

# Iterators

An iterator acts like a pointer.

Example

```cpp
list<int>::iterator it=l.begin();
```

```
10 20 30

↑
it
```

---

## begin()

Returns iterator to first node.

```cpp
l.begin();
```

---

## end()

Returns iterator after the last node.

```cpp
l.end();
```

```
10 20 30

         ↑

       end()
```

---

## rbegin()

Returns reverse iterator pointing to the last node.

```cpp
l.rbegin();
```

---

## rend()

Returns reverse iterator before the first node.

```cpp
l.rend();
```

---

# List Memory Representation

Unlike vectors, a list is **not stored in contiguous memory**.

```
Head

↓

+-----+      +-----+      +-----+
| 10 | ----> | 20 | ----> | 30 |
+-----+      +-----+      +-----+

Separate memory locations connected by pointers
```

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
| insert() | O(1) (given an iterator) |
| erase() | O(1) (given an iterator) |
| remove() | O(n) |
| reverse() | O(n) |
| sort() | O(n log n) |
| unique() | O(n) |
| swap() | O(1) |
| begin() | O(1) |
| end() | O(1) |
| rbegin() | O(1) |
| rend() | O(1) |

---

# Interview Points

- A `list` is implemented as a **doubly linked list**.
- Elements are **not stored in contiguous memory**.
- Random access is **not supported**, so `l[0]` and `l.at(0)` do not exist.
- Insertions and deletions are efficient because only pointers need to be updated.
- Accessing the *n*th element requires sequential traversal, taking **O(n)** time.
- `remove(value)` removes **all occurrences** of the specified value.
- `unique()` removes only **consecutive duplicate** elements.
- `sort()` is a member function of `list`; you cannot use `std::sort()` on a list because it requires random-access iterators.

---

# When Should You Use a List?

Use a list when:

- Frequent insertions and deletions are required.
- Insertions/deletions happen in the middle of the container.
- Random access is **not** required.
- The size changes frequently.

Avoid using a list when:

- You need fast indexing (`arr[i]`).
- You frequently access elements by position.
- Cache performance and memory efficiency are important.

---

# Summary

- **List** is a sequence container implemented as a **doubly linked list**.
- It provides **O(1)** insertion and deletion at the front, back, or any position when you already have an iterator.
- It does **not** support indexing or random access.
- It uses more memory than a vector because each node stores pointers.
- Common functions include `push_front()`, `push_back()`, `pop_front()`, `pop_back()`, `insert()`, `erase()`, `remove()`, `sort()`, `reverse()`, `unique()`, and `swap()`.
- Use a list when insertion and deletion performance is more important than random access.