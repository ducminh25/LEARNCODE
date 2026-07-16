#include <iostream>

int main() {
    int V, A1, B1, A2, B2;
    cin >> V >> A1 >> B1 >> A2 >> B2;

    int daysRabbit = (V - A1 + A1 - B1 - 1) / (A1 - B1) + 1;
    int daysTurtle = (V - A2 + A2 - B2 - 1) / (A2 - B2) + 1;

    if (daysRabbit < daysTurtle) {
        cout << "THO";
    } else if (daysRabbit > daysTurtle) {
        cout << "RUA";
    } else {
        cout << "HOA";
    }
    return 0;
}