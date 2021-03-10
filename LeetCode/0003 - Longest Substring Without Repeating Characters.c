
int max(int a, int b) {
    return (a > b ? a : b);
}
int lengthOfLongestSubstring(char * s){
    int n = strlen(s);
    int occ[256];
    memset(occ, 0, sizeof(occ));
    int ans = 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (occ[s[i]]) {
            --occ[s[j++]];
        }
        occ[s[i]]++;
        ans = max(ans, i - j + 1);
    }
    return ans;
}