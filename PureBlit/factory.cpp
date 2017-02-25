#include <main/pluginfactoryvst3.h>
#include "processor.h"
#include "controller.h"
#include <windows.h>

#define pluginName "PureBlit"
constexpr auto Version = "1.0.0";

BEGIN_FACTORY_DEF("Clouds Terminal 2", "http://cterm2.s601.xrea.com", "mailto:Syn.Tri.Naga@gmail.com")
	DEF_CLASS2(INLINE_UID_FROM_FUID(Processor::cid), PClassInfo::kManyInstances, kVstAudioEffectClass,
		pluginName, Vst::kDistributable, PlugType::kInstrumentSynth, Version, kVstVersionString, Processor::createInstance)
	DEF_CLASS2(INLINE_UID_FROM_FUID(Controller::cid), PClassInfo::kManyInstances, kVstComponentControllerClass,
		pluginName " Controller", 0, "", Version, kVstVersionString, Controller::createInstance)
END_FACTORY

bool InitModule() { return true; }
bool DeinitModule() { return true; }
