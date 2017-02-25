#include "controller.h"

// {F63449DD-D231-4382-8E99-46EEACC075D0}
FUID Controller::cid(0xf63449dd, 0x4382d231, 0xee46998e, 0xd075c0ac);

tresult Controller::initialize(FUnknown* pContext)
{
	auto res = EditController::initialize(pContext);
	if (res != kResultTrue) return res;
	Parameter* param;
	param = new RangeParameter(L"Osc1 Output Multiplier", PBParameter::Osc1OutMult, L"%", 0.0, 200.0, 100.0);
	param->setPrecision(1);
	this->parameters.addParameter(param);
	param = new RangeParameter(L"Osc2 Output Multiplier", PBParameter::Osc2OutMult, L"%", 0.0, 200.0, 100.0);
	param->setPrecision(1);
	this->parameters.addParameter(param);
	return kResultTrue;
}
