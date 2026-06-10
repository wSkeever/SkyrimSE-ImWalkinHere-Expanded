#pragma once

#include "AutoTOML.hpp"

struct Settings {
    using ISetting = AutoTOML::ISetting;
    using bSetting = AutoTOML::bSetting;

    static void load() {
        try {
            const auto table = toml::parse_file("Data/SKSE/Plugins/ImWalkinHere.toml"s);
            for (const auto& setting : ISetting::get_settings()) {
                setting->load(table);
            }
        } catch (const toml::parse_error& e) {
            std::ostringstream ss;
            ss << "Error parsing file \'" << *e.source().path << "\':\n"
               << '\t' << e.description() << '\n'
               << "\t\t(" << e.source().begin << ')';
            logger::error(fmt::runtime(ss.str()));
            throw std::runtime_error("failed to load settings"s);
        }
    }

    static inline bSetting disableAllyCollision{"General"s, "disableAllyCollision"s, true};
    static inline bSetting disableAllySummonCollision{"General"s, "disableAllySummonCollision"s, true};
    static inline bSetting disableDialogueCollision{"General"s, "disableDialogueCollision"s, true};
    static inline bSetting disableSummonCollision{"General"s, "disableSummonCollision"s, true};
    static inline bSetting disablePetCollision{"General"s, "disablePetCollision"s, true};
    static inline bSetting disableFriendlyCollision{"General"s, "disableFriendlyCollision"s, true};
};