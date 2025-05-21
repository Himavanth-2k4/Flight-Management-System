
# ✈️ Flight Management System in C

A structured and efficient **Flight Management System** developed in **C** using fundamental data structures like **Binary Search Trees (BST)** and **Linked Lists**. This console-based application emulates core functionalities of an airline reservation system, including seat booking, cancellation, reservation tracking, and flight browsing.

---

## 📌 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Data Structures Used](#data-structures-used)
- [Program Flow](#program-flow)
- [Installation & Compilation](#installation--compilation)
- [How to Use](#how-to-use)
- [Sample Output](#sample-output)
- [Folder Structure](#folder-structure)
- [Author](#author)
- [License](#license)

---

## 📝 Overview

This Flight Management System allows users to manage flights and passengers through a user-friendly command-line interface. Flights are managed using a Binary Search Tree (BST) based on their flight numbers, while passenger records are maintained using singly linked lists within each flight node. The system enables dynamic seat allocation, cancellation, and flight browsing operations in a memory-efficient manner.

---

## 🎯 Features

- 🔍 **Search Flights:** Lookup flights using unique flight numbers.
- 📋 **Display Flights:** View all available flights using in-order traversal of the BST.
- ✅ **Book a Seat:** Reserve a seat on a specific flight for a passenger.
- ❌ **Cancel Reservation:** Remove a passenger's reservation from a flight.
- 📄 **View Reservation Status:** Display booked and available seats along with passenger details for a flight.
- 💡 **Dynamic Memory Allocation:** Efficient memory usage with linked list nodes for passengers and tree nodes for flights.
- 🧪 **Robust Input Handling:** Validates flight presence and booking status before any operations.

---

## 🧱 Data Structures Used

### 1. Binary Search Tree (BST)
- Used to store flights based on `flightNumber` for quick search and ordered display.
- Enables O(log n) performance on balanced input for insert/search operations.

### 2. Singly Linked List
- Each flight node maintains a linked list of passengers.
- Supports dynamic addition and removal of passengers for each flight.

---

## 🔄 Program Flow

```mermaid```
graph TD;  

    A[Start] --> B[Display Menu]
    B --> C{User Choice}
    C -->|1| D[Display Flights (Inorder BST)]
    C -->|2| E[Book a Seat -> Add Passenger to Linked List]
    C -->|3| F[Cancel Reservation -> Remove Node from List]
    C -->|4| G[View Reservation Status]
    C -->|5| H[Search for a Flight]
    C -->|6| I[Exit]
    D --> B
    E --> B
    F --> B
    G --> B
    H --> B
## ⚙️ Installation & Compilation

### Prerequisites

- GCC Compiler (or any standard C compiler)
- Terminal or Command Prompt (for compiling and running)

### Steps

#### Clone the Repository
```bash```
git clone https://github.com/your-username/FlightManagementSystem.git
cd FlightManagementSystem

## 🧭 How to Use  

Once the program starts, you'll see a menu like this:

Flight Reservation System
1. View available flights
2. Book a seat
3. Cancel reservation
4. Check reservation status
5. Search for Flight
6. Exit
You can select an option (1-6) to interact with the system. Each input is followed by clear prompts and success/error messages.

## 💻 Sample Output

Flight Reservation System
1. View available flights
2. Book a seat
3. Cancel reservation
4. Check reservation status
5. Search for Flight
6. Exit
Enter your choice: 2
Enter flight number: SA8972
Enter passenger name: Riya
Ticket booked successfully on flight SA8972 to Kolkata for Riya.

## 📁 Folder Structure

FlightManagementSystem

│

├── flight_management.c     # Complete C source code

└── README.md               # Project documentation
## 👨‍💻 Author
Kshatriya Himavanth Singh

Developer | Engineer | Programmer

📧 k.himavanthsingh@gmail.com

🔗 [Github](https://github.com/)

## 📜 License
This project is licensed under the MIT License - see the LICENSE file for details.

