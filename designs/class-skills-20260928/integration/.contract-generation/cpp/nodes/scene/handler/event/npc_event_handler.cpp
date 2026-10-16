#include "npc_event_handler.h"
#include "thread_context/ecs_context.h"

///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
void NpcEventHandler::Register()
{
    tlsEcs.dispatcher.sink<InitializeNpcCompsEvent>().connect<&NpcEventHandler::InitializeNpcCompsEventHandler>();
}

void NpcEventHandler::UnRegister()
{
    tlsEcs.dispatcher.sink<InitializeNpcCompsEvent>().disconnect<&NpcEventHandler::InitializeNpcCompsEventHandler>();
}
void NpcEventHandler::InitializeNpcCompsEventHandler(const InitializeNpcCompsEvent& event)
{
///<<< BEGIN WRITING YOUR CODE
///<<< END WRITING YOUR CODE
}
