// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once
#include "BehaviorTreeFactory.generated.h"

UCLASS()
class UBehaviorTreeFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

	// UFactory interface
	virtual UObject* FactoryCreateNew(UClass* Class,UObject* InParent,FName Name,EObjectFlags Flags,UObject* Context,FFeedbackContext* Warn) override;
	virtual bool CanCreateNew() const override;
	// End of UFactory interface
};



