
#include "thread_context/ecs_context.h"
#include "proto/common/database/mysql_database_table.pb.h"
#include "player/system/bag_marshal.h"
#include "player/system/mission_marshal.h"

void PlayerDatabaseMessageFieldsUnmarshal(entt::entity player, const player_database& message){
	tlsEcs.actorRegistry.emplace<Transform>(player, message.transform());
	tlsEcs.actorRegistry.emplace<PlayerUint64Comp>(player, message.uint64_pb_component());
	tlsEcs.actorRegistry.emplace<PlayerSkillListComp>(player, message.skill_list());
	tlsEcs.actorRegistry.emplace<PlayerUint32Comp>(player, message.uint32_pb_component());
	tlsEcs.actorRegistry.emplace<BaseAttributesComp>(player, message.derived_attributes_component());
	tlsEcs.actorRegistry.emplace<LevelComp>(player, message.level_component());
	tlsEcs.actorRegistry.emplace<CurrencyComp>(player, message.currency());
	tlsEcs.actorRegistry.emplace<PlayerStressTestProbe>(player, message.stress_test_probe());
	tlsEcs.actorRegistry.emplace<PlayerMergeStateComp>(player, message.merge_state());
	tlsEcs.actorRegistry.emplace<PlayerAttributeComp>(player, message.attribute_component());
	tlsEcs.actorRegistry.emplace<PlayerPetComp>(player, message.pet_component());
	bag_marshal::Unmarshal(player, message.bag_component());
	mission_marshal::Unmarshal(player, message.mission_component());
	tlsEcs.actorRegistry.emplace<PlayerProfileComp>(player, message.profile_component());
	tlsEcs.actorRegistry.emplace<PlayerAssetOpLedgerComp>(player, message.asset_op_ledger());
	tlsEcs.actorRegistry.emplace<BattleSettlementLedgerComp>(player, message.settlement_ledger());
}

void PlayerDatabaseMessageFieldsMarshal(entt::entity player, player_database& message){
	message.mutable_transform()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<Transform>(player));
	message.mutable_uint64_pb_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerUint64Comp>(player));
	message.mutable_skill_list()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerSkillListComp>(player));
	message.mutable_uint32_pb_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerUint32Comp>(player));
	message.mutable_derived_attributes_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<BaseAttributesComp>(player));
	message.mutable_level_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<LevelComp>(player));
	message.mutable_currency()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<CurrencyComp>(player));
	message.mutable_stress_test_probe()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerStressTestProbe>(player));
	message.mutable_merge_state()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerMergeStateComp>(player));
	message.mutable_attribute_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerAttributeComp>(player));
	message.mutable_pet_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerPetComp>(player));
	bag_marshal::Marshal(player, *message.mutable_bag_component());
	mission_marshal::Marshal(player, *message.mutable_mission_component());
	message.mutable_profile_component()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerProfileComp>(player));
	message.mutable_asset_op_ledger()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<PlayerAssetOpLedgerComp>(player));
	message.mutable_settlement_ledger()->CopyFrom(tlsEcs.actorRegistry.get_or_emplace<BattleSettlementLedgerComp>(player));
}
