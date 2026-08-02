# C++ STL Set Notes

# What is a Set?

A **Set** is an associative container provided by the C++ Standard Template Library (STL).

A set stores **unique elements** in **sorted (ascending) order**.

If duplicate values are inserted, they are **automatically ignored**.

Header File

```cpp
#include <set>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use a Set?

A set is useful when you need to:

- Store only **unique elements**.
- Automatically keep elements **sorted**.
- Perform fast searching, insertion, and deletion.
- Remove duplicate values from a collection.

Example

Input

```
10 20 30 20 10 40 50
```

Stored in Set

```
10 20 30 40 50
```

Duplicates are removed automatically.

---

# Characteristics of Set

- Stores only **unique elements**
- Automatically sorts elements in ascending order
- Duplicate elements are ignored
- Implemented using a **Red-Black Tree**
- Supports iterators
- Does not support indexing (`[]`)

---

# Internal Working

A `set` is internally implemented using a **Red-Black Tree**, which is a self-balancing Binary Search Tree.

Example

```
         30
        /  \
      20    50
     / \    / \
   10 25 40 60
```

The tree remains balanced after every insertion and deletion.

Therefore,

- Searching is fast
- Insertion is fast
- Deletion is fast

Time Complexity

```
O(log n)
```

---

# Creating a Set

## Empty Set

```cpp
set<int> s;
```

---

## Set with Initial Values

```cpp
set<int> s = {10,20,30,40};
```

---

# Inserting Elements

```cpp
s.insert(40);
s.insert(20);
s.insert(10);
s.insert(50);
```

Output

```
10

20

40

50
```

Notice that elements are automatically sorted.

---

# Duplicate Elements

```cpp
s.insert(20);
s.insert(20);
s.insert(20);
```

Output

```
20
```

Only one copy is stored.

---

# size()

Returns the number of elements.

```cpp
s.size();
```

Example

```
10

20

30
```

Output

```
3
```

Time Complexity

```
O(1)
```

---

# empty()

Checks whether the set is empty.

```cpp
s.empty();
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

# find()

Searches for an element.

Syntax

```cpp
s.find(20);
```

Returns

- Iterator to the element if found.
- `s.end()` if not found.

Example

```cpp
if(s.find(20)!=s.end())
{
    cout<<"Found";
}
```

Time Complexity

```
O(log n)
```

---

# count()

Checks whether an element exists.

```cpp
s.count(20);
```

Returns

```
1
```

or

```
0
```

Since duplicates are not allowed, the answer is always **0 or 1**.

---

# erase()

Removes an element.

```cpp
s.erase(30);
```

Before

```
10

20

30

40
```

After

```
10

20

40
```

Time Complexity

```
O(log n)
```

---

# clear()

Removes all elements.

```cpp
s.clear();
```

Output

```
Size = 0
```

Time Complexity

```
O(n)
```

---

# swap()

Swaps two sets.

```cpp
s1.swap(s2);
```

Time Complexity

```
O(1)
```

---

# lower_bound()

Returns the **first element greater than or equal to** the given value.

```cpp
s.lower_bound(25);
```

Example

Set

```
10 20 30 40 50
```

Output

```
30
```

Time Complexity

```
O(log n)
```

---

# upper_bound()

Returns the **first element strictly greater than** the given value.

```cpp
s.upper_bound(30);
```

Example

Set

```
10 20 30 40 50
```

Output

```
40
```

Time Complexity

```
O(log n)
```

---

# Traversing a Set

## Range-Based Loop

```cpp
for(auto x : s)
{
    cout << x << " ";
}
```

---

## Iterator

```cpp
set<int>::iterator it;

for(it=s.begin();it!=s.end();it++)
{
    cout<<*it<<" ";
}
```

---

## Reverse Iterator

```cpp
set<int>::reverse_iterator rit;

for(rit=s.rbegin();rit!=s.rend();rit++)
{
    cout<<*rit<<" ";
}
```

---

# Iterators

## begin()

Returns iterator to the first element.

```cpp
s.begin();
```

---

## end()

Returns iterator after the last element.

```cpp
s.end();
```

---

## rbegin()

Returns reverse iterator to the last element.

```cpp
s.rbegin();
```

---

## rend()

Returns reverse iterator before the first element.

```cpp
s.rend();
```

---

# Example

```cpp
set<int> s;

s.insert(50);
s.insert(10);
s.insert(30);
s.insert(20);
s.insert(20);
```

Output

```
10

20

30

50
```

Notice

- Sorted automatically
- Duplicate `20` ignored

---

# Memory Representation

```
Set

↓

Red-Black Tree

↓

         30
        /  \
      20    50
     / \    / \
   10 25 40 60
```

Elements are stored according to their values, not insertion order.

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| insert() | O(log n) |
| erase() | O(log n) |
| find() | O(log n) |
| count() | O(log n) |
| lower_bound() | O(log n) |
| upper_bound() | O(log n) |
| size() | O(1) |
| empty() | O(1) |
| clear() | O(n) |
| swap() | O(1) |
| begin() | O(1) |
| end() | O(1) |

---

# Set vs Unordered Set

| Set | Unordered Set |
|------|---------------|
| Sorted | Unsorted |
| Red-Black Tree | Hash Table |
| O(log n) | Average O(1) |
| Supports `lower_bound()` | ❌ No |
| Supports `upper_bound()` | ❌ No |
| Ordered Traversal | Random Traversal |

---

# Set vs Multiset

| Set | Multiset |
|------|----------|
| Duplicate Elements ❌ | Duplicate Elements ✅ |
| Sorted | Sorted |
| Unique Values | Multiple Copies Allowed |

Example

```cpp
set<int> s;

s.insert(10);
s.insert(10);
```

Output

```
10
```

---

```cpp
multiset<int> ms;

ms.insert(10);
ms.insert(10);
```

Output

```
10

10
```

---

# Applications of Set

Sets are commonly used in:

- Removing Duplicate Elements
- Dictionary Applications
- Searching Data
- Database Indexing
- Graph Algorithms
- Competitive Programming
- Maintaining Unique IDs
- Mathematics (Union, Intersection, Difference)

---

# Interview Points

- `set` stores **unique elements only**.
- Elements are automatically stored in **ascending order**.
- Internally implemented using a **Red-Black Tree**.
- Searching, insertion, and deletion take **O(log n)** time.
- Duplicate values are ignored.
- `find()` returns an iterator.
- `count()` returns **0 or 1**.
- `lower_bound(x)` returns the first element **≥ x**.
- `upper_bound(x)` returns the first element **> x**.
- `set` supports iterators but **does not support indexing**.

---

# Summary

- **Set** is an associative container that stores **unique, sorted elements**.
- Duplicate values are automatically removed.
- It is implemented using a **Red-Black Tree**, giving **O(log n)** search, insertion, and deletion.
- It supports iterators but does **not** support array-style indexing.
- Common functions include `insert()`, `erase()`, `find()`, `count()`, `lower_bound()`, `upper_bound()`, `clear()`, `swap()`, `begin()`, and `end()`.
- Sets are widely used when unique elements and ordered storage are required.

---

# Quick Revision

| Feature | Set |
|---------|-----|
| Header File | `#include <set>` |
| Stores | Unique Elements |
| Duplicate Values | ❌ Not Allowed |
| Sorted | ✅ Yes |
| Internal Structure | Red-Black Tree |
| Random Access | ❌ No |
| Iterator Support | ✅ Yes |
| Search | O(log n) |
| Insert | O(log n) |
| Delete | O(log n) |
| Best Use | Store Unique & Sorted Data |