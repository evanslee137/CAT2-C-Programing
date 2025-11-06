/*
name:EVANS KOMAREN SEKUT
reg no:CT101/G/22798/24
description:user_paying
*/

#include <stdio.h>

int main() {
    double hours, wage, gross, tax, net;

    // enter input from user
    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours);
    printf("Enter hourly wage: ");
    scanf("%lf", &wage);

    // find gross pay with overtime
    if(hours > 40) {
        gross = 40 * wage + (hours - 40) * wage * 1.5;
    } else {
        gross = hours * wage;
    }

    // Calculate taxes
    if(gross <= 600) {
        tax = gross * 0.15;
    } else {
        tax = 600 * 0.15 + (gross - 600) * 0.20;
    }

    // Calculate net pay
    net = gross - tax;

    // show the results
    printf("Gross pay: $%.2lf\n", gross);
    printf("Taxes: $%.2lf\n", tax);
    printf("Net pay: $%.2lf\n", net);

    return 0;

}
