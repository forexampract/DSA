#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *day;
    int date;
    char *activity;
} Day;

/* Create calendar */
Day *create(int n) {
    Day *week = (Day *)malloc(n * sizeof(Day));
    for (int i = 0; i < n; i++) {
        week[i].day = (char *)malloc(20);
        week[i].activity = (char *)malloc(100);
    }
    return week;
}

/* Read data */
void read(Day *week, int n) {
    for (int i = 0; i < n; i++) {
        printf("\nEnter day name: ");
        scanf("%s", week[i].day);

        printf("Enter date: ");
        scanf("%d", &week[i].date);

        printf("Enter activity: ");
        scanf(" %[^\n]", week[i].activity);
    }
}

/* Display data */
void display(Day *week, int n) {
    printf("\n--- Week Activity Report ---\n");
    for (int i = 0; i < n; i++) {
        printf("%s %d : %s\n",
               week[i].day, week[i].date, week[i].activity);
    }
}

int main() {
    int n = 7;
    Day *week = create(n);

    read(week, n);
    display(week, n);

    for (int i = 0; i < n; i++) {
        free(week[i].day);
        free(week[i].activity);
    }
    free(week);

    return 0;
}
