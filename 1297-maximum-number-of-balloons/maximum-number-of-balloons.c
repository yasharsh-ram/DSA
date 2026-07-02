int maxNumberOfBalloons(char* text) {
    int freq[26] = {0};
    for (int i = 0; text[i] != '\0'; i++) {
        freq[text[i] - 'a']++;
    }
    char target[] = "balloon";
    int need[26] = {0};
    for (int i = 0; target[i] != '\0'; i++) {
        need[target[i] - 'a']++;
    }
    int ans = 10000;
    for (int i = 0; i < 26; i++) {
        if (need[i] > 0) {
            if (freq[i] / need[i] < ans) {
                ans = freq[i] / need[i];
            }
        }
    }
    return ans;
}