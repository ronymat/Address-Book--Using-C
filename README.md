#  Address Book – Using C

## Project Overview

The Address Book is a menu-driven, file-based application implemented in C that allows users to manage contact information efficiently.
This project demonstrates structured programming, file handling, input validation, and modular design using arrays and structures in C.
The system enables users to create, search, edit, delete, and list contacts with persistent storage support.

## Objectives

* Implement full Create, Read, Update, Delete operations
* Store and retrieve contact data using file handling
* Prevent duplicate phone numbers and email IDs
* Validate user input for data integrity
* Maintain persistent storage across executions
* Practice modular programming using header and source files


## Technologies Used

* C Programming
* GCC Compiler
* Makefile
* Text File Handling
* Structures & Arrays


## Core Concepts

* Structures (`struct`)
* Modular Programming
* File Handling (`fopen`, `fprintf`, `fscanf`)
* String Manipulation (`strcpy`, `strcmp`, `strstr`)
* Input Validation
* Linear Search Algorithm
* Array Shifting for Deletion
* Static Memory Allocation


## Features

* Create new contact
* Search contact by name, phone, or email
* Edit contact details
* Delete contact
* List all contacts in formatted table view
* Automatic loading of contacts at startup
* Saving contacts to file
* Mobile number validation (10 digits, unique)
* Email validation (.com format, unique)


## File Storage Format

Contacts are stored in `contacts.txt` in CSV-like format:

```
3
John Doe,1234567890,john@gmail.com
Alice,9876543210,alice@gmail.com
```

* First line → Number of contacts
* Remaining lines → `name,phone,email`


## How to Compile

### Using Makefile:

```bash
make
./addressbook
```

