
#include <stdio.h>

struct Student {
    int id;
    char name[50];
    float marks;
};

int main() {
    struct Student s[100];
    int count = 0;
    int choice, id, i, j, found;

    do {
        printf("\n===== STUDENT MANAGEMENT SYSTEM =====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Update Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                if (count >= 100) {
                    printf("Student storage is full!\n");
                    break;
                }

                printf("Enter Student ID: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (s[i].id == id) {
                        found = 1;
                        break;
                    }
                }

                if (found) {
                    printf("Student ID already exists!\n");
                    break;
                }

                s[count].id = id;

                printf("Enter Student Name: ");
                scanf(" %49[^\n]", s[count].name);

                printf("Enter Student Marks: ");
                scanf("%f", &s[count].marks);

                if (s[count].marks < 0 || s[count].marks > 100) {
                    printf("Invalid marks!\n");
                    break;
                }

                count++;

                printf("Student added successfully!\n");
                break;

            case 2:
                if (count == 0) {
                    printf("No student records found!\n");
                } else {
                    for (i = 0; i < count; i++) {
                        printf("\nStudent ID: %d\n", s[i].id);
                        printf("Student Name: %s\n", s[i].name);
                        printf("Student Marks: %.2f\n", s[i].marks);
                    }
                }
                break;

            case 3:
                printf("Enter Student ID to update: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (s[i].id == id) {

                        printf("Enter new name: ");
                        scanf(" %49[^\n]", s[i].name);

                        printf("Enter new marks: ");
                        scanf("%f", &s[i].marks);

                        if (s[i].marks < 0 || s[i].marks > 100) {
                            printf("Invalid marks!\n");
                            break;
                        }

                        found = 1;
                        printf("Student updated successfully!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Student ID not found!\n");
                }
                break;

            case 4:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);

                found = 0;

                for (i = 0; i < count; i++) {
                    if (s[i].id == id) {

                        for (j = i; j < count - 1; j++) {
                            s[j] = s[j + 1];
                        }

                        count--;
                        found = 1;

                        printf("Student deleted successfully!\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Student ID not found!\n");
                }
                break;

            case 5:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}
