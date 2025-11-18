---

# DanGun Date Provider Library

단군력(단기)을 기반으로 시간 연산을 제공하는 C 라이브러리입니다.

이 라이브러리는 한국에서 사용되었던 단군력(단기) 체계를 C 언어 환경에서 다루기 쉽게 구성한 도구 모음입니다. 단군력의 기점을 **기원전 2333년 1월 1일 00시**로 설정하고, `time.h`의 기준 시각과의 간격을 초 단위로 계산하여 단군력 기준 시각을 제공합니다.
또한 단기가 역사적으로 서기의 월·일 체계를 그대로 사용한 점을 고려하여, 날짜 구조체에서는 **연도만 단기로 변환**하도록 설계했습니다.

---

## Features

### ✔ 단군력 기준 누적 초 계산

현재 시각 또는 임의의 `time_t` 값을 이용해
**단군력 원년부터 경과한 초**를 계산해 줍니다.

### ✔ 단기 날짜 구조체(DangunTime) 제공

`time_t` 값을 기반으로 단기 연도 + 서기 월·일·시·분·초로 구성된 구조체를 반환합니다.

### ✔ 단군력 기점과 UNIX 기준점(1990-01-01) 간 오프셋 내장

상수 `GAP_BETWEEN_YEARS`를 통해 오프셋을 자동 반영하며
사용자가 별도로 계산할 필요가 없습니다.

---

## Core Concepts

### ● 단군력(Dangun Calendar)의 기점

* **BC 2333년 1월 1일 00:00**
* 한국에서 일정 기간 공식 기년 방식으로 사용된 날짜입니다.

### ● GAP_BETWEEN_YEARS

단군력 기점과 `1990-01-01 00:00:00` 사이의 시간을
초 단위로 환산한 값입니다.

```c
const int64_t GAP_BETWEEN_YEARS = 136390867200LL;
```

### ● DangunTime 구조체

```c
typedef struct {
    int year;   // 단군기원 기준 연도
    int month;
    int day;
    int hour;
    int minute;
    int second;
} DangunTime;
```

연도는 단기 방식으로 변환하며, 월·일·시·분·초는 서기 달력을 그대로 따릅니다.

---

## System Requirements

이 라이브러리는 모든 연산을 `int64_t` 기반으로 처리합니다.
단군력 기점과 현재 시각 사이의 간격이 매우 크기 때문에
**64비트 정수 타입을 지원하는 시스템에서 사용하는 것을 권장합니다.**

* `int64_t`는 C99 표준에서 정의한 64비트 정수 타입입니다.
* 32비트 시스템에서는 표현 가능한 정수 범위가 충분하지 않아
  오버플로가 발생할 가능성이 있습니다.

---

## API Reference

### 1) `int64_t get_seconds(void)`

현재 시각을 기준으로
단군력 원년부터 경과한 초를 반환합니다.

### 2) `int64_t get_seconds_till(time_t seconds)`

입력된 `time_t` 값을 기준으로
단군력 원년부터 흐른 초를 계산합니다.

### 3) `DangunTime get_date(time_t seconds)`

입력된 `time_t` 값을 단기 방식의 `DangunTime` 구조체로 변환합니다.

---

## Usage Example

```c
#include "library.h"
#include <stdio.h>

int main(void) {
    // 1. 현재 단기 기준 누적 초
    int64_t now_dangun_seconds = get_seconds();
    printf("Seconds since DanGun epoch: %lld\n", now_dangun_seconds);

    // 2. 특정 시각 기준 계산
    time_t some_time = time(NULL) - 3600; // 한 시간 전
    int64_t dangun_seconds = get_seconds_till(some_time);
    printf("Seconds (1 hour ago): %lld\n", dangun_seconds);

    // 3. 단기 날짜 구조체
    DangunTime dg = get_date(time(NULL));
    printf("Dangun date: %d-%02d-%02d %02d:%02d:%02d\n",
           dg.year, dg.month, dg.day,
           dg.hour, dg.minute, dg.second);

    return 0;
}
```

---

## License

이 프로젝트는 MIT License를 따릅니다.
자세한 내용은 `LICENSE` 파일을 참고해 주십시오.

---