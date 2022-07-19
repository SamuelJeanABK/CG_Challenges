#include <iostream>
#include <vector>
#include <string>
  
std::vector<long long> NumberList;
std::string input;

bool ParseForNumbers();

int main()
{
START:
    std::cout << "PROMPT: Enter a single number to receive cubed result,\nor a space-separated list of three numbers for their sum and average." << std::endl << std::endl;
    std::cout << "Input quit or exit to terminate the application." << std::endl << std::endl;
INPUT:
    // Clear all values for safety when performing consectuive inputs
    std::cin.clear();
    NumberList.clear();
    input.clear();
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "quit" || input == "exit") { return 0; };
    if (!ParseForNumbers())
    {
        std::cout << "The entered value did not match the prompt." << std::endl << std::endl;
        goto START;
    }
    else
    {
        if (NumberList.size() == 1)
        {
            std::cout << "Cubed value: " << NumberList.at(0) * NumberList.at(0) * NumberList.at(0);
        }
        else
        {
            int sum = NumberList.at(0) + NumberList.at(1) + NumberList.at(2);
            std::cout << "Sum, average: " << sum << ", " << sum / 3;
        }
        std::cout << std::endl << std::endl;
    }
    goto INPUT;
}

bool ParseForNumbers()
{
    // Because we are processing only 1 or 3 numbers, an irregular number of spaces means we can get them to retry their input.
    short space_count = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ' ') { space_count++;};
    }
    if (space_count != 2 && space_count != 0) { return false; };

    std::string piece;

    for (int i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
        {
            piece.push_back(input[i]);
            if (i != input.length()-1) { continue; };
        }
        if (!piece.empty())
        {
            try 
            {
                NumberList.push_back(stoll(piece));
            }
            catch (const std::out_of_range& oor)
            {
                std::cout << "ERROR: Number too large!" << std::endl << std::endl;
                return false;
            };
            piece.clear();
        }
    }
    return true;
}