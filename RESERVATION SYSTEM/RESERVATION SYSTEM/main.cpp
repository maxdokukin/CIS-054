//
//  main.cpp
//  RESERVATION SYSTEM
//
//  Created by Max on 04/24/2021.
//

#include <iostream>
#include "string.h"
#include <iomanip>
#include <sstream>
#include <stdlib.h>

using namespace std;

//STRING FUNCTIONS//
string allign(string baseSting, int requiredWidth);


//SEAT CLASS DEFINITION//
class Seat{
    
private:
    int id;
    char row;
    bool reserved = false, selected = false;
    double price;
    
public:
    Seat(){
        
    };
    
    Seat(int n, char r){
        
        id = n;
        row = r;
    }
    
    string getAsString(){
        
        string output = to_string(id) + row;
        
        if(output.length() < 3)
            output = " " + output;
        
        return output;
    }
    
    bool isAvailable(){
        
        return !reserved;
    }
    
    bool isSelected(){
        
        return selected;
    }
    
    void makeSelection(){
        
        selected = true;
        reserved = true;
    }
    
    void clearSelection(){
        
        selected = false;
        reserved = false;
    }
    
    void makeReservation(){
        
        reserved = true;
        selected = false;
    }
    
    void clearReservation(){
        
        reserved = false;
    }
    
    void setPrice(double p){
        
        price = p;
    }
    
    double getPrice(){
        
        return price;
    }
    
    string getPriceString(){
        
        ostringstream doubleConverter;
        doubleConverter << std::fixed << setprecision(2) << price;
        
        string strPrice = "$" + doubleConverter.str();
        
        return allign(strPrice, 10);
    }
};


//CONSTANTS//
#define TAX_RATE 0.055
double const rowPrices[] = {1, 2, 5, 20, 50, 100, 200, 500, 1000, 2000};
int takenSeats = 0; //counter that required by the assignment. program can work without it

//OTHER FUNCTIONS//
bool menu(Seat *seats[], int rows, int cols, int order);

//INPUT FUNCTIONS//
char inputChar(string compText);
int inputInt(string compText);
void inputSeatSelection(int *r, int *c);

//PRINT FUNCTIONS//
void printSeats(Seat *seats[], int rows, int cols);
void printReceipt(string selectedSeats, int orderNum);
void printOrderHeader(int o);

//SEAT ARRAY FUNCTIONS//
void initializeSeats        (Seat *seats[], int rows, int cols);
int countAvailableSeats     (Seat *seats[], int rows, int cols);
void printAvailableSeatInfo (Seat *seats[], int rows, int cols);
int countSelectedSeats      (Seat *seats[], int rows, int cols);
void confirmSelections      (Seat *seats[], int rows, int cols);


int main(int argc, const char * argv[]) {
    
    cout << "Welcome to the most advanced booking system V1.1!\n" << endl;
    
    //INPUTS//
    int rows = inputInt("Enter number of rows : ");
    int cols = inputInt("Enter number seats in the row : ");
    
    Seat *seats[rows];// seat array
    
    initializeSeats(seats, rows, cols);

    int orderNum = 0; //order counter
    
    while(menu(seats, rows, cols, orderNum)) //menu cycle for multiple orders
        orderNum++;

    cout << "Nice, right?" << endl;
    
    for(int i = 0; i < rows; i++)
        delete [] seats[i];
    
    //delete [] seats; //I was not able to do it because "Cannot delete expression of type 'Seat *[rows]'"
    
    return 0;
}


//OTHER FUNCTIONS//
bool menu(Seat *seats[], int rows, int cols, int order){
        
    int selectedRow = 0, selectedCol = 0; //current seat selection
    
    string selectedSeats = ""; //seat selection log for printing receipt
    
    printOrderHeader(order);

    printSeats(seats, rows, cols);

    //no more seats
    
        //how I woud do it
        //if(!countAvailableSeats(seats, rows, cols))
        //    return false;
        
        //made like this to meet criteria
        if(takenSeats == rows * cols)
            return false;
    
    while(1){
        
        inputSeatSelection(&selectedRow, &selectedCol); //user seat selection input
        
        //if input is valid check//
        if(selectedRow < 0 || selectedRow > rows - 1 || selectedCol < 0 || selectedCol > cols - 1){
            
            cout << "Wrong seat selection! \nMake sure seat is not occupied and input format is correct (ex. 4A, 1B)" << endl;
            continue;
        }
        
        //seat was selected check//
        if(seats[selectedRow][selectedCol].isSelected()){
            
            cout << "Would you like to remove selection from " << seats[selectedRow][selectedCol].getAsString() << "? ";
            
            if(inputChar("(Y/N) ? ") == 'Y'){
                
                seats[selectedRow][selectedCol].clearSelection();
                
                takenSeats--;
                
                //remove seat from purchase log//
                string logRemoval = seats[selectedRow][selectedCol].getAsString() + ":" + to_string(seats[selectedRow][selectedCol].getPrice()) + ";";
                int removeInd = int(selectedSeats.find(logRemoval));
                selectedSeats = selectedSeats.replace(removeInd, logRemoval.length(), "");
            }
            
            printSeats(seats, rows, cols);
            
            if(inputChar("Would you like to select another seat (Y/N) ? ") == 'N') //cycle break
                break;
            
            continue;
        }
        
        //seat available check//
        if(!seats[selectedRow][selectedCol].isAvailable()){
            
            cout << "This seat is not available!" << endl;
            continue;
        }
        
        
        seats[selectedRow][selectedCol].makeSelection(); //mark seat as selected
        
        selectedSeats += seats[selectedRow][selectedCol].getAsString() + ":" + to_string(seats[selectedRow][selectedCol].getPrice()) + ";"; //add seat selection to the log
        
        takenSeats++;
        
        printSeats(seats, rows, cols);

        
        if(inputChar("Would you like to select another seat (Y/N) ? ") == 'N') //cycle break
            break;

    }
    
    confirmSelections(seats, rows, cols);
    
    printReceipt(selectedSeats, order);
    
    return true;
}
/**
 alligns string to the center
 */
string allign(string baseSting, int requiredWidth){
    
    string alligned = baseSting;
    
    for(int b = 0; alligned.length() != 10; b++){ //allign it to the center
        
        if(b % 2 == 0)
            alligned = " " + alligned;
        
        else
            alligned += " ";
    }
    
    return alligned;
}

//INPUT FUNCTIONS//
/**
 inuputs char from user
 */
char inputChar(string compText){
    
    char a;
    cout << compText;
    cin >> a;
    fflush(stdin);

    return toupper(a);
}

/**
 inputs int from user
 */
int inputInt(string compText){
    
    cout << compText;
    int input;
    cin >> input;
    fflush(stdin);

    return input;
}
/**
 inputs seat from user and converts to array dimensions
 */
void inputSeatSelection(int *r, int *c){
    
    char letter;
    
    cout << "Select seat : ";
    
    cin >> *r >> letter;
    fflush(stdin);

    *c = toupper(letter) - 65;
    
    (*r)--;
}


//PRINT FUNCTIONS//

////PRINT SEATS////
/**
 prints one row of seats
 */
void printRow(Seat *row, int cols, int rowNum){
    
    string outputLines[6]; //output buffer
        
    string rowN = allign(to_string(rowNum), 10); //convert current row number to row letter
    
    //come magic going on here
    outputLines[0] = "+----------+";

    outputLines[1] += "|          ";
    outputLines[2] += "|          ";
    outputLines[3] += "|" + rowN;
    outputLines[4] += "|          ";
    outputLines[5] += "|          ";
    
    //add each seat to the output lines
    for(int i = 0; i < cols; i++){
        
        outputLines[0] += "----------+";
        
        if(row[i].isSelected()){
            
            outputLines[1] += "|          ";
            outputLines[2] += "| ******** ";
            outputLines[3] += "|  *" + row[i].getAsString() + " *  ";
            outputLines[4] += "| ******** ";
            outputLines[5] += "| SELECTED ";
        }
        
        else if(row[i].isAvailable()){
            
            outputLines[1] += "|        _ ";
            outputLines[2] += "|       // ";
            outputLines[3] += "|   " + row[i].getAsString() + "//  ";
            outputLines[4] += "|  ===*/   ";
            outputLines[5] += "|" + row[i].getPriceString();
        }
        
        else{
            
            outputLines[1] += "|\\\\      //";
            outputLines[2] += "|  \\\\  //  ";
            outputLines[3] += "| RESERVED ";
            outputLines[4] += "|  //  \\\\  ";
            outputLines[5] += "|//      \\\\";
        }
    }
    
    outputLines[1] += "|";
    outputLines[2] += "|";
    outputLines[3] += "|";
    outputLines[4] += "|";
    outputLines[5] += "|";

    //print generated outputs
    for(int i = 0; i < 6; i++)
        cout << outputLines[i] << endl;
}

/**
 prints header with numbers, same print idea as printRow
 */
void printSeatsHeader(int cols){
    
    string outputLines[6];
    
    outputLines[0] += "+----------+";
    outputLines[1] += "|\\\\\\\\\\\\\\\\\\\\";
    outputLines[2] += "|\\\\\\\\\\\\\\\\\\\\";
    outputLines[3] += "|\\\\\\\\\\\\\\\\\\\\";
    outputLines[4] += "|\\\\\\\\\\\\\\\\\\\\";
    outputLines[5] += "|\\\\\\\\\\\\\\\\\\\\";
    for(int i = 0; i < cols; i++){
        
        string rowN (1, char(i + 65)); //convert current row number to row letter
        
        rowN = allign(rowN, 10);
        
        outputLines[0] += "----------+";
        outputLines[1] += "|          ";
        outputLines[2] += "|          ";
        outputLines[3] += "|" + rowN;
        outputLines[4] += "|          ";
        outputLines[5] += "|          ";
    }
    
    outputLines[1] += "|";
    outputLines[2] += "|";
    outputLines[3] += "|";
    outputLines[4] += "|";
    outputLines[5] += "|";
    
    for(int i = 0; i < 6; i++)
        cout << outputLines[i] << endl;
    
}

/**
 prints whole grid of seats
 */
void printSeats(Seat *seats[], int rows, int cols){
    
    printSeatsHeader(cols);
    
    //print each row
    for(int i = 0; i < rows; i++)
        printRow(seats[i], cols, i + 1);
    
    //final split line
    cout << "+";
    for(int i = 0; i < cols + 1; i++)
        cout << "----------+";
    cout << endl;
    
    //some info
    printAvailableSeatInfo(seats, rows, cols);
}

/**
 prints how many seats available and selected
 */
void printAvailableSeatInfo(Seat *seats[], int rows, int cols){
    
    int availableSeats = countAvailableSeats(seats, rows, cols);
    
    //how many columns already was printed counter to match table width when info printed
    int colsPrinted = 4;
    
    if(availableSeats){
        
        cout << "|SEATS AVAILABLE : " << left << setw(3) << availableSeats << "|";
        cout << " SEATS SELECTED : " << left << setw(3) << countSelectedSeats(seats, rows, cols) << "|";
    }
    
    else{
        
        cout << "|                 NO AVAILABLE SEATS!                  |";
        colsPrinted ++;
    }
    
    //match table widht
    for(int i = colsPrinted; i < cols + 1; i++)
        cout << "          |";

    cout << endl;
    
    //final split line
    cout << "+";
    for(int i = 0; i < cols + 1; i++)
        cout << "----------+";
    cout << endl;
}


////PRINT ORDER HEADER////
/**
 prints order id in the fancy way
 */
void printOrderHeader(int o){
    
    cout << "------------------------------------------" << endl <<
    "|" << right << setw(25) << "Order №" << left << setw(3) << o << right << setw(15) << "|" << endl <<
    "------------------------------------------" << endl;
}

////PRINT RECIPT////
void printTimeStamp(){
    
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    //time formatting
    string date = (1 + ltm->tm_mon < 10 ? "0" : "") + to_string(1 + ltm->tm_mon) + "/" + (ltm->tm_mday < 10 ? "0" : "") + to_string(ltm->tm_mday) + "/" + to_string(1900 + ltm->tm_year);
    string time = (ltm->tm_hour < 10 ? "0" : "") + to_string(ltm->tm_hour) + ":" + (ltm->tm_min < 10 ? "0" : "") + to_string(ltm->tm_min) + ":" + (ltm->tm_sec < 10 ? "0" : "") + to_string(ltm->tm_sec);

    cout << "|" << left << setw(10) << date << right << setw(30) << time << "|" << endl;
}

/**
 prints reciept
 */
void printReceipt(string selectedSeats, int orderNum){
    
    cout << endl << endl << endl;
    
    printOrderHeader(orderNum);
    printTimeStamp();
    cout << "|----------------------------------------|" << endl;
    
    double totalPrice = 0; //total check sum
    
    //convert log string to printable info
    while(!selectedSeats.empty()){
        
        int index = int(selectedSeats.find(":"));
        
        //get seat number
        string seat = selectedSeats.substr(0, index);
        selectedSeats = selectedSeats.substr(index + 1, selectedSeats.length() - index);
        
        index = int(selectedSeats.find(";"));
        
        //get seat price
        double price = atof(selectedSeats.substr(0, index - 1).c_str());
        selectedSeats = selectedSeats.substr(index + 1, selectedSeats.length() - index);
        
        totalPrice += price;
        
        cout << "|Seat      " <<
            right << setw(10) << seat <<
            setw(11) << "$" <<
            left << setw(8) << setprecision(2) << fixed << price << " |" << endl;
    }
    
    cout << "|----------------------------------------|" << endl;

    cout << "| Subtotal" << right << setw(22) << "$" << left << setw(8) << setprecision(2) << fixed << totalPrice << " |" << endl;
    cout << "| Tax" << right << setw(27) << "$" << left << setw(8) << setprecision(2) << fixed << totalPrice * TAX_RATE << " |" << endl;

    cout << "|----------------------------------------|" << endl;

    cout << "|Total" << right << setw(26) << "$" << left << setw(8) << setprecision(2) << fixed << totalPrice * (TAX_RATE + 1) << " |" << endl;
    cout << "------------------------------------------" << endl;

    cout << endl << endl << endl;
}



//SEAT ARRAY FUNCTIONS//
/**
 makes all selected seats reserved
 */
void confirmSelections(Seat *seats[], int rows, int cols){
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(seats[i][j].isSelected())
                seats[i][j].makeReservation();
}

void initializeSeats(Seat *seats[], int rows, int cols){
    
    for(int i = 0; i < rows; i++)
        seats[i] = new Seat[cols];
    
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++){
        
            seats[i][j] = Seat(i + 1, (char) j + 65);
            
            seats[i][j].setPrice(rowPrices[i]);
        }
}

int countAvailableSeats(Seat *seats[], int rows, int cols){
    
    int availableSeats = 0;
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(seats[i][j].isAvailable())
                availableSeats++;
    
    return availableSeats;
}

int countSelectedSeats(Seat *seats[], int rows, int cols){
    
    int selectedSeats = 0;
    
    for(int i = 0; i < rows; i++)
        for(int j = 0; j < cols; j++)
            if(seats[i][j].isSelected())
                selectedSeats++;
    
    return selectedSeats;
}
