/*
* Copyright (c) 2025 Kim Seung-heon
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef DAN_GUN_DATE_PROVIDER_LIBRARY_H
#define DAN_GUN_DATE_PROVIDER_LIBRARY_H

#include <stdint.h>
#include <time.h>


extern const int64_t GAP_BETWEEN_YEARS; //The time-gap between BC 2333 - AC 1990(expressed in seconds)

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DangunTime;    //Structure for returning the dan_gun-time


int64_t get_seconds(void);
int64_t get_seconds_till(time_t);
DangunTime get_date(time_t);




#endif //DAN_GUN_DATE_PROVIDER_LIBRARY_H