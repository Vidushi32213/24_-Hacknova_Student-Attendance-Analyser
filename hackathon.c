#include <stdio.h>

#define STUDENTS 10
#define CLASSES 5
#define THRESHOLD 75

int main()
{
    int attendance[STUDENTS][CLASSES];
    int present[STUDENTS];
    float percentage[STUDENTS];
    int i, j;

    printf("=====================================\n");
    printf("      STUDENT ATTENDANCE ANALYZER\n");
    printf("=====================================\n");

    printf("\nEnter 1 for Present and 0 for Absent\n");

    /* Taking attendance */
    for(i = 0; i < STUDENTS; i++)
    {
        printf("\nStudent %d:\n", i + 1);

        for(j = 0; j < CLASSES; j++)
        {
            printf("Class %d: ", j + 1);
            scanf("%d", &attendance[i][j]);
        }
    }

    /* Display attendance table */
    printf("\n\n=====================================\n");
    printf("          ATTENDANCE REPORT\n");
    printf("=====================================\n");

    printf("Student\t");

    for(j = 0; j < CLASSES; j++)
    {
        printf("C%d\t", j + 1);
    }

    printf("Percentage\n");

    /* Calculate attendance percentage */
    for(i = 0; i < STUDENTS; i++)
    {
        present[i] = 0;

        printf("%d\t", i + 1);

        for(j = 0; j < CLASSES; j++)
        {
            if(attendance[i][j] == 1)
            {
                printf("P\t");
                present[i]++;
            }
            else
            {
                printf("A\t");
            }
        }

        percentage[i] =
            ((float)present[i] / CLASSES) * 100;

        printf("%.2f%%\n", percentage[i]);
    }

    /* Display students below 75% */
    printf("\n=====================================\n");
    printf("     STUDENTS BELOW 75%% ATTENDANCE\n");
    printf("=====================================\n");

    for(i = 0; i < STUDENTS; i++)
    {
        if(percentage[i] < THRESHOLD)
        {
            printf("Student %d : %.2f%%\n",
                   i + 1, percentage[i]);
        }
    }

    return 0;
}