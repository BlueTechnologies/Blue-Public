package export.hxsrc;

class System {
	public static function runcmd(command:Dynamic) {
		Sys.command(command);
	}

	public static function exit(exitCode:Dynamic) {
		Sys.exit(exitCode);
	}
}
