class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int firstRectLeft = rec1[0];
        int firstRectBottom = rec1[1];
        int firstRectRight = rec1[2];
        int firstRectTop = rec1[3];
        int secondRectLeft = rec2[0];
        int secondRectBottom = rec2[1];
        int secondRectRight = rec2[2];
        int secondRectTop = rec2[3];
        bool hasHorizontalOverlap = min(firstRectRight, secondRectRight) > max(firstRectLeft, secondRectLeft);
        bool hasVerticalOverlap = min(firstRectTop, secondRectTop) > max(firstRectBottom, secondRectBottom);
        return hasHorizontalOverlap && hasVerticalOverlap;
    }
};