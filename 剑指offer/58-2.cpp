char* reverseLeftWords(char* s, int n){
    int len = strlen(s);
    char *p = (char*)malloc(sizeof(char)*len+1);
    strcpy(p, s+n);
    strncpy(p+len-n, s, n);
    p[len] = '\0';
    return p;
}
