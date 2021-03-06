// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "MovieScene.h"
#include "MovieScene3DConstraintTrack.h"
#include "MovieScene3DAttachTrack.generated.h"


/**
 * Handles manipulation of path tracks in a movie scene.
 */
UCLASS( MinimalAPI )
class UMovieScene3DAttachTrack
	: public UMovieScene3DConstraintTrack
{
	GENERATED_UCLASS_BODY()

public:

	// UMovieScene3DConstraintTrack interface

	virtual void AddConstraint( float Time, float ConstraintEndTime, const FName SocketName, const FGuid& ConstraintId ) override;

public:

	// UMovieSceneTrack interface

	virtual TSharedPtr<IMovieSceneTrackInstance> CreateInstance() override;

#if WITH_EDITORONLY_DATA
	virtual FText GetDisplayName() const override;
#endif
};
