#ifndef UEB1_CALENDAR_H
#define UEB1_CALENDAR_H

#include "datastructure.h"

/***************************************************************************
 *  Creates a new appointment with optional Location and Duration
 ***************************************************************************/
void createAppointment();

/***************************************************************************
 *
***************************************************************************/
void editAppointment();

/***************************************************************************
 *
***************************************************************************/
void deleteAppointment();

/***************************************************************************
 *
 ***************************************************************************/
void searchAppointment();

/***************************************************************************
 *  Not necessary after rework into a double linked list
 ***************************************************************************/
void sortCalendar();

/***************************************************************************
 *  Helper: printAppointment
 ***************************************************************************/
void listCalendar(int n, int D);

/***************************************************************************
 *  Not necessary after rework into a double linked list
 ***************************************************************************/
void freeCalendar(TAppointment *appointments);

/***************************************************************************
 *  Prints Information how many new appointmens are created
 ***************************************************************************/
void printInfoNewAppointments(int n);

/***************************************************************************
 *  Prints aate and aay of the week
 ***************************************************************************/
void printDateHeader(TAppointment *a);

void printLineAppointment();

/***************************************************************************
 *  Finds a place for a new element
 ***************************************************************************/
int orderByDateTime(TAppointment *a, TAppointment *b);

void printDListeinLine(TAppointment *appointment);

#endif