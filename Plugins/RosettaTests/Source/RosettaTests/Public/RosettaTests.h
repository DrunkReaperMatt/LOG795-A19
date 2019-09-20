#pragma once

#include "ModuleManager.h"

class RosettaTestsImpl : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	void StartupModule();
	void ShutdownModule();
};