# RescueAnimalService

A C++ console application that manages rescue animals using a Binary Search Tree (BST). Supports intake, reservation, and listing of dogs and monkeys with structured attributes, input validation, and dynamic memory management.

## Overview

This system simulates a rescue animal intake and tracking service. It demonstrates object-oriented design, inheritance, and tree-based data structures. The application is menu-driven and allows users to interactively manage a collection of animals.

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
