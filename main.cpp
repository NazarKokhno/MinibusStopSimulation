#include <iostream>
#include "Passenger.h"
#include "Queue.h"

using namespace std;

int main()
{
    Queue<int> q1(3);

    q1.push(10);
    q1.push(20);

    Queue<int> q2 = q1;

    Queue<int> q3(5);
    q3 = q1;            

    cout << "Q1: " << q1.front() << " " << q1.back() << endl;
    cout << "Q2: " << q2.front() << " " << q2.back() << endl;
    cout << "Q3: " << q3.front() << " " << q3.back() << endl;

    q2.pop();

    cout << "Q1 size: " << q1.size() << endl;
    cout << "Q2 size: " << q2.size() << endl;
}