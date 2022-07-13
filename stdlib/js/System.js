var exec = require('child_process').exec;

class System {

    static runcmd(cmd) {
        exec(cmd,
            null
        );
    }

    static exit(code) {
        throw new Error();
    }
}