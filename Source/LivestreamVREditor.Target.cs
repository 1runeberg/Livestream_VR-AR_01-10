// MIT License [https://opensource.org/licenses/MIT] Copyright (c) 2017 runeberg.io

using UnrealBuildTool;
using System.Collections.Generic;

public class LivestreamVREditorTarget : TargetRules
{
	public LivestreamVREditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "LivestreamVR" } );
	}
}
