// Let's check if it's a Leap Year

#include <chrono>
#include <iostream>
#include <map>
#include <string>

std::string input;
std::map<int, std::string> month_names
{
    {1, "January"},
    {2, "February"},
    {3, "March"},
    {4, "April"},
    {5, "May"},
    {6, "June"},
    {7, "July"},
    {8, "August"},
    {9, "September"},
    {10, "October"},
    {11, "November"},
    {12, "December"}
};

std::string CheckLeapYear(int year);
void HandleInput(std::string input);

int main()
{
    std::stringstream ss;
    ss << std::chrono::system_clock::now();
    std::string time = ss.str();

    std::string year, month, day;
    year = time.substr(0, 4);
    month = time.substr(5, 2);
    day = time.substr(8, 2);

    std::cout << "The current system date is " << month_names[stoi(month)] << " "+day+", " << year << std::endl;
    std::cout << CheckLeapYear(stoi(year)) << std::endl << std::endl;
    std::cout << "You may input other years to check if it is a leap year or not, or input quit to exit the program." << std::endl << std::endl;

    while (input != "quit")
    {
        std::cin.clear();
        input.clear();
        std::cout << "> ";
        std::getline(std::cin, input);

        HandleInput(input);
    }

    return 0;
}

std::string CheckLeapYear(int year)
{
    bool bPassCheck = false;

    if (year%4 == 0)
    {
        bPassCheck = true;
        if (year%100 == 0)
        {
            bPassCheck = false;
            if (year%400 == 0)
            {
                bPassCheck = true;
            }
        }
    }

    if (bPassCheck)
    {
        return "The year "+std::to_string(year)+" is a leap year.";
    }
    else
    {
        return "The year "+std::to_string(year)+" is NOT a leap year.";
    }
}

void HandleInput(std::string input)
{
    if (input == "quit") {return;}

    else
    {
        try
        {
            std::cout << CheckLeapYear(stoi(input)) << std::endl << std::endl;
        }
        catch (const std::invalid_argument& ia)
        {
            std::cout << "Invalid argument: the provided input could not be interpreted as a year." << std::endl << std::endl;
        }
    }
    return;
}