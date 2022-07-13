global function read(filename) {
    f = open(filename, "r")
    return f.read()
    f.close()
}

global function write(filename, content) {
    f = open(filename, "w")
    write(f, content)
    f.close()
}