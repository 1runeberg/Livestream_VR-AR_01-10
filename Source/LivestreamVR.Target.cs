// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

using UnrealBuildTool;
using System.Collections.Generic;

public class LivestreamVRTarget : TargetRules
{
	public LivestreamVRTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "LivestreamVR" } );
	}
}
