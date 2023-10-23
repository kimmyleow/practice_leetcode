int maxArea(int* height, int heightSize){
    int i = 0;
    int j = heightSize - 1;
    int area = 0;

    while(j>i){
        area = j - i * fmax(height[i], height[j]);
    }

}