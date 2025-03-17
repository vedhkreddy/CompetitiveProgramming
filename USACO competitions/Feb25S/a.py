import os

def compareCards(card1, card2):
    if len(card1) == 1:
        if card1 in card2:
            return True
        return False
    if len(card2) == 1:
        if card2 in card1:
            return True
        return False

    same = 0
    if card1[0] == card2[0]:
        same += 1
    if card1[1] == card2[1]:
        same += 1
    if card1[2] == card2[2]:
        same += 1

    return same == 2

def checkGame(p1, p2, hand):
    for card in hand:
        if compareCards(p1, card) or compareCards(p2, card):
            return False
    return True

def printResult(piles, hand, drawPile):
    p1, p2 = piles.split(" ")
    hand = hand.split(" ")
    drawPile = drawPile.split(" ")

    gameOver = False

    while not gameOver:
        possible = True
        pile = 0

        while possible:
            print(f"{p1} {p2} {hand}")
            foundCard = False

            for i in range(len(hand)):
                if compareCards(p1, hand[i]) and (pile == 1 or pile == 0):
                    foundCard = True
                    p1 = hand[i]
                    pile = 1
                    hand.pop(i)
                    break

                if compareCards(p2, hand[i]) and (pile == 2 or pile == 0):
                    foundCard = True
                    p2 = hand[i]
                    pile = 2
                    hand.pop(i)
                    break

            if not foundCard:
                possible = False

        if len(drawPile) == 0 or len(hand) == 7:
            gameOver = True

        print(f"Drawing... from {drawPile}")

        while len(hand) < 7 and len(drawPile) > 0:
            card = drawPile.pop(0)
            hand.append(card)

        print(f"{p1} {p2} {hand}")

    return f"{len(hand)} {p1} {p2}"

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')
    piles = input()
    hand = input()
    drawPile = input()
    result = printResult(piles, hand, drawPile)
    fptr.write(result + '\n')
    fptr.close()
