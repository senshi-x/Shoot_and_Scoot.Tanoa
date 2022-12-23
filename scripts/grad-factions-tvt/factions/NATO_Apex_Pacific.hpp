class NATO_Apex_Pacific {
    class AllUnits {
        uniform[] = {
            "U_B_T_Soldier_AR_F",
            "U_B_T_Soldier_SL_F",
            "U_B_T_Soldier_F"
        };
        vest = "V_Chestrig_rgr";
        backpack = "";
        headgear[] = {
            "H_HelmetB_Light_tna_F",
            "H_HelmetB_Enh_tna_F",
            "H_HelmetB_tna_F"
        };
        primaryWeapon = "";
        primaryWeaponMagazine = "";
        primaryWeaponOptics = "";
        primaryWeaponMuzzle = "";
        primaryWeaponPointer = "";
        primaryWeaponUnderbarrel = "";
        primaryWeaponUnderbarrelMagazine = "";
        secondaryWeapon = "";
        secondaryWeaponMagazine = "";
        secondaryWeaponMuzzle = "";
        secondaryWeaponOptics = "";
        secondaryWeaponPointer = "";
        secondaryWeaponUnderbarrel = "";
        secondaryWeaponUnderbarrelMagazine = "";
        handgunWeapon = "hgun_P07_khk_F";
        handgunWeaponMagazine = "16Rnd_9x21_Mag";
        handgunWeaponMuzzle = "";
        handgunWeaponOptics = "";
        handgunWeaponPointer = "";
        handgunWeaponUnderbarrel = "";
        handgunWeaponUnderbarrelMagazine = "";
        goggles = "";
        nvgoggles = ""; // "NVGoggles_tna_F";
        radio = "TFAR_anprc152";
        binoculars = "Binocular";
        map = "ItemMap";
        gps = "ItemGPS";
        compass = "ItemCompass";
        watch = "ItemWatch";
        addItemsToUniform[] = {
            MEDICITEMS_BASE,
            LIST_2("ACE_Chemlight_HiWhite"),
            // "ACE_Flashlight_MX991",
            "ACE_MapTools"
          };
        addItemsToVest[] = {
            LIST_2("16Rnd_9x21_Mag"),
            LIST_1("SmokeShell"),
            LIST_1("SmokeShellGreen"),
            LIST_2("Chemlight_green")
        };
        addItemsToBackpack[] = {};
    };

    class Type {
        // rifleman (base class for hunter-killer teams)
        class Soldier_F {
            vest[] = {
              "V_PlateCarrier1_tna_F",
              "V_PlateCarrier2_tna_F",
              "V_PlateCarrierSpec_tna_F"
            };
            primaryWeapon = "arifle_MX_khk_F";
            primaryWeaponMagazine = "30Rnd_65x39_caseless_khaki_mag";
            primaryWeaponOptics = "optic_Aco";
            addItemsToVest[] = {
                LIST_7("30Rnd_65x39_caseless_khaki_mag"),
                LIST_2("HandGrenade")
            };
        };

        // squad leader
        class Soldier_SL_F: Soldier_F {
            backpack = "TFAR_rt1523g_bwmod";
            binoculars = "Laserdesignator_03";
            addItemsToBackpack[] = {
                LIST_3("30Rnd_65x39_caseless_khaki_mag_Tracer"),
                LIST_1("Laserbatteries")
            };
        };
        
        // medic
        class Medic_F: Soldier_F {
            backpack = "B_AssaultPack_tna_BTMedic_F";
            addItemsToBackpack[] = {
                LIST_30("ACE_fieldDressing"),
                LIST_10("ACE_morphine"),
                LIST_10("ACE_epinephrine"),
                LIST_5("ACE_bloodIV"), // 1 liter
                // LIST_5("ACE_bloodIV_500"),
                LIST_5("ACE_personalAidKit")
            };
        };
        
        // engineer
        class Engineer_F: Soldier_F {
            primaryWeapon = "arifle_MX_GL_khk_F";   // MX with underbarrel grenade launcher
            backpack = "B_AssaultPack_tna_F";
            addItemsToBackpack[] = {
                LIST_1("ToolKit"),
                LIST_1("ACE_EntrenchingTool"),
                LIST_1("ACE_wirecutter")
            };
        };
        
        // marksman
        class soldier_M_F: Soldier_F {
            primaryWeapon = "arifle_MXM_khk_F";
            primaryWeaponMagazine = "30Rnd_65x39_caseless_khaki_mag";
            primaryWeaponOptics = "optic_SOS_khk_F";
            primaryWeaponUnderbarrel = "bipod_01_F_khk"
        };
        
        /*** following are classes not derived from the rifleman ***/
        
        // automatic rifle 
        class Soldier_AR_F {
            vest[] = {
              "V_PlateCarrier1_tna_F",
              "V_PlateCarrier2_tna_F"
            };
            primaryWeapon = "arifle_MX_SW_khk_F";
            primaryWeaponMagazine = "100Rnd_65x39_caseless_khaki_mag";
            primaryWeaponUnderbarrel = "bipod_01_F_khk";
            addItemsToVest[] = {
                LIST_5("100Rnd_65x39_caseless_khaki_mag")
            };
        };
        
        // artillery gunner
        class Support_Mort_F {
            primaryWeapon = "arifle_MXC_khk_Holo_Pointer_F";
            primaryWeaponMagazine = "30Rnd_65x39_caseless_khaki_mag";
            primaryWeaponOptics = "optic_Holosight_khk_F";
            goggles = "G_Tactical_Clear";
            addItemsToVest[] = {
                LIST_5("30Rnd_65x39_caseless_khaki_mag")
            };
        };       
    };
};