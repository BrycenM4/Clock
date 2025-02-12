// CS-210 Module Three Assignment.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Brycen McEuen
// CS-210 Module Three

#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <string>

void displayClock(int hours, int twelveHour, int minutes, int seconds, std::string period) {
    // Display 24 hour clock
    std::cout << "24-Hour Clock: " << (hours < 10 ? "0" : "") << hours << " : "
        << (minutes < 10 ? "0" : "") << minutes << " : "
        << (seconds < 10 ? "0" : "") << seconds << "\n";

    // Display 12-hour clock
    std::cout << "12-Hour Clock: " << (twelveHour < 10 ? "0" : "") << twelveHour << " : "
        << (minutes < 10 ? "0" : "") << minutes << " : "
        << (seconds < 10 ? "0" : "") << seconds << " " << period << "\n";          
}

void addOneHour(int& hours, int& twelveHour, std::string& period) {
    hours++; // adds one hour
    if (hours >= 24) {
        hours = 0; // if the hours are 24 or more, then hours are reset to zero
    }
    period = (hours < 12) ? "AM" : "PM"; // defines whether its AM or PM based on how the user sets the clock
    twelveHour = (hours % 12 == 0) ? 12 : hours % 12; // converts 24 hour clock to 12 hour clock

    std::cout << "\n" << "One hour added.\n";
}

void addOneMinute(int& hours, int& twelveHour, int& minutes, std::string& period) {
    minutes++; // adds one minute
    if (minutes >= 60) {
        minutes = 0;
        hours++; // if minutes reach 60 or more, then it adds an hour
        if (hours >= 24) {
            hours = 0; // if the hours reach 24, then it resets back to zero
        }
        period = (hours < 12) ? "AM" : "PM";
        twelveHour = (hours % 12 == 0) ? 12 : hours % 12; // converts 24 hour clock to 12 hour clock
    }
    std::cout << "\n" << "One minute added.\n";
}

void addOneSecond(int& hours, int& twelveHour, int& minutes, int& seconds, std::string& period) {
    seconds++; // adds one second
    if (seconds >= 60) {
        seconds = 0; // if seconds reach 60 or more, then they reset back to zero
        addOneMinute(hours, twelveHour, minutes, period); // if seconds reach 60 or more, it also adds another minute
    }
    std::cout << "\n" << "One second added.\n";
}
void setClock(int& hours,int& twelveHour, int& minutes, int& seconds, std::string& period) {
    std::cout << "Set Hours (0-23): ";
    std::cin >> hours;
    while (hours < 0 || hours >= 24) { // verifies that input is within valid range
        std::cout << "Invalid input for hours. Please try again.\n";
        std::cout << "Set Hours (0-23): ";
        std::cin >> hours;
    }

    std::cout << "Set Minutes (0-59): ";
    std::cin >> minutes;
    while (minutes < 0 || minutes >= 60) { // verifies that input is within valid range
        std::cout << "Invalid input for minutes. Please try again. \n";
        std::cout << "Set Minutes (0-59): ";
        std::cin >> minutes;
    }

    std::cout << "Set Seconds (0-59): ";
    std::cin >> seconds;
    while (seconds < 0 || seconds >= 60) { // verifies that input is within valid range
        std::cout << "Invalid input for seconds. Please try again. \n";
        std::cout << "Set Seconds (0-59): ";
        std::cin >> seconds;
    }

    period = (hours < 12) ? "AM" : "PM"; // sets AM or PM based on what the user initially inputs

    twelveHour = (hours % 12 == 0) ? 12 : hours % 12; // converts 24 hour clock to 12 hour clock

    std::cout << "\n" << "Time updated successfully!\n" << "\n";
}



int main() {
    int twelveHour = 0, hours = 0, minutes = 0, seconds = 0;
    std::string period; // includes all variables

    std::cout << "Welcome to the Chada Tech Digital Clock!\n";

    std::cout << "\nPlease set the current time in a 24-hour format.\n";
    
    setClock(hours, twelveHour, minutes, seconds, period); // allows user to set clock

    char option;


    while (true) {

        displayClock(hours, twelveHour, minutes, seconds, period);
        
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Add One Hour\n";
        std::cout << "2. Add One Minute\n";
        std::cout << "3. Add One Second\n";
        std::cout << "4. Exit Program\n" << "\n";
        std::cout << "Choose an option: ";
        std::cin >> option;

        if (option == '1') {
            addOneHour(hours, twelveHour, period); // adds one hour
        }
        else if (option == '2') {
            addOneMinute(hours, twelveHour, minutes, period); // adds one minute
        }
        else if (option == '3') {
            addOneSecond(hours, twelveHour, minutes, seconds, period); // adds one second
        }
        else if (option == '4') {
            std::cout << "Exiting...\n"; // exits the program
            break;
        }
        else {
            std::cout << "\nInvalid option. Please try again.\n"; // any other command is invalid 
        }
    }

    return 0;
}
    

