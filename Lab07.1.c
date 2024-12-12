#include <stdio.h>
#include <math.h>

double func(double x) {
    return sin(x) + 0.5 * x * x;
}

int main() {
    double x_start = -1.0, x_end = 1.0, step = 0.2;
    int n = (int)((x_end - x_start) / step) + 1;
    double x, y_prev, y, y_next, integral_rect = 0.0, integral_trap = 0.0;

    printf("x: ");
    for (int i = 0; i < n; i++) {
        x = x_start + i * step;
        y = func(x);

        printf("%.2f ", x);  
        if (i > 0) {
            integral_rect += y_prev * step;
            integral_trap += (y_prev + y) * step / 2;
            if (i < n - 1) { 
                y_next = func(x + step);
                if (y > y_prev && y > y_next) printf("\nMax at x=%.2f, y=%.4f", x, y);
                if (y < y_prev && y < y_next) printf("\nMin at x=%.2f, y=%.4f", x, y);
            }
        }
        y_prev = y;
    }

    printf("\nIntegral (Rectangles) = %.4f\n", integral_rect);
    printf("Integral (Trapezoids) = %.4f\n", integral_trap);

    return 0;
}