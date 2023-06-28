params ["_oldUnit", "_killer", "_respawn", "_respawnDelay"];


// Kotomo bridge is a bit more than 8km away from the Opfor base near Saint-Paul.
// An AI in a prowler takes 8:30 min from bridge to base.
// Thus the respawn time penalty is set to be about 1min per 1km distance from point of dying to respawn point
private _respawnPoint = switch (playerSide) do
{
	case west:      { blufor_respawn    };
	case east:      { opfor_respawn     };
	case civilian:  { civilian_respawn  }; 
};
private _distance = (_oldUnit distance2D _respawnPoint);
private _timePenalty = if (playerSide == civilian) then { 
                              0;   // no time penalty for respawning Zeus
                          } else { 
                              _distance/1000 * 60;  // 60s per 1km distance
                          };
// setPlayerRespawnTime _timePenalty;

hint parseText format ["You died <t color='#ff0000'>%1km</t> away from your respawn point. %2
I plan to implement a respawn time penalty of <t color='#ff0000'>%3min %4s</t> for this in the future. %5
<t color='#00ffff'>Tell me in the debriefing how you would feel about that.</t> :-)", (_distance/1000) toFixed 3, "<br/><br/>", (_timePenalty/60) toFixed 0, (_timePenalty%60) toFixed 0, "<br/><br/>"];
