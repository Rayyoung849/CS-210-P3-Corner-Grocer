# Airgead Banking – Investment Calculator
_CS-210 • C++ • Date submitted: 04/25/25_

---

## Project Summary
Airgead Banking asked for a console app to help high-school students see **how compound interest and monthly deposits grow an investment over time**.  
The program lets a user enter

* initial investment  
* optional monthly deposit  
* annual interest rate  
* number of years  

and then prints two side-by-side reports—one **without** monthly deposits and one **with**—so students can compare the impact.

---

## What I Did Well (earned 91 %)
* **Clear OOP design:** all calculations live in one `InvestmentCalculator` class.  
* **Readable output:** fixed-width columns and 2-decimal currency.  
* **Inline comments throughout** so the logic is easy to follow.  
* **Meets every functional requirement** in the spec.

---

## Possible Enhancements (includes instructor feedback)
| Idea &nbsp;&nbsp;*(source)* | Why it helps |
|-----------------------------|--------------|
| Add robust **input-validation loops** *(instructor)* | prevents crashes and bad data |
| Replace magic numbers (e.g., **12 months**) with **named constants** | easier maintenance, fewer typos |
| Separate **report formatting** into its own class | follows single-responsibility principle |
| Let user choose **output to a CSV file** | easier sharing / analysis |
| Improve **rounding logic** for currency *(instructor)* | avoids off-by-pennies errors |
| Mark getters as **`const`** and pass large objects by **`const reference`** *(instructor)* | safer, more efficient |

---

## Toughest Challenge & How I Beat It
Accurately compounding monthly interest **while inserting deposits at the correct point** in each cycle.  
I sketched the cash flow on paper, verified small samples in a spreadsheet, and stepped through the loop with the VS debugger until the numbers matched.

_Resources added to my toolbox_: cppreference.com (`setprecision`), VS watch window, class Discord for peer advice.

---

## Transferable Skills
* **Object-oriented class design**  
* **Loop + formula integration** (finance math shows up in many apps)  
* **Console I/O formatting** for professional CLI tools  
* **GitHub workflow** (branching, commits, pull requests)

---

## Maintainability | Readability | Adaptability
* Descriptive names (`m_initialInvestment`, not `x`)  
* Single-purpose functions (`balanceWithMonthlyDeposit()` instead of a monolithic `main`)  
* Heavy commenting **and this README** for future devs  
* No hard-coded limits—change one variable and rebuild

---

## How to Run
1. Open `AirgeadBanking.sln` in Visual Studio 2022 +.  
2. Press the green **Local Windows Debugger** button.  
3. Enter the prompted values and view the reports.

Enjoy!
