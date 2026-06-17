#include <iostream>
#include <array>
#include <string>

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

void printDeck(const std::array<Cards,52> &deck)
{
	for(auto &card : deck)
	{
		printCard(card);
		std::cout << "\n";
	}
}

void swapCard(Cards &card1,Cards &card2)
{
	std::swap(card1,card2);
}

int randomCard()
{
	return rand() % 52;
}

void shuffleDeck(std::array<Cards,52> &deck)
{
	int randomIndex = randomCard();

	for(int i = 1; i < 52; ++i)
	{
		swapCard(deck[i], deck[randomIndex]);
	}
}

int getCardValue(const Cards& card)
{
	switch(card.cardSuits)
	{
	case SUITS_CARD_RANK_2:     return 2;
	case SUITS_CARD_RANK_3:     return 3;
	case SUITS_CARD_RANK_4:     return 4;
	case SUITS_CARD_RANK_5:     return 5;
	case SUITS_CARD_RANK_6:     return 6;
	case SUITS_CARD_RANK_7:     return 7;
	case SUITS_CARD_RANK_8:     return 8;
	case SUITS_CARD_RANK_9:     return 9;
	case SUITS_CARD_RANK_10:    return 10;
	case SUITS_CARD_RANK_VALET: return 10;
	case SUITS_CARD_RANK_DAMA:  return 10;
	case SUITS_CARD_RANK_KOROL: return 10;
	case SUITS_CARD_RANK_TYZ:   return 11;

	default:
		std::cout << "Error";
		return 0;
	}
}

bool playBlackjack(const std::array<Cards,52> &deck)
{
	const Cards *ptrCard = &deck[0];

	int player{};
	int dealer{};

	dealer += getCardValue(*ptrCard++);

	player += getCardValue(*ptrCard++);
	player += getCardValue(*(ptrCard++));

	while(true)
	{

		bool isPlayerSrand = false;

		std::cout << "Hit or Stand? (h/s): ";

		std::string choose{};

		std::getline(std::cin, choose);

		if(choose == "h" || choose == "hit")
		{

			player += getCardValue(*ptrCard++);

		   std::cout << "score: " << player << '\n';
		}  
		else if (choose == "stand" || choose == "s"){

			std::cout << "you score: " << player << '\n';

			std::cout << "dealer score: " << dealer << '\n';

			isPlayerSrand = true;

			break;
		}

		if (player == 21)
		{
			std::cout << "You win!\n";
			break;
		}

		if (player > 21)
		{
			std::cout << "You lose!\nWin dealer";
			return false;		
		}


		if (dealer < 17)
			dealer += getCardValue(*ptrCard++);
		
		if (dealer > 21)
		{
			std::cout << "You win\n";
			return false;
		}

		if (dealer == 21)
		{
			std::cout << "you lose\nWin dealer\n";
			break;
		}

		if (isPlayerSrand)
		{
			if(player > dealer)
			{
				std::cout << "Player win\n";

				std::cout << "you score: " << player << '\n';
				std::cout << "dealer score: " << dealer << '\n';

				return false;
			}

			else if(player < dealer)
			{
				std::cout << "Player lose\nWin dealer\n";

				std::cout << "you score: " << player << '\n';
				std::cout << "dealer score: " << dealer << '\n';

				return false;
			}
			else
			{
				std::cout << "Draw\n";
			
				return false;
			}
		}
	}
	return true;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));

	std::array<Cards,52> deck;
	int card{};

	for(int i = 0; i < SUITS_MAX_SUITS; ++i)
	{
		for(int j = 0; j < DIGNITIES_CARD_MAX; ++j)
		{
			deck[card].cardSuits = static_cast<SuitsCard>(i);
			deck[card].cardDignies = static_cast<DignitiesCard>(j);
			++card;
		}
	}
	shuffleDeck(deck);
	playBlackjack(deck);

	return 0;
}
