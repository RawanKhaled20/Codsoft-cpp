#include <iostream>
#include <vector>
#include <limits> // Include the limits header for cin.ignore()

using namespace std;

// Constants
const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

//movie list names
void Movieshow()
{
    cout<<"1. Spiderman No way Home   rating:4.7    starts at: 09:00 am  "<<endl;
    cout<<"2. Dark Night              rating:4.8    starts at: 12:00 pm  "<<endl;
    cout<<"3. Superman                rating:4.5    starts at: 02:00 pm  "<<endl;
    cout<<"4. Avengers                rating:4.8    starts at: 06:00 pm  "<<endl;
    cout<<"5. Miraculous Awakieng     rating:4.9    starts at: 09:00 pm  "<<endl;
}

// Function to display the seating chart
void displaySeats(vector<vector<char>>& seats) {
    cout << "  1 2 3 4 5 6 7 8 9 10" << endl;
    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to make a booking
void makeBooking(vector<vector<char>>& seats, int row, int col, double& totalCost) {
    if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS && seats[row][col] == 'X') {
        cout << "Seat " << char('A' + row) << col + 1 << " is already booked." << endl;
    } else if (row >= 0 && row < NUM_ROWS && col >= 0 && col < NUM_COLS) {
        seats[row][col] = 'X';
        totalCost += TICKET_PRICE;
        cout << "Booking confirmed for Seat " << char('A' + row) << col + 1 << ". Total cost: $" << totalCost << endl;
    } else {
        cout << "Invalid seat selection." << endl;
    }
}

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, '.')); // Initialize all seats as available
    double totalCost = 0.0;
    int choice;

    cout << "Welcome to the Movie Ticket Booking System!" << endl;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. View Movie Listings\n";
        cout << "2. View Seat Availability\n";
        cout << "3. Make Booking\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        // Check if the input is a valid integer not a char
        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number." << endl;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
            continue; // Repeat the loop
        }

        switch (choice) {
            case 1:
                cout << "Movie Listings: Movie Name, ratings Show, time." << endl;
                Movieshow();
                break;
            case 2:
                cout << "Seat Availability:" << endl;
                displaySeats(seats);
                break;
            case 3:
                char row;
                int col;
                cout << "Enter row (A-E) and seat number (1-10): ";
                cin >> row >> col;
                row = toupper(row);
                makeBooking(seats, row - 'A', col - 1, totalCost);
                break;
            case 4:
                cout << "Thank you for using the Movie Ticket Booking System!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
