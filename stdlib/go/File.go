package main
import (
	"os"
)

func read(path dynamic) (interface{}, dynamic) {
	var content, err = os.ReadFile(path.(string));
	return content, err;
}

func write(path2 dynamic, content dynamic) {
var d1 = []byte(content.(string))
os.WriteFile(path2.(string), d1, 0644)
}