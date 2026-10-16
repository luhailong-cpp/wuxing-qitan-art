
#include "thread_context/ecs_context.h"
#include "proto/common/database/mysql_database_table.pb.h"
#include "player/system/bag_marshal.h"
#include "player/system/mission_marshal.h"

void PlayerDatabase1MessageFieldsUnmarshal(entt::entity player, const player_database_1& message){
	tlsEcs.actorRegistry.emplace<PlayerStressTestProbe>(player, message.stress_test_probe());
}

void PlayerDatabase1MessageFieldsMarshal(entt::entity player, player_database_1& message){
	message.mutable_stress_test_probe()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerStressTestProbe>(player));
}
