#pragma once
#include <cstddef>

class Date
{
    public:
        Date();
        ~Date();
    public:
        Date(int year, size_t month, size_t day);
        size_t daysBetween(const Date& other) const;
        Date addDays(size_t days) const;
        void displayDate() const;
    public:
        bool operator==(const Date& other) const;
        bool operator!=(const Date& other) const;
        bool operator<(const Date& other) const;
        bool operator>(const Date& other) const;
        bool operator<=(const Date& other) const;
        bool operator>=(const Date& other) const;

    private:
        int m_year {};
        size_t m_month {};
        size_t m_day {};
};
