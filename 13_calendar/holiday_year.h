#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define FRIDAY 5
#define MONDAY 1
#define THURSDAY 4
#define FIRST_WEEK h->day<8 
#define SECOND_WEEK h->day>7&&h->day<15
#define THIRD_WEEK h->day>14&&h->day<22
#define FOURTH_WEEK h->day>21&&h->day<29
#define LAST_WEEK h->day>24&&h->day<32
#define COLUMNS 4
#define BOLD 1
#define RED	1
#define BLACK 0
#define CYAN 6
#define WHITE 7
#define FG 30
#define BG 40

struct holiday {
	int month;
	int day;
	int year;
	int wday;
	char *name;
};

int isholiday(struct holiday *h);

