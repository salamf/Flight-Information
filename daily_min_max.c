//
// Created by Salam Fazil on 2019-11-16.
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

    float maxTemp[12][31]={0};

    float minTemp[12][31]={0};

    int sum[12][31]={0};


    while (fscanf(input_file, "%d %d %d %d %d %f", &month, &day, &hour, &minute, &station_number, &temperature) == 6) {

        if (sum[month-1][day-1] == 0) {

            maxTemp[month - 1][day - 1] = temperature;
            minTemp[month - 1][day - 1] = temperature;
        }

        if (maxTemp[month - 1][day - 1] < temperature) {
            maxTemp[month - 1][day - 1] = temperature;
        }

        if (minTemp[month - 1][day - 1] > temperature) {
            minTemp[month - 1][day - 1] = temperature;
        }

        sum[month-1][day-1]++;
    }

        fclose(input_file);


        FILE *output_file = fopen("daily_minimum_maximum_summary.txt", "w");

        if (!output_file) {
            printf("Unable to open output file.\n");
            return 1;
        }

        for (int r = 1; r < 13; ++r) {
            for (int c = 1; c < 32; ++c) {

                if(sum[r-1][c-1] != 0){
                    fprintf(output_file, "%d %d %.2f %.2f\n", r , c , minTemp[r - 1][c - 1], maxTemp[r - 1][c - 1]);
                }

            }

        }

        fclose(output_file);

        return 0;
}
