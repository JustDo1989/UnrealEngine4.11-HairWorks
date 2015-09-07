// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "GeometryCacheEdModulePublicPCH.h"
#include "GeometryCacheEdModule.h"
#include "IAssetTools.h"
#include "ComponentAssetBroker.h"
#include "AssetTypeActions_GeometryCache.h"
#include "GeometryCacheAssetBroker.h"
#include "GeometryCacheComponent.h"

IMPLEMENT_MODULE(FGeometryCacheEdModule, GeometryCacheEd)

void FGeometryCacheEdModule::StartupModule()
{
	FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();

	IAssetTools& AssetTools = AssetToolsModule.Get();
	AssetAction = new FAssetTypeActions_GeometryCache();
	AssetTools.RegisterAssetTypeActions(MakeShareable(AssetAction));

	AssetBroker = new FGeometryCacheAssetBroker();
	FComponentAssetBrokerage::RegisterBroker(MakeShareable(AssetBroker), UGeometryCacheComponent::StaticClass(), true, true);
}

void FGeometryCacheEdModule::ShutdownModule()
{
	if (UObjectInitialized())
	{
		FAssetToolsModule& AssetToolsModule = FAssetToolsModule::GetModule();
		IAssetTools& AssetTools = AssetToolsModule.Get();
		AssetTools.UnregisterAssetTypeActions(AssetAction->AsShared());
		FComponentAssetBrokerage::UnregisterBroker(MakeShareable(AssetBroker));
	}
}