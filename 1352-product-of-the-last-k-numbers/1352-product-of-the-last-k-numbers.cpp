class ProductOfNumbers {
public:
    vector<int> arr;
    int lst = -1, prod = 1;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            prod = 1;
            arr.push_back(0);
            lst = arr.size()-1;
            return;
        }
        prod = prod * num;
        arr.push_back(prod);
    }
    
    int getProduct(int k) {
        int rem = arr.size() - lst;
        if(k >= rem)
            return 0;
        if(lst + rem - k - 1 < 0 || arr[lst + rem - k - 1] == 0)
            return arr.back();
        return (arr.back() / arr[lst + rem - k - 1]); 
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */