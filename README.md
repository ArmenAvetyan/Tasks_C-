# C++ Learning & Implementation Projects

A comprehensive repository containing various C++ projects, algorithms, and data structure implementations. This collection demonstrates core C++ concepts, advanced features, and practical applications.

## 📂 Full Repository Structure

```
.
├── algorithms/
│   ├── bubble_sort.hpp
│   ├── insertion_sort.hpp
│   ├── selection_sort.hpp
│   ├── binary_search.hpp
│   ├── counting_sort.hpp
│   ├── equal_range.hpp
│   ├── lower_bound.hpp
│   ├── marge_sort.hpp
│   ├── quick_select.hpp
│   ├── quick_sort.hpp
│   ├── raddix_sort.hpp
│   ├── upper_bound.hpp
│   └── test.cpp
│
├── DOnStore/
│   ├── main.cpp
│   ├── onStore.cpp
│   └── onStore.hpp
│
├── Employee_Pay_Sys/
│   ├── include/
│   │   ├── bonus_eligible.hpp
│   │   ├── employee.hpp
│   │   ├── freelancer.hpp
│   │   ├── full_time_employee.hpp
│   │   ├── part_time_employee.hpp
│   │   └── pay_sys.hpp
│   └── src/
│       ├── employee.cpp
│       ├── freelancer.cpp
│       ├── full_time_employee.cpp
│       ├── main.cpp
│       ├── part_time_employee.cpp
│       └── pay_sys.cpp
│
├── files/
│   ├── CountFileStatistics.cpp
│   ├── FileEncryptionProgram.cpp
│   ├── MergeTwoFiles.cpp
│   └── copy_file.cpp
│
├── forward_listIMP/
│   ├── forward_list.cpp
│   └── forward_list.hpp
│
├── LMS/
│   ├── lms.cpp
│   ├── lms.hpp
│   └── main.cpp
│
├── library_management_system/
│   ├── include/
│   ├── src/
│   └── LMS.drawio
│
├── matrix_class/
│   ├── matrix.cpp
│   └── matrix.hpp
│
├── smartPointers_imp/
│   ├── shared_ptr.cpp
│   ├── shared_ptr.hpp
│   ├── weak_ptr.cpp
│   └── weak_ptr.hpp
│
├── variadicTemplates_tasks/
│   ├── format.cpp
│   ├── max_variadic.cpp
│   ├── print_reverse.cpp
│   └── variadicTemplatePrint.cpp
│
├── vectorIMP/
│   ├── vector.cpp
│   └── vector.hpp
│
└── README.md

```

## 📁 Repository Structure

### **Quick Reference**

| Project | Type | Language | Purpose |
|---------|------|----------|---------|
| **algorithms** | Sorting & Searching | C++ | Sorting and searching algorithm implementations |
| **DOnStore** | System | C++ | Online store management with data structures |
| **Employee_Pay_Sys** | System | C++ | Payroll management with OOP inheritance |
| **files** | Utilities | C++ | File I/O and manipulation programs |
| **forward_listIMP** | Data Structure | C++ | Custom singly linked list implementation |
| **LMS** | System | C++ | Simple library management system |
| **library_management_system** | System | C++ | Advanced library management with diagrams |
| **matrix_class** | Data Structure | C++ | Matrix with mathematical operations |
| **smartPointers_imp** | Memory Management | C++ | Shared/Weak pointer implementations |
| **variadicTemplates_tasks** | Advanced Templates | C++ | Variadic template metaprogramming |
| **vectorIMP** | Data Structure | C++ | Custom dynamic array implementation |

---

### **Detailed Project Descriptions**

### **algorithms**
Collection of sorting and searching algorithm implementations:

**Files:**
- `bubble_sort.hpp` - Bubble sort implementation
- `insertion_sort.hpp` - Insertion sort implementation
- `selection_sort.hpp` - Selection sort implementation
- `binary_search.hpp` - Binary search implementation (recursive and iterative versions)
- `counting_sort.hpp` - Counting sort implementation
- `equal_range.hpp` - Equal range implementation
- `lower_bound.hpp` - Lower bound implementation
- `marge_sort.hpp` - Merge sort implementation
- `quick_select.hpp` - Quickselect implementation
- `quick_sort.hpp` - Quick sort implementation
- `raddix_sort.hpp` - Radix sort implementation (base-10 and 256-bucket/byte-based versions)
- `upper_bound.hpp` - Upper bound implementation
- `test.cpp` - Test driver for the algorithms above

**Features:**
- Elementary and advanced sorting algorithms (bubble, insertion, selection, merge, quick, counting, radix)
- Binary search with both recursive and iterative implementations
- Related search utilities (lower_bound, upper_bound, equal_range)
- Radix sort with base-10 and 256-bucket (byte-wise) variants
- Quickselect for order statistics
- Use of C++20 concepts for template constraints
- Use of the Ranges library
- Comparison and analysis of sorting/searching methods
- Time complexity demonstrations

---

### **DOnStore**
Online Store management system with data structures and transactions:

**Files:**
- `main.cpp` - Application entry point
- `onStore.cpp` - Online store implementation
- `onStore.hpp` - Online store class definition

**Features:**
- Product management
- Shopping cart operations
- Order processing
- Transaction handling

---

### **Employee_Pay_Sys**
Comprehensive employee payroll management system using inheritance and polymorphism:

**Directory Structure:**
```
Employee_Pay_Sys/
├── include/
│   ├── bonus_eligible.hpp      # Bonus eligibility interface
│   ├── employee.hpp             # Base employee class
│   ├── freelancer.hpp           # Freelancer employee type
│   ├── full_time_employee.hpp   # Full-time employee type
│   ├── part_time_employee.hpp   # Part-time employee type
│   └── pay_sys.hpp              # Payroll system class
└── src/
    ├── main.cpp                 # Application entry point
    ├── employee.cpp             # Base employee implementation
    ├── freelancer.cpp           # Freelancer implementation
    ├── full_time_employee.cpp   # Full-time employee implementation
    ├── part_time_employee.cpp   # Part-time employee implementation
    └── pay_sys.cpp              # Payroll system implementation
```

**Features:**
- Object-oriented employee hierarchy
- Multiple employee types (Full-time, Part-time, Freelancer)
- Bonus eligibility system
- Salary calculation and processing
- Payroll management

---

### **files**
File I/O and file manipulation utilities:

**Files:**
- `CountFileStatistics.cpp` - Analyze file statistics (lines, words, characters)
- `FileEncryptionProgram.cpp` - Simple file encryption/decryption
- `MergeTwoFiles.cpp` - Combine two files into one
- `copy_file.cpp` - File copying utility

**Features:**
- File reading and writing operations
- Stream handling
- Data processing and analysis
- File manipulation utilities

---

### **forward_listIMP**
Custom singly linked list (forward list) implementation:

**Files:**
- `forward_list.hpp` - Forward list class definition
- `forward_list.cpp` - Forward list implementation

**Features:**
- Singly linked list data structure
- Insert and delete operations
- Traversal and iteration
- Memory management
- Node-based structure

---

### **LMS**
Simple Library Management System for book and member management:

**Files:**
- `main.cpp` - Application entry point
- `lms.hpp` - Library management class definition
- `lms.cpp` - Library management implementation

**Features:**
- Book inventory management
- Member management
- Basic borrowing/returning system
- Search functionality

---

### **library_management_system**
Advanced Library Management System with comprehensive features:

**Directory Structure:**
```
library_management_system/
├── include/             # Header files
├── src/                 # Source files
└── LMS.drawio          # System architecture diagram
```

**Features:**
- Advanced book tracking
- Member authentication
- Reservation system
- Overdue tracking
- Fine calculations
- Report generation

---

### **matrix_class**
Custom matrix data structure with mathematical operations:

**Files:**
- `matrix.hpp` - Matrix class definition
- `matrix.cpp` - Matrix implementation

**Features:**
- Matrix creation and initialization
- Basic operations (addition, multiplication, transpose)
- Determinant calculations
- Operator overloading (+, -, *, etc.)
- Element access and modification

---

### **smartPointers_imp**
Smart pointer implementations for automatic memory management:

**Files:**
- `shared_ptr.hpp` - Shared pointer class definition
- `shared_ptr.cpp` - Shared pointer implementation
- `weak_ptr.hpp` - Weak pointer class definition
- `weak_ptr.cpp` - Weak pointer implementation

**Features:**
- Reference counting mechanism
- Shared pointer (multiple ownership)
- Weak pointer (non-owning reference)
- Memory leak prevention
- RAII (Resource Acquisition Is Initialization) pattern
- Circular reference handling

---

### **variadicTemplates_tasks**
Advanced C++ template metaprogramming using variadic templates:

**Files:**
- `variadicTemplatePrint.cpp` - Print variadic template arguments
- `format.cpp` - Variadic template formatting utilities
- `max_variadic.cpp` - Find maximum value with variadic templates
- `print_reverse.cpp` - Print arguments in reverse order

**Features:**
- Variable length template arguments
- Template specialization
- Fold expressions (C++17)
- Type traits
- Compile-time computations
- Parameter packs

---

### **vectorIMP**
Custom dynamic array (vector) implementation:

**Files:**
- `vector.hpp` - Vector class definition
- `vector.cpp` - Vector implementation

**Features:**
- Dynamic memory allocation
- Automatic resizing and capacity management
- Random element access
- Iterator support
- Push/pop operations
- Exception handling
- STL-like interface

## 🛠️ Technologies & Concepts

- **Language**: C++ (C++20 and later standards)
- **Paradigms**: Object-Oriented Programming, Generic Programming
- **Key Concepts**:
  - Data Structures
  - Algorithms
  - Memory Management
  - Smart Pointers
  - Templates & Metaprogramming
  - C++20 Concepts
  - Ranges Library
  - Object-Oriented Design
  - Exception Handling
  - File I/O

## 📋 Requirements

- **Compiler**: GCC, Clang, or MSVC (C++20 or later)
- **Build System**: CMake (optional) or manual compilation
- **Operating System**: Windows, macOS, or Linux

## 🚀 Getting Started

### **Quick Compilation Guide**

Each project can be compiled differently based on its structure:

**Simple Projects (single or few files):**
```bash
# algorithms, files, forward_listIMP, matrix_class, vectorIMP
cd <project_name>
clang++ -std=c++23 *.cpp -o program
./program
```

**Projects with src/ and include/ structure:**
```bash
# Employee_Pay_Sys
cd Employee_Pay_Sys
clang++ -std=c++23 -I include src/*.cpp -o payroll
./payroll
```

**Variadic Templates Project:**
```bash
# variadicTemplates_tasks
cd variadicTemplates_tasks
clang++ -std=c++23 *.cpp -o variadic
./variadic
```

**DOnStore Project:**
```bash
cd DOnStore
clang++ -std=c++23 *.cpp -o store
./store
```

**LMS Projects:**
```bash
cd LMS
clang++ -std=c++23 *.cpp -o library
./library
```

**smartPointers Project:**
```bash
cd smartPointers_imp
clang++ -std=c++23 *.cpp -o pointers
./pointers
```

---

### **Using CMake (Optional)**

If CMakeLists.txt exists:
```bash
cd <project_name>
mkdir build
cd build
cmake ..
make
./program
```

## 📚 Project Dependencies

Most projects are self-contained and don't require external libraries. Some optional features may use:
- Standard Library (STL)
- POSIX APIs (for file operations)
- Platform-specific APIs (Windows/Linux)

## 🔧 Compilation Flags (Recommended)

For debugging and catching undefined behavior:
```bash
clang++ -std=c++23 -Wall -Wextra -g -fsanitize=undefined *.cpp -o program
```

For optimization:
```bash
clang++ -std=c++23 -O2 *.cpp -o program
```

## 📖 How to Use This Repository

1. **Browse Projects**: Navigate to any folder to explore its implementation
2. **Study Code**: Review implementation details and design patterns
3. **Compile & Test**: Build and run projects to see them in action
4. **Modify**: Adapt code for learning purposes
5. **Extend**: Add new features or algorithms

## 🎯 Learning Objectives

This repository covers:
- ✅ Fundamental and advanced data structures
- ✅ Algorithm design and optimization
- ✅ Memory management and pointer operations
- ✅ Object-oriented design principles
- ✅ Template programming and metaprogramming
- ✅ C++20 concepts and the Ranges library
- ✅ File I/O and system programming
- ✅ Best practices and code organization

## 📝 Code Style

- Uses meaningful variable and function names
- Includes comments for complex logic
- Follows Standard C++ guidelines
- Implements proper error handling
- Uses RAII principles for resource management

## ⚠️ Notes

- Always use appropriate compilation flags for safety
- Code is for educational purposes

## 🤝 Contributing

To improve or expand these projects:
1. Review existing implementations
2. Add new algorithms or features
3. Improve documentation
4. Optimize existing code
5. Add test cases

## 📄 License

Educational use - Free to use and modify for learning purposes.

## 📞 Support

For questions about specific implementations:
- Review source code comments
- Check project-specific documentation (if available)
- Examine test files for usage examples

---

**Last Updated**: 2026

**Language**: C++ (C++20 and later)

**Level**: Intermediate to Advanced
