# RescueAnimalService

A C++ console application that manages rescue animals using a Binary Search Tree (BST). Supports intake, reservation, and listing of dogs and monkeys with structured attributes, input validation, and dynamic memory management.

## Overview

This system simulates a rescue animal intake and tracking service. It demonstrates object-oriented design, inheritance, and tree-based data structures. The application is menu-driven and allows users to interactively manage a collection of animals. This project was created for a Programming Languages course at SNHU, and I further expanded the project to include a Binary Search Tree for another course at SNHU.

## Features

- Intake new dogs and monkeys with validated input
- Search animals by unique ID
- Print lists of:
  - All dogs
  - All monkeys
  - All unreserved animals
- Dog-specific attributes: breed
- Monkey-specific attributes: species, tail/body/height measurements
- Enum-based classification for type, gender, training status, and species
- Binary Search Tree implementation for efficient data management
- Input validation and error handling for robust user experience

## Technologies Used

- Language: C++17
- Libraries: `<iostream>`, `<string>`, `<limits>`, `<ctime>`, `<cctype>`

## Getting Started

### Prerequisites

- C++ compiler (e.g., g++, clang++)
- Terminal or IDE with console support

### Build & Run

```bash
g++ -std=c++17 -o RescueAnimalService RescueAnimalService.cpp
./RescueAnimalService

```
### Menu Options
```bash
--- Rescue Animal Service Menu ---
1. Intake new dog
2. Intake new monkey
3. Reserve an animal
4. Print a list of all dogs
5. Print a list of all monkeys
6. Print a list of all animals that are not reserved
9. Exit
```

## 🧠 Skills Demonstrated

This project showcases a strong mix of technical and professional skills relevant to software engineering and IT infrastructure roles:

### ✅ Core Technical Skills
- **Object-Oriented Programming (OOP)**  
  Inheritance (`Dog`, `Monkey` from `RescueAnimal`), encapsulation via getters/setters, and enum-based type safety.
- **Data Structures**  
  Implementation of a Binary Search Tree (BST) for efficient storage, search, and traversal of animal records.
- **Input Validation & Error Handling**  
  Robust checks for user input types, ranges, and formats to ensure clean and reliable interaction.
- **Console-Based UI Design**  
  Menu-driven interface with modular functions for intake, reservation, and display operations.

### 🛠 Software Engineering Practices
- **Code Organization**  
  Logical separation of concerns between data models, tree logic, and user interface.
- **Documentation & Readability**  
  Clear inline comments, descriptive naming, and structured formatting for maintainability.
- **Reusability & Extensibility**  
  Modular design supports future enhancements like new animal types or persistent storage.

### 💼 Professional & Transferable Skills
- **Analytical Thinking**  
  Designing a searchable tree structure and mapping real-world entities into structured data models.
- **Problem Solving**  
  Handling edge cases like duplicate IDs, empty trees, and invalid inputs.
- **Communication & Presentation**  
  Code is structured for clarity and explanation—ideal for portfolio reviews and team collaboration.
