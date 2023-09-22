# Simple C Database Management System
This is a simple command-line database management system implemented in C. It allows you to perform basic CRUD (Create, Read, Update, Delete) operations on a collection of records.

## Features
- Create a new record with an ID and a name.
- Read a record by its ID.
- Update a record's name by its ID.
- Delete a record by its ID.
- Data is stored in a binary file (database.dat) for persistence between program executions.
- Prerequisites
- Before running the program, make sure you have a C compiler (e.g., GCC) installed on your system.

## Usage
Clone the repository to your local machine:
```bash
git clone https://github.com/yourusername/simple-c-database.git
```
Change to the project directory:
```bash
cd simple-c-database
```
Compile the program:
```bash
gcc main.c -o database
```
Run the program:
```bash
./database
```

## Menu Options
1. Create Record: Enter an ID and a name to create a new record.
2. Read Record: Enter an ID to read a record.
3. Update Record: Enter an ID and a new name to update an existing record.
4. Delete Record: Enter an ID to delete a record.
5. Exit: Save the database to the file and exit the program.

## Data Persistence
The program stores the data in a binary file named database.dat in the same directory. This allows data to persist between program runs.

## Database Limits
The maximum number of records in the database is set to 1000 (MAX_DATABASE_SIZE).
If the database is full, you won't be able to add more records.

## Contributing
Feel free to contribute to this project by submitting pull requests.

## Acknowledgments
This project was created as a simple example of database management in C. It can be a starting point for more complex database systems or educational purposes.