#include <stdio.h>
#define FREEZING_F 32
#define BOILING_F 212

float f_to_c(double f)
{
    return (f - FREEZING_F) * 5 / 9;
}

int main()
{
    double userInputF;
    int i;
    printf("%10s\t%7s\n", "Fahrenheit", "Celsius");
    for (i = FREEZING_F; i <= BOILING_F; i += 10)
    {
        printf("%10d\t%7.1lf\n", i, f_to_c(i));
    }
    printf("\nEnter a temperature in Fahrenheit: ");
    scanf("%lf", &userInputF);
    printf("Celsius: %7.2lf\n", f_to_c(userInputF));
}
