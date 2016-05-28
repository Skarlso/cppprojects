#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    cout << "Enter a number: "; // ask user for a number
    int x = 0;
    cin >> x; // read number from console and store it in x
    cout << "You entered " << x << std::endl;
    return 0;
}
