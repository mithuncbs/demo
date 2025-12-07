#include <stdio.h>
#include <string.h>

#define MAX_SEM 8
#define MAX_COURSE 6

struct Course
{
    char name[50];
    float credit;
    float marks;
    float gradePoint;
};

struct Course semesters[MAX_SEM][MAX_COURSE];
int courseCount[MAX_SEM] = {0};

float getGradePoint(float marks)
{
    if (marks >= 80)
        return 4.00;
    else if (marks >= 75)
        return 3.75;
    else if (marks >= 70)
        return 3.50;
    else if (marks >= 65)
        return 3.25;
    else if (marks >= 60)
        return 3.00;
    else if (marks >= 55)
        return 2.75;
    else if (marks >= 50)
        return 2.50;
    else if (marks >= 45)
        return 2.25;
    else if (marks >= 40)
        return 2.00;
    else
        return 0.0;
}

void inputSemester(int sem)
{
    printf("\n------------------------------\n");
    printf("     Entering Semester %d\n", sem + 1);
    printf("------------------------------\n");

    courseCount[sem] = MAX_COURSE;

    for (int i = 0; i < MAX_COURSE; i++)
    {
        getchar();

        printf("\nCourse %d name: ", i + 1);
        scanf("%[^\n]", semesters[sem][i].name);

        printf("Credit: ");
        scanf("%f", &semesters[sem][i].credit);

        printf("Marks (0-100): ");
        scanf("%f", &semesters[sem][i].marks);

        semesters[sem][i].gradePoint = getGradePoint(semesters[sem][i].marks);
    }

    printf("\nSemester %d data saved successfully!\n", sem + 1);
}

float calculateSGPA(int sem)
{
    float totalGrade = 0, totalCredit = 0;

    for (int i = 0; i < courseCount[sem]; i++)
    {
        totalGrade += semesters[sem][i].gradePoint * semesters[sem][i].credit;
        totalCredit += semesters[sem][i].credit;
    }
    if (totalCredit == 0)
        return 0;
    return totalGrade / totalCredit;
}

float calculateCGPA(int totalSem)
{
    float totalGrade = 0, totalCredit = 0;

    for (int s = 0; s < totalSem; s++)
    {
        for (int c = 0; c < courseCount[s]; c++)
        {
            totalGrade += semesters[s][c].gradePoint * semesters[s][c].credit;
            totalCredit += semesters[s][c].credit;
        }
    }

    if (totalCredit == 0)
        return 0;
    return totalGrade / totalCredit;
}

void displayResults(int totalSem)
{
    printf("\n\n     -----------------------------\n");
    printf("              SGPA & CGPA\n");
    printf("     -----------------------------\n");

    for (int s = 0; s < totalSem; s++)
    {
        printf("         Semester %d SGPA: %.2f\n", s + 1, calculateSGPA(s));
    }

    printf("\n          Overall CGPA: %.2f\n", calculateCGPA(totalSem));
    printf("     -----------------------------\n\n");
}

int main()
{
    int choice, totalSem = 0;

    printf("    =-----------------------------=\n");
    printf("           CGPA COUNTER v1.1\n");
    printf("    =-----------------------------=\n");

    while (1)
    {
        printf("\n-------------- MAIN MENU --------------\n");
        printf(" 1. Input Semester Data\n");
        printf(" 2. Display SGPA & CGPA\n");
        printf(" 3. Exit\n");
        printf("--------------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (totalSem < MAX_SEM)
            {
                inputSemester(totalSem);
                totalSem++;
            }
            else
            {
                printf("8 Semesters Already Entered!\n");
            }
        }
        else if (choice == 2)
        {
            displayResults(totalSem);
        }
        else if (choice == 3)
        {
            printf("\nThank you for using CGPA Counter!\n");
            break;
        }
        else
        {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}