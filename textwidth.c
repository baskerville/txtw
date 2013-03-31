#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <cairo/cairo.h>
#include "textwidth.h"

int text_width(char *font_family, int font_size, char *s) {
    cairo_surface_t *surface = cairo_image_surface_create(CAIRO_FORMAT_RGB24, 1, 1);
    cairo_t *cr = cairo_create(surface);
    cairo_text_extents_t te;
    cairo_select_font_face(cr, font_family, CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
    cairo_set_font_size(cr, font_size);
    cairo_text_extents(cr, s, &te);
    int width = te.x_advance;
    cairo_destroy(cr);
    cairo_surface_destroy(surface);
    return width;
}

int main(int argc, char *argv[]) {
    char font_family[MAXLEN] = FONT_FAMILY;
    int font_size = FONT_SIZE;
    char opt;

    while ((opt = getopt(argc, argv, "hvf:s:")) != -1) {
        switch (opt) {
            case 'h':
                printf("textwidth [-h|-v|-f FONT|-s SIZE] STRING ...\n");
                return EXIT_SUCCESS;
                break;
            case 'v':
                printf("%s\n", VERSION);
                return EXIT_SUCCESS;
                break;
            case 'f':
                strncpy(font_family, optarg, sizeof(font_family));
                font_family[MIN(sizeof(font_family), strlen(optarg))] = '\0';
                break;
            case 's':
                font_size = atoi(optarg);
                break;
        }
    }

    int num = argc - optind;
    char **args = argv + optind;

    for (int i = 0; i < num; i++)
        printf("%i%s", text_width(font_family, font_size, args[i]), i < (num - 1) ? " " : "\n");

    return EXIT_SUCCESS;
}
