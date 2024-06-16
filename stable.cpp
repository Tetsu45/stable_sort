#include <iostream>
#include <cstring>

using namespace std;

struct Card {
    char suit;
    int value;
};

Card* read_input(int& num_cards) {
    cin >> num_cards;
    if (num_cards < 1 || num_cards > 36) {
        return nullptr;
    }
    Card* cards = new Card[num_cards];
    for (int i = 0; i < num_cards; i++) {
        char input[3];
        cin.get(input, 3);
        cin.get(); // Remove the newline character
        cards[i].suit = input[0];
        cards[i].value = input[1] - '0'; // Convert character to integer
    }
    return cards;
}

bool is_stable(Card* cards, Card* sorted_cards, int num_cards) {
    bool stable = true;
    for (int i = 0; i < num_cards - 1; i++) {
        if (sorted_cards[i].value == sorted_cards[i + 1].value) {
            if (cards[i].suit > cards[i + 1].suit) {
                stable = false;
                break;
            }
        }
    }
    return stable;
}

void bubble_sort(Card* cards, int num_cards) {
    for (int i = 0; i < num_cards; i++) {
        for (int j = num_cards - 1; j >= i + 1; j--) {
            if (cards[j].value < cards[j - 1].value) {
                Card temp = cards[j - 1];
                cards[j - 1] = cards[j];
                cards[j] = temp;
            }
        }
    }
}

void selection_sort(Card* cards, int num_cards) {
    for (int i = 0; i < num_cards - 1; i++) {
        int min = i;
        for (int j = i + 1; j < num_cards; j++) {
            if (cards[j].value < cards[min].value) {
                min = j;
            }
        }
        if (min != i) {
            Card temp = cards[min];
            cards[min] = cards[i];
            cards[i] = temp;
        }
    }
}

int main() {
    int num_cards;
    Card* cards = read_input(num_cards);
    if (cards == nullptr) {
        cout << "Invalid input!" << endl;
        return -1;
    }

    Card* bubble_sorted = new Card[num_cards];
    Card* selection_sorted = new Card[num_cards];
    memcpy(bubble_sorted, cards, num_cards * sizeof(Card));
    memcpy(selection_sorted, cards, num_cards * sizeof(Card));

    bubble_sort(bubble_sorted, num_cards);
    selection_sort(selection_sorted, num_cards);

    for (int i = 0; i < num_cards; i++) {
        if (i == num_cards - 1) {
            cout << bubble_sorted[i].suit << bubble_sorted[i].value << endl;
        } else {
            cout << bubble_sorted[i].suit << bubble_sorted[i].value << " ";
        }
    }

    if (is_stable(cards, bubble_sorted, num_cards)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    for (int i = 0; i < num_cards; i++) {
        if (i == num_cards - 1) {
            cout << selection_sorted[i].suit << selection_sorted[i].value << endl;
        } else {
            cout << selection_sorted[i].suit << selection_sorted[i].value << " ";
        }
    }

    if (is_stable(cards, selection_sorted, num_cards)) {
        cout << "Stable" << endl;
    } else {
        cout << "Not stable" << endl;
    }

    delete[] cards;
    delete[] bubble_sorted;
    delete[] selection_sorted;

    return 0;
}