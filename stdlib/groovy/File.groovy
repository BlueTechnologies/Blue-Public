import java.io.File
import java.util.Scanner
import java.io.FileNotFoundException

def read(path) {
    String filec = new File(path).text
    return filec
}

def write(path, content) {
    new FileWriter(path, true).with {
    write(content)
    flush()
}
}