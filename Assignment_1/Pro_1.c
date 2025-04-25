#include <stdio.h>
#include <stdlib.h>

float cal_avg_of_each_city_temp(float temp_of_city[])
{
    float sum = 0;
    for (int i = 0; i < 365; i++)
    {
        sum += temp_of_city[i];
    }

    return sum / 365;
}

int main()
{
    // int x = (rand()%21) + 20 ;
    // printf("%d",x);

    float temp_of_city[5][365];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 365; j++)
        {
            temp_of_city[i][j] = (rand() % 21) + 20;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        printf("average temp of city_%d = %.2fdegree C\n", i + 1, cal_avg_of_each_city_temp(temp_of_city[i]));
    }

    float total_sum = 0 ;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 365; j++)
        {
            total_sum = total_sum + temp_of_city[i][j];
        }
    }


    printf("Overall average temp = %f",total_sum/(365*5));

    return 0;
}
