using System;

dynamic runcmd(dynamic? command) {
   Diagnostics.Process.Start("CMD.exe", command);
}

dynamic exit(dynamic? exit_code) {
if (Windows.Forms.Application.MessageLoop) 
{
   Windows.Forms.Application.Exit();
}
else
{
   Environment.Exit(exit_code);
}
}
