#include "Sand.hh"
#include "TextureManager.hh"

Sand::Sand() : 
	Element(0, TextureManager::get("sand"))
{

}

unsigned char Sand::getId()
{
	return Elements::SAND;
}

void Sand::handle(unsigned x, unsigned y, Board* board)
{
	Element& down = board->get(x, y + 1);
	Element& left = board->get(x - 1, y);
	Element& right = board->get(x + 1, y);
	Element& downLeft = board->get(x - 1, y + 1);
	Element& downRight = board->get(x + 1, y + 1);

	// Move Down Left
	auto mDownLeftAir = [&]() -> bool {
		if ((left.getId() == Elements::AIR || left.getId() == Elements::LIQUID) &&
			(downLeft.getId() == Elements::AIR || downLeft.getId() == Elements::LIQUID))
		{
			board->set(x, y, &downLeft);
			board->set(x - 1, y + 1, this);
			return true;
		}
		return false;
	};
	// Move Down Right
	auto mDownRightAir = [&]() -> bool {
		if ((right.getId() == Elements::AIR || right.getId() == Elements::LIQUID) &&
			(downRight.getId() == Elements::AIR || downRight.getId() == Elements::LIQUID))
		{
			board->set(x, y, &downRight);
			board->set(x + 1, y + 1, this);
			return true;
		}
		return false;
	};

	// Move Down
	if (down.getId() == Elements::AIR || (down.getId() == Elements::LIQUID && !board->isUsed(x, y + 1))) {
		board->set(x, y, &down);
		board->set(x, y + 1, this);
	}
	else {
		unsigned char r = rand() & 1;
		switch (r)
		{
		case 0:
			if (!mDownLeftAir())
				mDownRightAir();
			break;
		case 1:
			if (!mDownRightAir())
				mDownLeftAir();
			break;
		}
	}
}