*This project has been created as part of the 42 curriculum by caide-so.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 School curriculum. The goal is to sort a stack of integers using the minimum number of operations, with only two stacks (`a` and `b`) and a restricted set of instructions available.

Stack `a` starts with a random list of unique integers. Stack `b` starts empty. The program must output the shortest possible sequence of instructions to sort stack `a` in ascending order (smallest value at the top).

This project explores algorithmic complexity, data structures (doubly-linked lists), and optimization strategies. The core algorithm implemented is the **Turk algorithm**, a greedy approach that calculates the cheapest move at each step based on positional cost analysis.

### Available Operations

| Instruction | Description |
|-------------|-------------|
| `sa` / `sb` | Swap the top two elements of stack a / b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` / `pb` | Push top element of b to a / a to b |
| `ra` / `rb` | Rotate stack a / b upward (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` / `rrb` | Reverse rotate stack a / b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

### Bonus — checker

The bonus part implements a `checker` program that reads a list of instructions from stdin and verifies whether they correctly sort the given stack, outputting `OK` or `KO`.

---

## Instructions

### Requirements

- `gcc` / `cc` with flags `-Wall -Wextra -Werror`
- `make`
- A Unix-like environment (Linux / macOS)

### Compilation

```bash
# Clone the repository
git clone  push_swap
cd push_swap

# Build push_swap
make

# Build the bonus checker
make bonus

# Clean object files
make clean

# Full clean (removes binaries)
make fclean

# Rebuild from scratch
make re
```

### Usage

```bash
# Basic usage — outputs the list of instructions
./push_swap 4 67 3 87 23

# Count the number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verify correctness with the bonus checker
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

# Error handling examples
./push_swap 0 one 2 3      # → Error (non-integer argument)
./push_swap 1 2 2 3        # → Error (duplicates)
./push_swap                # → (no output, no error)
```

### Performance Benchmarks

| Numbers | Max operations (100% score) | Min operations (80% score) |
|---------|-----------------------------|----------------------------|
| 100     | < 700                       | < 1100                     |
| 500     | ≤ 5500                      | < 8500                     |

---

## Technical Overview

The sorting logic is split into three cases based on input size:

- **2 elements** — single `sa` if needed
- **3 elements** — dedicated `three_sort` using at most 2 operations
- **4+ elements** — **Turk algorithm**:
  1. Push all but 3 elements to stack `b`, computing optimal targets and costs
  2. Sort the remaining 3 in stack `a`
  3. Push everything back from `b` to `a` using target-based positioning
  4. Rotate `a` until the minimum is on top

Cost optimization uses simultaneous rotations (`rr` / `rrr`) whenever both the node and its target are in the same half of their respective stacks.

---

## Resources

### Algorithms & Concepts

- [Sorting Algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Big-O Complexity Cheat Sheet](https://www.bigocheatsheet.com/)
- [Turk Algorithm explanation — Medium](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) — the primary sorting strategy used in this project
- [Linked Lists — GeeksforGeeks](https://www.geeksforgeeks.org/data-structures/linked-list/)

### 42 Community Resources

- [push_swap visualizer](https://github.com/o-reo/push_swap_visualizer) — useful for debugging and understanding algorithm behavior
- [push_swap tester](https://github.com/gemartin99/Push-Swap-Tester) — automated correctness and performance testing

### AI Usage

AI (Claude) was used in this project for the following tasks:

- **Understanding algorithm complexity trade-offs** between different sorting approaches (insertion sort, radix sort, Turk) before committing to an implementation
- **Generating this README** based on the project subject requirements and existing source files

In all cases, the AI-generated content was reviewed, tested, and fully understood before being incorporated. No functions were copy-pasted without comprehension — the goal was to use AI as a thinking aid, not a code generator.
