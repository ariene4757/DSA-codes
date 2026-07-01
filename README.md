# Data Structures and Algorithms (DSA) in C++

## Overview
This repository contains my personal implementations of core Data Structures and Algorithms from scratch using C++. It serves as a continuous learning portfolio aimed at mastering memory management, algorithmic efficiency, and object-oriented design patterns.

## 📂 Repository Structure
The repository is modular. Each Data Structure or Algorithm is isolated in its own dedicated directory. 

Inside each directory, you will typically find:
* `*.h` or `*.cpp` files containing the core logic and template-based implementation.
* `main.cpp` containing unit tests and edge cases to verify the implementation.
* (Optional) A local `.gitignore` to prevent compiled binaries from being tracked.

## ✨ Key Features
* **Built from Scratch:** No reliance on the C++ Standard Template Library (STL) for the core logic (unless explicitly stated).
* **Template-Based:** Implementations are highly generic to support various data types.
* **Memory Safe:** Strict focus on dynamic memory allocation and preventing memory leaks using proper destructors.
* **Algorithmically Optimized:** Emphasis on maintaining standard Time and Space complexities.

## 🚀 How to Run
To compile and test any specific data structure, use a standard C++ compiler (like `g++`). 

1. Open your terminal and navigate to the desired module's folder:
   ```bash
   cd <Folder_Name>
   ```
2. Compile the test file:
   ```bash
   g++ main.cpp -o test_run
   ```
3. Execute the compiled binary:
   * **Windows:** `.\test_run`
   * **Linux/Mac:** `./test_run`