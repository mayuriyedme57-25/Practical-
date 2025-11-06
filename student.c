#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int rollNo;
    float avgMarks;
    int age;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    struct Student s[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Roll No: ");
        scanf("%d", &s[i].rollNo);
        printf("Average Marks: ");
        scanf("%f", &s[i].avgMarks);
        printf("Age: ");
        scanf("%d", &s[i].age);
    }

    // Bubble Sort (Descending by avgMarks)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].avgMarks < s[j + 1].avgMarks) {
                struct Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    printf("\nStudents sorted in descending order of Average Marks:\n");
    printf("--------------------------------------------------------\n");
    printf("%-10s %-10s %-10s %-10s\n", "Name", "RollNo", "AvgMarks", "Age");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-10s %-10d %-10.2f %-10d\n", s[i].name, s[i].rollNo, s[i].avgMarks, s[i].age);
    }

    return 0;
}
