#include <random>
#include "Liquid.hh"
#include "Air.hh"
#include "TextureManager.hh"

Liquid::Liquid() : 
	Element(0, TextureManager::get("water"))
{

}

unsigned char Liquid::getId()
{
	return ID;
}

void Liquid::handle(unsigned x, unsigned y, Board* board)
{
	Element& up = board->get(x, y - 1);
	Element& down = board->get(x, y + 1);
	Element& left = board->get(x - 1, y);
	Element& right = board->get(x + 1, y);
	Element& downLeft = board->get(x - 1, y + 1);
	Element& downRight = board->get(x + 1, y + 1);

	auto mLeftAir = [&]() -> bool {
		// Move Left
		if (left.getId() == Air::ID) {
			board->set(x, y, &left);
			board->set(x - 1, y, this);
			return true;
		}
		return false;
	};

	auto mRightAir = [&]() -> bool {
		// Move Right
		if (right.getId() == Air::ID) {
			board->set(x, y, &right);
			board->set(x + 1, y, this);
			return true;
		}
		return false;
	};

	auto mDownLeftAir = [&]() -> bool {
		// Move Down Left Air
		if (left.getId() == Air::ID && downLeft.getId() == Air::ID) {
			board->set(x, y, &downLeft);
			board->set(x - 1, y + 1, this);
			return true;
		}
		return false;
	};
	auto mDownRightAir = [&]() -> bool {
		// Move Down Right Air
		if (right.getId() == Air::ID && downRight.getId() == Air::ID) {
			board->set(x, y, &downRight);
			board->set(x + 1, y + 1, this);
			return true;
		}
		return false;
	};
	auto mDownLeftLiquid = [&]() -> bool {
		// Move Down Left Liquid
		if (left.getId() == Air::ID && downLeft.getId() == Liquid::ID) {
			board->set(x, y, &left);
			board->set(x - 1, y, this);
			return true;
		}
		return false;
	};

	auto mDownRightLiquid = [&]() -> bool {
		// Move Down Right Liquid
		if (right.getId() == Air::ID && downRight.getId() == Liquid::ID) {
			board->set(x, y, &right);
			board->set(x + 1, y, this);
			return true;
		}
		return false;
	};

	// Move Down
	if (down.getId() == Air::ID) {
		board->set(x, y, &down);
		board->set(x, y + 1, this);
	}
	else {
		std::random_device rd;
		std::minstd_rand e1(rd());
		std::uniform_int_distribution<int> uniform_dist(0, 1);
		int r = uniform_dist(e1);

		switch (r)
		{
		case 0:
			if (!mDownLeftAir())
				if (!mDownLeftLiquid())
					if (!mDownRightAir())
						if (!mDownRightLiquid())
							if (!mLeftAir())
								if(!mRightAir());

			break;
		case 1:
			if (!mDownRightAir())
				if (!mDownRightLiquid())
					if (!mDownLeftAir())
						if (!mDownLeftLiquid())
							if (!mRightAir())
								mLeftAir();
			break;
		}
	}

	// Set Pression
	unsigned char p = 0;
	p = left.getPression() > right.getPression() ? left.getPression() : right.getPression();
	p = up.getPression() > p ? up.getPression() : p;
	this->setPression(p);
}