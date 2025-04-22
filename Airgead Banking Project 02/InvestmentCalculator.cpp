#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>

// Constructor to initialize member variables
InvestmentCalculator::InvestmentCalculator(double initialInvestment, double monthlyDeposit,
    double annualInterestRate, int numberOfYears) {
    m_initialInvestment = initialInvestment;
    m_monthlyDeposit = monthlyDeposit;
    m_annualInterestRate = annualInterestRate;
    m_numberOfYears = numberOfYears;
}

// Getters and setters implementation
double InvestmentCalculator::getInitialInvestment() const {
    return m_initialInvestment;
}

void InvestmentCalculator::setInitialInvestment(double initialInvestment) {
    m_initialInvestment = initialInvestment;
}

double InvestmentCalculator::getMonthlyDeposit() const {
    return m_monthlyDeposit;
}

void InvestmentCalculator::setMonthlyDeposit(double monthlyDeposit) {
    m_monthlyDeposit = monthlyDeposit;
}

double InvestmentCalculator::getAnnualInterestRate() const {
    return m_annualInterestRate;
}

void InvestmentCalculator::setAnnualInterestRate(double annualInterestRate) {
    m_annualInterestRate = annualInterestRate;
}

int InvestmentCalculator::getNumberOfYears() const {
    return m_numberOfYears;
}

void InvestmentCalculator::setNumberOfYears(int numberOfYears) {
    m_numberOfYears = numberOfYears;
}

/**
 * Prints the calculated results of each years investment details in 3 separate fields
 * @param year year number
 * @param yearEndBalance the current dollar value of the investment
 * @param interestEarned dollar amount of how much earned in that year
 */
void InvestmentCalculator::printDetails(int year, double yearEndBalance, double interestEarned) const {
    // Set fixed point notation and precision to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);

    // Print year with consistent width
    std::cout << std::setw(4) << year;

    // Add consistent spacing between columns
    std::cout << "          ";

    // Print year-end balance with exactly 1 space between $ and number
    std::cout << "$" << std::setw(1) << yearEndBalance;

    // Add consistent spacing between columns
    std::cout << "          ";

    // Print interest earned with exactly 1 space between $ and number
    std::cout << "$" << std::setw(1) << interestEarned;

    // End the line
    std::cout << std::endl;
}

/**
 * Calculates and returns an end of year balance for given number of years
 * without monthly deposits
 * @return the final calculated end of year balance
 */
double InvestmentCalculator::calculateBalanceWithoutMonthlyDeposit() const {
    // Initialize the starting balance with the initial investment
    double balance = m_initialInvestment;

    // Convert annual interest rate to monthly
    double monthlyInterestRate = m_annualInterestRate / 100 / 12;

    // Track the interest earned each year
    double previousYearBalance = 0.0;
    double interestEarnedThisYear = 0.0;

    // Iterate through each year
    for (int year = 1; year <= m_numberOfYears; year++) {
        // Store the balance at the beginning of the year to calculate interest earned
        previousYearBalance = balance;

        // Compound interest monthly (12 times per year)
        for (int month = 0; month < 12; month++) {
            // Calculate and add monthly interest to the balance
            balance += balance * monthlyInterestRate;
        }

        // Calculate interest earned this year
        interestEarnedThisYear = balance - previousYearBalance;

        // Print the details for this year
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return the final balance after all years of compounding
    return balance;
}

/**
 * Calculates and returns an end of year balance for a given number of years
 * with additional monthly deposits
 * @return the final calculated end of year balance
 */
double InvestmentCalculator::balanceWithMonthlyDeposit() const {
    // Convert annual interest rate to monthly
    double monthlyInterestRate = m_annualInterestRate / 100.0 / 12.0;

    // Initialize balance with the initial investment
    double balance = m_initialInvestment;

    // Declare variables outside the loops
    double interestEarnedThisYear = 0.0;
    double monthlyInterest = 0.0;

    // Process each year
    for (int year = 1; year <= m_numberOfYears; year++) {
        // Reset yearly interest accumulator
        interestEarnedThisYear = 0.0;

        // Process each month within the year
        for (int month = 1; month <= 12; month++) {
            // Calculate interest for this month
            monthlyInterest = balance * monthlyInterestRate;

            // Add interest to balance
            balance += monthlyInterest;

            // Track total interest earned this year
            interestEarnedThisYear += monthlyInterest;

            // Add monthly deposit at the end of the month
            balance += m_monthlyDeposit;
        }

        // Display information for this year
        printDetails(year, balance, interestEarnedThisYear);
    }

    // Return the final balance
    return balance;
}

/**
 * Display investment reports (both with and without monthly deposits)
 */
void InvestmentCalculator::displayInvestmentReport() const {
    // Display results without monthly deposits
    std::cout << std::endl;
    std::cout << "Balance and Interest Without Additional Monthly Deposits" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "Year - Year End Balance - Year End Interest Rate" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    calculateBalanceWithoutMonthlyDeposit();

    // Display results with monthly deposits
    std::cout << std::endl << std::endl;
    std::cout << "Balance and Interest With Additional Monthly Deposits" << std::endl;
    std::cout << "========================================================" << std::endl;
    std::cout << "Year - Year End Balance - Year End Interest Rate" << std::endl;
    std::cout << "--------------------------------------------------------" << std::endl;
    balanceWithMonthlyDeposit();
}