#include <stdio.h>

struct time {
  int hour;
  int min;
  int sec;
};

// Function to add two time objects
struct time add_time(struct time t1, struct time t2) {
  struct time sum;
  sum.sec = t1.sec + t2.sec;
  sum.min = t1.min + t2.min + (sum.sec / 60);
  sum.sec %= 60;
  sum.hour = t1.hour + t2.hour + (sum.min / 60);
  sum.min %= 60;
  return sum;
}

// Function to subtract two time objects
struct time subtract_time(struct time t1, struct time t2) {
  struct time diff;
  diff.sec = t1.sec - t2.sec;
  diff.min = t1.min - t2.min - (diff.sec < 0 ? 1 : 0);
  diff.sec += (diff.sec < 0 ? 60 : 0);
  diff.hour = t1.hour - t2.hour - (diff.min < 0 ? 1 : 0);
  diff.min += (diff.min < 0 ? 60 : 0);
  return diff;
}

// Function to display a time object
void display_time(struct time t) {
  printf("%d:%d:%d\n", t.hour, t.min, t.sec);
}

// Function to read a time object from the user
struct time read_time() {
  struct time t;
  printf("Enter hour: ");
  scanf("%d", &t.hour);
  printf("Enter minute: ");
  scanf("%d", &t.min);
  printf("Enter second: ");
  scanf("%d", &t.sec);
  return t;
}

int main() {
  struct time t1, t2, sum, diff;

  // Read two time objects from the user
  t1 = read_time();
  t2 = read_time();

  // Add the two time objects
  sum = add_time(t1, t2);
  printf("The sum of the two time objects is: ");
  display_time(sum);

  // Subtract the two time objects
  diff = subtract_time(t1, t2);
  printf("The difference of the two time objects is: ");
  display_time(diff);

  return 0;
}
