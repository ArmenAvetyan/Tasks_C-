#include "date.hpp"
#include <print>

Date::Date() = default;

Date::~Date() = default;

Date::Date(int year, size_t month, size_t day)
    : m_year(year), m_month(month), m_day(day)
{
}

size_t Date::daysBetween(const Date& other) const
{
    size_t days = (m_year - other.m_year) * 365
        + (m_month - other.m_month) * 30
        + (m_day - other.m_day);

    return days ? days : 0;
}

Date Date::addDays(size_t days) const
{
    Date newDate = *this;

    newDate.m_day += days;

    while(newDate.m_day > 30) {
        newDate.m_day -= 30;
        newDate.m_month++;

        if(newDate.m_month > 12){
            newDate.m_month -= 12;
            newDate.m_year++;
        }
    }
    return newDate;
}

void Date::displayDate() const
{
    std::println("{}.{}.{}", m_day, m_month, m_year);
}

bool Date::operator==(const Date& other) const
{
    return m_year == other.m_year &&
           m_month == other.m_month &&
           m_day == other.m_day;
}

bool Date::operator!=(const Date& other) const
{
    return !(*this == other);
}

bool Date::operator<(const Date& other) const
{
    if(m_year != other.m_year) return m_year < other.m_year;
    if(m_month != other.m_month) return m_month < other.m_month;
    return m_day < other.m_day;
}

bool Date::operator>(const Date& other) const
{
    return other < *this;
}

bool Date::operator<=(const Date& other) const
{
    return !(other < *this);
}

bool Date::operator>=(const Date& other) const
{
    return !(*this < other);
}
