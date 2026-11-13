class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        deque<int> dq;
        dq.push_front(deck.back());
        for(int i = n-2; i >= 0; --i){
            for(int j = 0; j < dq.size()-1; ++j){
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
            }
            dq.push_front(deck[i]);
        }
        int i = 0;
        while(!dq.empty()){
            deck[i++] = dq.front();
            dq.pop_front(); 
        }
        return deck;
    }
};