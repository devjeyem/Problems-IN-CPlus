#include <iostream>
#include <cmath>

using namespace std;

int isPrime(int num);
int reversedPalindrome(int num);

int main ()
{
    int start,end;
    cout << "Start: ";
    cin >> start;
    cout << "End: ";
    cin >> end;
    for (int i = start; i <= end ;i++)
    {
        if (isPrime(i) && isPrime(reversedPalindrome(i)))
        {
            if (reversedPalindrome(i)>start)
            {
                cout << i << ",";
            }
        }
    }

}

int isPrime(int num)
{
    if (num <= 1)
    {
        return 0;
    }
    for (int i=2;i*i<=num;i++)
    {
        if (num%i==0)
        {
            return 0;
        }
    }
    return num;
}

int reversedPalindrome(int num)
{
    int reversed= 0;
    while (num != 0)
    {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

