# STL Iterator Types in C++

## What is an Iterator?

An **Iterator** is an object that is used to **traverse (iterate through)** elements of an STL container.

It works like a **pointer**, allowing you to access elements one by one.

Example:

```cpp
vector<int> v = {10, 20, 30};

auto it = v.begin();

cout << *it << endl;   // 10
it++;
cout << *it << endl;   // 20
```

---

# Types of Iterators

STL defines **5 iterator categories**.

| Iterator Type          | Read | Write | Forward | Backward | Random Access |
| ---------------------- | :--: | :---: | :-----: | :------: | :-----------: |
| Input Iterator         |   ✅  |   ❌   |    ✅    |     ❌    |       ❌       |
| Output Iterator        |   ❌  |   ✅   |    ✅    |     ❌    |       ❌       |
| Forward Iterator       |   ✅  |   ✅   |    ✅    |     ❌    |       ❌       |
| Bidirectional Iterator |   ✅  |   ✅   |    ✅    |     ✅    |       ❌       |
| Random Access Iterator |   ✅  |   ✅   |    ✅    |     ✅    |       ✅       |

---

# 1. Input Iterator

## Definition

An **Input Iterator** is used to **read** elements one by one while moving **only in the forward direction**.

### Features

* Read data
* Move only forward
* Cannot move backward
* No random access

### Allowed Operations

```cpp
*it
++it
it++
```

### Not Allowed

```cpp
it--
it + 2
it[3]
```

### Example

```cpp
vector<int> v = {10,20,30};

auto it = v.begin();

cout << *it << endl;

it++;

cout << *it << endl;
```

### Real-Life Example

Reading pages of a book one by one.

```
Page1 → Page2 → Page3 → Page4
```

---

# 2. Output Iterator

## Definition

An **Output Iterator** is used to **write** values into a container.

### Features

* Write only
* Forward movement only
* Cannot read existing values

### Example

```cpp
vector<int> v;

auto it = back_inserter(v);

*it = 10;
*it = 20;

for(int x : v)
    cout << x << " ";
```

Output

```
10 20
```

### Real-Life Example

Writing answers on a blank paper.

---

# 3. Forward Iterator

## Definition

A **Forward Iterator** can **read and write** elements while moving **only forward**.

### Features

* Read
* Write
* Forward only

### Allowed Operations

```cpp
*it
++it
```

### Not Allowed

```cpp
it--
it + 3
```

### Containers

* forward_list
* unordered_set
* unordered_map

### Example

```cpp
forward_list<int> fl = {10,20,30};

for(auto it = fl.begin(); it != fl.end(); ++it)
{
    cout << *it << " ";
}
```

---

# 4. Bidirectional Iterator

## Definition

A **Bidirectional Iterator** can move **forward as well as backward**.

### Features

* Read
* Write
* Forward
* Backward

### Allowed Operations

```cpp
++it
--it
```

### Not Allowed

```cpp
it + 2
it - 2
```

### Containers

* list
* set
* map
* multiset
* multimap

### Example

```cpp
list<int> l = {10,20,30};

auto it = l.begin();

++it;
--it;

cout << *it;
```

---

# 5. Random Access Iterator

## Definition

A **Random Access Iterator** is the most powerful iterator.

It can jump directly to any position.

### Features

* Read
* Write
* Forward
* Backward
* Random Access

### Allowed Operations

```cpp
++it
--it
it + 3
it - 2
it[2]
```

### Containers

* vector
* deque
* array

### Example

```cpp
vector<int> v = {10,20,30,40,50};

auto it = v.begin();

cout << *(it + 3);
```

Output

```
40
```

---

# Container vs Iterator Type

| Container     | Iterator Category |
| ------------- | ----------------- |
| vector        | Random Access     |
| array         | Random Access     |
| deque         | Random Access     |
| list          | Bidirectional     |
| set           | Bidirectional     |
| map           | Bidirectional     |
| multiset      | Bidirectional     |
| multimap      | Bidirectional     |
| unordered_set | Forward           |
| unordered_map | Forward           |
| forward_list  | Forward           |

---

# Iterator Operations

```cpp
begin()      // First element

end()        // One position after last element

rbegin()     // Reverse begin

rend()       // Reverse end

++it         // Next element

--it         // Previous element (if supported)

next(it)     // Next iterator

prev(it)     // Previous iterator

advance(it,n) // Move iterator

distance(first,last) // Distance between iterators
```

---

# Important Notes

### `begin()`

Points to the first element.

```
10 20 30 40
↑
begin()
```

---

### `end()`

Points **one position after** the last element.

```
10 20 30 40 X
            ↑
           end()
```

---

### Dereference

```cpp
*it
```

Returns the value pointed to by the iterator.

---

### Arrow Operator

Used mainly with `map` and `unordered_map`.

```cpp
it->first
```

Returns the **key**.

```cpp
it->second
```

Returns the **value**.

Equivalent to:

```cpp
(*it).first
(*it).second
```

---

# Memory Trick

```
Input
↓

Read Only
↓

Forward
```

```
Output
↓

Write Only
↓

Forward
```

```
Forward
↓

Read + Write
↓

Forward
```

```
Bidirectional
↓

Forward + Backward
```

```
Random Access
↓

Jump Anywhere
```

---

# Interview Points

* Iterators are used to traverse STL containers.
* `begin()` points to the first element.
* `end()` points one position after the last element.
* `*it` accesses the current element.
* `it->first` returns the key in `map`.
* `it->second` returns the value in `map`.
* `vector`, `deque`, and `array` provide **Random Access Iterators**.
* `list`, `set`, and `map` provide **Bidirectional Iterators**.
* `unordered_map`, `unordered_set`, and `forward_list` provide **Forward Iterators**.
* Random Access Iterators support `it + n`, `it - n`, and indexing (`it[n]`), while other iterator categories do not.

---

# Quick Revision Table

| Iterator      | Direction    | Read | Write | Supports `it+n` |
| ------------- | ------------ | ---- | ----- | --------------- |
| Input         | Forward      | ✅    | ❌     | ❌               |
| Output        | Forward      | ❌    | ✅     | ❌               |
| Forward       | Forward      | ✅    | ✅     | ❌               |
| Bidirectional | Both         | ✅    | ✅     | ❌               |
| Random Access | Any Position | ✅    | ✅     | ✅               |
