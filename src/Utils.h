#ifndef PBT_UTILS_H
#define PBT_UTILS_H

#include <chrono>

#include <string>

std::string getCurrentTimestamp();

std::string getDocumentsPath();
int getUserChoice();
int getValidatedInputRange(int min, int max);
double getValidatedDoubleInput(const std::string& prompt);
std::string getPBTExportsToExcelPath();
std::string getPBTExportsToCSVPath();
std::chrono::year_month_day parseDate(const std::string& dateStr);
std::string formatDate(const std::chrono::year_month_day& date);
std::chrono::year_month_day getCurrentDate();
bool isValidDate(const std::string& date_str);
bool isDateInRange(const std::chrono::year_month_day& date,
                       const std::chrono::year_month_day& startDate,
                       const std::chrono::year_month_day& endDate);


#endif // PBT_UTILS_H
