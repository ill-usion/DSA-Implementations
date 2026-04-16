#include <stdio.h>
#include <stdlib.h>

void draw_mark(int height) {
    for (int i = 0; i < height; i++)
        printf(" ̅");
    printf("\n");
}

void draw_ruler(int height) {
    if (height == 0)
        return;

    draw_ruler(height - 1);
    draw_mark(height);
    draw_ruler( height - 1);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("%s height\n", argv[0]);
        return 1;
    }
    
    int height = atoi(argv[1]);
    draw_ruler(height);

    return 0;
}
