class Solution {
public:
    int trap(vector<int>& height) {
        int totalWater = 0,i = 0,maxHeight = -1,maxHeightIndex = -1,localMaxHeight = -1;
        for(;i<height.size();i++)
        {
            if(maxHeight<height[i])
            {
                maxHeight = height[i];
                maxHeightIndex = i;
            }
        }
         i = 0;
        while(i<maxHeightIndex)
        {
             if(localMaxHeight<height[i])
            {
                localMaxHeight = height[i];
            }
            else
            {
                totalWater +=localMaxHeight-height[i];
            }
            i++;
        }
         i = height.size()-1;
        localMaxHeight = -1;
        while(i>maxHeightIndex)
        {
             if(localMaxHeight<height[i])
            {
                localMaxHeight = height[i];
            }
            else
            {
                totalWater +=localMaxHeight-height[i];
            }
            i--;
        }
        return totalWater;

	}
}