# Student Task Manager

A simple console-based task management application developed in C.

This project demonstrates the use of structures, pointers, dynamic memory allocation, and a singly linked list to manage student tasks.

## Features

- Add a new task
- Display all tasks
- Search for a task using Task ID
- Mark a task as completed
- Delete a task
- Assign priority to tasks
- Menu-driven console interface

## Data Structure Used

### Singly Linked List

Each task is stored as a node in a singly linked list.

Task 1 → Task 2 → Task 3 → NULL

The linked list allows tasks to be added and deleted dynamically.

## Technologies

- C
- GCC
- Git
- GitHub

## Project Structure

student-task-manager/
│
├── src/
│   └── task_manager.c
│
├── README.md
└── .gitignore

## How to Run

### Compile

```bash
gcc src/task_manager.c -o task_manager