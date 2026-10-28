*This project has been created as part of the 42 curriculum by arcamart.*

## Description

**ft_printf** is a custom C library that reimplements a subset of the libc `printf` function. The goal of the project is to understand how variadic functions work (`<stdarg.h>`), how numbers are converted to text in different bases, and how to structure a function that parses a format string and dispatches each conversion to the right handler.

The library is compiled into a static archive, `libftprintf.a`, which can be linked into any other C program. Only the system call `write` is used for output.

## Instructions

### Compilation

```bash
make         # builds libftprintf.a
make clean   # removes the object files
make fclean  # removes the object files and libftprintf.a
make re      # rebuilds everything from scratch
```

### Usage

Include the header in your source file and link against the archive:

```c
#include "ft_printf.h"
```

```bash
cc -Wall -Wextra -Werror main.c -L. -lftprintf -o program
```

## Library description

### Prototype

```c
int	ft_printf(const char *format, ...);
```

It writes the formatted output to the standard output and returns the number of characters written.

### Supported conversions

| Conversion | Argument type | Description |
|---|---|---|
| `%c` | `int` | Prints a single character. |
| `%s` | `char *` | Prints a string. A `NULL` pointer prints `(null)`. |
| `%p` | `void *` | Prints a pointer address in lowercase hexadecimal with a `0x` prefix. A `NULL` pointer prints `(nil)`. |
| `%d` | `int` | Prints a signed decimal number. |
| `%i` | `int` | Prints a signed decimal number (same as `%d`). |
| `%u` | `unsigned int` | Prints an unsigned decimal number. |
| `%x` | `unsigned int` | Prints an unsigned number in lowercase hexadecimal. |
| `%X` | `unsigned int` | Prints an unsigned number in uppercase hexadecimal. |
| `%%` | none | Prints a literal `%`. |

Flags, minimum field width and precision are not implemented.

## Technical choices

- **Single pass over the format string.** Plain characters are written as they are found. When a `%` is followed by a valid conversion, the matching argument is fetched with `va_arg` and printed, then both characters (the `%` and the conversion) are skipped.
- **The `va_list` is passed by pointer** to the function that dispatches each conversion, so that every `va_arg` call advances the same list that `ft_printf` owns.
- **`%c` is fetched as an `int`**, because a `char` passed through `...` is promoted to `int` (default argument promotion).
- **No dynamic allocation.** `%d` and `%i` are printed with a recursive function that works on a `long`, so `INT_MIN` is handled safely. `%u`, `%x`, `%X` and `%p` share one function that fills a fixed-size buffer from the end and prints from where the digits start, using an `unsigned long` so that 64-bit addresses fit.
- **A lookup string selects the digits** (`"0123456789abcdef"` or `"0123456789ABCDEF"`), so the same code serves every base.
- **Every output helper returns the number of characters it wrote**, and `ft_printf` accumulates them into its return value.
- **Rebuild on header changes.** The Makefile lists the header as a prerequisite of the object files, so changing only `ft_printf.h` triggers a recompilation.

## Limitations

- Only the mandatory conversions are supported (no flags, width or precision).
- The return value of `write` is not checked, so a failed `write` is not reported as `-1`.
- The behavior for an unsupported conversion is printed as plain text.

## Resources

- Unix manual pages (`man 3 printf`, `man 3 stdarg`, `man 2 write`)
- GitHub repositories
- YouTube videos
- GitBook pages
- Stack Overflow

### Use of AI

AI was used exclusively for learning purposes, as a complementary tool to the peer-to-peer approach. It was used to explain concepts and technical details when a subject called for going deeper than other resources allowed, such as how variadic functions and `<stdarg.h>` work, hexadecimal notation, and how `make` decides what to rebuild, in order to satisfy curiosity about how things work. AI was never used as a substitute for the creative process or for the peer-to-peer approach.