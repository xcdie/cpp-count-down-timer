#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void startTimer(int minutes) {
    int totalSeconds = minutes * 60;
    
    cout << "\nTimer started for " << minutes << " minutes. Stay focused!\n";
    
    while (totalSeconds > 0) {
        int mins = totalSeconds / 60;
        int secs = totalSeconds % 60;
        
      
        cout << "\rTime Remaining: " 
             << (mins < 10 ? "0" : "") << mins << ":" 
             << (secs < 10 ? "0" : "") << secs << "   " << flush;
             
        this_thread::sleep_for(chrono::seconds(1));
        totalSeconds--;
    }
    
    cout << "\n\nTime's up! Great work session! \a\n\n";
}

int main() {
    int choice;
    do {
        cout << "==== C++ Work Timer ====\n";
        cout << "1. Work Session (25 mins)\n";
        cout << "2. Short Break (5 mins)\n";
        cout << "3. Custom Timer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                startTimer(25);
                break;
            case 2:
                startTimer(5);
                break;
            case 3: {
                int customMins;
                cout << "Enter custom minutes: ";
                cin >> customMins;
                if (customMins > 0) {
                    startTimer(customMins);
                } else {
                    cout << "Invalid time entered.\n\n";
                }
                break;
            }
            case 4:
                cout << "Exiting work timer...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != 4);

    return 0;
}