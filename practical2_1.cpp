#include <iostream>


using namespace std;
class Rectangle
{
private:
    int length;
    int breadth;

public:
    Rectangle()
    {
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
    int area()
    {
        return length * breadth;
    }
    int premeter()
    {
        return 2 * (length + breadth);
    }
};
int main()
{
    Rectangle r1[20];
    int len, bre, n, num, count = 0;

    do
    {
        cout << "1. Calculate area and perimeter of rectangle" << endl
             << "2.Show the  data of rectangle" << endl
             << "3.Exit" << endl;
        cout << "Enter whatyou want to do: " << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            cout << "Enter the length and breadth of rectangle: ";
            cin >> len >> bre;
            r1[count] = Rectangle(len, bre);
            cout << "Area of rectangle is: " << r1[count].area() << endl;
            cout << "Perimeter of rectangle is: " << r1[count].premeter() << endl;
            count++;
            break;
        case 2:
            cout << "For which rectangle you want to show the data: ";
            cin >> num;
            if (num > count)
            {
                cout << "Invalid input" << endl;
            }
            else
            {
                cout << "Area of rectangle is: " << r1[num - 1].area() << endl;
                cout << "Perimeter of rectangle is: " << r1[num - 1].premeter() << endl;
            }
            break;
        case 3:
            cout << "Exiting..." << endl;

            break;
        default:
            cout << "Invalid input" << endl;
        }
    } while (n != 3);
    return 0;
}