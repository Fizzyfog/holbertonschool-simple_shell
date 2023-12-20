# holbertonschool-simple_shell
Simple shell implementation for Holberton School Lille. First term final project, with Amandine Kemp.

![Simple_Shell](https://github.com/Fizzyfog/holbertonschool-simple_shell/blob/main/simple_shell.png)

----------

# <p align="center">C - Simple Shell</p>

----------

## ➤ Menu:

- [➤ Description]()
- [➤ Flowchart]()
- [➤ Format types]()
- [➤ Examples]()
- [➤ Files that make up the _printf]()
- [➤ Requirements]()
- [➤ Author]()
- [➤ License]()


----------

## ➤ Description:

The Simple Shell is a user interface program that provides access to the OS. It accepts user commands and executes them. In the context of this project, the Simple Shell is a simplified version of the Unix shell, which allows executing basic commands. It is written in the C language.

----------

## ➤ Flowchart:

![➤ Flowchart ➤]()

----------

## ➤ If you want to use our Simple Shell:

### ➤ Librairies:
#include <stdarg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

----------

## ➤ For compilation: 

* Compile the code using :
``` gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh ```

----------

## ➤ Files description:

| Filename | Description | 
| -------- | -------- |
| main.h    | The main.h file is a header file. It contains function declarations and macros that are used across several source files. This file facilitates code modularity and consistency.    |
| shell.c    | The shell.c file is the heart of the program. It contains the main code that handles the execution of user commands. This file is responsible for interpreting user commands and calling the appropriate functions to execute these commands.    |
| _getenv.c    | The _getenv.c file contains the code for the '_getenv' function. This function is used to retrieve the value of a specified environment variable. It is useful for accessing operating system environment information.    |
| builtin_functions.c    | The builtin_functions.c file contains the code for the shell's built-in functions. These functions are interpreted directly by the shell itself, rather than by an external program. They can include commands such as cd, echo, exit, etc.    |
| execute.c    | The execute.c file contains the code that manages command execution in the shell. It is responsible for creating child processes to execute commands and managing their execution.    |
| free_memory.c    | The free_memory.c file contains the code to manage the release of dynamically allocated memory during program execution. It ensures that all allocated memory is correctly released, to avoid memory leaks.    |
| get_filepath.c    | The get_filepath.c file contains the code for the function that determines the full path of a file or program. This function is useful for locating files or programs to be executed by the shell."    |
| path_append.c    | The path_append.c file contains the code for the function that adds a specified path to the PATH environment variable. This function is useful for extending the locations where the shell looks for programs to run.    |
| print_error.c    | The print_error.c file contains the code for the function that handles the display of error messages. This function is used to inform the user when an error occurs during shell execution.    |
| searchinit.c    | The searchinit.c file contains the code for the function that initializes the shell's command search. This function prepares the shell to search for commands in the various directories specified in the PATH environment variable.    |
| split_arguments.c    | The split_arguments.c file contains the code for the function that splits command line arguments into several tokens. This function is essential for correctly interpreting user commands and passing them to the appropriate functions for execution.    |
| string_functions.c    | The string_functions.c file contains code for various functions that manipulate strings. These functions can include operations such as comparing strings, copying strings, searching within a string and so on. They are used throughout the program to manage string data.    |

----------

## ➤ Tests:

### ➤ Valgrind:

* String without type:``
	* Output: ``

## ➤ Man:

* Read the man using :
``` man ./man_3_printf ```

----------

## ➤ Requirements:

**General**

* All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
* A README.md file, at the root of the folder of the project is mandatory
* Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
* Your shell should not have any memory leaks
* No more than 5 functions per file
* All your header files should be include guarded
* Use system calls only when you need to (why?)

----------

## ➤ Author:

- Sarah IDRISSI [Github](https://github.com/Fizzyfog)
- Amandine KEMP [Github](https://github.com/amandinekemp)
----------

## ➤ License:

This project is subject to the MIT license. For detailed information on the conditions of this license, please consult the [LICENSE](https://github.com/amandinekemp/holbertonschool-simple_shell/blob/main/LICENSE) file included in the project.
