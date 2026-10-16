#include "battle_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void BattleEventHandler::Register()
{
    tlsEcs.dispatcher.sink<BattleSettlementEvent>().connect<&BattleEventHandler::BattleSettlementEventHandler>();
    tlsEcs.dispatcher.sink<BattleConfirmedEvent>().connect<&BattleEventHandler::BattleConfirmedEventHandler>();
}

void BattleEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<BattleSettlementEvent>().disconnect<&BattleEventHandler::BattleSettlementEventHandler>();
    tlsEcs.dispatcher.sink<BattleConfirmedEvent>().disconnect<&BattleEventHandler::BattleConfirmedEventHandler>();
}
void BattleEventHandler::BattleSettlementEventHandler(const BattleSettlementEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
void BattleEventHandler::BattleConfirmedEventHandler(const BattleConfirmedEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
