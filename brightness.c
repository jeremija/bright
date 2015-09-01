#include <stdlib.h>
#include <stdio.h>

char* BRIGHTNESS = "/sys/class/backlight/intel_backlight/brightness";
char* MAX_BRIGHTNESS = "/sys/class/backlight/intel_backlight/max_brightness";


int get_brightness(char* filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't read brightness from file: %s\n", filename);
        exit(1);
    }
    char brightness_chars[10];
    fscanf(fp, "%s", brightness_chars);
    fclose(fp);
    int brightness = atoi(brightness_chars);
    return brightness;
}

void set_brightness(int brightness) {
    FILE *fp = fopen(BRIGHTNESS, "w");
    if (fp == NULL) {
        fprintf(stderr, "Cannot write brightness to file: %s\n", BRIGHTNESS);
        exit(1);
    }
    fprintf(fp, "%d", brightness);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    printf("arg0: %s\n", argv[0]);

    if (argc < 2) {
        fprintf(stderr, "Expected an argument specifying an increment");
        exit(1);
    }

    int increment = atoi(argv[1]);

    int current_brightness = get_brightness(BRIGHTNESS);
    int max_brightness = get_brightness(MAX_BRIGHTNESS);

    int current_percent = 100 * current_brightness / max_brightness;

    int next_percent = current_percent + increment;
    if (next_percent < 0) next_percent = 0;
    else if (next_percent > 100) next_percent = 100;

    int next_brightness = next_percent * max_brightness / 100;

    printf("current brightness: %d\n", current_brightness);
    printf("next brightness: %d\n", next_brightness);

    set_brightness(next_brightness);

    return 0;
}
