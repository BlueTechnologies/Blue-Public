function read(filename)
finalstr = ""
file = io.open(filename, "r")
    for line in io.lines(file) do 
        finalstr = finalstr + line + "\n"
    end
    return finalstr
end

function write(filename, content)
    file = io.open(filename, "w")
    file.write(content)
end