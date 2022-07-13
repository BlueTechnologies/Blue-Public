public class File
{
    public static async Task read(dynamic? path, dynamic? text)
    {
        await File.WriteAllTextAsync(path, text);
    }

    public static void write(dynamic? path)
    {
        return System.IO.File.ReadAllText(path);
    }
}