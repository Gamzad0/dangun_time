/*
* Copyright (c) 2025 Kim Seung-heon
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "library.h"

#include <stdio.h>

const int64_t GAP_BETWEEN_YEARS = 136390867200LL;



int64_t get_seconds(void) {
    return (int64_t)time(NULL) + GAP_BETWEEN_YEARS;
}

int64_t get_seconds_till(time_t seconds) {
    return seconds + GAP_BETWEEN_YEARS;
}

DangunTime get_date(time_t seconds) {
    struct tm *t = localtime(&seconds);
    DangunTime dgtime = {t->tm_year+1900+2333,t->tm_mon+1,t->tm_mday, t->tm_hour,t->tm_min,t->tm_sec};
    return dgtime;
}