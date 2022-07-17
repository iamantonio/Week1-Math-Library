//
//  main.cpp
//  mathLibrary
//
//  Created by Antonio Vargas on 7/15/22.
//
/*  1. Your program shall compute the average, variance, and standard deviation for a set of 6 scores as well as the range (highest number and lowest number input).
 
    2. The standard deviation is defined to be the square root of the average of the four variance values. (See the example below).
 
    3. The menu and console IO for the program shall be created in a class separate from the math library class and from the file containing main ()
 
    4. Validate user input to ensure that only numbers are input for the calculations.
 
    5. Demonstrate at least one function calling another function in your program.
 */

#include <iostream>
#include <cmath>
#include <limits>
#include <sstream>
#include <vector>

// Created a class for the menu
class Menu {
public:
    int userOption;
    void setOption();
};

// Created a class to compute the scores
class ScoreCalculator {
    // declaring private variables for the ScoreCalculator class
    float varianceAverage[6] { 0,0,0,0,0,0};
    float average;
    float variance;
    float deviation;
public:
    float scores[6] {
        0,
        0,
        0,
        0,
        0,
        0
    } ;
    
    // method to get score from user
    void set_score ();
    
    // method to compute the average score
    float average_score() {
        average = (scores[0] + scores[1] +scores[2] +scores[3] +scores[4] +scores[5]) / 6;
        return average;
    }
    
    // method to compute the deviance
    void compute_deviance() {
        for (int i = 0; i < 6; i++) {
            varianceAverage[i] = pow((scores[i]-average),2);
        }
        
    }
    
    // method to compute the variance
    float compute_variance() {
        variance = (varianceAverage[0] +varianceAverage[1] +varianceAverage[2] +varianceAverage[3] +varianceAverage[4] +varianceAverage[5])/6;
        return variance;
    }
    
    // method to compute the deviance
    float compute_deviation() {
        deviation = sqrt(variance);
        return deviation;
    }
    
    
};

// set up the set_score function and also included a validation input within the function.
void ScoreCalculator::set_score(){
    
    for (int i = 0; i < 6; i++) {
        while (true) {
            std::cout << "Enter score " << i + 1 << ": ";
            if (std::cin >> scores[i]) {
                if (scores[i] <= 0.0 && scores[i] >=100.0) {
                    break;
                }
                break;
            } else {
                std::cout << "Enter a valid integer!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
    }
}

// set up the setOption function for the menu class
void Menu::setOption(){
    std::cout << "Choose the following options:\n1: Compute the Average\n2: Compute the Variance\n3: Compute the standard deviation\n5: Quit Program\n";
    std::cin>> userOption;
}


// Main function
int main() {
    ScoreCalculator score;
    ScoreCalculator* ptr; // Pointer of class›
    ptr = &score;
    std::cout<<"Enter the scores to compute:\n";
    score.set_score();
    Menu menu;
    do {
        
        menu.setOption();
        switch (menu.userOption) {
            case 1:
                std::cout << "The average score is " << ptr->average_score() << std::endl;
                break;
            case 2:
                score.compute_deviance();
                std::cout << "The variance average is " << ptr->compute_variance() << std::endl;
                break;
            case 3:
                std::cout << "The standard deviation is " << ptr->compute_deviation() << std::endl;
                break;
            
            case 5:
                std::cout << "Goodbye!" << std::endl;
                break;
                
            default:
                std::cout << "Not a valid option\n";
                break;
        }
    } while (menu.userOption != 5);
    
    
    
    
    return 0;
}
