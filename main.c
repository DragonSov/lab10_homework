#include <stdio.h>
#include <locale.h>
#define _USE_MATH_DEFINES
#include <math.h>

float area_rhomboid(float a, float b, double phi1_deg, double phi2_deg) {
    double phi1 = phi1_deg * M_PI / 180.0;
    double phi2 = phi2_deg * M_PI / 180.0;

    double s1 = 0.5 * a * a * sin(phi1);
    double s2 = 0.5 * b * b * sin(phi2);

    return (float)(s1 + s2);
}

void print_definition_rhomboid(void) {
    printf("Ромбойд — фигура, состоящая из двух равнобедренных треугольников,\n");
    printf("соединённых основаниями. Верхний треугольник имеет стороны a и угол φ1,\n");
    printf("нижний — стороны b и угол φ2. Фигура симметрична относительно вертикальной оси.\n\n");
}

void draw_rhomboid(int a, int b, double phi1_deg, double phi2_deg, char ch) {
    double phi1 = phi1_deg * M_PI / 180.0;
    double phi2 = phi2_deg * M_PI / 180.0;

    double k1 = tan((phi1 / 2.0));
    double k2 = tan((phi2 / 2.0));

    int max_width1 = 2 * (int)round((a - 1) * k1) + 1;
    int max_width2 = 2 * (int)round((b - 1) * k2) + 1;
    int max_width = (max_width1 > max_width2) ? max_width1 : max_width2;

    for (int y = 0; y < a; ++y) {
        int half = (int)round(y * k1);
        int width = 2 * half + 1;
        int spaces = (max_width - width) / 2;

        for (int i = 0; i < spaces; ++i) putchar(' ');
        for (int i = 0; i < width; ++i) putchar(ch);
        putchar('\n');
    }

    for (int y = 0; y < b; ++y) {
        int half = (int)round((b - 1 - y) * k2);
        int width = 2 * half + 1;
        int spaces = (max_width - width) / 2;

        for (int i = 0; i < spaces; ++i) putchar(' ');
        for (int i = 0; i < width; ++i) putchar(ch);
        putchar('\n');
    }
}

int main(void) {
    setlocale(LC_CTYPE, "RUS");

    int choice;
    do {
        printf("=== МЕНЮ ДЛЯ ФИГУРЫ: РОМБОЙД ===\n");
        printf("1) Рассчитать площадь\n");
        printf("2) Вывести определение фигуры\n");
        printf("3) Нарисовать фигуру\n");
        printf("0) Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);

        if (choice == 1) {
            float a, b;
            double phi1, phi2;

            printf("\n--- Площадь ромбоида ---\n");
            printf("Введите a (длина боковых сторон верхнего треугольника): ");
            scanf("%f", &a);
            printf("Введите b (длина боковых сторон нижнего треугольника): ");
            scanf("%f", &b);
            printf("Введите угол φ1 (вершина верхнего треугольника, градусы): ");
            scanf("%lf", &phi1);
            printf("Введите угол φ2 (вершина нижнего треугольника, градусы): ");
            scanf("%lf", &phi2);

            float s = area_rhomboid(a, b, phi1, phi2);
            printf("Площадь ромбоида S = %.3f\n\n", s);
        }
        else if (choice == 2) {
            printf("\n--- Определение фигуры ---\n");
            print_definition_rhomboid();
        }
        else if (choice == 3) {
            int a, b;
            double phi1, phi2;
            char ch;

            printf("\n--- Рисование ромбоида ---\n");
            printf("Введите символ заполнения фигуры: ");
            scanf(" %c", &ch);  // пробел перед %c, чтобы съесть '\n'

            printf("Введите a (высота верхней части, целое > 0): ");
            scanf("%d", &a);

            printf("Введите b (высота нижней части, целое > 0): ");
            scanf("%d", &b);

            printf("Введите угол 1 (угол вершины верхней части, в градусах): ");
            scanf("%lf", &phi1);

            printf("Введите угол 2 (угол вершины нижней части, в градусах): ");
            scanf("%lf", &phi2);

            draw_rhomboid(a, b, phi1, phi2, ch);
            printf("\n");
        }
        else if (choice != 0) {
            printf("Неизвестный пункт меню, попробуйте ещё раз.\n\n");
        }

    } while (choice != 0);

    printf("Выход из программы.\n");
    return 0;
}
