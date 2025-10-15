#include <stdio.h>

#include <entry.h>

int create_application(application* out_app) {
    printf("create_application() callback\n");
}

int initialize_application(application* app) {
    printf("initialize_application() callback\n");
}

int main(void) {
    application app_inst;

    create_application(&app_inst);

    initialize_application(&app_inst);

    return 0;
}