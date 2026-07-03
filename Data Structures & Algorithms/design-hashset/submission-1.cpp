#include<vector>
#include<algorithm>
using namespace std;
class MyHashSet {
    vector<long long> arr;
    bool binarySearch(vector<long long> &arr, int s, int e,int key){
        int mid = (s+e)/2;

        while(s<=e){
            if(arr[mid] == key ){
                return true;
            }
            else if(key < arr[mid]){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return false;
    }
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        arr.push_back(key);
    }
    
    void remove(int key) {
        if(arr.empty()){
            return;
        }
        else{

        arr.erase(std::remove(arr.begin(),arr.end(),key),arr.end());
        }
    }
    
    bool contains(int key) {
        if(arr.empty()){
            return false;
        }
        // int s = 0;
        // int e = this->arr.size()-1;
        // return binarySearch(this->arr,s,e,key);

        auto it = std::find(arr.begin(), arr.end(), key);    
        if(it !=arr.end()){
            return true;
        }    
        else{
            return false;
        }
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */