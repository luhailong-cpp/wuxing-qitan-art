#include "player_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void PlayerEventHandler::Register()
{
    tlsEcs.dispatcher.sink<RegisterPlayerEvent>().connect<&PlayerEventHandler::RegisterPlayerEventHandler>();
    tlsEcs.dispatcher.sink<PlayerUpgradeEvent>().connect<&PlayerEventHandler::PlayerUpgradeEventHandler>();
    tlsEcs.dispatcher.sink<InitializePlayerCompsEvent>().connect<&PlayerEventHandler::InitializePlayerCompsEventHandler>();
    tlsEcs.dispatcher.sink<PlayerLoginEvent>().connect<&PlayerEventHandler::PlayerLoginEventHandler>();
}

void PlayerEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<RegisterPlayerEvent>().disconnect<&PlayerEventHandler::RegisterPlayerEventHandler>();
    tlsEcs.dispatcher.sink<PlayerUpgradeEvent>().disconnect<&PlayerEventHandler::PlayerUpgradeEventHandler>();
    tlsEcs.dispatcher.sink<InitializePlayerCompsEvent>().disconnect<&PlayerEventHandler::InitializePlayerCompsEventHandler>();
    tlsEcs.dispatcher.sink<PlayerLoginEvent>().disconnect<&PlayerEventHandler::PlayerLoginEventHandler>();
}
void PlayerEventHandler::RegisterPlayerEventHandler(const RegisterPlayerEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void PlayerEventHandler::PlayerUpgradeEventHandler(const PlayerUpgradeEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void PlayerEventHandler::InitializePlayerCompsEventHandler(const InitializePlayerCompsEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void PlayerEventHandler::PlayerLoginEventHandler(const PlayerLoginEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
