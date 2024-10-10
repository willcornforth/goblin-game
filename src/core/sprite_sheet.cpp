#include "sprite_sheet.hpp"
#include "animation.hpp"

int SpriteSheet::GetRowForAnimActivity(AnimationActivity act)
{
	if (animMapping.empty()) {
		return -1;
	}

	const auto row = animMapping.find(act);

	if (row == animMapping.end()) {
		return -1;
	}

	return row->second;
}
