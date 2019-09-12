// arrayBombTest.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
//#include <stdio.h>
#include <iomanip>
#include <array>
using namespace std;

int main() {
   for (int k = 0; k < 3; k++) {
      const int width = 8;
      const int height = 8;
      int x, y;
      int intArray[width][width];

      //make random array
      for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
            intArray[i][j] = rand() % 10;
         }
      }

      //print
      for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
            cout << intArray[i][j] << " ";
         }
         cout << endl;
      }

      //coordinate
      cin >> x >> y;

      //variables to mark where bombing starts and ends
      int startX, startY;
      int endX, endY;

      //logic for starting x position
      //should handle if the blast reaches past the leftmost column of the array, or if x - 2 < 0
      if (x - 2 >= 0) {
         startX = x - 2;
      }
      else {
         startX = 0;
      }

      //logic for ending x position
      //should handle if the blast reaches past the rightmost column, or if x + 2 > length
      if (x + 2 < width) {
         endX = x + 2;
      }
      else {
         endX = width - 1; //size - 1
      }

      for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
            //logic for starting y position
            if (y - 2 >= 0) {
               startY = y - 2;
            }
            else {
               startY = 0;
            }

            //logic for ending y position
            if (y + 2 < height) {
               endY = y + 2;
            }
            else {
               endY = height - 1; //size - 1
            }
         }
      }

      //blow em up
      for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
            if (i >= startX && i <= endX && j >= startY && j <= endY) {
               intArray[i][j] = 0;
            }
         }
      }

      //print after blowing up
      for (int i = 0; i < width; i++) {
         for (int j = 0; j < height; j++) {
            cout << intArray[i][j] << " ";
         }
         cout << endl;
      }
   }
}

