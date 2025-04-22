#ifndef INVESTMENT_CALCULATOR_H
#define INVESTMENT_CALCULATOR_H

class InvestmentCalculator {
private:
    // Member variables for investment information
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterestRate;
    int m_numberOfYears;

public:
    // Constructor
    InvestmentCalculator(double initialInvestment, double monthlyDeposit,
        double annualInterestRate, int numberOfYears);

    // Getters and setters 
    double getInitialInvestment() const;
    void setInitialInvestment(double initialInvestment);

    double getMonthlyDeposit() const;
    void setMonthlyDeposit(double monthlyDeposit);

    double getAnnualInterestRate() const;
    void setAnnualInterestRate(double annualInterestRate);

    int getNumberOfYears() const;
    void setNumberOfYears(int numberOfYears);

    // Function to display yearly investment details
    void printDetails(int year, double yearEndBalance, double interestEarned) const;

    // Calculate balance without monthly deposits
    double calculateBalanceWithoutMonthlyDeposit() const;

    // Calculate balance with monthly deposits
    double balanceWithMonthlyDeposit() const;

    // Display results
    void displayInvestmentReport() const;
};

#endif // INVESTMENT_CALCULATOR_H
