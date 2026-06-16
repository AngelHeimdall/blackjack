#include <iostream>
#include <array>

enum DignitiesCard
{
	DIGNITIES_CARD_SUIT_TREFU,
	DIGNITIES_CARD_SUIT_BYBNU,
	DIGNITIES_CARD_SUIT_CHERVU,
	DIGNITIES_CARD_SUIT_PIKI,
	DIGNITIES_CARD_MAX
};

enum SuitsCard
{
   	SUITS_CARD_RANK_2,
	SUITS_CARD_RANK_3,
	SUITS_CARD_RANK_4,
	SUITS_CARD_RANK_5,
	SUITS_CARD_RANK_6,
	SUITS_CARD_RANK_7,
	SUITS_CARD_RANK_8,
	SUITS_CARD_RANK_9,
	SUITS_CARD_RANK_10,
	SUITS_CARD_RANK_VALET,
	SUITS_CARD_RANK_DAMA,
	SUITS_CARD_RANK_KOROL,
	SUITS_CARD_RANK_TYZ,
	SUITS_MAX_SUITS
};


struct Cards
{
	DignitiesCard cardDignies;
	SuitsCard cardSuits;
};

void printCard(const Cards &card)
{

	switch(card.cardSuits)
	{
	case SUITS_CARD_RANK_2:
		std::cout << "2";
	break;
	
	case SUITS_CARD_RANK_3:
		std::cout << "3";
	break;

	case SUITS_CARD_RANK_4:
		std::cout << "4";
	break;

	case SUITS_CARD_RANK_5:
    	std::cout << "5";
	break;

	case SUITS_CARD_RANK_6:
		std::cout << "6";
	break;

	case SUITS_CARD_RANK_7:
		std::cout << "7";
		break;

	case SUITS_CARD_RANK_8:
		std::cout << "8";
	break;

	case SUITS_CARD_RANK_9:
		std::cout << "9";
	break;

	case SUITS_CARD_RANK_10:
		std::cout << "10";
	break;

	case SUITS_CARD_RANK_VALET:
    	std::cout << "Valet";
	break;

	case SUITS_CARD_RANK_DAMA:
		std::cout << "Dama";
	break;

	case SUITS_CARD_RANK_KOROL:
		std::cout << "Korol";
	break;

	case SUITS_CARD_RANK_TYZ:
		std::cout << "Tyz";
	break;

	default:
		std::cout << "Error";
	break;
	}

	switch(card.cardDignies)
	{

	case DIGNITIES_CARD_SUIT_TREFU:
		std::cout << "Trefu";
	break;

	case DIGNITIES_CARD_SUIT_BYBNU:
		std::cout << "Bybnu";
	break;

	case DIGNITIES_CARD_SUIT_CHERVU:
		std::cout << "Chervu";
	break;

	case DIGNITIES_CARD_SUIT_PIKI:
		std::cout << "Piki";
	break;

	default:
		std::cout << "Error";
	break;
	}
}

void printDeck(const std::array<Cards, 52> &deck)
{
	for (auto &card : deck)
	{
		printCard(card);
		std::cout << "\n";
	}
}

void swapCard(Cards &card1, Cards &card2)
{
	std::swap(card1, card2);
}

int randomCard()
{
	return rand() % 52;
}

void shuffleDeck(std::array<Cards, 52> &deck)
{

	int randomIndex = randomCard();

	for (int i = 1; i < 52; ++i)
	{
		swapCard(deck[i], deck[randomIndex]);
	}
}

int main()
{	
	srand(static_cast<unsigned int>(time(nullptr)));

	std::array<Cards, 52> deck;
	int card{};

	for (int i = 0; i < SUITS_MAX_SUITS; i++)
	{
		for (int j = 0; j < DIGNITIES_CARD_MAX; j++)
		{
			deck[card].cardSuits = static_cast<SuitsCard>(i);
			deck[card].cardDignies = static_cast<DignitiesCard>(j);
			++card;
		}	
	}

	printDeck(deck);
   	shuffleDeck(deck);
	printDeck(deck);

	return 0;
}