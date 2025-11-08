*This project has been created as part of the 42 curriculum by <kerama>*

## **Description**

This is Libft, the very first created library, which includes essential functions from
the C standard library, like string.h, stdlib.h and unistd.h, from scratch. Additionally,
I have implemented custom utility functions, and explored linked list manipulation.

I recreated 43 functions, which 23 functions are essential functions, recreated from the
C standard library, 11 functions are custom utility functions, and 9 functions are created
to deal with linked lists, like creating a linked list, adding to the front, adding to the
back, deleting one node, deleting the whole linked list, and so on.

The goal of this project is to understand how some essential functions work, and develop our
own reusable library, which I will be able to use it in the next projects. I am also able to
update the library, add new functions, or optimize them, if nedded.

## **Instructions**

**1. Clone the repository**
```bash
git clone git@github.com:42learners/Common-Core---Libft-0170423f-c22d-4ffd-be76-703c7d46e890.git libft
cd libft
```
<br><br>
**2. Compile the library**
```bash
make
```
This will create a static library file called **libft.a**
```bash
libft.a
```
<br><br>
**3. Use the library in other projects**
```c
#include "libft.h"
```
```bash
cc main.c libft.a -o program
```
Them you can run the program
```bash
./program
```
<br><br>
Additionally, you can use other make commands
```bash
make clean     # Remove object files (.o)
make fclean    # Remove object files and libft.a
make re        # Recompile everything from scratch
```

## **Resources**
### **Documentation**
C Library Reference (cplusplus.com) -> For understanding the behaviour of standard C functions reimplemented in C.
GNU C Library Manual (glibc) -> Official documentation for the C standard library
man7.org -> Linux manual pages for functions like malloc, write and free


### **Tutorials & Articles**
GeeksforGeeks -> Strings in C
GeeksforGeeks -> Dynamic Memory Allocation in C
GeeksforGeeks -> Singly Linked Lists in C

### Use of AI in this project
AI (ChatGPT, model GPT-5) was used as a learning and support tool during the development of this project.
Specifically, it assisted in:

- Clarifying C concepts such as memory management, pointers, and library compilation.
- Explaining errors and debugging strategies encountered while building the library.
- Writing documentation — including README structure, Markdown formatting, and clean project descriptions.
- Improving code readability and comments, while ensuring compliance with Norminette rules.

## A Detailed Description

The **Libft** project is divided into **three main parts** — each focusing on different aspects of C programming: standard functions, utility extensions, and data structures.  
Below is a complete breakdown of what each section includes and how the functions are typically used.


### Part 1 – Libc Functions

These functions are **reimplementations** of commonly used functions from the C standard library (`libc`).  
They allow you to understand the inner workings of fundamental routines such as string manipulation, memory management, and character classification.

| Category | Functions | Description |
|-----------|------------|-------------|
| **Character checks** | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` | Check whether a given character is alphabetic, numeric, alphanumeric, part of ASCII, or printable. |
| **String length and manipulation** | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr` | Functions to measure and manipulate strings safely. For example, `ft_strlcpy` and `ft_strlcat` help avoid buffer overflows. |
| **Memory handling** | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp` | Work directly with raw memory areas — filling, copying, comparing, or searching. |
| **Character conversion** | `ft_toupper`, `ft_tolower` | Convert characters between uppercase and lowercase. |
| **Numeric conversion** | `ft_atoi` | Convert a string to an integer (`atoi` equivalent). |
| **Memory allocation** | `ft_calloc`, `ft_strdup` | Allocate and initialize memory safely; duplicate strings with proper memory handling. |

These functions serve as the foundation for later C projects, giving low-level control over memory and strings.


### Part 2 – Additional Functions

This section introduces **new helper functions** not present in libc, but extremely useful for everyday programming.  
They focus on **string creation, transformation, and output**.

| Function | Prototype | Description |
|-----------|------------|-------------|
| **`ft_substr`** | `char *ft_substr(char const *s, unsigned int start, size_t len);` | Returns a substring from string `s`, starting at index `start` with a maximum length of `len`. |
| **`ft_strjoin`** | `char *ft_strjoin(char const *s1, char const *s2);` | Concatenates two strings (`s1` + `s2`) into a new allocated string. |
| **`ft_strtrim`** | `char *ft_strtrim(char const *s1, char const *set);` | Removes all characters from the start and end of `s1` that appear in `set`. |
| **`ft_split`** | `char **ft_split(char const *s, char c);` | Splits a string into an array of substrings using the character `c` as a delimiter. |
| **`ft_itoa`** | `char *ft_itoa(int n);` | Converts an integer `n` to its string representation. Handles negative numbers too. |
| **`ft_strmapi`** | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | Creates a new string by applying a function `f` to each character of `s`. |
| **`ft_striteri`** | `void ft_striteri(char *s, void (*f)(unsigned int, char *));` | Applies a function `f` to each character of `s`, modifying it directly. |
| **`ft_putchar_fd`** | `void ft_putchar_fd(char c, int fd);` | Outputs a single character to the specified file descriptor. |
| **`ft_putstr_fd`** | `void ft_putstr_fd(char *s, int fd);` | Outputs a string to the specified file descriptor. |
| **`ft_putendl_fd`** | `void ft_putendl_fd(char *s, int fd);` | Outputs a string followed by a newline to the specified file descriptor. |
| **`ft_putnbr_fd`** | `void ft_putnbr_fd(int n, int fd);` | Outputs an integer in ASCII format to the specified file descriptor. |

Together, these functions give higher-level control of strings, making it easier to create and format dynamic data safely.


### Part 3 – Linked List Functions

This final section introduces **data structures**, specifically **singly linked lists**, which are essential for dynamic memory and algorithmic manipulation.

Each list node is based on this structure (defined in `libft.h`):

```c
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
} t_list;
```

| Function | Prototype | Description |
|-----------|------------|-------------|
| **`ft_lstnew`** | `t_list *ft_lstnew(void *content);` | Allocates and returns a new node with the given `content`. |
| **`ft_lstadd_front`** | `void ft_lstadd_front(t_list **lst, t_list *new);` | Adds a new node at the beginning of the list. |
| **`ft_lstsize`** | `int ft_lstsize(t_list *lst);` | Returns the number of nodes in the list. |
| **`ft_lstlast`** | `t_list *ft_lstlast(t_list *lst);` | Returns the last node of the list. |
| **`ft_lstadd_back`** | `void ft_lstadd_back(t_list **lst, t_list *new);` | Adds a new node at the end of the list. |
| **`ft_lstdelone`** | `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees the memory of one node, using the provided `del` function to free its content. |
| **`ft_lstclear`** | `void ft_lstclear(t_list **lst, void (*del)(void *));` | Deletes and frees the entire list. |
| **`ft_lstiter`** | `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies the function `f` to each node’s content. |
| **`ft_lstmap`** | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` | Creates a new list by applying the function `f` to each node’s content. If allocation fails, the `del` function is used to clear memory safely. |

These functions introduce essential **data structure concepts** like dynamic memory allocation, pointer manipulation, and safe cleanup patterns.
