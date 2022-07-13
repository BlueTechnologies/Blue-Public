class File

read: (file) ->
fs = require "fs"

filen = file
fs.readFileSync filen, 'utf8'

write: (file) ->
fs = require "fs"

filen = file
fs.writeFile filen, JSON.stringify(@classification), (error) -> null

