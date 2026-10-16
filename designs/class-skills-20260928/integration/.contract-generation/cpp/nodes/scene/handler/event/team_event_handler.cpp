#include "team_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void TeamEventHandler::Register()
{
    tlsEcs.dispatcher.sink<PlayerTeamRefreshEvent>().connect<&TeamEventHandler::PlayerTeamRefreshEventHandler>();
}

void TeamEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<PlayerTeamRefreshEvent>().disconnect<&TeamEventHandler::PlayerTeamRefreshEventHandler>();
}
void TeamEventHandler::PlayerTeamRefreshEventHandler(const PlayerTeamRefreshEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
