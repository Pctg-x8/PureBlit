#pragma once

#include <vst/vsteditcontroller.h>
#include <vst/vstaudioeffect.h>
#include <base/source/fstring.h>

enum PBParameter
{
	Osc1OutMult, Osc2OutMult
};

using namespace Steinberg;
using namespace Steinberg::Vst;
class Controller : public EditController
{
public:
	tresult PLUGIN_API initialize(FUnknown* pContext) override;
	// tresult PLUGIN_API createView(FIDString name);
	
	static FUnknown* createInstance(void*) { return static_cast<IEditController*>(new Controller()); }
	static FUID cid;
};
