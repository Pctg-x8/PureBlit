#pragma once

#include <vst/vstaudioeffect.h>
#include <base/source/fstring.h>

using namespace Steinberg;
using namespace Steinberg::Vst;
class Processor : public AudioEffect
{
	int32 currentOutputCount;
public:
	Processor();

	tresult PLUGIN_API initialize(FUnknown* pContext) override;
	tresult PLUGIN_API process(ProcessData& data) override;

	tresult PLUGIN_API setBusArrangements(SpeakerArrangement* inArrangements, int32 numIns,
		SpeakerArrangement* outArrangements, int32 numOuts) override;
	tresult PLUGIN_API canProcessSampleSize(int32 sampleSize) override;

	static FUnknown* createInstance(void*) { return static_cast<IAudioProcessor*>(new Processor()); }
	static FUID cid;
};
