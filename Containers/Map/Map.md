# C++ STL Map Notes

# What is a Map?

A **Map** is an associative container provided by the C++ Standard Template Library (STL).

A map stores data in the form of **Key-Value pairs**.

Each **key is unique**, and every key is associated with exactly one value.

Header File

```cpp
#include <map>
```

Namespace

```cpp
using namespace std;
```

---

# Why Use a Map?

A map allows us to:

- Store data using keys instead of indexes.
- Search elements quickly using keys.
- Automatically keep keys in sorted order.
- Prevent duplicate keys.

Example

```
Key        Value

IN   --->  India

US   --->  United States

UK   --->  United Kingdom
```

Instead of remembering indexes, we access values using keys.

---

# Characteristics of Map

- Stores data as **Key-Value pairs**
- Keys are **unique**
- Automatically sorts keys in **ascending order**
- Uses **Red-Black Tree** internally
- Supports Iterators
- No Random Access using indexes

---

# Internal Working

A `map` is implemented using a **Red-Black Tree**, which is a self-balancing Binary Search Tree.

Example

```
        20
       /  \
     10    40
    / \    / \
   5 15 30 50
```

Because the tree remains balanced:

- Searching is fast.
- Insertion is fast.
- Deletion is fast.

Time Complexity

```
O(log n)
```

---

# Creating a Map

## Empty Map

```cpp
map<string,string> mp;
```

---

## Integer Map

```cpp
map<int,string> mp;
```

---

## String to Integer

```cpp
map<string,int> mp;
```

---

# Inserting Elements

## Using []

```cpp
mp["IN"] = "India";
```

Example

```
IN → India
```

---

## Using insert()

```cpp
mp.insert(make_pair("US","United States"));
```

---

## Using pair

```cpp
pair<string,string> p;

p.first = "UK";
p.second = "United Kingdom";

mp.insert(p);
```

---

# Accessing Elements

## [] Operator

```cpp
cout << mp["IN"];
```

Output

```
India
```

> **Important:** If the key does not exist, `[]` creates a new key with a default value.

Example

```cpp
cout << mp["JP"];
```

Output

```
(empty string)
```

The key `"JP"` is automatically inserted.

---

## at()

```cpp
cout << mp.at("IN");
```

Output

```
India
```

> **Important:** `at()` throws an `std::out_of_range` exception if the key does not exist.

---

# Updating a Value

```cpp
mp["IN"] = "Bharat";
```

Output

```
IN → Bharat
```

---

# size()

Returns the number of key-value pairs.

```cpp
mp.size();
```

Example

```
IN
US
UK
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

Checks whether the map is empty.

```cpp
mp.empty();
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

Searches for a key.

Syntax

```cpp
mp.find("IN");
```

Returns

- Iterator to the element if found.
- `mp.end()` if not found.

Example

```cpp
if(mp.find("IN") != mp.end())
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

Checks whether a key exists.

Syntax

```cpp
mp.count("IN");
```

Returns

```
1
```

or

```
0
```

Since keys are unique, the result is always **0 or 1**.

---

# erase()

Removes a key.

```cpp
mp.erase("US");
```

Before

```
IN

US

UK
```

After

```
IN

UK
```

Time Complexity

```
O(log n)
```

---

# clear()

Removes all elements.

```cpp
mp.clear();
```

Size becomes

```
0
```

---

# swap()

Swaps two maps.

```cpp
mp1.swap(mp2);
```

Time Complexity

```
O(1)
```

---

# Traversing a Map

## Range-Based Loop

```cpp
for(auto x : mp)
{
    cout << x.first << " "
         << x.second << endl;
}
```

---

## Iterator

```cpp
map<string,string>::iterator it;

for(it = mp.begin(); it != mp.end(); it++)
{
    cout << it->first << " "
         << it->second << endl;
}
```

---

# Iterators

## begin()

Returns iterator to the first element.

```cpp
mp.begin();
```

---

## end()

Returns iterator after the last element.

```cpp
mp.end();
```

---

# Example

```cpp
map<int,string> student;

student[3]="Rohit";
student[1]="Aman";
student[2]="Priya";
```

Output

```
1 Aman

2 Priya

3 Rohit
```

Notice that the keys are automatically sorted.

---

# Memory Representation

```
Map

↓

Red-Black Tree

↓

        20
       /  \
     10    40
    / \    / \
   5 15 30 50
```

The elements are stored according to **keys**, not insertion order.

---

# Time Complexity

| Function | Complexity |
|-----------|------------|
| insert() | O(log n) |
| [] | O(log n) |
| at() | O(log n) |
| find() | O(log n) |
| erase() | O(log n) |
| count() | O(log n) |
| size() | O(1) |
| empty() | O(1) |
| clear() | O(n) |
| swap() | O(1) |
| begin() | O(1) |
| end() | O(1) |

---

# Map vs Unordered Map

| Map | Unordered Map |
|------|---------------|
| Sorted Keys | No Order |
| Red-Black Tree | Hash Table |
| O(log n) | Average O(1) |
| Slower | Faster (Average Case) |
| Supports ordered traversal | Traversal order is unpredictable |

---

# Difference Between [] and at()

## [] Operator

```cpp
mp["A"];
```

- Creates the key if it does not exist.
- Returns a default value.

Example

```cpp
map<string,int> mp;

cout << mp["ABC"];
```

Output

```
0
```

Now `"ABC"` exists in the map.

---

## at()

```cpp
mp.at("ABC");
```

If `"ABC"` does not exist,

```
Throws Exception
```

Use `at()` only when you are sure the key is already present.

---

# Applications of Map

Maps are widely used in:

- Dictionary Applications
- Student Database
- Employee Records
- Phone Book
- Word Frequency Counter
- Inventory Management
- Compiler Symbol Tables
- Caching Systems
- Database Indexing

---

# Interview Points

- `map` stores **Key-Value pairs**.
- Keys are always **unique**.
- Keys are automatically stored in **ascending order**.
- Internally implemented using a **Red-Black Tree**.
- Searching, insertion, and deletion take **O(log n)** time.
- `[]` inserts a new key if it does not exist.
- `at()` throws an exception if the key does not exist.
- `find()` returns an iterator.
- `count()` returns **0 or 1** because duplicate keys are not allowed.
- Iterators traverse the map in **sorted key order**.

---

# Summary

- **Map** is an associative container that stores **unique key-value pairs**.
- It automatically keeps keys in **sorted order**.
- It is implemented using a **Red-Black Tree**, giving **O(log n)** search, insertion, and deletion.
- It supports iterators but **does not support indexing** like arrays or vectors.
- Common functions include `insert()`, `[]`, `at()`, `find()`, `count()`, `erase()`, `clear()`, `swap()`, `begin()`, and `end()`.
- Maps are widely used when fast searching and ordered storage of key-value data are required.

---

# Quick Revision

| Feature | Map |
|---------|-----|
| Header File | `#include <map>` |
| Stores | Key-Value Pairs |
| Duplicate Keys | ❌ Not Allowed |
| Sorted | ✅ Yes |
| Internal Structure | Red-Black Tree |
| Random Access | ❌ No |
| Iterator Support | ✅ Yes |
| Search | O(log n) |
| Insert | O(log n) |
| Delete | O(log n) |
| Best Use | Ordered Key-Value Storage |