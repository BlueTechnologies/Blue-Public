class System

runcmd: (cmd) ->
exec = require('child_process').exec
exec cmd, (error, stdout, stderr) -> null