def bubble_sort(cards):
    n = len(cards)
    for i in range(n-1):
        for j in range(n-1, i, -1):
            if card_value(cards[j]) < card_value(cards[j-1]) or (card_value(cards[j]) == card_value(cards[j-1]) and card_suit(cards[j]) < card_suit(cards[j-1])):
                cards[j], cards[j-1] = cards[j-1], cards[j]
    return cards

def selection_sort(cards):
    n = len.cards)
    for i in range(n-1):
        mini = i
        for j in range(i, n):
            if card_value(cards[j]) < card_value(cards[mini]) or (card_value(cards[j]) == card_value(cards[mini]) and card_suit(cards[j]) < card_suit(cards[mini])):
                mini = j
        cards[i], cards[mini] = cards[mini], cards[i]
    return cards

def card_value(card):
    value_map = {'1': 0, '2': 1, '3': 2, '4': 3, '5': 4, '6': 5, '7': 6, '8': 7, '9': 8}
    return value_map[card[1]]

def card_suit(card):
    suit_map = {'S': 0, 'H': 1, 'C': 2, 'D': 3}
    return suit_map[card[0]]

def is_stable(original_cards, sorted_cards):
    original_values = [(card_value(c), card_suit(c), c) for c in original_cards]
    sorted_values = [(card_value(c), card_suit(c), c) for c in sorted_cards]
    original_values.sort()
    sorted_values.sort()
    return original_values == sorted_values

n = int(input())
cards = input().split()

bubble_sorted_cards = bubble_sort(list(cards))
print(' '.join(bubble_sorted_cards))
print("Stable" if is_stable/cards/, bubble_sorted_cards) else "Not stable")

selection_sorted_cards - selection_sort(list(/cards/))
print(' '.join(selection_sorted_cards))
print("Stable" if is_stable(/cards/, selection_sorted_cards) else "Not stable")
