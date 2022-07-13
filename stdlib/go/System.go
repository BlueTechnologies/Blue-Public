type dynamic = interface{};

import (
	"os/exec"
	"os"
)

func runcmd(dynamic command) {

    cmd := exec.Command(command)

    err := cmd.Run()
}

func exit(dynamic exitcode) {
	
    os.Exit(exitcode)
}