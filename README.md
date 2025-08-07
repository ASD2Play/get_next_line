# 📖 get_next_line

## Description

This project implements a function that reads and returns a single line from a file descriptor each time it is called. The function receives a file descriptor as input and returns the next line from the file as a null-terminated string.

**Function prototype:**
```c
char *get_next_line(int fd);
```

## Bonus

This repository includes the bonus part:
- Supports reading from multiple file descriptors simultaneously.
- Includes all required bonus functionalities as specified by the subject.

## Usage

1. **Compilation**

   For the mandatory part:
   ```sh
   gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o gnl
   ```

   For the bonus part:
   ```sh
   gcc -Wall -Wextra -Werror get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
   ```

2. **Example Usage**
   ```c
   char *line;
   int fd = open("file.txt", O_RDONLY);
   while ((line = get_next_line(fd)) != NULL)
   {
       printf("%s", line);
       free(line);
   }
   close(fd);
   ```

## Allowed Functions

- `read`
- `malloc`
- `free`

## Notes

- The function returns `NULL` when there is nothing left to read or if an error occurs.
- Always free the memory returned by `get_next_line` after use.
- For the bonus, you can use `get_next_line` with several file descriptors at the same time.

---
