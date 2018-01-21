#include <stdio.h>
#include <stdlib.h>

void rectangular(void);
void square(void);
void circle(void);

int main(){
    int type = 0;
    while(type != 4){
        printf("====================\n");
        printf("1.Rectangular 2.Square 3.Circle 4.Exit\n");
        printf("Choose the type of perimeter you want to calculate:\n");
        scanf("%d", &type);
        switch(type){
            case 1:
                rectangular();
                break;
            case 2:
                square();
                break;
            case 3:
                circle();
                break;
            case 4:
                printf("Goodbye!\n");
                exit(1);
            default:
                printf("Please follow the instruction carefully.\n");
                break;
        }
        
    }
    return 0;
}

void rectangular(void){
    float length, width, perimeter;
    printf("Please enter the Length and Width respectively.\n");
    scanf("%f %f", &length, &width);
    perimeter = (length + width) * 2;
    printf("The perimeter of a rectangular with (Length,Width) = (%.3f, %.3f) is %.3f\n", length, width, perimeter);
}

void square(void){
    float length, width, perimeter;
    printf("Please enter the Length.\n");
    scanf("%f", &length);
    perimeter = length * 4;
    printf("The perimeter of a square with (Length) = (%.3f) is %.3f\n", length, perimeter);
}

void circle(void){
    const double PI = 3.1415926;
    float radius, perimeter;
    printf("Please enter the radius of the circle.\n");
    scanf("%f", &radius);
    perimeter = 2 * PI * radius;
    printf("The perimeter of a circle with (Radius) = (%.3f) is %.3f\n", radius, perimeter);
}