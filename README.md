# Push_swap

## Summary  
This repository implements the **Push_swap** project, which sorts a list of integers using only stack operations (`push`, `swap`, `rotate`, and `reverse_rotate`) on two stacks (A and B). The goal is to produce the minimum sequence of valid operations to sort the input in ascending order. :contentReference[oaicite:0]{index=0}

## Repository Structure  
- **`push_swap.h`**  
  - Main header defining data structures (`t_list` nodes), function prototypes for parsing, validation, sorting, and stack operations (push, swap, rotate, reverse_rotate). :contentReference[oaicite:1]{index=1}  
- **`Makefile`**  
  - Contains build rules:  
    - `make` (or `make all`): Compiles all source files into the `push_swap` executable.  
    - `make clean` / `make fclean`: Removes object files and the executable.  
    - `make re`: Runs `fclean` then `all`. :contentReference[oaicite:2]{index=2}  
- **Source files (`*.c`)**  
  1. **`a_ft_split_ifrom1.c`**  
     - Custom implementation of `ft_split` (splits a string by spaces) to parse command-line arguments into individual tokens (numbers). :contentReference[oaicite:3]{index=3}  
  2. **`a_main_error_free.c`**  
     - Entry point (`main`), orchestrates:  
       - Argument parsing  
       - Input validation (calling `c_isvalid_stack.c`)  
       - Stack initialization (`b_stack_init_and_atol.c`)  
       - Invokes sorting logic (`d_ft_sort.c`)  
       - Handles freeing all allocated memory on error or completion. :contentReference[oaicite:4]{index=4}  
  3. **`b_stack_init_and_atol.c`**  
     - Initializes Stack A by converting each token to a `long` with `ft_atol`, checks for overflows, and builds a linked list (`t_list`).  
     - Ensures no duplicate integers. :contentReference[oaicite:5]{index=5}  
  4. **`c_isvalid_stack.c`**  
     - Validates that each token contains only digits (and optional leading `-`), and that the resulting list has no duplicates.  
     - Prints an error and exits if invalid. :contentReference[oaicite:6]{index=6}  
  5. **`d_cal_cost_rotation.c`**  
     - Computes the “cost” (number of rotations) needed to move each element from Stack A to its correct position in Stack B (or vice versa), optimizing rotations by choosing between rotating upwards or downwards. :contentReference[oaicite:7]{index=7}  
  6. **`d_ft_sort.c`**  
     - Implements the main sorting algorithm:  
       - For small `N` (≤3), uses minimal hardcoded sequences.  
       - For larger `N`, repeatedly pushes elements to Stack B based on computed costs, then moves them back to Stack A in sorted order. :contentReference[oaicite:8]{index=8}  
  7. **`d_sort_helper.c`**  
     - Helper functions used by `d_ft_sort.c`:  
       - Finds the position to insert an element in Stack B.  
       - Determines when to switch from pushing to pulling elements. :contentReference[oaicite:9]{index=9}  
  8. **`operation_push.c`**, **`operation_swap.c`**, **`operation_rotate.c`**, **`operation_reverse_rotate.c`**  
     - Implement the four fundamental operations on stacks:  
       - **`push`**: Moves the top element from one stack to the other.  
       - **`swap`**: Exchanges the first two elements of a stack.  
       - **`rotate`**: Shifts all elements up by one (first element becomes last).  
       - **`reverse_rotate`**: Shifts all elements down by one (last element becomes first).  
     - Each function prints the corresponding instruction (`pa`, `pb`, `sa`, `sb`, `ra`, `rb`, `rra`, `rrb`) to `stdout`. :contentReference[oaicite:10]{index=10}  
  9. **`utils_lst.c`**  
     - Utility functions for linked‐list (stack) management:  
       - Creating a new node (`ft_lstnew`)  
       - Adding to the back (`ft_lstadd_back`)  
       - Computing list size (`ft_lstsize`)  
       - Finding the minimum and maximum values, etc. :contentReference[oaicite:11]{index=11}  
- **`tester_results/`**  
  - Example logs or outputs from automated tester scripts (e.g., runtime validation, operation count). :contentReference[oaicite:12]{index=12}  
- **`push_swap.drawio`**  
  - A diagram (Draw.io) illustrating the overall algorithm flow: input parsing → validation → cost calculation → sorting steps → output sequence. :contentReference[oaicite:13]{index=13}

## Languages and Tools  
- **C (95.7%)**: Core language used for all data structures, parsing, validation, sorting logic, and stack operations. :contentReference[oaicite:14]{index=14}  
- **Makefile (4.3%)**: Automates compilation of source files into the `push_swap` executable. :contentReference[oaicite:15]{index=15}

## How to Use This Repository  
1. **Clone the repository**:  
   ```bash
   git clone https://github.com/yuhi-ootani/Push_swap.git
   cd Push_swap
   ``` :contentReference[oaicite:16]{index=16}

2. **Compile with Make**:  
   ```bash
   make
