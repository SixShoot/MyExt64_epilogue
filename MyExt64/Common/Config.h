
#pragma once

#include <string>
#include <set>
#include <vector>
#include <windows.h>

class Config {
public:
	static Config* Instance();

	struct Server {
		Server(Config *config);

		std::wstring name;
		int protocolVersion;
		bool debug;
		size_t maxIndex;
		size_t maxLevelMain;
		size_t maxLevelSubclass;
		time_t deadlockTimeout;
		time_t shutdownDuration;
		bool globalShout;
		bool globalTrade;
		bool allowLoadNpcSettingsAnyTime;
		bool mountKeepBuffs;
		bool dismountKeepBuffs;
		bool allowAirshipSkills;
		time_t pledgeLoadTimeout;
		time_t pledgeWarLoadTimeout;
		double vitalityMultiplier;
		std::vector<INT64> vitalityLevels;
		INT32 fixedPCCafePoints;
		bool enableVitaminManager;
		bool enableVitaminManagerNonPremiumItems;
		bool oneScriptDirectory;
		bool autoRemoveFromGMList;
		std::wstring loadDlls;
		std::wstring plugin;
		bool hookWriteProcessMemory;
	} *server;

	struct VoiceCommands {
		VoiceCommands(Config *config);

		bool enabled;
		bool expOnOff;
		bool online;
		bool offline;
		bool time;
		bool autoloot;
	} *voiceCommands;

	struct Fixes {
		Fixes(Config *config);

		int maxReplenishedVitalityPoints;
		bool commandChannelFriendly;
		int repeatSkillOnDistanceFailSeconds;
		bool disallowTradeInOlympiad;
		bool relogKeepSongsDances;
	} *fixes;

	struct Rate {
		Rate(Config *config);

		double adenaRate;
		double dropRate;
		double spoilRate;
		double bossDropRate;
		double herbRate;
		bool fixupLowLevel;
		std::set<INT64> ignoredItems;
		bool dump;
	} *rate;

	struct ClanRestrictions {
		ClanRestrictions(Config *config);

		UINT32 pledgeWarTimeout;
		UINT32 pledgeOustPenaltyTimeout;
		UINT32 pledgeWithdrawPenaltyTimeout;
		UINT32 pledgeOustedPenaltyTimeout;
		UINT32 pledgeRechallengePenaltyTimeout;
		UINT32 pledgeRechallengeDespiteRejectionPenaltyTimeout;
		UINT32 pledgeDismissTimeout;
		UINT32 pledgeDismissPenaltyTimeout;
		UINT32 pledgeDismissByNPC;
		UINT32 allianceCanAcceptNewMemberPledge;
		UINT32 allianceOustPenaltyTimeout;
		UINT32 allianceWithdrawPenaltyTimeout;
		UINT32 allianceOustedPenaltyTimeout;
		UINT32 allianceDismissPenaltyTimeout;
		UINT32 allianceRechallengePenaltyTimeout;
		UINT32 allianceRechallengeDespiteRejectionPenaltyTimeout;
		UINT32 castleAnnounceTime;
		UINT32 castleStandbyTime;
	} *clanRestrictions;

	struct BuffSystem {
		BuffSystem(Config *config);

		int maxSlots;
		int maxDivineInspirationBonusSlots;
	} *buffSystem;

	struct AutoLoot {
		AutoLoot(Config *config);

		bool autoLootMobDrop;
		bool autoLootBossDrop;
		int maximumAutoLootDistance;
		std::set<INT64> excludedItems;
	} *autoLoot;

	struct Beta {
		Beta(Config *config);

		bool enabled;
		bool level;
		bool class_;
		bool adena;
		bool noblesse;
		bool sp;
		bool fame;
	} *beta;

	struct Custom {
		Custom(Config *config);

		bool removeKamaelRace;
		bool removeVitalitySystem;
	} *custom;

	struct Npcd {
		Npcd(Config *config);

		bool useSplitAI;
		size_t aiBufferSizeMB;
	} *npcd;

protected:
	Config(const wchar_t *filename);
	std::wstring GetString(const wchar_t *section, const wchar_t *name, const wchar_t *defaultValue);
	INT64 GetInt(const wchar_t *section, const wchar_t *name, const INT64 defaultValue);
	bool GetBool(const wchar_t *section, const wchar_t *name, const bool defaultValue);
	double GetDouble(const wchar_t *section, const wchar_t *name, const double defaultValue);
	std::vector<INT64> GetIntList(const wchar_t *section, const wchar_t *name, const std::vector<INT64> &defaultValue);
	std::set<INT64> GetIntSet(const wchar_t *section, const wchar_t *name, const std::set<INT64> &defaultValue);

	std::wstring filename;
	static Config *instance;
};

