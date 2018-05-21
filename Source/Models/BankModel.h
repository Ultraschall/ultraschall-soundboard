#pragma once

#include "JuceHeader.h"
#include "Identifier.h"

struct BankModel
{
public:
	BankModel(ValueTree v)
		: state(v)
	{
		jassert(v.hasType(IDs::BANK));

		uuid.referTo(state, IDs::bank_uuid, nullptr);
		title.referTo(state, IDs::bank_title, nullptr);
	}

	ValueTree state;
	CachedValue<String> uuid;
	CachedValue<String> title;
};