#include <iostream>
#include <string>

using namespace std;

int main()
{
    /*We need a few variables to play with the user input and ensure we can
    match up the text output with the numerical input. We also need to make sure
    we can concatenate strings later on. The easiest way is to add strings and make
    that addition equal to the value of another string. e.g. str a = b+c is easy and straightforward.
    The arrays simply save time. I am not proud of my memory usage.*/
    string usrTime;
    string usrHour;
    string fullUsrHour;
    string usrMin;
    string fullUsrMin;
    int fullUsrHourNum;
    int fullUsrMinNum;
    int usrMinNum;
    string ones [9] = {"one","two","three","four","five","six","seven","eight","nine"};
    string tens [6] = {"ten","twenty","thirty","forty","fifty","sixty"};
    string withinTen [9] = {"eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen",
                            "eighteen","nineteen"};
    string tensHourOutput;
    string onesHourOutput;
    string hourOutput;
    string tensMinuteOutput;
    string onesMinuteOutput;
    string minuteOutput;

    /*Get's user input, you can use a colon.*/
    cout << "What time is it?" << endl;
    cin >> usrTime;

    /*This part is sort of important because it allows us to
    make the hour part of the user's input a single int. */
    usrHour = usrTime.at(0);
    fullUsrHour = usrHour + usrTime.at(1);

    /*We convert the string we created above into a single int.*/
    fullUsrHourNum = stoi(fullUsrHour);

    /*The text input changes based on which hour it is.
    An easy and quick way of handling this is to go through
    an array and find the string then just output the relevant
    string later on. With math this could be shorter. When
    I use both a tens and ones portion, it is so that I can easily
    concatenate the string for output.*/
    if(fullUsrHourNum < 10 && fullUsrHourNum > 0) {
        hourOutput = ones[(fullUsrHourNum - 1)];
    } else if(fullUsrHourNum == 10) {
        hourOutput = tens[0];
    } else if(fullUsrHourNum > 10 && fullUsrHourNum <= 12) {
        hourOutput = withinTen[(fullUsrHourNum - 11)];
    } else if(fullUsrHourNum > 12 && fullUsrHourNum < 22) {
        hourOutput = ones[(fullUsrHourNum - 13)];
    } else if(fullUsrHourNum == 22) {
        hourOutput = tens[(fullUsrHourNum - 22)];
    } else if(fullUsrHourNum == 23) {
        hourOutput = withinTen[(fullUsrHourNum - 23)];
    } else if(fullUsrHourNum == 0) {
        hourOutput = withinTen[1];
    }

    /*We're about to turn the minutes value into a single string with just
    those numbers.*/
    usrMin = usrTime.at(3);
    fullUsrMin = usrMin + usrTime.at(4);

    /*This is a conversion from string to int. Thanks Joey.*/
    fullUsrMinNum = stoi(fullUsrMin);

    /*This is the same thing as I did above for the hour portion.
    Basically, we're looking for the relevant text values based on
    where the number falls. This could be shorter with math. When
    I use both a tens and ones portion, it is so that I can easily
    concatenate the string for output.*/
    if(fullUsrMinNum < 10) {
        minuteOutput = "oh " + ones[(fullUsrMinNum - 1)];
    } else if (fullUsrMinNum == 10) {
        minuteOutput = tens[0];
    } else if(fullUsrMinNum > 10 && fullUsrMinNum < 20) {
        minuteOutput = withinTen[(fullUsrMinNum - 11)];
    } else if(fullUsrMinNum == 20) {
        minuteOutput = tens[1];
    } else if(fullUsrMinNum > 20 && fullUsrMinNum < 30) {
        tensMinuteOutput = tens[1];
        onesMinuteOutput = ones[(fullUsrMinNum - 21)];
        minuteOutput = tensMinuteOutput + " " + onesMinuteOutput;
    } else if(fullUsrMinNum == 30) {
        minuteOutput = tens[2];
    } else if(fullUsrMinNum > 30 && fullUsrMinNum < 40) {
        tensMinuteOutput = tens[2];
        onesMinuteOutput = ones[(fullUsrMinNum - 31)];
        minuteOutput = tensMinuteOutput + " " + onesMinuteOutput;
    } else if(fullUsrMinNum == 40) {
        minuteOutput = tens[3];
    } else if(fullUsrMinNum > 40 && fullUsrMinNum < 50) {
        tensMinuteOutput = tens[3];
        onesMinuteOutput = ones[(fullUsrMinNum - 41)];
        minuteOutput = tensMinuteOutput + " " + onesMinuteOutput;
    } else if(fullUsrMinNum == 50) {
        minuteOutput = tens[4];
    } else if(fullUsrMinNum > 50 && fullUsrMinNum < 60) {
        tensMinuteOutput = tens[4];
        onesMinuteOutput = ones[(fullUsrMinNum - 51)];
        minuteOutput = tensMinuteOutput + " " + onesMinuteOutput;
    } else if(fullUsrMinNum == 0) {
        minuteOutput = "";
    }

    /*Whether the output will be in AM or PM depends on the time of day.
    This is a final check allowing that detail to be accurate. */
    if(fullUsrHourNum < 12) {
        cout << "The time is " << hourOutput << " " << minuteOutput << " am" << endl;
    } else if(fullUsrHourNum >= 12) {
        cout << "The time is " << hourOutput << " " << minuteOutput << " pm" << endl;
    }

    return 0;
}
