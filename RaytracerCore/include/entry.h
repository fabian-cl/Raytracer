#pragma once

typedef struct application
{
    const char* name;
} application;

typedef enum APPLICATION_STATUS_CODE {
    APP_STATUS_OK = 0,
    APP_STATUS_ERR,
    APP_STATUS_COULD_NOT_CREATE,
    APP_STATUS_COULD_NOT_INITIALIZE,
} APPLICATION_STATUS_CODE;

#if !defined (USE_OWN_MAIN)

extern int create_application(application* out_app);

extern int initialize_application(application* app);

int main(void) {
    application app_inst;

    create_application(&app_inst);

    initialize_application(&app_inst);

    // run

    return 0;
}

#else
#pragma message("OWN MAIN")
#endif