#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H DATASTRUCTURE_H

#define MAX_CHARS 20
#define MAX_DESCRIPTION 100
#define MAX_LOCATION 15
#define MAX_APPOINTMENTS_ON_SCREEN 10
#define MAX_BUFFER_SIZE 256

typedef enum {
    NotaDay, Mo, Tu, We, Th, Fr, Sa, Su
} TDayOfTheWeek;

typedef struct {
    int Day;
    int Month;
    int Year;
    TDayOfTheWeek DayOfTheWeek;
} TDate;


typedef struct {
    int Hour;
    int Minute;
    int Second;
} TTime;

/** Double linked list **/
typedef struct Appointments {
    TDate Date;
    TTime Time;
    char *Description;
    char *Location;
    TTime *Duration;
    struct Appointments *Next;
    struct Appointments *Previous;
} TAppointment;

extern TAppointment *FirstAppointment, *LastAppointment;
extern int appointmentCount;
extern int newCount;


#endif //DATASTRUCTURE_H




