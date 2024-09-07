# Personal Expense Manager

## Overview

This project is a comprehensive financial reporting tool used from the CLI designed to manage and analyze transaction data. It allows users to import, export, and generate various financial reports based on different criteria such as date ranges, categories, and payment modes. The application also provides options to generate reports in CSV and Excel formats.

## Features

- **Transaction Management**: Import and manage financial transactions.
- **Report Generation**: Generate detailed financial reports based on various criteria.
- **Data Export**: Export reports to CSV and Excel formats for further analysis.

## Files and Classes

### Core Components

- **main.cpp**: The entry point of the application. It initializes the main menu and begins the user interaction loop.

### Transaction Management

- **Transaction.cpp**: Represents a single financial transaction. This class includes details like amount, date, category, transaction message and payment mode.
- **TransactionManager.cpp**: Manages a collection of transactions. It handles adding, removing, deleting transactions and all other operations related to transactions.
- **TransactionParser.cpp**: Parses transaction data from raw input, converting it into `Transaction` objects.

### Reports

- **Report.cpp**: The base class for all report types. It defines the common interface and functionality shared by all reports.
- **ReportManager.cpp**: Manages the generation and retrieval of different types of reports.
- **BalanceReport.cpp**: Generates a report detailing the balance from income and total expenses.
- **CategoryReport.cpp**: Generates a report summarizing expenses by category.
- **DateRangeReport.cpp**: Generates a report for transactions within a specified date range.
- **DetailedCategoryReport.cpp**: Provides a detailed transactions on transactions in selected category.
- **MonthlyReport.cpp**: Generates a monthly summary report.
- **PaymentModeReport.cpp**: Summarizes transactions based on the payment mode (e.g., cash, credit card).
- **QuarterlyReport.cpp**: Generates a quarterly summary report.

### Menu System

- **MainMenu.cpp**: Implements the main menu of the application, allowing the user to navigate between different features.
- **Menu.cpp**: The base class for all menu components, providing common functionality for user interaction.
- **MenuSwitcher.cpp**: Handles switching between different menus.
- **ReportMenu.cpp**: A specialized menu for selecting and generating reports.

### Data Import/Export

- **CSVImporter.cpp**: Handles the import of transaction data from CSV files.
- **CSVExporter.cpp**: Exports generated reports and transactions to CSV files.
- **ExcelExporter.cpp**: Exports generated reports and transactions to Excel format.

### Utilities

- **Utils.cpp**: Contains utility functions and helpers used throughout the application.

## How to Run

  1. Compile the project using your preferred C++ compiler.
  2. Run the `main` executable to start the application.
  3. Use the main menu to navigate through the available options, import data, generate reports, and export them as needed.
4. To try the project out 100transaction.csv file can be imported 

## Dependencies

- [xlsxwriter] = a library to write to excel files.

## How to compile
The project should run directly on mac
On windows the library is not available in my findings

## Creator
Vrushabh Jain
vrushabh.jain@tum.de
