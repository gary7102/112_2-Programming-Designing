#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

typedef struct {
    char name[10];
    double (*perimeter)(void*);
    double (*area)(void*);
} Shape;

// Circle structure
typedef struct {
    Shape base;
    double radius;
} Circle;

// Rectangle structure
typedef struct {
    Shape base;
    double length;
    double width;
} Rectangle;

// Square structure
typedef struct {
    Shape base;
    double edge;
} Square;

// Triangle structure
typedef struct {
    Shape base;
    double a, b, c; // sides of the triangle
} Triangle;

// Function to calculate the perimeter of a circle
double circlePerimeter(void* obj) {
    Circle* c = (Circle*)obj;
    return 2 * PI * c->radius;
}

// Function to calculate the area of a circle
double circleArea(void* obj) {
    Circle* c = (Circle*)obj;
    return PI * c->radius * c->radius;
}

// Function to calculate the perimeter of a rectangle
double rectanglePerimeter(void* obj) {
    Rectangle* r = (Rectangle*)obj;
    return 2 * (r->length + r->width);
}

// Function to calculate the area of a rectangle
double rectangleArea(void* obj) {
    Rectangle* r = (Rectangle*)obj;
    return r->length * r->width;
}

// Function to calculate the perimeter of a square
double squarePerimeter(void* obj) {
    Square* s = (Square*)obj;
    return 4 * s->edge;
}

// Function to calculate the area of a square
double squareArea(void* obj) {
    Square* s = (Square*)obj;
    return s->edge * s->edge;
}

// Function to calculate the perimeter of a triangle
double trianglePerimeter(void* obj) {
    Triangle* t = (Triangle*)obj;
    return t->a + t->b + t->c;
}

// Function to calculate the area of a triangle using Heron's formula
double triangleArea(void* obj) {
    Triangle* t = (Triangle*)obj;
    double s = (t->a + t->b + t->c) / 2;
    return sqrt(s * (s - t->a) * (s - t->b) * (s - t->c));
}

int main() {
    int n;
    scanf("%d", &n);

    Shape* shapes[n];
    double totalPerimeter = 0, totalArea = 0;

    for (int i = 0; i < n; i++) {
        char type;
        scanf(" %c", &type); // Notice the space before %c to eat any newline characters

        if (type == 'C') {
            Circle* c = malloc(sizeof(Circle));
            scanf("%lf", &c->radius);
            c->base.perimeter = circlePerimeter;
            c->base.area = circleArea;
            shapes[i] = (Shape*)c;
        } else if (type == 'R') {
            Rectangle* r = malloc(sizeof(Rectangle));
            scanf("%lf %lf", &r->length, &r->width);
            r->base.perimeter = rectanglePerimeter;
            r->base.area = rectangleArea;
            shapes[i] = (Shape*)r;
        } else if (type == 'S') {
            Square* s = malloc(sizeof(Square));
            scanf("%lf", &s->edge);
            s->base.perimeter = squarePerimeter;
            s->base.area = squareArea;
            shapes[i] = (Shape*)s;
        } else if (type == 'T') {
            Triangle* t = malloc(sizeof(Triangle));
            scanf("%lf %lf %lf", &t->a, &t->b, &t->c);
            t->base.perimeter = trianglePerimeter;
            t->base.area = triangleArea;
            shapes[i] = (Shape*)t;
        }
    }

    for (int i = 0; i < n; i++) {
        double p = shapes[i]->perimeter(shapes[i]);
        double a = shapes[i]->area(shapes[i]);
        printf("%.2f %.2f\n", p, a);
        totalPerimeter += p;
        totalArea += a;
    }

    printf("%.2f %.2f\n", totalPerimeter, totalArea);

    for (int i = 0; i < n; i++) {free(shapes[i]);}

    return 0;
}
