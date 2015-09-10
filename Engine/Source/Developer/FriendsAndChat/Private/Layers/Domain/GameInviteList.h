// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "IFriendList.h"

/**
 * Class containing the friend information - used to build the list view.
 */
class FGameInviteList
	: public TSharedFromThis<FGameInviteList>
	, public IFriendList
{
};

/**
 * Creates the implementation for an FFriendInviteList.
 *
 * @return the newly created FFriendInviteList implementation.
 */
FACTORY(TSharedRef< FGameInviteList >, FGameInviteList,
	const TSharedRef<class IFriendViewModelFactory>& FriendViewModelFactory,
	const TSharedRef<class FGameAndPartyService> & GamePartyInviteService);