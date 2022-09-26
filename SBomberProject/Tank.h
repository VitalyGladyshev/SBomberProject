#pragma once

#include <stdint.h>
#include <vector>
#include <string>

#include "Mediator.h"

#include "DestroyableGroundObject.h"

class Tank : public DestroyableGroundObject
{
public:
	Tank(Mediator* _pMed, std::string _sMessage);

	bool __fastcall isInside(double x1, double x2) const override;

	inline uint16_t GetScore() const override { return score; }

	void Draw() const override;

	Mediator* pMediator;

private:

	const uint16_t score = 30;

	std::string sMessage;
	std::vector<std::string> vecMessages;
};

