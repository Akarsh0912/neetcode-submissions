class Solution {
public:
    int findMax(vector<int>& arr){
        int maxi = INT_MIN;
        int n = arr.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
        }
        return maxi;
    }
    
    int calculateTotalHour(vector<int>& arr,int hourly){
        int totalHour = 0;
        int n = arr.size();
        for(int i=0;i<n;i++){
            totalHour = totalHour + ceil((double)arr[i] / (double)hourly);
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high = findMax(piles);
        int ans = 0;

        while(low<=high){
            int mid = low + (high-low)/2;

            int value = calculateTotalHour(piles,mid);
            
            if(value <= h){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }

        }
        return ans;
    }
};
