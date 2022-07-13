package export.hxsrc;

class File {
	public static function read(filename:Dynamic):Dynamic {
		return sys.io.File.getContent(filename);
	}

	public static function write(filename:Dynamic, content:Dynamic) {
		sys.io.File.saveContent(filename, content);
	}
}
