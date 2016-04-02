/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Month 9 will be represented as 09.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include<iostream>

struct node{
	int data;
	struct node *next;
};
int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
int countLeapYears(int year,int month)
{

	if (month <= 2)
		year--;
	return year / 4 - year / 100 + year / 400;
}
int between_days(struct node *date1head, struct node *date2head){
	int date1 = 0, month1 = 0, year1 = 0, date2 = 0, month2 = 0, year2 = 0;
	struct node *temp1 = date1head;
	int arr[8];
	int i = 0;
	for (i = 0; temp1 != NULL; i++)
	{
		arr[i] = temp1->data;
		temp1 = temp1->next;
	}
	int arr2[8];
	temp1 = date2head;
	for (i = 0; temp1 != NULL; i++)
	{
		arr2[i] = temp1->data;
		temp1 = temp1->next;
	}
	date1 = ((10 * arr[0]) + (1 * arr[1]));
	month1 = ((10 * arr[2]) + (1 * arr[3]));
	year1 = ((1000 * arr[4]) + (100 * arr[5]) + (10 * arr[6]) + (1 * arr[7]));
	date2 = ((10 * arr2[0]) + (1 * arr2[1]));
	month2 = ((10 * arr2[2]) + (1 * arr2[3]));
	year2 = ((1000 * arr2[4]) + (100 * arr2[5]) + (10 * arr2[6]) + (1 * arr2[7]));
	if (date1 <= 0 || month1 <= 0 || year1 <= 0 || date2 <= 0 || month2 <= 0 || year2 <= 0 || month1 > 12 || month2 > 12)
		return -1;
	if (month1 == 1 || month1 == 03 || month1 == 5 || month1 == 7 || month1 == 8 || month1 == 10 || month1 == 12)
	{
		if (date1 > 31)
			return -1;
	}
	if (month2 == 1 || month2 == 03 || month2 == 5 || month2 == 7 || month2 == 8 || month2 == 10 || month2 == 12)
	{
		if (date2 > 31)
			return -1;
	}
	if (month1 == 2)
	{
		if (month1 % 4 == 0 && month1 % 100 != 0)
		{
			if (month1 > 29)
				return -1;
		}
		else
		{
			if (month1 > 28)
				return -1;
		}
	}
	if (month2 == 2)
	{
		if (month2 % 4 == 0 && month2 % 100 != 0)
		{
			if (month2 > 29)
				return -1;
		}
		else
		{
			if (month2 > 28)
				return -1;
		}
	}

	if ((date1 == date2) && month1 == month2 && (year1 == year2))
		return 0;
	int daycount = 0;
	if (year1 == year2)
	{
		if (month1 == month2)
		{
			if (date1 > date2)
			{
				daycount = daycount + (date1 - date2 - 1);
				return daycount;
			}
			else if (date1 < date2)
			{
				daycount = daycount + (date2 - date1 - 1);
				return daycount;
			}
		}
	}
	
	else {
		long int year1days = year1 * 365 + date1;
		for (int i = 0; i < month1 - 1; i++)
			year1days += monthDays[i];
		year1days += countLeapYears(year1, month1);
		long int year2days = year2 * 365 + date2;
		for (int i = 0; i < month2 - 1; i++)
			year2days += monthDays[i];
		year2days += countLeapYears(year2, month2);
		return (year2days - year1days - 1);
	}
	return 0;
}