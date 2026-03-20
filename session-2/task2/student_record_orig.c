/**
 * @file student_record.c
 * @brief Implementation of a student record management system using structures
 */

#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50
#define NUM_MODULES 3

/**
 * @brief Structure to represent a student
 */
typedef struct {
    char name[NAME_LENGTH];  // Student's name
    int id;                  // Student's ID number
    float marks[NUM_MODULES]; // Marks for three modules
} Student;

/**
 * @brief Calculate the average mark for a student
 * 
 * @param student The student whose average mark is to be calculated
 * @return float The average mark
 */
float calculate_average(Student student) {
    float sum = 0.0;
    
    // Sum up all the module marks
    for (int i = 0; i < NUM_MODULES; i++) {
        sum += student.marks[i];
    }
    
    // Return the average
    return sum / NUM_MODULES;
}

/**
 * @brief Display student information including name, ID, marks, and average
 * 
 * @param student The student whose information is to be displayed
 */
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

/**
 * @brief Update student name
 * 
 * @param student Pointer to the student whose name is to be updated
 * @param new_name The new name for the student
 */
void update_name(Student *student, const char *new_name) {
    // Use strncpy to avoid buffer overflow
    strncpy(student->name, new_name, NAME_LENGTH - 1);
    student->name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
}

/**
 * @brief Update a specific module mark
 * 
 * @param student Pointer to the student whose mark is to be updated
 * @param module_index The index of the module to update (0, 1, or 2)
 * @param new_mark The new mark
 * @return int 1 if successful, 0 if module_index is invalid
 */
int update_mark(Student *student, int module_index, float new_mark) {
    // Validate the module index
    if (module_index < 0 || module_index >= NUM_MODULES) {
        return 0; // Invalid module index
    }
    
    // Update the mark
    student->marks[module_index] = new_mark;
    return 1; // Success
}

int main() {
    // Create and initialise a student variable
    Student student = {
        .name = "John Smith",
        .id = 12345,
        .marks = {75.0, 68.5, 81.0}
    };
    
    // Display original student information
    printf("Original student record:\n");
    display_student(student);
    
    // Calculate and display the average mark
    float average = calculate_average(student);
    printf("\nThe average mark is: %.1f\n", average);
    
    // Update the student's name and third module mark
    update_name(&student, "Jane Smith");
    update_mark(&student, 2, 92.5); // Update the third module (index 2)
    
    // Display the updated student information
    printf("\nAfter updates:\n");
    display_student(student);
    
    return 0;
}