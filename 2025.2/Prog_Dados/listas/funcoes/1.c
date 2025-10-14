#include <stdio.h>
#include <windows.h>

void celsius_to_fahrenheit(float *celsius, float *fahrenheit)
{
    *fahrenheit = (*celsius * 1.8) + 32;
}

int main()
{
    float celsius_temperature, fahrenheit_temperature;
    
    system("cls");

    printf("Vamos converter graus celsius para fahrenheit!\nInsira o valor dos graus (C): ");
    scanf("%f", &celsius_temperature);

    celsius_to_fahrenheit(&celsius_temperature, &fahrenheit_temperature);
    printf("%.1f graus Celsius equivalem a %.1f graus Fahrenheit", celsius_temperature, fahrenheit_temperature);

    return 0;
}