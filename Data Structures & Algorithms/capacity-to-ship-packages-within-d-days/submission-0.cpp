class Solution {
public:
    int findLoad(vector<int>& arr,int cap){
        int days=1;
        int load=0;

        for(int i=0;i<arr.size();i++){
            if(arr[i] + load > cap){
                days++;
                load = arr[i];
            }
            else{
                load = load + arr[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high = accumulate(weights.begin(),weights.end(),0);

        while(low <= high){
            int mid = low + (high-low)/2;

            int totalDays = findLoad(weights,mid);

            if(totalDays <= days){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;

    }
};