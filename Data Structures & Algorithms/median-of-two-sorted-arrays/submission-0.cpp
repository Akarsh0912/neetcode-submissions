class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> tempArray;

        for(auto num : nums1){
            tempArray.push_back(num);
        }

        for(auto num : nums2){
            tempArray.push_back(num);
        }
        sort(tempArray.begin(),tempArray.end());

        int size = tempArray.size();

        if(size % 2 ==0){
            float low = 0;
            float high = tempArray.size()-1;
            cout<<"HIGH=="<<tempArray.size()-1<<endl;
            cout<<"MID VALUE==="<<(low + (high-low)/2.0)<<endl;
            cout<<"EVEN INDEX==="<<floor(low + (high-low)/2.0)<<endl;
            cout<<"ODD EVEN===="<<ceil(low + (high-low)/2.0)<<endl;
            float even = tempArray[floor(low + (high-low)/2.0)];
            cout<<"Even Value--"<<even<<endl;
            float odd = tempArray[ceil(low + (high-low)/2.0)];
            cout<<"ODD Value==="<<odd<<endl;

            double ans = (even+odd)/2.0;
            cout<<"ANSWER=="<<ans<<endl;
            return ans;
            
        }
        else{
            int low = 0;
            int high = tempArray.size()-1;
            int mid = low + (high-low) /2;
            double ans = tempArray[mid];
            return ans;
        }
    }
};
