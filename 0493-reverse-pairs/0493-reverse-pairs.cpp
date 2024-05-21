#define ll long long
class Solution {
public:

    
    int countRev(vector<int> &v, int si, int mid, int ei){

        int j = mid+1;
        int ct = 0;
        for(int i = si; i <= mid; i++){
            while( j <= ei && v[i] > 2*1ll*v[j]){
                j++;
            }
            ct += j-(mid+1);
        }
        return ct;
    }

    void merge(vector<int> &v, int si, int mid, int ei){
        int i = si, j = mid+1, k = 0;
        vector<int> temp(ei-si+1);

        while(i <= mid && j <= ei){
            if(v[i] <= v[j]){
                temp[k++] = v[i++];
            }
            else{
                temp[k++] = v[j++];
            }
        }

        while(i <= mid){
            temp[k++] = v[i++];
        }
        while(j <= ei){
            temp[k++] = v[j++];
        }

        for(int i = si, k = 0; k <= ei-si; i++,k++){
            v[i] = temp[k];
        }

    }

    int mergeSort(vector<int> &v, int si, int ei){
        int ct = 0;
        if(si >= ei)return ct;
        int mid = si + (ei-si)/2;
        
        ct += mergeSort(v,si,mid);
        ct += mergeSort(v,mid+1,ei);

        ct += countRev(v,si,mid,ei);
        merge(v,si,mid,ei);

        return ct;
    }
    int reversePairs(vector<int>& nums) {
        int x = mergeSort(nums,0,nums.size()-1);
       
        return x;
    }
};