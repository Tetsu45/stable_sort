#include <iostream>
#include <cstring>
using namespace std;

struct Card {
    char suit;
    int value;
};

Card* read_input(int* num_cards) {
    Card* cards = new Card[*num_cards];
    for (int i = 0; i < *num_cards; i++) {
        char input[3];
        cin.get(input, 3);
        cin.get(); // removes new line
        cards[i].suit = input[0];
        cards[i].value = input[1] - '0'; // conversion of char into integer
    }
    return cards;
}

bool is_stable(Card* cards1, Card* cards2, int num_cards) {
    int count[10] = {0};
    for (int k = 0; k < num_cards; k++) count[cards1[k].value]++;
    int index[10];
    for (int h = 0; h < 10; h++) index[h] = count[h];
    for (int z = 1; z < 10; z++) index[z] += index[z - 1];
    Card* temp = new Card[num_cards];
    for (int i = num_cards - 1; i >= 0; i--) {
        temp[index[cards2[i].value] - 1] = cards2[i];
        index[cards2[i].value]--;
    }

    bool stable = true;
    for (int i = num_cards-1; i >= 0; i--) {
        if (temp[i].value == temp[i + 1].value && temp[i].suit < temp[i + 1].suit) {
            stable = false;
            break;
        }
    }
    delete[] temp;
    return stable;
}

Card* bubble_sort(Card* cards, int num_cards) {
    Card* bubble_cards = new Card[num_cards];
    memcpy(bubble_cards, cards, num_cards * sizeof(Card));
    for (int ix = 0; ix < num_cards; ix++) {
        for (int jx = num_cards - 1; jx > ix; jx--) {
            if (bubble_cards[jx].value < bubble_cards[jx - 1].value) {
                Card temp = bubble_cards[jx];
                bubble_cards[jx] = bubble_cards[jx - 1];
                bubble_cards[jx - 1] = temp;
            }
        }
    }
    return bubble_cards;
}

Card* selection_sort(Card* cards, int num_cards) {
    Card* selection_cards = new Card[num_cards];
    memcpy(selection_cards, cards, num_cards * sizeof(Card));
    for (int i = 0; i < num_cards; i++) {
        int min_index = i;
        for (int j = i + 1; j < num_cards; j++) {
            if (selection_cards[j].value < selection_cards[min_index].value) {
                min_index = j;
            }
        }
        if (min_index != i) {
            Card temp = selection_cards[i];
            selection_cards[i] = selection_cards[min_index];
            selection_cards[min_index] = temp;
        }
    }
    return selection_cards;
}

int main() {
    int num_cards = 0;
    cin >> num_cards;
    if (num_cards < 1 || num_cards > 36) return -1;
    cin.ignore(); // to ignore the newline character after the number of cards input
    Card* cards = read_input(&num_cards);
    Card* bubble_sorted = bubble_sort(cards, num_cards);
    Card* selection_sorted = selection_sort(cards, num_cards);

    for (int i = 0; i < num_cards; i++) {
        if (i == num_cards - 1) {
            cout << bubble_sorted[i].suit << bubble_sorted[i].value << "\n";
        } else {
            cout << bubble_sorted[i].suit << bubble_sorted[i].value << " ";
        }
    }
    if (is_stable(cards, bubble_sorted, num_cards)) {
        cout << "Stable\n";
    } else {
        cout << "Not stable\n";
    }

    for (int i = 0; i < num_cards; i++) {
        if (i == num_cards - 1) {
            cout << selection_sorted[i].suit << selection_sorted[i].value << "\n";
        } else {
            cout << selection_sorted[i].suit << selection_sorted[i].value << " ";
        }
    }
    if (is_stable(cards, selection_sorted, num_cards)) {
        cout << "Stable\n";
    } else {
        cout << "Not stable\n";
    }

    delete[] cards;
    delete[] bubble_sorted;
    delete[] selection_sorted;
    return 0;
}
