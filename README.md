# CSE-2201 Algorithm Analysis and Design

Small collection of algorithm and data-structure practice programs for the CSE-2201 course.

Most files are standalone examples with hard-coded sample input in `main()` or at the bottom of the Python script.

## Contents

### C++

| File | Topic |
| --- | --- |
| `bubble_sort.cpp` | Bubble sort |
| `selection_sort.cpp` | Selection sort |
| `insertion_sort.cpp` | Insertion sort function |
| `merge_sort.cpp` | Merge sort functions |
| `count_sort.cpp` | Counting sort |
| `radix_sort.cpp` | Radix sort |
| `bucket_sort.cpp` | Bucket sort for floating-point values in `[0, 1)` |
| `max_heap.cpp` | Max heap class with insert, extract, delete, and print examples |
| `min_d_and_c.cpp` | Divide-and-conquer minimum and maximum |
| `linked_list.cpp` | Basic linked-list node/list skeleton |

### Python

| File | Topic |
| --- | --- |
| `bin_search.py` | Recursive binary search |
| `counting_sort.py` | Counting sort |
| `min_d_and_c.py` | Divide-and-conquer minimum and maximum |

## Running

Compile and run a C++ file directly:

```bash
g++ -std=c++17 bubble_sort.cpp -o bubble_sort
./bubble_sort
```

Run a Python file directly:

```bash
python3 bin_search.py
```

Replace the filename with the algorithm you want to try.

## Notes

- This is an educational repo, so examples favor short demonstrations over reusable libraries.
- Some compiled binaries are present in the repo (`bubble_sort`, `bucket_sort`, `count_sort`, etc.); the source files are the useful part.
