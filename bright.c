#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

char* ENV_BRIGHTNESS_BACKEND = "BRIGHT_BACKEND";
char* BACKLIGHT_PATH = "/sys/class/backlight";
char* DEFAULT_BACKEND = "intel_backlight";

int get_brightness(char* backend, char* file) {
    size_t len = strlen(BACKLIGHT_PATH) + 1 + strlen(backend) + 1 + strlen(file);
    char filename[len];
    sprintf(filename, "%s/%s/%s", BACKLIGHT_PATH, backend, file);

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

void set_brightness(char* backend, char* file, int brightness) {
    size_t len = strlen(BACKLIGHT_PATH) + 1 + strlen(backend) + 1 + strlen(file);
    char filename[len];
    sprintf(filename, "%s/%s/%s", BACKLIGHT_PATH, backend, file);

    FILE *fp = fopen(filename, "a");
    if (fp == NULL) {
        fprintf(stderr, "Cannot write brightness to file: %s\n", filename);
        exit(1);
    }
    fprintf(fp, "%d", brightness);
    fclose(fp);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Expected an argument specifying an increment\n");
        exit(1);
    }

    char* backend = getenv(ENV_BRIGHTNESS_BACKEND);
    if (!backend) {
        backend = DEFAULT_BACKEND;
    }

    int current_brightness = get_brightness(backend, "brightness");
    int max_brightness = get_brightness(backend, "max_brightness");

    char c = argv[1][0];
    double increment = atof(argv[1]) / 100 * max_brightness + 0.5;
    int brightness = c == '+' || c == '-' ?
        current_brightness + increment : increment;

    if (brightness < 0) brightness = 0;
    else if (brightness > max_brightness) brightness = max_brightness;
    double percent = 100.0 * brightness / max_brightness;

    set_brightness(backend, "brightness", brightness);

    printf("%.0f%%\n", percent);
    return 0;
}
