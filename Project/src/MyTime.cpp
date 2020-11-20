//
// Created by limbe on 2020-11-20.
//

#include "MyTime.h"

MyTime::MyTime(): hours(0), minutes(0), seconds(0)
{
}

MyTime::MyTime(int pHours, int pMinutes, int pSeconds) : hours(pHours), minutes(pMinutes), seconds(pSeconds)
{
}

MyTime::~MyTime()
{

}

int MyTime::getHours() const
{
    return hours;
}

void MyTime::setHours(int pHours)
{
    hours = pHours;
}

int MyTime::getMinutes() const
{
    return minutes;
}

void MyTime::setMinutes(int pMinutes)
{
    minutes = pMinutes;
}

int MyTime::getSeconds() const
{
    return seconds;
}

void MyTime::setSeconds(int pSeconds)
{
    seconds = pSeconds;
}

MyTime MyTime::operator+(const MyTime &time) const
{
    MyTime sum;
    int totalSec=0;
    int totalMin=0;
    totalSec = seconds + time.seconds;
    sum.seconds = totalSec % 60;
    totalMin = minutes + time.minutes + totalSec/60;
    sum.minutes = totalMin %60;
    sum.hours = hours + time.hours + totalMin/60;

    return sum;
}

bool MyTime::operator<(const MyTime &time) const
{
    //converts time to seconds and compare
    return (hours*60*60 + minutes*60 + seconds) < (time.hours*60*60 + time.minutes*60 + seconds);
}

bool MyTime::operator==(const MyTime &time) const
{
    return hours==time.hours && minutes==time.minutes && seconds == time.seconds;
}

int MyTime::timeToSeconds() const
{
    return hours*60*60 + minutes*60 + seconds;
}

void MyTime::setTime(const int pTotalSec)
{
    int temp = 0;
    seconds = pTotalSec % 60;
    temp = pTotalSec/60;
    minutes = temp % 60;
    hours = temp/60;
}

ostream &operator<< (ostream &os, const MyTime &time)
{
    os << time.timeToSeconds();
    return os;
}

istream &operator>> (istream & is, MyTime &time)
{
    string str;
    is >> str;
    std::replace(str.begin(), str.end(), ':', ' ');  // replace ':' by ' '
    stringstream ss(str);

    time.setTime(temp);
    return is;
}

