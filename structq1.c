#include <stdio.h>

struct student {
  char name[50];
  int roll_no;
  float grade;
};

void read_student_info(struct student *students, int n) {
  for (int i = 0; i < n; i++) {
    printf("Enter the name of student %d: ", i + 1);
    scanf("%s", students[i].name);

    printf("Enter the roll number of student %d: ", i + 1);
    scanf("%d", &students[i].roll_no);

    printf("Enter the grade of student %d: ", i + 1);
    scanf("%c", &students[i].grade);
  }
}

void display_student_info(struct student *students, int n) {
  for (int i = 0; i < n; i++) {
    printf("Name: %s\n", students[i].name);
    printf("Roll number: %d\n", students[i].roll_no);
    printf("Grade: %c\n", students[i].grade);
  }
}

void sort_student_info(struct student *students, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      if (students[i].roll_no > students[j].roll_no) {
        struct student temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }
}

int main() {
  int n;
  printf("Enter the number of students: ");
  scanf("%d", &n);

  struct student students[n];

  read_student_info(students, n);

  sort_student_info(students, n);

  display_student_info(students, n);

  return 0;
}
