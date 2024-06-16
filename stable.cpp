#include <iostream>
#include <cstring>
using namespace std;
int getSuitValue(char suit);
void selection_sort(Card* cards,int* num_cards);
bool compare_funtion(int* num1,int* num2);
struct Card{
    char suit;
    int value;
}
bool read_input(){
    int num_cards;
    cin >> num_cards;
    if (n< 1 || n > 36) return false;
    Card *cards = new Card[num_cards];
    for(int i = 0;i< num_cards; i++){
        char input[3];//i used 
        cin.get(input,3);
        cin.get();//removes new line
        cards.suit = input[0];
        cards.value = input[1] - '0';//coversion of char into integer!
    }

    
    delete[] *cards;
}
void selection_sort(Card* cards,int* num_cards){
    Card *selection_cards = new Card[*num_cards];
    for (int i = 0; i < *num_cards-1;i++){
        int min = i;
        for(int j = i+1;j<*num_cards;j++){
            if (cards[j].value == cards[j-1].value){
                int val1 = getSuitValue(cards[j].suit);
                int val2 = getSuitValue(cards[j-1].suit);
                if (val1 < val2) min = j;
            }
            if (cards[j].value < cards[j-1].value){
                min = j;
            }
        }
        if (min !=  i){
            
        }
    }

    delete[] *selection_cards;
}
int getSuitValue(char suit){
    switch(suit):
    case 'S': return 0;
    case 'H': return 1;
    case 'C': return 2;
    case 'D': return 3;
    default : return -1;
}
bool compare_funtion(int* num1,int* num2){
    if (num1 > num2) return true
    else return false;
}
int main(){
    return -1;
}