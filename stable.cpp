#include <iostream>
#include <cstring>
using namespace std;
struct Card{
    char suit;
    int value;
}
int* read_input(int* num_cards){
    Card *cards = new Card[*num_cards];
    for(int i = 0;i< *num_cards; i++){
        char input[3];
        cin.get(input,3);
        cin.get();//removes new line
        cards.suit = input[0];
        cards.value = input[1] - '0';//coversion of char into integer!
    } 
    return cards;
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
    return 0;
}