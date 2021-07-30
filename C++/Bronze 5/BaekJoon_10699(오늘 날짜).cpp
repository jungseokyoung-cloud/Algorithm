#include <iostream>
#include <ctime>
char* timeToString(struct tm *t);
int main(void) {
    struct tm *t;
    time_t timer;
    timer = time(NULL);
    t = localtime(&timer);
    printf("%s\n", timeToString(t));
    return 0;
}
char* timeToString(struct tm *t) {
    static char s[20];
    sprintf(s, "%04d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
    return s;
}
