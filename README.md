

## How to Compile, Run, and Clean the Project

### Prerequisites

Make sure you have the following tools installed:
- `g++` (GNU Compiler Collection for C++)
- `make` (Build automation tool)

### Steps to Compile, Run, and Clean the Project

1. **Compile the Project**:

    To compile the project, run the following command:
    ```sh
    make
    ```

    This command will compile the source files and create an executable named `ConsoleBang`.

2. **Run the Executable**:

    To run the compiled executable, use the following command:
    ```sh
    ./ConsoleBang
    ```

3. **Build and Run the Project**:

    You can also compile the project and immediately run the executable by using:
    ```sh
    make run
    ```

    This command will ensure the project is compiled and then execute the resulting binary.

4. **Clean the Project**:

    To clean up the compiled files and remove the executable, use:
    ```sh
    make clean
    ```

    This command will delete all object files and the executable, leaving only the source files and the `Makefile` intact.

