class Solution {
    public static boolean binarysearch(int arr[],int m){
        int j=0;
        int k=arr.length-1;
        while(j<=k){
            int mid=(j+k)/2;
            if(mid!=m && arr[mid]==2*arr[m]){
                return true;
            }
            else if(arr[mid]>2*arr[m]){
                k=mid-1;
            }
            else{
                j=mid+1;
            }
        }
        return false;

    }
    public boolean checkIfExist(int[] arr) {
        Arrays.sort(arr);
        int n=arr.length;
        for(int i=0;i<n;i++){
            if(binarysearch(arr,i)){
                return true;
            }
        }
        return false;
    }
}