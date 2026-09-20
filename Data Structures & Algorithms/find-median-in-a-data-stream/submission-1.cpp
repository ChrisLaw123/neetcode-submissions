class MedianFinder {
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (nums.size() == 0) {
            nums.push_back(num);
            return;
        }
        for(int i{}; i < nums.size(); i++) {
            if(num < nums[i]) {
                nums.insert(nums.begin() + i, num);
                return;
            }
        }
        nums.push_back(num);
    }
    
    double findMedian() {
        int size = nums.size();
        if (size == 0) return 0;
        double res{};
        
        if (size % 2 == 0) {
            res = (nums[size/2] +nums[(size/2) - 1]) /2.0;
            return res;
        } 
        res = nums[size/2];
        return res;
    }

    vector<int> nums;
};
