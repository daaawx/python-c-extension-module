#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    FILE* fp = fopen("write.txt", "w");
    fputs("Python!", fp);
    fclose(fp);
    return 1;
}
