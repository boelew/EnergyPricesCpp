#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include <string>
#include <ctime>

/**
 * @brief Get the time in history
 *
 * @param days Number of days to go back in history
 * @return std::tm* Pointer to the tm structure representing the time
 */
std::tm *getTimeInHistory(int days);

/**
 * @brief Get the current local time
 *
 * @return std::tm* Pointer to the tm structure representing the current local time
 */
std::tm *getLocalTime();

/**
 * @brief Set the time to midnight
 *
 * @param time Pointer to the tm structure to be modified
 * @return std::tm* Pointer to the modified tm structure
 */
std::tm *setToMidnight(std::tm *time);

/**
 * @brief Set the time to the end of the day
 *
 * @param time Pointer to the tm structure to be modified
 * @return std::tm* Pointer to the modified tm structure
 */
std::tm *setToEndOfDay(std::tm *time);

/**
 * @brief Print the current time
 *
 * @param time Pointer to the tm structure representing the time to be printed
 */
void printTime(std::tm *time);

/**
 * @brief Format the date
 *
 * @param tm Reference to the tm structure representing the date to be formatted
 * @return std::string Formatted date string
 */
std::string formatDate(const std::tm &tm);

#endif // TIME_UTILS_H