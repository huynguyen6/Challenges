// TalkingClock.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

string hourStrings[] = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve" };
string teens[] = {  "ten", "eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eightteen","nineteen", };
string tensPlace[] = { "","", "twenty","thirty", "fourty", "fifty" };
string *onesPlace = hourStrings;

int main()
{
  string inTimeStr = "";
  string outTimeStr = "";

  cout << "Input 24-hour time {HH:MM}" << endl;
  cin >> inTimeStr;

  // convert string time into two integer compenents.
  unsigned hour   = ((inTimeStr[0] - '0') * 10) + (inTimeStr[1] - '0');
  unsigned minute = ((inTimeStr[3] - '0') * 10) + (inTimeStr[4] - '0');
  bool isAM = false;


  //convert 24 hour time to 12 hour time.
  if (hour < 12) {
    isAM = true;
  }
  if (hour == 0) {
    hour = 12;
  }
  if (hour > 12) {
    hour -= 12;
  }

  // convert minute into string
  string minStr = "";

  if (minute == 0) {
    //do nothing
  } else if(minute < 10) {
    minStr = "o' ";
    minStr += onesPlace[minute];
  } else if (minute >= 10 && minute < 20) {
    minStr = teens[minute - 10];
  } else if (minute >= 20) {
    minStr = tensPlace[minute / 10];
    minStr += "-";
    minStr += onesPlace[minute % 10];
  }

  //output
  cout << "it is " << " " << hourStrings[hour]<< " " << minStr << " " << (isAM?"AM":"PM") << endl;

  return 0;
}
