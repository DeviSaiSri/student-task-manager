#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Task {
    int id;
    char name[100];
    int priority;
    int completed;
    struct Task *next;
};

struct Task *head = NULL;

int taskIdExists(int id) {
    struct Task *temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            return 1;
        }

        temp = temp->next;
    }

    return 0;
}

void addTask() {
    struct Task *newTask = (struct Task *)malloc(sizeof(struct Task));

    printf("\nEnter Task ID: ");
    scanf("%d", &newTask->id);
    
    if (taskIdExists(newTask->id)) {
    printf("\nTask ID already exists. Please use a different ID.\n");
    free(newTask);
    return;
    }
    printf("Enter Task Name: ");
    scanf(" %[^\n]", newTask->name);

    printf("Enter Priority (1-High, 2-Medium, 3-Low): ");
    scanf("%d", &newTask->priority);

    newTask->completed = 0;
    newTask->next = NULL;

    if (head == NULL) {
        head = newTask;
    } else {
        struct Task *temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newTask;
    }

    printf("\nTask added successfully!\n");
}

void displayTasks() {
    struct Task *temp = head;

    if (temp == NULL) {
        printf("\nNo tasks available.\n");
        return;
    }

    printf("\n========== TASKS ==========\n");

    while (temp != NULL) {
        printf("\nID       : %d", temp->id);
        printf("\nTask     : %s", temp->name);
        printf("\nPriority : ");

        if (temp->priority == 1)
            printf("High");
        else if (temp->priority == 2)
            printf("Medium");
        else
            printf("Low");

        printf("\nStatus   : %s\n",
               temp->completed ? "Completed" : "Pending");

        temp = temp->next;
    }

    printf("\n===========================\n");
}

void searchTask() {
    int id;
    struct Task *temp = head;

    printf("\nEnter Task ID to search: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            printf("\nTask Found!\n");
            printf("Task: %s\n", temp->name);
            printf("Status: %s\n",
                   temp->completed ? "Completed" : "Pending");
            return;
        }

        temp = temp->next;
    }

    printf("\nTask not found.\n");
}

void completeTask() {
    int id;
    struct Task *temp = head;

    printf("\nEnter Task ID: ");
    scanf("%d", &id);

    while (temp != NULL) {
        if (temp->id == id) {
            temp->completed = 1;
            printf("\nTask marked as completed!\n");
            return;
        }

        temp = temp->next;
    }

    printf("\nTask not found.\n");
}

void deleteTask() {
    int id;
    struct Task *temp = head;
    struct Task *previous = NULL;

    printf("\nEnter Task ID to delete: ");
    scanf("%d", &id);

    if (temp != NULL && temp->id == id) {
        head = temp->next;
        free(temp);
        printf("\nTask deleted successfully!\n");
        return;
    }

    while (temp != NULL && temp->id != id) {
        previous = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nTask not found.\n");
        return;
    }

    previous->next = temp->next;
    free(temp);

    printf("\nTask deleted successfully!\n");
}

int main() {
    int choice;

    do {
        printf("\n====== STUDENT TASK MANAGER ======\n");
        printf("1. Add Task\n");
        printf("2. Display Tasks\n");
        printf("3. Search Task\n");
        printf("4. Complete Task\n");
        printf("5. Delete Task\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;

            case 2:
                displayTasks();
                break;

            case 3:
                searchTask();
                break;

            case 4:
                completeTask();
                break;

            case 5:
                deleteTask();
                break;

            case 6:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice.\n");
        }

    } while (choice != 6);

    return 0;
}