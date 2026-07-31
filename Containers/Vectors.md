# C++ STL Vector Notes

# What is a Vector?

A **vector** is a dynamic array provided by the C++ Standard Template Library (STL).

Unlike a normal array, a vector can **grow or shrink automatically** during program execution.

It stores elements in **contiguous memory**, just like an array, which allows fast random access.

Header File:

```cpp
#include <vector>
```

Namespace:

```cpp
using namespace std;
```

---

# Why Use Vector?

Normal arrays have a fixed size.

```cpp
int arr[5];
```

If the array becomes full, you cannot add more elements.

A vector automatically allocates more memory when needed.

Example:

```cpp
vector<int> numbers;
```

As you keep inserting elements, the vector increases its capacity automatically.

---

# Advantages of Vector

- Dynamic size
- Fast random access using indexes
- Automatic memory management
- Stores elements in contiguous memory
- Easy insertion at the end
- Compatible with STL algorithms
- Supports iterators

---

# Disadvantages of Vector

- Inserting or deleting elements in the middle is slow.
- Uses extra memory because of capacity management.
- Reallocation may occur when capacity is exceeded.

---

# Internal Working of a Vector

Initially:

```
Size = 0
Capacity = 0
```

After:

```cpp
v.push_back(10);
```

```
10
```

```
Size = 1
Capacity = 1
```

After inserting another element:

```
10 20
```

```
Size = 2
Capacity = 2
```

When capacity becomes full, the vector allocates a larger memory block (typically doubling the capacity), copies the existing elements to the new block, and deletes the old block.

Example:

```
Capacity = 4

10 20 30 40
```

Insert another element:

```
New Capacity = 8

10 20 30 40 50
```

---

# Creating a Vector

## Empty Vector

```cpp
vector<int> v;
```

Creates an empty vector.

---

## Vector with Fixed Size

```cpp
vector<int> v(5);
```

Creates a vector of size 5.

All values are initialized to 0.

```
0 0 0 0 0
```

---

## Vector with Fixed Size and Initial Value

```cpp
vector<int> v(5, 100);
```

```
100 100 100 100 100
```

---

## Copy Constructor

```cpp
vector<int> v2(v1);
```

Copies all elements from `v1` into `v2`.

---

# Common Vector Functions

---

## push_back()

Adds an element at the end.

Syntax:

```cpp
v.push_back(value);
```

Example:

```cpp
vector<int> v;

v.push_back(10);
v.push_back(20);
v.push_back(30);
```

Result:

```
10 20 30
```

Time Complexity:

```
O(1) Amortized
```

---

## pop_back()

Removes the last element.

Syntax:

```cpp
v.pop_back();
```

Example:

Before:

```
10 20 30
```

After:

```
10 20
```

Time Complexity:

```
O(1)
```

---

## size()

Returns the number of elements.

Syntax:

```cpp
v.size();
```

Example:

```
10 20 30
```

```
Size = 3
```

Time Complexity:

```
O(1)
```

---

## capacity()

Returns the amount of allocated memory.

Syntax:

```cpp
v.capacity();
```

Example:

```
Size = 3

Capacity = 4
```

Capacity is always greater than or equal to size.

Time Complexity:

```
O(1)
```

---

## front()

Returns the first element.

Syntax:

```cpp
v.front();
```

Example:

```
10 20 30
```

Output:

```
10
```

---

## back()

Returns the last element.

Syntax:

```cpp
v.back();
```

Example:

```
10 20 30
```

Output:

```
30
```

---

## empty()

Checks whether the vector contains any elements.

Syntax:

```cpp
v.empty();
```

Returns:

```
true
```

or

```
false
```

---

## clear()

Removes every element.

Syntax:

```cpp
v.clear();
```

Example:

Before:

```
10 20 30
```

After:

```
{}
```

Size becomes 0.

Capacity usually remains unchanged.

---

## resize()

Changes the size of the vector.

Syntax:

```cpp
v.resize(newSize);
```

Example:

```
10 20 30
```

```cpp
v.resize(5);
```

Result:

```
10 20 30 0 0
```

Reducing:

```cpp
v.resize(2);
```

Result:

```
10 20
```

---

## assign()

Replaces all elements.

Syntax:

```cpp
v.assign(count, value);
```

Example:

```cpp
v.assign(4,50);
```

Result:

```
50 50 50 50
```

---

## swap()

Exchanges two vectors.

Syntax:

```cpp
v1.swap(v2);
```

Example:

Before:

```
v1

10 20 30

v2

100 200 300
```

After:

```
v1

100 200 300

v2

10 20 30
```

Time Complexity:

```
O(1)
```

---

## insert()

Inserts elements at a specified position.

Syntax:

```cpp
v.insert(position, value);
```

Beginning:

```cpp
v.insert(v.begin(),10);
```

Middle:

```cpp
v.insert(v.begin()+2,50);
```

End:

```cpp
v.insert(v.end(),100);
```

Example:

Before:

```
10 20 30
```

Insert 15 at index 1:

```
10 15 20 30
```

Time Complexity:

```
O(n)
```

---

## erase()

Removes one element or a range.

Single element:

```cpp
v.erase(v.begin()+2);
```

Range:

```cpp
v.erase(v.begin()+1,v.begin()+4);
```

Example:

Before:

```
10 20 30 40 50
```

After:

```
10 50
```

Time Complexity:

```
O(n)
```

---

# Accessing Elements

## [] Operator

```cpp
v[2];
```

Fast but **does not check bounds**.

If the index is invalid, the behavior is undefined.

Time Complexity:

```
O(1)
```

---

## at()

```cpp
v.at(2);
```

Checks bounds.

If the index is invalid, it throws an exception (`std::out_of_range`).

Time Complexity:

```
O(1)
```

---

# Traversing a Vector

## Using Index

```cpp
for(int i=0;i<v.size();i++)
{
    cout<<v[i];
}
```

---

## Range-Based For Loop

```cpp
for(int x:v)
{
    cout<<x;
}
```

---

## Using Iterators

```cpp
vector<int>::iterator it;

for(it=v.begin();it!=v.end();it++)
{
    cout<<*it;
}
```

---

## Reverse Iterators

```cpp
vector<int>::reverse_iterator it;

for(it=v.rbegin();it!=v.rend();it++)
{
    cout<<*it;
}
```

---

# Iterators

An **iterator** is an object that behaves like a pointer and is used to traverse elements in a container.

Example:

```cpp
vector<int>::iterator it=v.begin();
```

```
10 20 30 40

↑
it
```

---

## begin()

Returns an iterator pointing to the first element.

```cpp
v.begin();
```

---

## end()

Returns an iterator pointing **one position after the last element**.

```cpp
v.end();
```

```
10 20 30 40
            ↑
          end()
```

---

## rbegin()

Returns a reverse iterator pointing to the last element.

```cpp
v.rbegin();
```

---

## rend()

Returns a reverse iterator pointing before the first element.

```cpp
v.rend();
```

---

# Vector Memory Diagram

```
Index

0   1   2   3

10 20 30 40
```

```
begin()

↓

10 20 30 40

             ↑

           end()
```

Reverse:

```
rbegin()

↓

40 30 20 10

             ↑

           rend()
```

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| push_back() | O(1) Amortized |
| pop_back() | O(1) |
| front() | O(1) |
| back() | O(1) |
| size() | O(1) |
| capacity() | O(1) |
| empty() | O(1) |
| clear() | O(n) |
| insert() | O(n) |
| erase() | O(n) |
| resize() | O(n) (if expanding) |
| assign() | O(n) |
| swap() | O(1) |
| operator[] | O(1) |
| at() | O(1) |
| begin() | O(1) |
| end() | O(1) |
| rbegin() | O(1) |
| rend() | O(1) |

---

# Interview Points

- A vector is a **dynamic array**.
- It stores elements in **contiguous memory**.
- `push_back()` has **amortized O(1)** complexity.
- When capacity is full, the vector reallocates memory (typically doubles the capacity), copies existing elements, and deallocates the old memory.
- `size()` returns the number of elements currently stored.
- `capacity()` returns the allocated storage available before reallocation is needed.
- `operator[]` does **not** perform bounds checking.
- `at()` performs bounds checking and throws an exception if the index is invalid.
- `front()` returns the first element, while `back()` returns the last element.
- `insert()` and `erase()` in the middle of a vector are **O(n)** because elements need to be shifted.
- `swap()` exchanges two vectors in **O(1)** time by swapping their internal data.

---

# Summary

- **Vector** is the most commonly used STL sequence container.
- It combines the advantages of arrays with automatic resizing.
- It provides fast random access and efficient insertion at the end.
- It supports iterators and works seamlessly with STL algorithms like `sort()`, `find()`, `reverse()`, and `binary_search()`.
- Understanding vectors thoroughly is essential before learning other STL containers such as `deque`, `list`, `stack`, `queue`, `set`, and `map`.