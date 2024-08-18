# Personal Expense Tracker

Description: An application to track personal expenses
Features:

Input transactions with categories, amounts, and dates.
Display a summary of expenses and income.
Generate reports for a specific time period.
Export and import transaction data (CSV or Excel).

TODO:
try to change the dates to chrono libra
# Project Name

## Overview

This project is a comprehensive financial reporting tool designed to manage and analyze transaction data. It allows users to import, export, and generate various financial reports based on different criteria such as date ranges, categories, and payment modes. The application also provides options to generate reports in CSV and Excel formats.

## Features

- **Transaction Management**: Import and manage financial transactions.
- **Report Generation**: Generate detailed financial reports based on various criteria.
- **Data Export**: Export reports to CSV and Excel formats for further analysis.

## Files and Classes

### Core Components

- **main.cpp**: The entry point of the application. It initializes the main menu and begins the user interaction loop.

### Transaction Management

- **Transaction.cpp**: Represents a single financial transaction. This class includes details like amount, date, category, and payment mode.
- **TransactionManager.cpp**: Manages a collection of transactions. It handles adding, removing, and querying transactions.
- **TransactionParser.cpp**: Parses transaction data from raw input, converting it into `Transaction` objects.

### Reports

- **Report.cpp**: The base class for all report types. It defines the common interface and functionality shared by all reports.
- **ReportManager.cpp**: Manages the generation and retrieval of different types of reports.
- **BalanceReport.cpp**: Generates a report detailing the balance over a period.
- **CategoryReport.cpp**: Generates a report summarizing transactions by category.
- **DateRangeReport.cpp**: Generates a report for transactions within a specified date range.
- **DetailedCategoryReport.cpp**: Provides a detailed report on transactions in each category.
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
- **CSVExporter.cpp**: Exports generated reports to CSV files.
- **ExcelExporter.cpp**: Exports generated reports to Excel format.

### Utilities

- **Utils.cpp**: Contains utility functions and helpers used throughout the application.

## How to Run

1. Compile the project using your preferred C++ compiler.
2. Run the `main` executable to start the application.
3. Use the main menu to navigate through the available options, import data, generate reports, and export them as needed.

## Dependencies

- [Any required libraries or dependencies for the project]
- [Instructions for installing dependencies]

## Contribution

If you'd like to contribute to this project, please fork the repository and submit a pull request. For major changes, please open an issue to discuss what you would like to change.

## License

This project is licensed under the [Your License Here].
