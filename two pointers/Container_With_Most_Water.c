static inline int max_v(int a, int b) {
    return a > b ? a : b;
}

static inline int calArea(int *height, int l, int r) {
    return (r-l)*min_v(height[l], height[r]);
}

int maxArea(int* height, int heightSize) {
    int l, r, area;
    int max = 0;
    
    l = 0; 
    r = heightSize-1;
    while (l < r) {
        max = max_v(calArea(height, l, r), max);
        if (height[l] < height[r])
            l++;
        else
            r--;
    }
    return max;
}

/*
int maxArea_bruteForce(int* height, int heightSize) {
    int l, r, i, j;
    int max = 0;
    
    for (i = 0; i < heightSize-1; i++) {
        for (j = i+1; j < heightSize; j++) {
            int area = calArea(height, i, j);
            
            if (area > max)
                max = area;
        }
    }
    
    return max;
}
*/