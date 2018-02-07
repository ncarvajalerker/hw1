//caldenar.c -- Natalia Carvajal Erker
#include<stdio.h>

int startingDay (int year) { //takes in the year and divids it by the instance given to check if it is a leap year or not.
    int leapYear4 = (year - 1) / 4;
    int leapYear100 = (year - 1) / 100;
    int leapyear400 = (year - 1) / 400;
    return (year + leapYear4 - leapYear100 + leapyear400) % 7; 
    //subtract leapyear100 so that if it is the 100th year in the loop it isn't a leap year. %7 because of the amount of days in the week.
}


    int printMonth(int year, int days, int startingDay){
       int dayOfWeek;

        for (dayOfWeek = 0; dayOfWeek < startingDay; dayOfWeek++){ //daysOfWeek used to show the amount of spaces. 
            printf("     ");
        }

        for (int date = 1; date <= days; date++){ //pre-condition is the date is set to one and keeps increasing until the amount of days in the month runs out.

            printf("%5d", date);

            if(++dayOfWeek>6){ //this contains the starting day of each week in the month.
                printf("\n");
                dayOfWeek =0;
            }
        }

        if(dayOfWeek !=0){ //this contains the day of the week for the month that's about to start.
            printf("\n");
            startingDay = dayOfWeek;
        }

        return startingDay; //this will initilize the next month.
    }


int printMonthName(int year, int month, int startingDay){
    int days;
         switch (month) { //sets month equal to each string with the month name and the number of days.
            case 1 :
            printf("January %d\n", year);
            days = 31;
            break;

            case 2 :
            printf("Febuary %d\n", year);
            days = 28;
            break;

            case 3 :
            printf("March %d\n", year);
            days = 31;
            break;

            case 4 :
            printf("April %d\n", year);
            days = 30;
            break;

            case 5 :
            printf("May %d\n", year);
            days = 31;
            break;

            case 6 :
            printf("June %d\n", year);
            days = 30;
            break;

            case 7 :
            printf("June %d\n", year);
            days = 31;
            break;

            case 8 :
            printf("August %d\n", year);
            days = 30;
            break;

            case 9 :
            printf("September %d\n", year);
            days = 30;
            break;

            case 10 :
            printf("October %d\n", year);
            days = 31;
            break;

            case 11 :
            printf("November %d\n", year);
            days = 30;
            break;

            case 12 :
            printf("December %d\n", year);
            days = 31;
            break;


        }
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");
        return days; //gives the other functions each amount of days that the months contain.
    }

void printCalendar (int year, int startingDay){

    int month, days;

    for (month = 1; month <= 12; month++){ //will print 12 days of the month matching them to the number of days they contain and their name.

        printf("\n");

        days = printMonthName(year, month, startingDay);
         //initiates printMonthName function taking in year and startingDay and sets days equal to it.
        startingDay = printMonth(year, days, startingDay); //sets startingDay equal to printMonth so it can start on the correct day.

       }

       }

int main(void){
    int year;

    printf("Monthly Calendar\n");
    printf("Please enter year for this calendar:- ");
    scanf("%d", &year); //stores the input number inside the int year.
    if(year <= 0){ //for negative years
        printf("Please only enter positive numbers for the year, thank you.");
        scanf("%d", &year);
    }
    else { //when the year isn't negative it prints the calendar.
        printf("***    CALENDAR for %d ***\n", year);
        printf("\n"); //formatting

        printCalendar(year, startingDay(year)); //initiates the printCalendar function and takes in the parameters starting day and year.
    }
}
