// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// void print_black_cells(const char *df_expr, int *index, int x, int y, int size) {
//     char current_char = df_expr[*index];
//     (*index)++; // Move to the next character in the DF expression for the next call or action

//     if (current_char == '0') {
//         // If the current section is all white, do nothing.
//         return;
//     } else if (current_char == '1') {
//         // If the current section is all black, print all the cells in this section.
//         for (int i = x; i < x + size; i++) {
//             for (int j = y; j < y + size; j++) {
//                 printf("%d,%d\n", i, j);
//             }
//         }
//     } else if (current_char == '2') {
//         // If the section is mixed, divide it into 4 sub-sections and process each.
//         int half_size = size / 2;
//         print_black_cells(df_expr, index, x, y, half_size); // Top-left
//         print_black_cells(df_expr, index, x, y + half_size, half_size); // Top-right
//         print_black_cells(df_expr, index, x + half_size, y, half_size); // Bottom-left
//         print_black_cells(df_expr, index, x + half_size, y + half_size, half_size); // Bottom-right
//     }
// }

// void encode(const char *df_expr, int width) {
//     int index = 0;
//     if (df_expr[index] == '0') {
//         printf("all white\n");
//         return;
//     } else {
//         print_black_cells(df_expr, &index, 0, 0, width);
//     }
// }

// int main() {
//     char str[101]; // Adjusted the size to 101 to account for the null terminator
//     int width;
//     scanf("%100s", str); // Ensure we do not read more than 100 characters, to avoid buffer overflow
//     scanf("%d", &width);

//     encode(str, width);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

// 坐标结构体
typedef struct {
    int x;
    int y;
} Coordinate;

// 全局变量来存储坐标和坐标的数量
Coordinate coordinates[64]; // 最大可能的坐标数为8x8的矩阵
int coord_count = 0;

// 用于qsort的比较函数
int compare_coordinates(const void* a, const void* b) {
    Coordinate *coord_a = (Coordinate *)a;
    Coordinate *coord_b = (Coordinate *)b;
    if (coord_a->x == coord_b->x) return coord_a->y - coord_b->y;
    return coord_a->x - coord_b->x;
}

// 递归打印黑色单元格的函数
void print_black_cells(const char *df_expr, int *index, int x, int y, int size) {
    char current_char = df_expr[*index];
    (*index)++;

    if (current_char == '0') {
        // 全白
        return;
    } else if (current_char == '1') {
        // 全黑，记录坐标
        for (int i = x; i < x + size; i++) {
            for (int j = y; j < y + size; j++) {
                coordinates[coord_count++] = (Coordinate){i, j};
            }
        }
    } else if (current_char == '2') {
        // 混合，递归处理四个子区域
        int half_size = size / 2;
        print_black_cells(df_expr, index, x, y, half_size);
        print_black_cells(df_expr, index, x, y + half_size, half_size);
        print_black_cells(df_expr, index, x + half_size, y, half_size);
        print_black_cells(df_expr, index, x + half_size, y + half_size, half_size);
    }
}

void encode(const char *df_expr, int width) {
    int index = 0;
    coord_count = 0; // 重置坐标计数

    if (df_expr[index] == '0') {
        printf("all white\n");
        return;
    } else {
        print_black_cells(df_expr, &index, 0, 0, width);
        // 对坐标排序
        qsort(coordinates, coord_count, sizeof(Coordinate), compare_coordinates);
        // 打印排序后的坐标
        for (int i = 0; i < coord_count; i++) {
            printf("%d,%d\n", coordinates[i].x, coordinates[i].y);
        }
    }
}

int main() {
    char str[101];
    int width;
    scanf("%100s", str);
    scanf("%d", &width);

    encode(str, width);

    return 0;
}
