#include "lib/robin_hood.h"
#include "lib/SimpleIni.h"

class settings
{
public:
	
	static void readSettings();
	static inline bool bLogUserEvent = false;

	using userInputEvent = std::string;
	using animationEvent = std::string;
	static inline robin_hood::unordered_set<userInputEvent> registeredEvents;

	static inline robin_hood::unordered_map<userInputEvent, RE::SpellItem*> movementDirectionTraceMap;


	static inline robin_hood::unordered_map<userInputEvent, animationEvent> animEventMap_u;
	static inline robin_hood::unordered_map<userInputEvent, std::vector<RE::SpellItem*>*> keyTraceMap_u;
	static inline robin_hood::unordered_map<userInputEvent, std::vector<RE::SpellItem*>*> spellCastingMap_u;

	using buttonEvent = std::string;
	static inline robin_hood::unordered_map<buttonEvent, animationEvent> animEventMap_b;
	static inline robin_hood::unordered_map<buttonEvent, std::vector<RE::SpellItem*>*> keyTraceMap_b;
	static inline robin_hood::unordered_map<buttonEvent, std::vector<RE::SpellItem*>*> spellCastingMap_b;
private:
	static bool readSimpleIni(CSimpleIniA& a_ini, const char* a_iniAddress);
	static void readPluginSettings();
	static void readCustomConfigs();
	static void readMovementKeyTraceConfig();

	static void ReadBoolSetting(CSimpleIniA& a_ini, const char* a_sectionName, const char* a_settingName, bool& a_setting);
	static void ReadFloatSetting(CSimpleIniA& a_ini, const char* a_sectionName, const char* a_settingName, float& a_setting);
	static void ReadIntSetting(CSimpleIniA& a_ini, const char* a_sectionName, const char* a_settingName, uint32_t& a_setting);

};