//
//  main.cpp
//  Extra credit
//
//  Created by Max on 25/04/2021.
//

#include <iostream>

using namespace std;

#include <stdio.h>

#include <stdlib.h>

#include <time.h>


void moveTortoise(int* turtlePosition);

void moveHare(int* rabbitPosition);


int harePosition = 0;

int tortPosition = 0;

int* turtlePosition = &tortPosition;

int* rabbitPosition = &harePosition;

int main(void)

{

    

    int race = 1;

    size_t i;

    srand(time(NULL));


    cout << "ON YOUR MARK, GET SET\nBANG !!!!!\nAND THEY'RE OFF!!!!!\n";

    cout << "H T";



    while (race == 1) {

        moveTortoise(turtlePosition);

        moveHare(rabbitPosition);



        if (*rabbitPosition < 0) {

            *rabbitPosition = 0;

        }

        else if (*turtlePosition < 2) {

            *turtlePosition = 2;

        }

        else if (*rabbitPosition == *turtlePosition) {

            int k;

            for (k = 0; k < *rabbitPosition - 1; k++) {

                cout << " ";

            }

            cout << "Ouch!\n";

        }



    

        for (i = 0; i < 70; i++) {



            if (i == *rabbitPosition) {

                cout << "H";

            }

            else if (i == *turtlePosition) {

                cout << "T";

            }

            else {

                cout << " ";

            }

        }

        cout << "\n";

        
        if (*rabbitPosition >= 70) {

            cout << "\nHare wins ";

            race = 0;

        }

        if (*turtlePosition >= 70) {

            cout << "\nTORTOISE WINS!!! YAY!!!";

            race = 0;

        }

        if (*rabbitPosition >= 70 && *turtlePosition >= 70) {

            cout << "\n tie.";

            race = 0;

        }

    }

}

void moveTortoise(int* turtlePosition) {



    int val = rand() % 10 + 1;

    switch (val) {

    case 1:

    case 2:

    case 3:

    case 4:

    case 5:

        *turtlePosition += 3;

        break;

    case 6:

    case 7:

        *turtlePosition -= 6;

        break;

    case 8:

    case 9:

    case 10:

        *turtlePosition += 1;

        break;

    }

}

void moveHare(int* rabbitPosition) {



    int val = rand() % 10 + 1;

    switch (val) {

    case 1:

    case 2:

        *rabbitPosition += 0;

        break;

    case 3:

    case 4:

        *rabbitPosition += 9;

        break;

    case 5:

        *rabbitPosition -= 12;

        break;

    case 6:

    case 7:

    case 8:

        *rabbitPosition += 1;

        break;

    case 9:

    case 10:

        *rabbitPosition -= 2;

        break;

    }

}
