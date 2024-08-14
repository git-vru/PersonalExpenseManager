#ifndef PBT_UTILS_H
#define PBT_UTILS_H

#include <string>

std::string getCurrentTimestamp();

std::string getDocumentsPath();
int getUserChoice();
int getValidatedInputRange(int min, int max);
double getValidatedDoubleInput(const std::string& prompt);
std::string getPBTExportsToExcelPath();
std::string getPBTExportsToCSVPath();


#endif // PBT_UTILS_H
