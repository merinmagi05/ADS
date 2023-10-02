#include <stdio.h>

struct Distance {
int feet;
float inches;
};

struct Distance addDistances(struct Distance d1, struct Distance d2) {
struct Distance result;

result.inches = d1.inches + d2.inches;
result.feet = d1.feet + d2.feet;

if (result.inches >= 12.0) {
result.feet++;
result.inches -= 12.0;
}
return result;
}

int main() {
struct Distance distance1, distance2, sum;

printf("Enter distance 1:\n");
printf("Feet: ");
scanf("%d", &distance1.feet);
printf("Inches: ");
scanf("%f", &distance1.inches);

printf("Enter distance 2:\n");
printf("Feet: ");
scanf("%d", &distance2.feet);
printf("Inches: ");
scanf("%f", &distance2.inches);

sum = addDistances(distance1, distance2);

printf("Sum of distances: %d feet %.2f inches\n", sum.feet, sum.inches);

return 0;
}
