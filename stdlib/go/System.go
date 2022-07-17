package main
import (
	"os/exec"
	"os"
)

func runcmd(command dynamic) {

    cmd := exec.Command(command.(string))

    cmd.Run()
}

func exit(exitcode dynamic) {
	
    os.Exit(exitcode.(int))
}