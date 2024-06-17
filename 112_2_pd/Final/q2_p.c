#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define PI 4

#define shapeText(TYPE) char name[10]; \
    int (*perimeter)(struct TYPE*); \
    int (*area)(struct TYPE*); 
typedef struct shape_s {  shapeText(shape_s); } shape_t; 

typedef struct circle_s { 
       shapeText(circle_s); 
       int radius; 
} circle_t; 
typedef struct rectangle_s 
{ 
    shapeText(rectangle_s); 
      int width, height; 
} rectangle_t; 
typedef struct square_s{ 
 shapeText(square_s); 
       int side; 
} square_t; 
typedef struct triangle_s { 
       shapeText(triangle_s); 
       int s1, s2, s3; 
} triangle_t; 

int circlePerimiter(circle_t *c){return c->radius*2*PI;}
int circleArea(circle_t *c){return c->radius*c->radius*PI;}
int rectanglePerimiter(rectangle_t *r){return 2*(r->height+r->width);}
int rectangleArea(rectangle_t *r){return r->height*r->width;}
int squarePerimiter(square_t *s){return s->side*4;}
int squareArea(square_t *s){return s->side*s->side;}
int trianglePerimiter(triangle_t *t){return t->s1 + t->s2 + t->s3;}
int triangleArea(triangle_t *t){
    int s = (t->s1 + t->s2 + t->s3)/2;
    return sqrt(s * (s - t->s1) * (s - t->s2) * (s - t->s3));
}

shape_t* newShape(char *name){
    if(strcmp(name, "circle") == 0){
        circle_t *c = (circle_t *)malloc(sizeof(circle_t));
        strcpy(c->name, name);
        c->perimeter = circlePerimiter;
        c->area = circleArea;
        return (shape_t *)c;
    }
    else if(strcmp(name, "rectangle") == 0){
        rectangle_t *r = (rectangle_t *)malloc(sizeof(rectangle_t));
        strcpy(r->name, name);
        r->perimeter = rectanglePerimiter;
        r->area = rectangleArea;
        return (shape_t *)r;
    }
    else if(strcmp(name, "square") == 0){
        square_t *s = (square_t *)malloc(sizeof(square_t));
        strcpy(s->name, name);
        s->perimeter = squarePerimiter;
        s->area = squareArea;
        return (shape_t *)s;
    }
    else if(strcmp(name, "triangle") == 0){
        triangle_t *t = (triangle_t *)malloc(sizeof(triangle_t));
        strcpy(t->name, name);
        t->perimeter = trianglePerimiter;
        t->area = triangleArea;
        return (shape_t *)t;
    }
}

void printShape(shape_t *shapes[], int num){
    int perimeter = 0, area = 0;
    for(int i=0; i<num; i++){
        printf("%s %d %d\n", shapes[i]->name, shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
        perimeter += shapes[i]->perimeter(shapes[i]);
        area += shapes[i]->area(shapes[i]);
    }
    printf("%d %d", perimeter, area);
}

void sortShape(shape_t *shapes[], int num){
    for(int i=0; i<num-1; i++){
        for(int j=0; j<num-i-1; j++){
            if(shapes[j]->perimeter(shapes[j]) < shapes[j+1]->perimeter(shapes[j+1]) ||
            (shapes[j]->perimeter(shapes[j]) == shapes[j+1]->perimeter(shapes[j+1]) && shapes[j]->area(shapes[j]) == shapes[j+1]->area(shapes[j+1]))){
                shape_t *temp = shapes[j];
                shapes[j] = shapes[j+1];
                shapes[j+1] = temp;
            }
        }
    }
}



void main(){
    int num;
    scanf("%d", &num);
    shape_t *shape[num];
    for(int i=0; i<num; i++){
        char type[10];
        scanf("%s", type);
        shape[i] = newShape(type);
        if(shape[i]){
            if(strcmp(type, "triangle") == 0){
                triangle_t *t = (triangle_t *)shape[i];
                scanf("%d %d %d", &t->s1, &t->s2, &t->s3);
            }else if(strcmp(type, "circle") == 0){
                circle_t *c = (circle_t *)shape[i];
                scanf("%d", &c->radius);
            }else if(strcmp(type, "rectangle") == 0){
                rectangle_t *r = (rectangle_t *)shape[i];
                scanf("%d %d", &r->height, &r->width);
            }else if(strcmp(type, "square") == 0){
                square_t *s = (square_t *)shape[i];
                scanf("%d", &s->side);
            }
        }
    }
    sortShape(shape, num);
    printShape(shape, num);
}