# Ex02: PmergeMe - Ford-Johnson Algorithm (Merge-Insertion Sort)

## Overview

This exercise implements the **Ford-Johnson algorithm**, also known as **merge-insertion sort**. It is a comparison-based sorting algorithm designed to minimize the number of comparisons needed to sort a sequence. The algorithm is implemented using two different containers (`std::vector` and `std::deque`) to compare their performance.

---

## The Algorithm Explained

### Why Ford-Johnson?

The Ford-Johnson algorithm was designed in 1959 to approach the theoretical minimum number of comparisons needed to sort n elements. While not always the fastest in practice (due to memory overhead), it performs fewer comparisons than most other sorting algorithms.

### Algorithm Steps

1. **Pairing**: Group elements into pairs and compare each pair (1 comparison per pair)
2. **Recursive Sort**: Recursively sort the sequence of larger elements from each pair
3. **Insertion**: Insert the smaller elements (pend) into the sorted sequence (main) using binary search, following the Jacobsthal sequence order

---

## Visual Example

Starting with: `[5, 1, 8, 3, 2, 7, 4, 6]`

### Step 1: Pairing
```
(5,1) -> (5,1)  [5 > 1, so 5 is "main", 1 is "pend"]
(8,3) -> (8,3)  [8 > 3]
(2,7) -> (7,2)  [7 > 2, swap order]
(4,6) -> (6,4)  [6 > 4, swap order]

main = [5, 8, 7, 6]
pend = [1, 3, 2, 4]
```

### Step 2: Recursively Sort Main
```
main = [5, 8, 7, 6] -> After recursion -> [5, 6, 7, 8]
pend reordered to match: [1, 4, 2, 3]
```

### Step 3: Insert Pend Using Jacobsthal Order
```
Insert pend[0]=1 at beginning (paired with smallest main element)
main = [1, 5, 6, 7, 8]

Jacobsthal order for remaining: 3, 2, 4 (indices)
Insert in this order using binary search with optimized bounds
```

---

## Function Documentation

### Core Sorting Functions

#### `vector_recursive_sort` / `deque_recursive_sort`
**Location**: `PmergeMe.cpp:54-74` / `PmergeMe.cpp:111-131`

The main recursive function that orchestrates the entire algorithm.

```cpp
std::vector<int> PmergeMe::vector_recursive_sort(std::vector<int> &vec)
```

**Purpose**: Entry point for the sorting algorithm. Handles the complete sorting process recursively.

**How it works**:
1. Base case: If size <= 1, return (already sorted)
2. Create pairs from consecutive elements
3. Save the odd element if size is odd
4. Split pairs into main (larger) and pend (smaller)
5. Recursively sort main
6. Reorder pend to match sorted main's order
7. Insert pend elements into main using Jacobsthal sequence

---

### Pairing Phase

#### `add_to_vector_pair` / `add_to_deque_pair`
**Location**: `vector.cpp:15-40` / `deque.cpp:15-40`

```cpp
void PmergeMe::add_to_vector_pair(std::vector<std::pair<int, int>> &pairs, std::vector<int> &vec)
```

**Purpose**: Creates pairs from consecutive elements, comparing each pair to determine which is larger.

**How it works**:
1. Iterate through the vector in steps of 2
2. Compare elements at positions `i` and `i+1`
3. Store as pair with larger element first: `(max, min)`
4. If odd number of elements, the last element is handled separately

**Why pairs?**: By pairing elements, we reduce the problem size by half while using only n/2 comparisons.

---

#### `push_to_main_pend`
**Location**: `vector.cpp:41-53` / `deque.cpp:41-53`

```cpp
void PmergeMe::push_to_main_pend(std::vector<int> &main, std::vector<int> &pend, std::vector<std::pair<int, int>> &pairs)
```

**Purpose**: Separates pairs into two sequences - main (larger elements) and pend (smaller elements).

**How it works**:
- `pairs[i].first` (larger) goes to `main`
- `pairs[i].second` (smaller) goes to `pend`

**Key insight**: After main is sorted, each `pend[i]` is guaranteed to be smaller than the corresponding `main[i]` it was paired with.

---

### Reordering Phase

#### `sort_the_pend`
**Location**: `vector.cpp:54-76` / `deque.cpp:54-76`

```cpp
void PmergeMe::sort_the_pend(std::vector<int> &main, std::vector<int> &pend,
                              std::vector<int> &sorted_main, std::vector<int> &sorted_pend)
```

**Purpose**: Reorders the pend elements to maintain the pairing relationship after main is sorted.

**Why needed?**: When main is recursively sorted, the original pairing indices become invalid. For each element in sorted_main, we find its original position in main and take the corresponding pend element.

**Example**:
```
Before sorting main: main = [8, 5, 7], pend = [3, 1, 2]
After sorting main: sorted_main = [5, 7, 8]
We need sorted_pend = [1, 2, 3] to maintain relationships
```

---

### Jacobsthal Sequence

#### `calculate_jacobthal_num`
**Location**: `PmergeMe.cpp:183-201`

```cpp
int calculate_jacobthal_num(int x)
```

**Purpose**: Computes the nth Jacobsthal number using the recurrence relation.

**Formula**: `J(n) = J(n-1) + 2 * J(n-2)`

**Sequence**: 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, ...

**Why Jacobsthal?**: The Jacobsthal sequence determines the optimal insertion order to minimize comparisons. By inserting elements in this order, binary search bounds can be optimized to use exactly `ceil(log2(bound))` comparisons.

---

#### `generate_insertion_sequence`
**Location**: `vector.cpp:108-145` / `deque.cpp:108-145`

```cpp
void PmergeMe::generate_insertion_sequence(std::vector<int> &pend_vec,
                                            std::vector<int> &j_seq,
                                            std::vector<int> &order)
```

**Purpose**: Generates the optimal order for inserting pend elements based on Jacobsthal numbers.

**How it works**:
1. Generate Jacobsthal numbers up to pend size: 3, 5, 11, 21, ...
2. For each Jacobsthal number, count down to the previous one
3. Add any remaining indices not covered

**Example** (pend size = 6):
```
Jacobsthal sequence: 3, 5
Order generation:
  From 3: add 3, 2
  From 5: add 5, 4 (3,2 already added)
  Remaining: add 6 (index 1 handled separately)
Final order: [3, 2, 5, 4, 6]
```

---

### Insertion Phase

#### `insert_vector` / `insert_deque`
**Location**: `PmergeMe.cpp:76-108` / `PmergeMe.cpp:133-165`

```cpp
void PmergeMe::insert_vector(std::vector<int>& pend_vec, std::vector<int> &main_vec)
```

**Purpose**: Inserts pend elements into main using binary search in Jacobsthal order.

**How it works**:
1. Insert first pend element at position 0 (always smallest paired element)
2. Follow Jacobsthal-based insertion order
3. Use optimized binary search bounds (`high = 2*high + 1` pattern)
4. Insert each element at the position found by binary search

**Bound optimization**: When inserting the kth element in Jacobsthal order, we know it can only be in positions 0 to (2^k - 1), reducing comparisons.

---

#### `binary_search_vec` / `binary_search_deq`
**Location**: `vector.cpp:86-107` / `deque.cpp:86-107`

```cpp
int PmergeMe::binary_search_vec(std::vector<int> &vec, int value, int high)
```

**Purpose**: Finds the correct insertion position for a value using binary search.

**How it works**:
1. Standard binary search with low=0 and adjustable high bound
2. Returns the index where value should be inserted
3. Counts each comparison for algorithm analysis

**Time complexity**: O(log n) comparisons per element

---

### Utility Functions

#### `is_in_vector` / `is_in_deque`
**Location**: `vector.cpp:77-85` / `deque.cpp:77-85`

**Purpose**: Checks if a value exists in the container (used during insertion order generation).

#### `fill_vector_and_deque`
**Location**: `PmergeMe.cpp:168-182`

**Purpose**: Populates both containers with the input data for comparison.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| Pairing | O(n) | O(n) |
| Recursive Sort | T(n/2) | O(log n) stack |
| Pend Reordering | O(n) | O(n) |
| Insertion | O(n log n) | O(n) |
| **Total** | **O(n log n)** | **O(n)** |

### Comparison Count

The Ford-Johnson algorithm achieves approximately:
- **Upper bound**: `n * ceil(log2(n)) - 2^ceil(log2(n)) + 1` comparisons
- This is very close to the information-theoretic lower bound of `ceil(log2(n!))`

---

## Container Comparison

### std::vector
- Contiguous memory
- O(n) insertion (elements must be shifted)
- Better cache locality
- Generally faster for this algorithm due to cache efficiency

### std::deque
- Non-contiguous chunks
- O(n) insertion (similar to vector)
- Worse cache locality
- May be slower despite theoretical similarity

---

## File Structure

```
ex02/
├── main.cpp        # Entry point, input parsing, timing
├── PmergeMe.hpp    # Class definition
├── PmergeMe.cpp    # Core algorithm, Jacobsthal, utility functions
├── vector.cpp      # Vector-specific implementations
├── deque.cpp       # Deque-specific implementations
├── debug.cpp       # Debug output functions
└── Makefile        # Build configuration
```

---

## Usage

```bash
./PmergeMe 3 5 9 7 4
```

**Output**:
```
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector: X.XXX us
Time to process a range of 5 elements with std::deque: X.XXX us
```

---

## References

- Ford, L.R.; Johnson, S.M. (1959). "A Tournament Problem". The American Mathematical Monthly.
- Knuth, D.E. (1998). "The Art of Computer Programming, Volume 3: Sorting and Searching".
