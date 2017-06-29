#ifndef DATABASE_DATABASE_H
#define DATABASE_DATABASE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "calendar.h"
#include "datetime.h"
#include "datastructure.h"

/***************************************************************************
*  int:    saveCalendar
*  description: Opens the file and puts <Calendar> and </Canendar> beetween appointments
*  parameter:   fileName, TAppointment, counter
*  result :     notZero if was succesful saved
****************************************************************************/
int saveCalendar(char *DbFileName, int amount);


/***************************************************************************
*  void:    saveAppointment
*  description: Saves current appointment into file
*  parameter:   see function arguments
* ***************************************************************************/
void saveAppointment(FILE *DbFile, TAppointment *appointment);


/***************************************************************************
*  int:    loadAppointment
*  description: loads current appointment into TAppointment
*  result :     not a zero of appointment is correct
* ***************************************************************************/
int loadAppointment(FILE *DbFile, TAppointment *appointment);


/***************************************************************************
*  int:    loadCalendar
*  description: Opens the file and searchs for <Calendar> and </Calendar> beetween appointments
*  parameter:   fileName, TAppointment, counter
*  result :     notZero if was succesful opened and a data is transfered into a memory
 *  ***************************************************************************/
int loadCalendar(char *);

/***************************************************************************
*  int:    writeDate
*  description: wtites formated TDate into a file
*  parameter:   pointer to a file, pointer to TDate
*  result :     -
****************************************************************************/
void writeDate(FILE *file, TDate *date);

/***************************************************************************
*  int:    writeTime
*  description: writes formated TTime into a file
*  parameter:   pointer to a file, pointer to TTime
*  result :     -
****************************************************************************/
void writeTime(FILE *, TTime *);


/***************************************************************************
*  int:    writeTDuration
*  description: is equal to writeTime
***************************************************************************/
void writeDuration(FILE *, TTime *);


/***************************************************************************
*  void:    printDbInfo
*  description: prints the amount of appointments in the dagtabase-file
*  or zero if file is empty
***************************************************************************/
void printDbInfo(int);


/***************************************************************************
*  void:    deleteWhiteSpaces
*  description: deletes spaces and horisontal tabs
***************************************************************************/
void deleteWhiteSpaces(char **);


/***************************************************************************
*  int:    parceTag
*  description: parses a tag and recognizes it
*  parameter:   pointer to an memory address
*  result :     zero if tag is wrong, else one is returned (changes a pointer)
*  ***************************************************************************/
int parseTag(char **pThisLine, int l);


/***************************************************************************
*  void:    reallocTagMemory
*  description: reallocates a memory according with a real size of string
***************************************************************************/
void reallocTagMemory(char **pThisStr);

/***************************************************************************
*  void:    parseDateInAppointment
*  description: parces a date in format dd.mm.yyyy
 *  into a TDate of current appointment
***************************************************************************/
int parseDateInAppointment(FILE *, TDate *);


/***************************************************************************
*  void:    parseTimeInAppointment
*  description: parces a date in format hh:mm:ss
 *  into a TTime of current appointment
***************************************************************************/
int parseTimeInAppointment(FILE *, TTime *);

/***************************************************************************
*  void:    parseDurationInAppointment
*  description: equal to parseTimeInAppointment
***************************************************************************/
int parseTimeInAppointment(FILE *, TTime *);

/***************************************************************************
*  void:    parseDescriptionInAppointment
*  description: saves Description into a specified field
***************************************************************************/
int parseDescriptionInAppointment(FILE *, char **);

/***************************************************************************
*  void:    parseLocationInAppointment
*  description: saves Text into a specified field
***************************************************************************/
int parseLocationInAppointment(FILE *, char **);

#endif
