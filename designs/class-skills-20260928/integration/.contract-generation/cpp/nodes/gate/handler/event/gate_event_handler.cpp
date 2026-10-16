#include "gate_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void GateEventHandler::Register()
{
    tlsEcs.dispatcher.sink<contracts::kafka::RoutePlayerEvent>().connect<&GateEventHandler::RoutePlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::KickPlayerEvent>().connect<&GateEventHandler::KickPlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PlayerDisconnectedEvent>().connect<&GateEventHandler::PlayerDisconnectedEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PlayerLeaseExpiredEvent>().connect<&GateEventHandler::PlayerLeaseExpiredEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BindSessionEvent>().connect<&GateEventHandler::BindSessionEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::RedirectToGateEvent>().connect<&GateEventHandler::RedirectToGateEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PushToPlayerEvent>().connect<&GateEventHandler::PushToPlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToPlayersEvent>().connect<&GateEventHandler::BroadcastToPlayersEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToSceneEvent>().connect<&GateEventHandler::BroadcastToSceneEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToAllEvent>().connect<&GateEventHandler::BroadcastToAllEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BindBattleEvent>().connect<&GateEventHandler::BindBattleEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::UnbindBattleEvent>().connect<&GateEventHandler::UnbindBattleEventHandler>();
}

void GateEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<contracts::kafka::RoutePlayerEvent>().disconnect<&GateEventHandler::RoutePlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::KickPlayerEvent>().disconnect<&GateEventHandler::KickPlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PlayerDisconnectedEvent>().disconnect<&GateEventHandler::PlayerDisconnectedEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PlayerLeaseExpiredEvent>().disconnect<&GateEventHandler::PlayerLeaseExpiredEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BindSessionEvent>().disconnect<&GateEventHandler::BindSessionEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::RedirectToGateEvent>().disconnect<&GateEventHandler::RedirectToGateEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::PushToPlayerEvent>().disconnect<&GateEventHandler::PushToPlayerEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToPlayersEvent>().disconnect<&GateEventHandler::BroadcastToPlayersEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToSceneEvent>().disconnect<&GateEventHandler::BroadcastToSceneEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BroadcastToAllEvent>().disconnect<&GateEventHandler::BroadcastToAllEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::BindBattleEvent>().disconnect<&GateEventHandler::BindBattleEventHandler>();
    tlsEcs.dispatcher.sink<contracts::kafka::UnbindBattleEvent>().disconnect<&GateEventHandler::UnbindBattleEventHandler>();
}
void GateEventHandler::RoutePlayerEventHandler(const contracts::kafka::RoutePlayerEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::KickPlayerEventHandler(const contracts::kafka::KickPlayerEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::PlayerDisconnectedEventHandler(const contracts::kafka::PlayerDisconnectedEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::PlayerLeaseExpiredEventHandler(const contracts::kafka::PlayerLeaseExpiredEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::BindSessionEventHandler(const contracts::kafka::BindSessionEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::RedirectToGateEventHandler(const contracts::kafka::RedirectToGateEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::PushToPlayerEventHandler(const contracts::kafka::PushToPlayerEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::BroadcastToPlayersEventHandler(const contracts::kafka::BroadcastToPlayersEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::BroadcastToSceneEventHandler(const contracts::kafka::BroadcastToSceneEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::BroadcastToAllEventHandler(const contracts::kafka::BroadcastToAllEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::BindBattleEventHandler(const contracts::kafka::BindBattleEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void GateEventHandler::UnbindBattleEventHandler(const contracts::kafka::UnbindBattleEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
