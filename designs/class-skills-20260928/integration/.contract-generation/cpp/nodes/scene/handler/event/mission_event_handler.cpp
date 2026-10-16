#include "mission_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void MissionEventHandler::Register()
{
    tlsEcs.dispatcher.sink<AcceptMissionEvent>().connect<&MissionEventHandler::AcceptMissionEventHandler>();
    tlsEcs.dispatcher.sink<ConditionEvent>().connect<&MissionEventHandler::ConditionEventHandler>();
    tlsEcs.dispatcher.sink<OnAcceptedMissionEvent>().connect<&MissionEventHandler::OnAcceptedMissionEventHandler>();
    tlsEcs.dispatcher.sink<OnMissionAwardEvent>().connect<&MissionEventHandler::OnMissionAwardEventHandler>();
}

void MissionEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<AcceptMissionEvent>().disconnect<&MissionEventHandler::AcceptMissionEventHandler>();
    tlsEcs.dispatcher.sink<ConditionEvent>().disconnect<&MissionEventHandler::ConditionEventHandler>();
    tlsEcs.dispatcher.sink<OnAcceptedMissionEvent>().disconnect<&MissionEventHandler::OnAcceptedMissionEventHandler>();
    tlsEcs.dispatcher.sink<OnMissionAwardEvent>().disconnect<&MissionEventHandler::OnMissionAwardEventHandler>();
}
void MissionEventHandler::AcceptMissionEventHandler(const AcceptMissionEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void MissionEventHandler::ConditionEventHandler(const ConditionEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void MissionEventHandler::OnAcceptedMissionEventHandler(const OnAcceptedMissionEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void MissionEventHandler::OnMissionAwardEventHandler(const OnMissionAwardEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
