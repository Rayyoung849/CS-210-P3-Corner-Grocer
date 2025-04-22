// Project 2 Airgead Banking
// CS-210
// Date: 04/03/25
// AirgeadBanking.cpp


#include <iostream>   // For input/output operations
#include <iomanip>    // For formatting output with setprecision 
#include "InvestmentCalculator.h"  // Include our custom calculator class

int main() {
    // Declare variables for storing user input values
    // Initialize all to zero to prevent any garbage values
    double initialInvestment = 0.0;  // Stores the starting investment amount
    double monthlyDeposit = 0.0;     // Stores the amount added each month
    double interestRate = 0.0;       // Stores the annual interest percentage
    int years = 0;                   // Stores the investment time period

    // Display welcome message to the user
    std::cout << "Hello from Airgead Banking!" << std::endl << std::endl;

    // Prompt user for investment parameters and store their inputs
    std::cout << "Initial Investment Amount ($): ";
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit ($): ";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (%): ";
    std::cin >> interestRate;

    std::cout << "Number of Years: ";
    std::cin >> years;

    // Echo back the input values with proper formatting for confirmation
    // Set fixed-point notation and 2 decimal places for dollar amounts
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::endl;
    std::cout << "Initial Investment Amount: $" << initialInvestment << std::endl;
    std::cout << "Monthly Deposit: $" << monthlyDeposit << std::endl;
    std::cout << "Annual Interest: %" << interestRate << std::endl;
    std::cout << "Number of Years: " << years << std::endl;

    // Create an InvestmentCalculator object with the user-provided values
    // This will be used to perform all our investment calculations
    InvestmentCalculator calculator(initialInvestment, monthlyDeposit, interestRate, years);

    // Generate and display both investment reports using our calculator object
    calculator.displayInvestmentReport();

    return 0;  // Return successful program execution status
}