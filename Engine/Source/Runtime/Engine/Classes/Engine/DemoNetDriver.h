// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "DemoNetDriver.generated.h"

/**
 * Simulated network driver for recording and playing back game sessions.
 */
UCLASS(transient, config=Engine)
class UDemoNetDriver
	: public UNetDriver
{
	GENERATED_UCLASS_BODY()

	/** Name of the file to read/write from */
	FString DemoFilename;

	/** Current record/playback frame number */
	int32 DemoFrameNum;

	/** Last time (in real seconds) that we recorded a frame */
	double LastRecordTime;

	/** Total time of demo in seconds */
	float DemoTotalTime;

	/** Current record/playback position in seconds */
	float DemoCurrentTime;

	/** Total number of frames in the demo */
	int32 DemoTotalFrames;

	/** True if we're in the middle of recording a frame */
	bool bIsRecordingDemoFrame;

	/** True if we are at the end of playing a demo */
	bool bDemoPlaybackDone;

	/** True if as have paused all of the channels */
	bool bChannelsArePaused;

	/** This is our spectator controller that is used to view the demo world from */
	APlayerController* SpectatorController;

	UPROPERTY(config)
	FString DemoSpectatorClass;

	/** Our network replay streamer */
	TSharedPtr< class INetworkReplayStreamer > ReplayStreamer;

	uint32 GetDemoCurrentTimeInMS() { return (uint32)( (double)DemoCurrentTime * 1000 ); }

	/** Internal debug timing/tracking */
	double		AccumulatedRecordTime;
	double		LastRecordAvgFlush;
	double		MaxRecordTime;
	int32		RecordCountSinceFlush;
	float		TimeToSkip;

	bool		bSavingCheckpoint;
	double		LastCheckpointTime;

	void		SaveCheckpoint();

private:
	bool		bIsFastForwarding;

public:

	// UNetDriver interface.

	virtual bool InitBase( bool bInitAsClient, FNetworkNotify* InNotify, const FURL& URL, bool bReuseAddressAndPort, FString& Error ) override;
	virtual void FinishDestroy() override;
	virtual FString LowLevelGetNetworkNumber() override;
	virtual bool InitConnect( FNetworkNotify* InNotify, const FURL& ConnectURL, FString& Error ) override;
	virtual bool InitListen( FNetworkNotify* InNotify, FURL& ListenURL, bool bReuseAddressAndPort, FString& Error ) override;
	virtual void TickDispatch( float DeltaSeconds ) override;
	virtual void TickFlush( float DeltaSeconds ) override;
	virtual void ProcessRemoteFunction( class AActor* Actor, class UFunction* Function, void* Parameters, struct FOutParmRec* OutParms, struct FFrame* Stack, class UObject* SubObject = nullptr );
	virtual bool IsAvailable() const override { return true; }
	ENGINE_API void SkipTime(float InTimeToSkip);
	bool InitConnectInternal( FString& Error );
	virtual bool ShouldClientDestroyTearOffActors() const;

public:

	// FExec interface

	virtual bool Exec( UWorld* InWorld, const TCHAR* Cmd, FOutputDevice& Ar ) override;

public:

	/** @todo document */
	bool UpdateDemoTime( float* DeltaTime, float TimeDilation );

	/** Called when demo playback finishes, either because we reached the end of the file or because the demo spectator was destroyed */
	void DemoPlaybackEnded();

	/** @return true if the net resource is valid or false if it should not be used */
	virtual bool IsNetResourceValid(void) { return true; }

	void TickDemoRecord( float DeltaSeconds );
	void PauseChannels( const bool bPause );
	bool ConditionallyReadDemoFrame();
	bool ReadDemoFrame( FArchive* Archive );
	void TickDemoPlayback( float DeltaSeconds );
	void SpawnDemoRecSpectator( UNetConnection* Connection );
	void ResetDemoState();

	void StopDemo();

	void ReplayStreamingReady( bool bSuccess, bool bRecord );
	void CheckpointReady( bool bSuccess );
};
