type dynamic = interface{};
import (
    "iotuil"
    "fmt"
    "log"
	"os"
	"bufio"
)

func read(dynamic path) {
	content, err := os.ReadFile(path);
	return content;
	defer content.Close();
}

func write(dynamic content, dynamic path) {
d1 := []byte(content)
err := os.WriteFile(path, d1, 0644)
defer f.Close()
}