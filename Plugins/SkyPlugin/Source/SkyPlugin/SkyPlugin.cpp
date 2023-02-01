// Copyright Epic Games, Inc. All Rights Reserved.

#include "SkyPlugin.h"

#define LOCTEXT_NAMESPACE "FSkyPluginModule"

void FSkyPluginModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	const FString ShaderDirectory = FPaths::Combine(FPaths::ProjectPluginsDir(), TEXT("/SkyPlugin/Shaders"));
	AddShaderSourceDirectoryMapping("/SkyPlugin/Shaders", ShaderDirectory);
}

void FSkyPluginModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	ResetAllShaderSourceDirectoryMappings();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSkyPluginModule, SkyPlugin)