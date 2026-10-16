# 五行奇谈 · 游戏美术成果

本仓库独立保存 Q 版游戏美术、当前设计、切图与接入文件，以及逐图模型、质量和来源文字记录。范围仅包括原 image 项目；客户端、服务端和协议工具由各自工程维护。

## 资源入口

- [已确认风格与成图索引](designs/README.md)
- [UI 制作规范](qdao_ui_redesign_v5/UI_SPEC.md)
- [主城地图切图规范](主城地图切图规范.md)与[当前地图制作记录](qdao_city_tiles_4k_20260916/README.md)
- [角色动作制作](qdao_original_roster_v14_hd/action-remake-20261001/)
- [宠物战斗资源与交付](designs/creature-combat-20261005/delivery/README.md)
- [装备 UI](designs/equipment-ui-20261009/README.md)
- [场景交付说明](SCENE_DELIVERY.md)

## 使用与接入

正式图、当前设计、运行时图集、manifest、切片工具及必要生成来源按原相对目录保留。文件夹中的日期或版本号不代表该资源已废弃，请以当前索引和各目录 README 为准。

接入 Unity 时按对应资源目录的 README、manifest 和 unity-slices 说明操作；引用 ../mmorpg-client 的文档指向外部客户端工程。部分历史来源记录包含原机器绝对路径，它们作为来源证据保留，不是新仓运行目录。

三张 64K 主城地图仍有在制内容；导出与上传不代表它们已经通过正式验收。每个资产的实际状态以其当前制作记录为准。

## 给接手的 Codex

先阅读[项目规则](AGENTS.md)、[后续交接](docs/WUXING_QITAN_HANDOFF.md)、[美术定调](docs/QDAO_ART_DIRECTION.md)与[已确认成图](designs/README.md)。生图前读取[统一图像设置](config/image-generation.json)与[执行策略](docs/IMAGE_MODEL_POLICY.md)。沿用已确认风格，保留逐图模型、质量和来源证据。

本仓以当前有效文件建立独立历史，未导入原仓旧 Git 历史。稀疏检出隐藏的正式动作、设计依赖和来源记录已按原索引对象恢复；缓存、运维诊断、编译中间文件及清理回执确认的旧媒体不纳入。

[导出清单与逐文件 SHA256](docs/repository-export-20261015.json)记录来源版本、恢复和排除依据。可运行 Node.js 校验资源：

```powershell
node tools/verify-repository.cjs
```
