
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define HTTP_UNAUTHORIZED      401 /* auth needed, respond with auth hdr */
#define HTTP_NOT_IMPLEMENTED   501 /* used for unrecognized requests */
#define HTTP_FORBIDDEN         403


#ifdef CONFIG_FEATURE_HTTPD_CGI
static const char request_GET[] = "GET";
#endif

void sendHeaders(int responseNum)
{
  #ifdef CONFIG_LFS
  long total = 10L;
  #else
  int total = 10;
  #endif
  assert(sizeof(total)==sizeof(int));
  printf("%d\r\n", total); //ERROR
}

void handleIncoming(const char *request)
{
#ifdef CONFIG_FEATURE_HTTPD_BASIC_AUTH
  int random = 1;//rand() % 79;
  int http_unauthorized = random;

  if (http_unauthorized) {
    sendHeaders(HTTP_UNAUTHORIZED);
  }
#endif

#ifdef CONFIG_FEATURE_HTTPD_CGI
  if (request != request_GET) {
    sendHeaders(HTTP_NOT_IMPLEMENTED);
  }
#endif
}

int main(int argc, char** argv)
{
  const char request[] = "POST";
  handleIncoming(request);
  return 0;
}
