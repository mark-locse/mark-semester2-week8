#include <stdio.h>
#include <string.h>
#include "structure.h"
#include "student.h"

float calculate_average(Student student) {
    float sum = 0.0;
    
    // Sum up all the module marks
    for (int i = 0; i < NUM_MODULES; i++) {
        sum += student.marks[i];
    }
    
    // Return the average
    return sum / NUM_MODULES;
}

void display_student(Student student) {
    float average = calculate_average(student);
    
    printf("Student Information:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Module marks: ");
    
    for (int i = 0; i < NUM_MODULES; i++) {
        printf("%.1f", student.marks[i]);
        if (i < NUM_MODULES - 1) {
            printf(", ");
        }
    }
    
    printf("\nAverage mark: %.1f\n", average);
}

void update_name(Student *student, const char *new_name) {
    // Use strncpy to avoid buffer overflow
    strncpy(student->name, new_name, NAME_LENGTH - 1);
    student->name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
}

int update_mark(Student *student, int module_index, float new_mark) {
    // Validate the module index
    if (module_index < 0 || module_index >= NUM_MODULES) {
        return 0; // Invalid module index
    }
    
    // Update the mark
    student->marks[module_index] = new_mark;
    return 1; // Success
}