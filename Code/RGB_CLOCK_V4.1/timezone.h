// timezones.h - Updated version
#ifndef TIMEZONES_H
#define TIMEZONES_H

#include <Arduino.h>

struct TimezoneEntry {
    const char* zoneName;
    const char* posixString;
};

// Don't specify array size in header
extern const TimezoneEntry timezoneDatabase[];
extern const int TIMEZONE_COUNT;

String getPosixString(const char* zoneName);
void printAllTimezones();

#endif