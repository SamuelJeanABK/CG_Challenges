#include <iostream>
#include <vector>
#include <string>

std::string input;
int number = 0;
bool bQuit = false;
std::vector<int> factors;

void HandleInput(std::string input);
void FactorNumber(int num);

int main()
{
    std::cout << "Please input a positive integer..." << std::endl << std::endl;

    while (!bQuit)
    {
        HandleInput(input);
        factors.clear();
    }
}

void HandleInput(std::string input)
{
    input.clear();
    std::cin.clear();

    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "quit") {bQuit = true; return;};

    try
    {
        number = stoi(input);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return;
    }

    FactorNumber(number);
    std::cout << "Factors of " << number << ": " << std::endl;
    for (int i = 0; i < factors.size(); i++)
    {
        std::cout << factors[i] << std::endl;
    }
    std::cout << std::endl;
}

void FactorNumber(int num)
{
    for (int i = num; i > 0; i--)
    {
        if (num%i == 0)
        {
            factors.push_back(i);
        }
    }
}