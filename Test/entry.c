#include <entry.h>

#include <stdio.h>

int create_application(application* out_app) {
    printf("Create application\n");
    return APP_STATUS_OK;
}

int initialize_application(application* app) {
    printf("Initialize application\n");
    return APP_STATUS_OK;
}
/**
int main (void) {
    printf("Hello world!");
    return 0;
}*/