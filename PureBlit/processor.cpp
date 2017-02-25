#include "processor.h"
#include "controller.h"
#include <functional>
#include <windows.h>

template<typename T> constexpr auto inRange(T from, T val, T to) { return from <= val && val <= to; }
template<typename T> constexpr auto forall(const T* ptr, size_t count, std::function<bool(const T&)> pred)
{
	for (size_t n = 0; n < count; n++) if (!pred(ptr[n])) return false;
	return true;
}

// {53765069-7E13-48E6-ABD9-13E1CA26BFFD}
FUID Processor::cid(0x53765069, 0x48e67e13, 0xe113d9ab, 0xfdbf26ca);

Processor::Processor()
{
	this->setControllerClass(Controller::cid);
}
tresult Processor::initialize(FUnknown* pContext)
{
	auto res = AudioEffect::initialize(pContext);
	if (res != kResultTrue) return res;
	this->addEventInput(L"Note Events", 1);
	this->addAudioOutput(L"Oscillator 1", SpeakerArr::kStereo);
	this->addAudioOutput(L"Oscillator 2", SpeakerArr::kStereo);
	this->currentOutputCount = 2;
	return kResultTrue;
}
tresult Processor::setBusArrangements(SpeakerArrangement* inArrangements, int32 numIns, SpeakerArrangement* outArrangements, int32 numOuts)
{
	if (numIns == 0 && inRange<int32>(1, numOuts, 2) &&
		forall<SpeakerArrangement>(outArrangements, numOuts, [](const SpeakerArrangement& arr) { return arr == SpeakerArr::kStereo; }))
	{
		auto res = AudioEffect::setBusArrangements(inArrangements, numIns, outArrangements, numOuts);
		if (res != kResultTrue) return res;
		this->currentOutputCount = numOuts;
		return kResultTrue;
	}
	else return kResultFalse;
}
tresult Processor::canProcessSampleSize(int32 sampleSize)
{
	return sampleSize == kSample32 || sampleSize == kSample64 ? kResultTrue : kResultFalse;
}
tresult Processor::process(ProcessData& data)
{
	if (data.numOutputs > 0)
	{
		for (auto n = 0; n < this->currentOutputCount; n++)
		{
			data.outputs[n].silenceFlags = 0x11;
		}
	}
	return kResultTrue;
}
