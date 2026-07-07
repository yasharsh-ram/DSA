int strStr(char* haystack, char* needle) {
    int i = 0;
    while (haystack[i] != '\0') {
        int j = 0;
        int k = i;
        while(needle[j]!= '\0' && haystack[k] == needle[j]){
            k++;
            j++;
        }
        if (needle[j] == '\0')
            return i;
        i++;
    }
    return -1;
}
