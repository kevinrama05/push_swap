*This project has been created as part of the 42 curriculum by vgramozi, kerama.*

# Push Swap

## Description

**push_swap** is an algorithmic optimization project whose goal is to sort a stack of integers
using **only two stacks (`a` and `b`)** and a **restricted set of operations**, while producing
the **smallest possible number of moves**.

The program receives a list of integers as arguments and outputs a sequence of valid
Push_swap operations (`sa`, `pb`, `ra`, etc.) that sorts the numbers in **ascending order** in stack `a`.

The main challenge of this project is not sorting itself, but **choosing and designing efficient
algorithms** that minimize the number of operations depending on input size and disorder.

This implementation embeds **multiple sorting strategies**, measures the **disorder** of the input,
and dynamically selects the most appropriate algorithm at runtime.

---

## Features

* Full implementation in **C**, compliant with the 42 Norm
* Strict error handling (invalid input, duplicates, overflow)
* No memory leaks (checked with `valgrind`)
* Four distinct sorting strategies:

  * Simple – O(n²)
  * Medium – O(n√n)
  * Complex – O(n log n)
  * Adaptive – automatic selection based on disorder
* Optional **benchmark mode** showing detailed metrics
* Optimized to meet 42 performance requirements:

  * `< 1500` operations for 100 numbers
  * `< 8000` operations for 500 numbers

---

## Allowed Operations

The program outputs only valid Push_swap instructions:

* **Swap:** `sa`, `sb`, `ss`
* **Push:** `pa`, `pb`
* **Rotate:** `ra`, `rb`, `rr`
* **Reverse rotate:** `rra`, `rrb`, `rrr`

Each instruction is printed on its own line to **stdout**.

---

## Compilation

```bash
make
```

Available Makefile rules:

* `make` / `make all`
* `make clean`
* `make fclean`
* `make re`

The binary produced is named:

```bash
./push_swap
```

---

## Usage

```bash
./push_swap [OPTIONS] <list of integers>
```

### Strategy Selection

| Option       | Description                      |
| ------------ | -------------------------------- |
| `--simple`   | Force O(n²) algorithm            |
| `--medium`   | Force O(n√n) algorithm           |
| `--complex`  | Force O(n log n) algorithm       |
| `--adaptive` | Adaptive strategy (default)      |
| `--bench`    | Enable benchmark output (stderr) |

If no option is provided, the program runs in **adaptive mode**.

---

### Examples

#### Basic usage

```bash
./push_swap 2 1 3 6 5 8
```

#### Count operations

```bash
./push_swap 4 67 3 87 23 | wc -l
```

#### Force a strategy

```bash
./push_swap --complex 5 4 3 2 1
```

#### Checker verification

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_os $ARG
```

---

## Benchmark Mode

When `--bench` is enabled, performance metrics are printed to **stderr**, while operations remain on **stdout**.

### Example

```bash
./push_swap --bench 4 67 3 87 23 2> bench.txt | ./checker_os 4 67 3 87 23
```

### Benchmark Output

```
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n√n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

---

## Algorithm Overview

### Disorder Metric

Before sorting, the program computes a **disorder value** between `0` and `1`,
representing how far the input stack is from being sorted.

* `0.0` → already sorted
* `1.0` → worst possible order

This metric is used by the adaptive strategy to select the optimal algorithm.

---

### Implemented Strategies

#### 1. Simple Algorithm — **O(n²)**

* Used for very small or nearly sorted inputs
* Based on repeated minimum extraction
* Minimal overhead, easy to reason about

#### 2. Medium Algorithm — **O(n√n)**

* Chunk-based / range-based sorting
* The input is divided into √n chunks
* Each chunk is pushed and reintegrated efficiently

#### 3. Complex Algorithm — **O(n log n)**

* Radix-sort–style approach using indexed values
* Stable and efficient for large datasets
* Meets strict operation count requirements

#### 4. Adaptive Algorithm (Default)

* Chooses strategy based on disorder:

  * **Low disorder (< 0.2):** O(n)
  * **Medium disorder (0.2–0.5):** O(n√n)
  * **High disorder (≥ 0.5):** O(n log n)
* Balances performance and operation count dynamically

---

## Error Handling

The program prints `Error\n` to **stderr** if:

* Arguments are not valid integers
* Values exceed `INT_MIN` / `INT_MAX`
* Duplicate numbers are provided

No output is produced on invalid input.

---

## Performance Targets

| Input Size | Good   | Excellent |
| ---------- | ------ | --------- |
| 100 nums   | < 1500 | < 700     |
| 500 nums   | < 8000 | < 5500    |

All benchmarks are validated using the official checker.

---

## Contributors

* **kerama**

  * Algorithm design
  * Adaptive strategy
  * Benchmark system

* **vgrtamozi**

  * Parsing and validation
  * Stack operations
  * Memory management and testing

Both contributors fully understand and can explain all parts of the code.

---

## Resources

* 42 Push_swap Subject (Born2Code)
* [https://en.wikipedia.org/wiki/Stack_(abstract_data_type)](https://en.wikipedia.org/wiki/Stack_%28abstract_data_type%29)
* [https://en.wikipedia.org/wiki/Sorting_algorithm](https://en.wikipedia.org/wiki/Sorting_algorithm)
* [https://en.wikipedia.org/wiki/Big_O_notation](https://en.wikipedia.org/wiki/Big_O_notation)

### AI Usage

AI tools were used **only for assistance**, including:

* Algorithm discussion and comparison
* Debugging explanations
* README structuring and clarity

All generated content was reviewed, understood, and adapted manually.
No code was blindly copied.

---

## Final Notes

This project emphasizes **algorithmic thinking**, **complexity analysis**, and **clean C design**
under strict constraints.

Optimizing push_swap is not about finding *one* perfect algorithm, but about understanding
*when* and *why* a strategy performs best.
