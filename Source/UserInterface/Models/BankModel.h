#pragma once

#include "JuceHeader.h"
#include "../../Store/Identifier.h"

struct BankModel
{
  public:
	BankModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::BANK));

		id.referTo(state, IDs::bank_id, nullptr);
		title.referTo(state, IDs::bank_title, nullptr);
	}

	ValueTree state;
	CachedValue<String> id;
	CachedValue<String> title;
};
