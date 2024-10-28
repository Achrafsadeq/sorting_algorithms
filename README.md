# 0x1B. C - Sorting algorithms & Big O

## Description
This project focuses on implementing various sorting algorithms in C and understanding their time complexities using Big O notation. You'll learn how to implement different sorting algorithms, analyze their performance, and choose the most efficient algorithm for specific scenarios. This project is meant to be done in teams of two students with pair programming for at least the mandatory part.

## Requirements

| Category | Details |
|----------|---------|
| Editors | vi, vim, emacs |
| Compiler | Ubuntu 20.04 LTS using gcc with options -Wall -Werror -Wextra -pedantic -std=gnu89 |
| File Endings | All files should end with a new line |
| Style Guide | Betty style. It will be checked using betty-style.pl and betty-doc.pl |
| README | A README.md file at the root of the project folder is mandatory |
| Function Limit | No more than 5 functions per file |
| Library Usage | Standard library usage is forbidden unless specified otherwise |
| Header Files | All prototypes should be included in sort.h with include guards |
| Global Variables | Not allowed |

### General
- At least four different sorting algorithms
- What is the Big O notation, and how to evaluate the time complexity of an algorithm
- How to select the best sorting algorithm for a given input
- What is a stable sorting algorithm
- How to work with doubly linked lists
- Understanding time complexity notations: O(1), O(n), O(n²), etc.
- Proper usage of print_array and print_list functions

  ## Task Table

| Task Number | Description                    | File                     |
|-------------|--------------------------------|--------------------------|
| 0           | Bubble sort                    | `0-bubble_sort.c`, `0-O` |
| 1           | Insertion sort                 | `1-insertion_sort_list.c`, `1-O` |
| 2           | Selection sort                 | `2-selection_sort.c`, `2-O` |
| 3           | Quick sort                     | `3-quick_sort.c`, `3-O` |
| 4           | Shell sort - Knuth Sequence    | `100-shell_sort.c`       |
| 5           | Cocktail shaker sort           | `101-cocktail_sort_list.c`, `101-O` |
| 6           | Counting sort | `102-counting_sort.c`, `102-O` |
| 7           | Merge sort | `103-merge_sort.c`, `103-O` |
| 8           | Heap sort | `104-heap_sort.c`, `104-O` |
| 9           | Radix sort | `105-radix_sort.c` |
| 10          | Bitonic sort | `106-bitonic_sort.c`, `106-O` |
| 11          | Quick Sort - Hoare Partition scheme | `107-quick_sort_hoare.c`, `107-O` |
| 12          | Dealer (deck of cards sorting) | `1000-sort_deck.c`, `deck.h` |

### Data Structure
```c
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

### Test Requirements
- All files should end with a new line
- Functions will be compiled with provided print_array.c and print_list.c files
- Sorting is not required for arrays/lists with size less than 2
- Big O notations should be written in the simplest form
- Time complexity files should have one notation per line
- Repository should be one per group

### Provided Functions
The project includes these helper functions for testing:
```c
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
```

### Big O Format
Time complexity should be expressed in these notations:
- O(1)
- O(n)
- O(n!)
- O(n^2)
- O(log(n))
- O(nlog(n))
- O(n+k)

## Resources
- Sorting algorithm concepts
- Big O notation
- Sorting algorithms animations
- CS50 Algorithms explanation by David Malan
- Testing resources: Random.org (for generating test integers)

## Mission Director
This project is supervised by the ALX Software Engineering Program.

## Developer
**Codename**: Achraf Sadaeq

## Acknowledgments
Holberton School, in collaboration with the ALX Software Engineering Program, developed this project for educational purposes.

