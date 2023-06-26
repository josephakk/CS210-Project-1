#include <iostream>
#include <iomanip>

using namespace std;

void DisplayMenu() {
    cout << "1 - Increase Hour" << endl;
    cout << "2 - Increase Minute" << endl;
    cout << "3 - Increase Second" << endl;
    cout << "4 - Exit Program" << endl;
}

int InputValidation(const string& prompt, int minVal, int maxVal) {
    int input;
    cout << prompt << endl;
    while (!(cin >> input) || input < minVal || input > maxVal) {
        cout << "Invalid, enter a number between:" << minVal << " - " << maxVal << "." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return input;
}

void AddHour(int& hours) {
    hours = (hours + 1) % 24;
}

void AddMinute(int& minutes, int& hours) {
    minutes = (minutes + 1) % 60;
    if (minutes == 0)
        AddHour(hours);
}

void AddSecond(int& seconds, int& minutes, int& hours) {
    seconds = (seconds + 1) % 60;
    if (seconds == 0)
        AddMinute(minutes, hours);
}

void PrintSingleStar() {
    cout << '*';
}

void PrintMultipleStars() {
    cout << "    ********************          ********************";
}

void DisplayClocks(int hours, int minutes, int seconds) {
    cout << "\n       12-Hour Clock            "<<"      24-Hour clock      " << endl;
    cout << "        " << setw(2) << setfill('0') << (hours % 12 == 0 ? 12 : hours % 12) << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << (hours < 12 ? " AM" : " PM") << "       "
        << "      "
        << "         " << setw(2) << setfill('0') << hours << ":"
        << setw(2) << setfill('0') << minutes << ":"
        << setw(2) << setfill('0') << seconds << "         " << endl;
}

int main() {
    int hours = InputValidation("Enter Hour(s):", 1, 24);
    int minutes = InputValidation("Enter Minute(s):", 0, 59);
    int seconds = InputValidation("Enter Second(s):", 0, 59);
    int choice;
   

    do {
        PrintMultipleStars();
        DisplayClocks(hours, minutes, seconds);
        PrintMultipleStars();
        cout << endl;

        DisplayMenu();
        choice = InputValidation("\nPlease enter your choice (1-4):", 1, 4);

        if (choice == 1) {
            AddHour(hours);
        }
        else if (choice == 2) {
            AddMinute(minutes, hours);
        }
        else if (choice == 3) {
            AddSecond(seconds, minutes, hours);
        }
        else if (choice == 4) {
            cout << "Program Finished" << endl;
        }
        else {
            cout << "Invalid input. Try again." << endl;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}