# 📚 Introduction to Basic Data Structures: STL `list` in C++

This document provides a structured overview of the `std::list` container in C++, including constructors, capacity functions, modifiers, operations, and element access methods, along with their respective time complexities.

---

## 📦 Constructors

| Syntax | Description | Time Complexity |
|--------|-------------|-----------------|
| `list<type> myList;` | Constructs a list with 0 elements. | O(1) |
| `list<type> myList(N);` | Constructs a list with N elements (garbage values). | O(N) |
| `list<type> myList(N, V);` | Constructs a list with N elements, each with value `V`. | O(N) |
| `list<type> myList(list2);` | Constructs a list by copying another list `list2`. | O(N) |
| `list<type> myList(A, A+N);` | Constructs a list from an array `A` of size `N`. | O(N) |
| `list<type> myList(v.begin(), v.end());` | Constructs a list by copying from vector `v`. | O(N) |

---

## 📏 Capacity Functions

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `myList.size()` | Returns the number of elements. | O(1) |
| `myList.max_size()` | Returns the max possible size. | O(1) |
| `myList.clear()` | Removes all elements. | O(N) |
| `myList.empty()` | Checks if list is empty. | O(1) |
| `myList.resize(K)` | Resizes the list. | O(K) *(difference between new and current size)* |

---

## ✍️ Modifiers

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `myList = list2` or `myList.assign(list2.begin(), list2.end())` | Assigns values from another list. | O(N) |
| `myList.push_back()` | Adds an element to the tail. | O(1) |
| `myList.push_front()` | Adds an element to the head. | O(1) |
| `myList.pop_back()` | Removes the tail element. | O(1) |
| `myList.pop_front()` | Removes the head element. | O(1) |
| `myList.insert(pos, val)` | Inserts elements at a specific position. | O(N + K) |
| `myList.erase(pos)` | Deletes elements from a specific position. | O(N + K) |

> 🔸 Note:  
> - `replace(begin, end, oldVal, newVal)` — Replaces `oldVal` with `newVal` *(not part of list STL)* – O(N)  
> - `find(begin, end, val)` — Finds value `val` *(not part of list STL)* – O(N)

---

## ⚙️ Operations

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `myList.remove(V)` | Removes all occurrences of value `V`. | O(N) |
| `myList.sort()` | Sorts in ascending order. | O(N log N) |
| `myList.sort(greater<type>())` | Sorts in descending order. | O(N log N) |
| `myList.unique()` | Removes consecutive duplicates (after sorting). | O(N) *(+ sort: O(N log N))* |
| `myList.reverse()` | Reverses the list. | O(N) |

---

## 🔍 Element Access

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `myList.front()` | Returns the first element. | O(1) |
| `myList.back()` | Returns the last element. | O(1) |
| `next(myList.begin(), i)` | Accesses the ith element. | O(N) |

---

## 🔁 Iterators

| Function | Description | Time Complexity |
|----------|-------------|-----------------|
| `myList.begin()` | Iterator to the first element. | O(1) |
| `myList.end()` | Iterator to the past-the-end element. | O(1) |

---

## ✅ Summary

- `std::list` is a **doubly-linked list** in C++ STL.
- Efficient for frequent **insertions/deletions at head or tail**.
- Not efficient for **random access** (unlike `vector` or `deque`).
- Supports **bidirectional iterators**.

---

> 📝 *Use `std::list` when you require frequent insertions/deletions from anywhere in the list without the need for random access.*

