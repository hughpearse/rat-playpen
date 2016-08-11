#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include <string.h>

size_t function_pt(void *ptr, size_t size, size_t nmemb, void *stream){
    printf("%s", ptr);
    printf("\n");
    return size * nmemb;
}

int main(void)
{
  CURL *curl;
  CURLcode res;
 
  curl = curl_easy_init();
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org?format=txt");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, function_pt);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n", 
              curl_easy_strerror(res));
    curl_easy_cleanup(curl);
  }
  return 0;
}

