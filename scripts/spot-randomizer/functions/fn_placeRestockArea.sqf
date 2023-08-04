private _is_Zeus = !isNull (getAssignedCuratorLogic player);

// START inline function definition ////////////////////////////

private _spot_randomizer_fnc_TriggerCondition =  // inline function
{
    private _return = false;

    private _vicsInZone = thisList select { _x isKindOf "LandVehicle"};
    {
        private _isSupplyVehicle = ([_x] call ace_rearm_fnc_isSource);

        // prevent broken containers from acting as resupply
        private _container = thisTrigger getVariable "shootnscoot_station";
        if (_is_Zeus && !alive _container) then { systemChat "supply container is dead"; };

        if (_isSupplyVehicle && (!isEngineOn _x) && alive _container) then
        {
            if (_is_Zeus) then { systemChat "supply vehicle detected"; };
            _return = true;
            break;
        };
    } forEach _vicsInZone;

    _return;
};

private _spot_randomizer_fnc_onTriggerActivation = // inline function
{
    if (_is_Zeus) then { systemChat "On Activation"; };

    private _vicsInZone = thisList select { _x isKindOf "LandVehicle"};
    {
        private _isSupplyVehicle = ([_x] call ace_rearm_fnc_isSource);
        private _capacity = GetNumber (configfile >> "CfgVehicles" >> typeof _x >> "ace_rearm_defaultSupply");
        if (_isSupplyVehicle && !isEngineOn _x) then {
            _x setFuel 1;
            [_x, _capacity] call ace_rearm_fnc_setSupplyCount;
            if (_is_Zeus) then { systemChat format ["refueled and restocked with %1 supply credits", _capacity]; };
        };

    } forEach thisList;
};


// END inline function definition ////////////////////////////


_trigger = createTrigger ["EmptyDetector", _this, true];
_trigger setVariable ["shootnscoot_station", _this];
_trigger setTriggerText "resupply_trigger";
_trigger setTriggerActivation ["ANY", "PRESENT", true];
_trigger setTriggerStatements [
    toString spot_randomizer_fnc_TriggerCondition,
    toString spot_randomizer_fnc_onTriggerActivation,
    ""
];
_trigger setTriggerArea [12, 10, getDir _this, true];
_trigger setTriggerTimeout [15, 15, 15, true];
_trigger setTriggerInterval 3;
_trigger setSoundEffect ["RHS_Autoloader", "", "", ""];
