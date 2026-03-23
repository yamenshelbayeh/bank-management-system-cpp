# Bank Management System in C++

A console-based banking system built in C++ with support for client management, user management, transactions, login tracking, permissions, and currency exchange.

## Overview

This project simulates a small banking system through a menu-driven console interface.  
It allows authenticated users to manage clients, perform transactions, manage system users, and access additional banking tools depending on their assigned permissions.

The project is structured using object-oriented programming principles and organized into multiple modules such as core classes, screens, login handling, and utility helpers.

## Features

### Authentication & Security
- User login system
- Limited login attempts
- Invalid login handling
- Login register/history screen
- Simple password encryption/decryption for file-based authentication

### Client Management
- Show client list
- Add new client
- Delete client
- Update client information
- Find client
- Store and load client records from file

### Transactions
- Deposit money
- Withdraw money
- Transfer funds between clients
- Transfer log tracking
- Total balances support

### User Management
- List users
- Add new user
- Delete user
- Update user
- Find user
- Manage user permissions

### Permission System
The system supports different access levels for different users.

Example permissions include:
- Show clients
- Add clients
- Delete clients
- Update clients
- Find clients
- Transactions
- Manage users
- Login register
- Currency exchange

### Currency Exchange
- List currencies
- Find a currency
- Update currency rate
- Currency calculator

## Screens Included

The application includes multiple console screens, such as:
- Login Screen
- Main Screen
- Client List Screen
- Manage Users Screen
- Login Register Screen
- Currency Exchange Screen

## Demo Login

For testing purposes, you can use a demo account with full permissions:

- Username: `User2`
- Password: `1234`

This account is included only to make the project easy to run and explore locally.

## Project Structure

```text
bank-management-system-cpp/
├── README.md
├── LICENSE
├── .gitignore
├── Coruse11-BankProject.sln
└── Coruse11-BankProject/
    ├── Core/
    ├── Screens/
    ├── Utils/
    ├── Global.h
    └── source/header files
