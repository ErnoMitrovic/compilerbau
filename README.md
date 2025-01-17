# Compilerbau Project

## Overview
The goal of this project is to implement a compiler for a C-like programming language. The compiler will consist of the following main components:

1. **Lexer**: Converts the input source code into a sequence of tokens.
2. **Parser**: Constructs an Abstract Syntax Tree (AST) from the token sequence using LL parsing.
3. **Code Generator**: Translates the AST into CMa-code, which can be executed in the VAM (Virtual Abstract Machine).
4. **Language Extension (Optional)**: Adds an additional feature to the language while maintaining compatibility with the CMa-code.

### Key Features
- **Native Implementation**: The compiler will be implemented entirely in C++ without the use of external libraries or tools.
- **Subset of C Language**: The compiler will support a subset of C, including basic data types, operators, control structures, and functions.
- **CMa-code Generation**: Output will be in CMa-code format for execution in the VAM.
- **Extensible Design**: The project includes the possibility to extend the language with an additional feature for bonus points.

### Project Phases
1. **Language Specification**: Define the subset of C language to be supported.
2. **Lexer Implementation**: Tokenize the input source code.
3. **Parser Implementation**: Create a recursive descent parser to construct the AST.
4. **Code Generation**: Translate the AST into CMa-code.
5. **Testing and Validation**: Verify the correctness of each component.
6. **Language Extension**: (Optional) Implement a language extension.

### Folder Details
1. **`src/`**:
   - Contains all source code for the project.
   - Separate subfolders for lexer, parser, and code generation for better modularity.

2. **`tests/`**:
   - Contains unit tests for each module.
   - Ensure comprehensive test coverage for lexer, parser, and code generator.

3. **`docs/`**:
   - Contains documentation, including language specification and project planning.
   - `example_programs/` contains test cases written in the C-like language.

4. **`build/`**:
   - Directory for build artifacts (executables, object files).

5. **`CMakeLists.txt`**:
   - Build system configuration for compiling the project.

6. **`README.md`**:
   - Project overview and instructions for setup and usage.

7. **`.gitignore`**:
   - Specifies files and directories to ignore in version control.

## Development Tools
- **Programming Language**: C++
- **Build System**: CMake
- **Version Control**: Git

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/ErnoMitrovic/compilerbau
   ```

2. Build the project:
   ```bash
   mkdir build && cd build
   cmake ..
   make
   ```

3. Run the compiler:
   ```bash
   ./compiler <source_file.c>
   ```

4. Test the compiler:
   ```bash
   cd tests
   ./run_tests
   ```

