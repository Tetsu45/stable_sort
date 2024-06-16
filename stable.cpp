#include <iostream>
#include <cstring>
using namespace std;
struct Card{
    char suit;
    int value;
};
Card* read_input(int* num_cards){
    Card *cards = new Card[*num_cards];
    for(int i = 0;i< *num_cards; i++){
        char input[3];
        cin.get(input,3);
        cin.get();//removes new line
        cards[i].suit = input[0];
        cards[i].value = input[1] - '0';//coversion of char into integer!
    } 
    return cards;
}
is_stable(Card* cards1,Card* cards2,int* num_cards){
    int count[10] = {0};
    for(int k = 0; k <*num_cards;k++) count[cards1[i].value]++;
    int index[10];
    for(int h = 0; h<10;k++) index[h] = count[h];
    for(int z = i; z <10;z++) index[z] = index[z-1];
    Card *temp =  new Card[*num_cards];
    for (int i = *num_cards - 1; i >= 0; i--) {
        temp[index[cards2[i].value] - 1] = cards[i];
        index[cards2[i]]--;
    }

    bool stable = true;
    for (int i = 0; i < n - 1; i++) {
        if (temp[i].value == temp[i + 1].value && temp[i].suit < temp[i + 1].suit) {
            stable = false;
            break;
        }
    }
    delete[] temp;
    return stable;
}
int* bubble_cards(Card *cards,int* num_cards){
    Card* bubble_cards = new Card[*num_cards];
    for (int ix = 0; ix < *num_cards; ix++) {
    for (int jx = *num_cards - 1; jx >= ix + 1; jx--) {
        if (arr[jx].value < arr[jx - 1].value) {
            int temp = arr[jx - 1];
            arr[jx - 1] = arr[jx];
            arr[jx] = temp;
        }
    }
}
bubble_cards = cards;
return bubble_cards
}
int* selection_cards(Card *cards,int* num_cards){
    Card* selection_cards = new Card[*num_cards];
    for(int i = 0;i < *num_cards ; i++){
        int min = i;
        for(int j = i+1;j<*num_cards;j++){
            if(cards[j].value < cards[j-1].value ){
                min = j;
            }
            if (min != i){
                Card temp = cards[min];
                cards[min] = cards[j-1];
                cards[j-1] = temp;
            }
        }
    }
    selection_cards = cards;
    return  selection_cards;
}
int main(){
    int num_cards = 0
    cin >> num_cards;
    if (n< 1 || n > 36) return -1;
    int* cards = read_input(&num_cards);
    int* orginal = cards;
    int* select_sorted =  selection_cards(cards,&num_cards);
    int* bubble_sorted = bubble_cards(cards,&num_cards);
    for(int hx = 0; hx < num_cards;hx++){
        if(hx == num_cards-1){
            cout << bubble_sorted[hx] << "\n";
        }
        else cout << bubble_sorted[hx] << " ";
    }
    if (is_stable(cards,bubble_sorted,&num_cards)){
        cout << "Stable" << "\n";
    }
    else cout << "Not stable" << "\n";
    for (int ex = 0; ex < num_cards;ex++){
        if(ex == num_cards-1) cou << select_sorted[ex] << "\n";
        else cout << select_sorted[ex] << " ";
    }
    if (is_stable(cards,bubble_sorted,&num_cards)){
        cout << "Stable" << "\n";
    }
    else cout << "Not stable" << "\n";
    delete[] cards;
    delete[] orginal;
    delete[] select_sorted;
    delete[] bubble_sorted;
    return 0;
}