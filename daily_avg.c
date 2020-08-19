//Salam Fazil
//V00935894


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

    float avg_temp[12][31];

    float sum[12][31];

    for (int r = 0; r < 12 ; ++r) {
        for (int c = 0; c < 31; ++c) {

            avg_temp[r][c] = 0;

            sum[r][c] = 0;

        }
    }


    while (fscanf (input_file, "%d %d %d %d %d %f", &month, &day, &hour, &minute, &station_number, &temperature) == 6 ){

        avg_temp[month - 1][day - 1] += temperature;
        sum[month - 1][day - 1]++;
    }


    fclose(input_file);


    FILE *output_file = fopen("daily_averages_summary.txt", "w");

    if (!output_file) {
        printf("Unable to open output file.\n");
        return 1;
    }

    for (int r = 0; r < 12 ; ++r) {
        for (int c = 0; c < 31 ; ++c) {

            if (sum[r][c] != 0) {
                fprintf(output_file, "%d %d %.2f\n", r + 1, c + 1, avg_temp[r][c] / sum[r][c]);
            }

        }

    }


    fclose(output_file);

    return 0;

}