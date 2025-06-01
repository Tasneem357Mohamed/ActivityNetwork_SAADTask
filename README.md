# Project Management: Critical Path Method (CPM) Calculator

This C++ project implements the **Critical Path Method (CPM)**, a fundamental technique in project management. It helps you analyze project tasks, determine their earliest and latest possible start and finish times, identify **critical tasks** (those that cannot be delayed without delaying the entire project), and calculate the **overall project duration**.

---

## Table of Contents

- [About the Project](#about-the-project)
- [How CPM Works](#how-cpm-works)
- [Key Features](#key-features)
- [Getting Started](#getting-started)
    - [Prerequisites](#prerequisites)
    - [Building the Project](#building-the-project)
    - [Running the Application](#running-the-application)
- [Input File Format](#input-file-format)
- [Output Explained](#output-explained)
- [Our Development Team](#our-development-team)

---

## About the Project

Managing projects with multiple interdependent tasks can be complex. The Critical Path Method provides a structured way to visualize project timelines, dependencies, and potential bottlenecks. This application automates the calculations involved in CPM, making it easier to plan, schedule, and track your projects.

---

## How CPM Works

CPM involves two main passes:

1. **Forward Pass**: Calculates the **Earliest Start (ES)** and **Earliest Finish (EF)** times for each task. It determines the soonest a task can begin and end, considering all preceding dependencies. The earliest finish time of the last task represents the minimum possible project duration.
2. **Backward Pass**: Calculates the **Latest Start (LS)** and **Latest Finish (LF)** times for each task. It determines the latest a task can begin and end without delaying the overall project completion time.
3. **Slack Calculation**: The difference between LS and ES (or LF and EF) for a task is its **slack** or **float**. Tasks with zero slack are **critical tasks**, meaning any delay in these tasks will directly extend the project's total duration.
4. **Critical Path Identification**: The longest sequence of critical tasks from start to finish forms the **critical path**. This path dictates the minimum time required to complete the project.

---

## Key Features

- **Task Management**: Define tasks with their durations and dependencies.
- **Early/Late Time Calculation**: Automatically computes Early Start, Early Finish, Late Start, and Late Finish times for all tasks.
- **Project Duration**: Determines the minimum possible duration to complete the entire project.
- **Critical Task Identification**: Flags tasks that are critical to the project timeline.
- **Critical Path Discovery**: Identifies and lists all possible critical paths within the project network.
- **File I/O**: Reads project data from `input.txt` and writes results to `output.txt`.

---

## Getting Started

Follow these instructions to get a copy of the project up and running on your local machine.

### Prerequisites

You'll need a C++ compiler to build this project (e.g., g++).

### Building the Project

1. **Save the code**: Save the provided C++ code as `main.cpp`.
2. **Compile**: Open your terminal or command prompt, navigate to the directory where you saved `main.cpp`, and compile it using a C++ compiler:
    Bash
    ```
    g++ main.cpp -o cpm_calculator -std=c++11
    ```
    This command compiles `main.cpp` and creates an executable file named `cpm_calculator` (or `cpm_calculator.exe` on Windows).
    

### Running the Application

1. **Prepare your input**: Create a file named `input.txt` in the same directory as your executable. Refer to the [Input File Format](https://www.google.com/search?q=%23input-file-format) section for details on how to structure this file.
2. **Execute**: Run the compiled program from your terminal:
    Bash
    ```
    ./cpm_calculator
    ```
    The program will read from `input.txt` and write all its output to `output.txt`.

---

## Input File Format

The `input.txt` file should follow this structure:

1. The first line contains a single integer: **`num_of_tasks`** (the total number of tasks in your project).
2. Each subsequent line represents a task and should contain:
    - **`task_id`**: An integer representing the unique ID of the task (1-indexed).
    - **`duration`**: An integer representing the duration of the task.
    - **`num_of_dependencies`**: An integer representing how many tasks this current task depends on.
    - **`dep_id1 dep_id2 ...`**: `num_of_dependencies` integers, each being the ID of a task that the current `task_id` depends on. If a task has no dependencies, `num_of_dependencies` should be `0`.

**Example `input.txt`:**

```
5
1 5 0
2 3 1 1
3 4 1 1
4 6 2 2 3
5 2 1 4
```

This example represents a project with 5 tasks:

- **Task 1**: Duration 5, no dependencies.
- **Task 2**: Duration 3, depends on Task 1.
- **Task 3**: Duration 4, depends on Task 1.
- **Task 4**: Duration 6, depends on Task 2 and Task 3.
- **Task 5**: Duration 2, depends on Task 4.

---

## Output Explained

All program output will be written to `output.txt`.

- **Dependencies and Dependents**: Lists each task and its direct predecessors (dependencies) and successors (dependents).
- **After Forward Pass**: Shows the **Early Start (ES)** and **Early Finish (EF)** times for each task.
    - **ES**: The earliest time a task can begin.
    - **EF**: The earliest time a task can be completed (`ES + Duration`).
- **After Backward Pass**: Shows the **Late Start (LS)** and **Late Finish (LF)** times for each task.
    - **LS**: The latest time a task can begin without delaying the project.
    - **LF**: The latest time a task can be completed without delaying the project (`LS + Duration`).
- **Final Task Schedule**: A consolidated table displaying ES, EF, LS, and LF for all tasks.
- **Critical Paths**: Lists all identified critical paths. Each path is a sequence of task IDs, where any delay in a task on this path will delay the entire project.
- **Project Duration**: The total minimum time required to complete the entire project, derived from the maximum Early Finish time of all tasks.

---

## Our Development Team

| Name            | GitHub Profile                               |
| :-------------- | :------------------------------------------- |
| [Member 1 Name] | [**Replace with actual GitHub profile URL**] |
| [Member 2 Name] | [**Replace with actual GitHub profile URL**] |
| [Member 3 Name] | [**Replace with actual GitHub profile URL**] |
| [Member 4 Name] | [**Replace with actual GitHub profile URL**] |
| [Member 5 Name] | [**Replace with actual GitHub profile URL**] |
| [Member 6 Name] | [**Replace with actual GitHub profile URL**] |
`