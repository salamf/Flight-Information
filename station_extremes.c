//
// Created by Salam Fazil on 2019-11-17.
// V00935894

#include <stdio.h>

int main() {

    FILE *input_file = fopen("input_data.txt", "r");

    if (!input_file) {
        printf("Unable to open input file.\n");
        return 1;
    }

    int month = 0;
    int day = 0;
    int hour = 0;
    int minute = 0;
    int station_number = 0;
    float temperature = 0;


    int max_month[1000] ;
    int min_month[1000];

    int max_day[1000] ;
    int min_day[1000] ;

    int hourMax[1000] ;
    int hourMin[1000] ;

    int minMax[1000];
    int minMin[1000] ;

    int stationCount[1000];

    float maxTemp[1000];

    float minTemp[1000];

    int sum[1000];

    int i = 0;

    while (i < 1000) {

        max_month[i] = 0;
        min_month[i] = 0;

        max_day[i] = 0;
        min_day[i] = 0;

        hourMax[i] = 0;
        hourMin[i] = 0;

        minMax[i] = 0;
        minMin[i] = 0;

        maxTemp[i] = 0;

        minTemp[i] = 0;

        sum[i] = 0;

        stationCount[i] = 0;

        i++;
    }

    while (fscanf(input_file, "%d %d %d %d %d %f", &month, &day, &hour, &minute, &station_number, &temperature) == 6) {

        if (sum[station_number - 1] == 0) {

            max_month[station_number - 1] = month;
            min_month[station_number - 1] = month;

            max_day[station_number - 1] = day;
            min_day[station_number - 1] = day;

            hourMax[station_number - 1] = hour;
            hourMin[station_number - 1] = hour;

            minMax[station_number - 1] = minute;
            minMin[station_number - 1] = minute;

            maxTemp[station_number - 1] = temperature;

            minTemp[station_number - 1] = temperature;

            stationCount[station_number - 1] = station_number;

            sum[station_number - 1]++;

        }
        if (maxTemp[station_number - 1] < temperature) {

            max_month[station_number - 1] = month;

            max_day[station_number - 1] = day;

            hourMax[station_number - 1] = hour;

            minMax[station_number - 1] = minute;

            maxTemp[station_number - 1] = temperature;
        }


    if (minTemp[station_number - 1] > temperature) {

        min_month[station_number - 1] = month;

        min_day[station_number - 1] = day;

        hourMin[station_number - 1] = hour;

        minMin[station_number - 1] = minute;

        minTemp[station_number - 1] = temperature;
    }

        sum[station_number - 1]++;
    }
        fclose(input_file);


        FILE *output_file = fopen("station_extremes.txt", "w");

        if (!output_file) {
            printf("Unable to open output file.\n");
            return 1;
        }

    for (int i = 0; i < 1000; ++i) {
                if(sum[i] != 0)
                    fprintf(output_file, "Station %d: Minimum = %.2f degrees (%02d/%02d %02d:%02d), Maximum = %.2f degrees (%02d/%02d %02d:%02d)\n", stationCount[i] , minTemp[i], min_month[i], min_day[i], hourMin[i], minMin[i], maxTemp[i], max_month[i], max_day[i], hourMax[i], minMax[i]);
                }

    fclose(output_file);

    return 0;
}