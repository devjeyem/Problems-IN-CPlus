#include <iostream>
#include <cmath>

using namespace std;

int factorial(int digit);
int isCurious(int num);
int collatzCycle(int num);
void printCollatz(int num);

int main ()
{
    for(int i = pow(10,1); i<pow(10,6);i++)
    {
        int curiousNum = isCurious(i);
        if (curiousNum != 0)
        {
            cout << "Curious Number : " << curiousNum << " Collatz Cycle: " << collatzCycle(curiousNum) << endl;
            cout << "\n";
            printCollatz(curiousNum);
            cout << "\n";
        }
    }
}

int factorial(int digit)
{
    int result=1;
    for (int i=1; i<=digit;i++)
    {
        result = result * i;
    }
    return result;
}

int isCurious(int num)
{
    int originalNumber = num;
    int sum = 0;
    while (num > 0)
    {
        int digit = num % 10;
        sum = sum + factorial(digit);
        num = num / 10;
    }

    if (originalNumber==sum)
        return originalNumber;
    else
        return 0;

}

int collatzCycle(int num)
{
    int count = 0;
    while (num != 1)
    {
        if (num % 2 == 0)
            num = num / 2;
        else
            num = 3 * num + 1;
        count++;
    }
    return count;
}

void printCollatz(int num)
{
    cout << "Collatz Sequence for " << num << " : " ;
    while (num != 1)
    {
        cout << num << " ";
        if (num % 2 == 0)
            num = num / 2;
        else
            num = 3 * num + 1;
    }
    cout << "1\n";
}
