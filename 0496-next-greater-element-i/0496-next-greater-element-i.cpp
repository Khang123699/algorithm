class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> res(nums1.size(), -1);
        int count=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    count=j;
                    for(count;count<nums2.size();count++){
                        if(nums2[count]>nums2[j]){
                            res[i]=nums2[count];
                            break;
                        }
                    }
                break;
                }
            }
        }
    return res;
    }
};