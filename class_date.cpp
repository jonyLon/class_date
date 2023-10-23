#include "Date.h"

int main()
{
    mDate first(10, 2, 2000);
    mDate second(11, 3, 2010);
    first.print();
    second.print();
    int sub = second - first;
    cout << "Days between dates: " << sub << endl;
    cout << boolalpha << (second == first) << endl;
    cout << boolalpha << (second != first) << endl;
    cout << boolalpha << (second > first) << endl;
    cout << boolalpha << (second < first) << endl;
    first += 200;
    first.print();
}

